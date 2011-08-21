/******************************************************
SuperEQ written by Naoki Shibata  shibatch@users.sourceforge.net

Shibatch Super Equalizer is a graphic and parametric equalizer plugin
for winamp. This plugin uses 16383th order FIR filter with FFT algorithm.
It's equalization is very precise. Equalization setting can be done
for each channel separately.


Homepage : http://shibatch.sourceforge.net/
e-mail   : shibatch@users.sourceforge.net

Some changes are from foobar2000 (www.foobar2000.org):

Copyright � 2001-2003, Peter Pawlowski
All rights reserved.

Other changes are:

Copyright � 2003, Klaus Post

*******************************************************/

#include <math.h>
#include "stdafx.h"
#include "supereq.h"
#include "paramlist.h"



enum {N_BANDS=18};

struct eq_config
{
	int bands[N_BANDS];
};

static const eq_config def_bands = {20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20};


static void setup_bands(const eq_config & src,double dst[N_BANDS])
{
	int n;
	for(n=0;n<N_BANDS;n++)
	{
		dst[n] = (double)pow(10.0,(src.bands[n]-20)/-20.0);
	}
}


class AVSsupereq : public GenericVideoFilter 
{
private:
	ptr_list_simple<supereq_base> eqs;
	UINT last_nch,last_srate;
	paramlist paramroot;
	eq_config my_eq;
	mem_block_t<audio_sample> interlace_buf;

  int dstbuffer_size;
  int dst_samples_filled;

  SFLOAT* dstbuffer;
  SFLOAT* passbuffer;
  __int64 next_sample;
  __int64 inputReadOffset;

public:
static AVSValue __cdecl Create(AVSValue args, void*, IScriptEnvironment* env);


AVSsupereq(PClip _child, const char* filename, IScriptEnvironment* env)
: GenericVideoFilter(ConvertAudio::Create(_child, SAMPLE_FLOAT, SAMPLE_FLOAT))
{
  last_nch = vi.AudioChannels();
  last_srate = vi.audio_samples_per_second;
  
  FILE *settingsfile;
  settingsfile = fopen(filename, "r");		
  
  if (settingsfile != NULL) {
    int n;
    for(n=0;n<N_BANDS;n++) {
      int readval;
      if (fscanf(settingsfile, "%d", &readval) == 1) {
        my_eq.bands[n] = ((-readval)+20);
      }
    }
    fclose(settingsfile);
  } else {
    env->ThrowError("SuperEQ: Could not open file");
  }
  
  UINT n;
  for(n=0;n<last_nch;n++)
    eqs.add_item(new supereq<float>);
  double bands[N_BANDS];
  //    my_eq = cfg_eq;
  setup_bands(my_eq,bands);
  for(n=0;n<last_nch;n++)
    eqs[n]->equ_makeTable(bands,&paramroot,(double)last_srate);

  dstbuffer = new SFLOAT[vi.audio_samples_per_second * vi.AudioChannels()];  // Our buffer can minimum contain one second.
  passbuffer = new SFLOAT[vi.audio_samples_per_second * vi.AudioChannels()];  // Our buffer can minimum contain one second.
  dstbuffer_size = vi.audio_samples_per_second;

  next_sample = 0;  // Next output sample
  inputReadOffset = 0;  // Next input sample
  dst_samples_filled = 0;
}

void __stdcall AVSsupereq::GetAudio(void* buf, __int64 start, __int64 count, IScriptEnvironment* env)
{

  if (start != next_sample) {  // Reset on seek
    inputReadOffset = start;  // Reset at new read position.
    dst_samples_filled=0;

    eqs.delete_all();
    UINT n;
    for(n=0;n<last_nch;n++)
      eqs.add_item(new supereq<float>);
    double bands[N_BANDS];
    setup_bands(my_eq,bands);
    for(n=0;n<last_nch;n++)
      eqs[n]->equ_makeTable(bands,&paramroot,(double)last_srate);
  }

  bool buffer_full = false;
  int samples_filled = 0;

  do {
    // Empty buffer if something is still left.
    if (dst_samples_filled) {
      int copysamples = min((int)count-samples_filled, dst_samples_filled);
      // Copy finished samples
      env->BitBlt((BYTE*)buf+samples_filled*last_nch*sizeof(SFLOAT),0,
        (BYTE*)dstbuffer,0,copysamples*last_nch*sizeof(SFLOAT),1);
      dst_samples_filled -= copysamples;

      if (dst_samples_filled) { // Move non-used samples
        memcpy(dstbuffer, &dstbuffer[copysamples*last_nch], dst_samples_filled*sizeof(SFLOAT)*last_nch);
      }
      samples_filled += copysamples;
      if (samples_filled >= count)
        buffer_full = true;
    }
    // If buffer empty - refill
    if (dst_samples_filled<=0) {
      // Feed new samples to filter
      child->GetAudio(dstbuffer, inputReadOffset, last_srate, env);
      inputReadOffset += last_srate;

			for(UINT n=0;n<last_nch;n++)  // Copies n channels to separate buffers to individual filters
			{
				UINT s;
				for(s=0;s<last_srate;s++)
					passbuffer[s]=dstbuffer[s*last_nch+n];
				
				eqs[n]->write_samples(passbuffer, last_srate);
			}

      // Read back samples from filter
		  int samples_out = 0;
		  for(UINT n=0;n<last_nch;n++)  // Copies back samples from individual filters
		  {
			  SFLOAT *data_out = eqs[n]->get_output(&samples_out);
        // Check temp buffer size
        if (dstbuffer_size < samples_out) {
          if (dstbuffer_size)
            delete[] dstbuffer;
          dstbuffer = new SFLOAT[samples_out*last_nch];
          dstbuffer_size = samples_out;
        }
			  UINT s;
			  for(s=0;s<(UINT)samples_out;s++)
				  dstbuffer[s*last_nch+n]=data_out[s];
      }
			dst_samples_filled = samples_out;
		}  
  } while (!buffer_full);
  next_sample += count;
}
	~AVSsupereq()
	{
    delete[] dstbuffer;
    delete[] passbuffer;
		eqs.delete_all();
	}


};

AVSValue __cdecl AVSsupereq::Create(AVSValue args, void*, IScriptEnvironment* env) {
  return new AVSsupereq(args[0].AsClip(), args[1].AsString(), env);
}


AVSFunction SuperEq_filters[] = {
  { "SuperEQ", "cs", AVSsupereq::Create },
  { 0 }
};


