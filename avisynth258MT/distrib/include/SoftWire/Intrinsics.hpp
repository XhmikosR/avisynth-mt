/* Automatically generated file, do not modify */
/* To regenerate this file uncomment generateIntrinsics() in InstructionSet.cpp */

#ifndef SOFTWIRE_NO_INTRINSICS

typedef OperandIMM IMM;
typedef OperandAL AL;
typedef OperandAX AX;
typedef OperandEAX EAX;
typedef OperandDX DX;
typedef OperandCL CL;
typedef OperandCX CX;
typedef OperandECX ECX;
typedef OperandST0 ST0;
typedef OperandREG8 REG8;
typedef OperandREG16 REG16;
typedef OperandREG32 REG32;
typedef OperandFPUREG FPUREG;
typedef OperandMMREG MMREG;
typedef OperandXMMREG XMMREG;
typedef OperandMEM8 MEM8;
typedef OperandMEM16 MEM16;
typedef OperandMEM32 MEM32;
typedef OperandMEM64 MEM64;
typedef OperandMEM128 MEM128;
typedef OperandR_M8 R_M8;
typedef OperandR_M16 R_M16;
typedef OperandR_M32 R_M32;
typedef OperandR_M64 R_M64;
typedef OperandR_M128 R_M128;
typedef OperandXMM32 XMM32;
typedef OperandXMM64 XMM64;
typedef OperandREF REF;
typedef OperandSTR STR;

#define enc virtual Encoding*

enc aaa(){return x86(0);}
enc aas(){return x86(1);}
enc aad(){return x86(2);}
enc aad(REF a){return x86(3,a);}
enc aad(int a){return x86(3,(IMM)a);}
enc aam(){return x86(4);}
enc aam(REF a){return x86(5,a);}
enc aam(int a){return x86(5,(IMM)a);}
enc adc(REG8 a,REG8 b){return x86(6,a,b);}
enc adc(MEM8 a,REG8 b){return x86(6,a,b);}
enc adc(R_M8 a,REG8 b){return x86(6,a,b);}
enc adc(REG16 a,REG16 b){return x86(7,a,b);}
enc adc(MEM16 a,REG16 b){return x86(7,a,b);}
enc adc(R_M16 a,REG16 b){return x86(7,a,b);}
enc adc(REG32 a,REG32 b){return x86(8,a,b);}
enc adc(MEM32 a,REG32 b){return x86(8,a,b);}
enc adc(R_M32 a,REG32 b){return x86(8,a,b);}
enc lock_adc(MEM8 a,REG8 b){return x86(9,a,b);}
enc lock_adc(MEM16 a,REG16 b){return x86(10,a,b);}
enc lock_adc(MEM32 a,REG32 b){return x86(11,a,b);}
enc adc(REG8 a,MEM8 b){return x86(12,a,b);}
enc adc(REG8 a,R_M8 b){return x86(12,a,b);}
enc adc(REG16 a,MEM16 b){return x86(13,a,b);}
enc adc(REG16 a,R_M16 b){return x86(13,a,b);}
enc adc(REG32 a,MEM32 b){return x86(14,a,b);}
enc adc(REG32 a,R_M32 b){return x86(14,a,b);}
enc adc(REG8 a,char b){return x86(15,a,(IMM)b);}
enc adc(AL a,char b){return x86(15,a,(IMM)b);}
enc adc(CL a,char b){return x86(15,a,(IMM)b);}
enc adc(MEM8 a,char b){return x86(15,a,(IMM)b);}
enc adc(R_M8 a,char b){return x86(15,a,(IMM)b);}
enc adc(REG16 a,char b){return x86(16,a,(IMM)b);}
enc adc(REG16 a,short b){return x86(16,a,(IMM)b);}
enc adc(MEM16 a,char b){return x86(16,a,(IMM)b);}
enc adc(MEM16 a,short b){return x86(16,a,(IMM)b);}
enc adc(R_M16 a,char b){return x86(16,a,(IMM)b);}
enc adc(R_M16 a,short b){return x86(16,a,(IMM)b);}
enc adc(REG32 a,REF b){return x86(17,a,b);}
enc adc(REG32 a,int b){return x86(17,a,(IMM)b);}
enc adc(MEM32 a,REF b){return x86(17,a,b);}
enc adc(MEM32 a,int b){return x86(17,a,(IMM)b);}
enc adc(R_M32 a,REF b){return x86(17,a,b);}
enc adc(R_M32 a,int b){return x86(17,a,(IMM)b);}
enc lock_adc(MEM8 a,char b){return x86(20,a,(IMM)b);}
enc lock_adc(MEM16 a,char b){return x86(21,a,(IMM)b);}
enc lock_adc(MEM16 a,short b){return x86(21,a,(IMM)b);}
enc lock_adc(MEM32 a,REF b){return x86(22,a,b);}
enc lock_adc(MEM32 a,int b){return x86(22,a,(IMM)b);}
enc add(REG8 a,REG8 b){return x86(28,a,b);}
enc add(MEM8 a,REG8 b){return x86(28,a,b);}
enc add(R_M8 a,REG8 b){return x86(28,a,b);}
enc add(REG16 a,REG16 b){return x86(29,a,b);}
enc add(MEM16 a,REG16 b){return x86(29,a,b);}
enc add(R_M16 a,REG16 b){return x86(29,a,b);}
enc add(REG32 a,REG32 b){return x86(30,a,b);}
enc add(MEM32 a,REG32 b){return x86(30,a,b);}
enc add(R_M32 a,REG32 b){return x86(30,a,b);}
enc lock_add(MEM8 a,REG8 b){return x86(31,a,b);}
enc lock_add(MEM16 a,REG16 b){return x86(32,a,b);}
enc lock_add(MEM32 a,REG32 b){return x86(33,a,b);}
enc add(REG8 a,MEM8 b){return x86(34,a,b);}
enc add(REG8 a,R_M8 b){return x86(34,a,b);}
enc add(REG16 a,MEM16 b){return x86(35,a,b);}
enc add(REG16 a,R_M16 b){return x86(35,a,b);}
enc add(REG32 a,MEM32 b){return x86(36,a,b);}
enc add(REG32 a,R_M32 b){return x86(36,a,b);}
enc add(REG8 a,char b){return x86(37,a,(IMM)b);}
enc add(AL a,char b){return x86(37,a,(IMM)b);}
enc add(CL a,char b){return x86(37,a,(IMM)b);}
enc add(MEM8 a,char b){return x86(37,a,(IMM)b);}
enc add(R_M8 a,char b){return x86(37,a,(IMM)b);}
enc add(REG16 a,char b){return x86(38,a,(IMM)b);}
enc add(REG16 a,short b){return x86(38,a,(IMM)b);}
enc add(MEM16 a,char b){return x86(38,a,(IMM)b);}
enc add(MEM16 a,short b){return x86(38,a,(IMM)b);}
enc add(R_M16 a,char b){return x86(38,a,(IMM)b);}
enc add(R_M16 a,short b){return x86(38,a,(IMM)b);}
enc add(REG32 a,REF b){return x86(39,a,b);}
enc add(REG32 a,int b){return x86(39,a,(IMM)b);}
enc add(MEM32 a,REF b){return x86(39,a,b);}
enc add(MEM32 a,int b){return x86(39,a,(IMM)b);}
enc add(R_M32 a,REF b){return x86(39,a,b);}
enc add(R_M32 a,int b){return x86(39,a,(IMM)b);}
enc lock_add(MEM8 a,char b){return x86(42,a,(IMM)b);}
enc lock_add(MEM16 a,char b){return x86(43,a,(IMM)b);}
enc lock_add(MEM16 a,short b){return x86(43,a,(IMM)b);}
enc lock_add(MEM32 a,REF b){return x86(44,a,b);}
enc lock_add(MEM32 a,int b){return x86(44,a,(IMM)b);}
enc addpd(XMMREG a,XMMREG b){return x86(50,a,b);}
enc addpd(XMMREG a,MEM128 b){return x86(50,a,b);}
enc addpd(XMMREG a,R_M128 b){return x86(50,a,b);}
enc addps(XMMREG a,XMMREG b){return x86(51,a,b);}
enc addps(XMMREG a,MEM128 b){return x86(51,a,b);}
enc addps(XMMREG a,R_M128 b){return x86(51,a,b);}
enc addsd(XMMREG a,XMMREG b){return x86(52,a,b);}
enc addsd(XMMREG a,MEM64 b){return x86(52,a,b);}
enc addsd(XMMREG a,XMM64 b){return x86(52,a,b);}
enc addss(XMMREG a,XMMREG b){return x86(53,a,b);}
enc addss(XMMREG a,MEM32 b){return x86(53,a,b);}
enc addss(XMMREG a,XMM32 b){return x86(53,a,b);}
enc addsubpd(XMMREG a,XMMREG b){return x86(54,a,b);}
enc addsubpd(XMMREG a,MEM128 b){return x86(54,a,b);}
enc addsubpd(XMMREG a,R_M128 b){return x86(54,a,b);}
enc addsubps(XMMREG a,XMMREG b){return x86(55,a,b);}
enc addsubps(XMMREG a,MEM128 b){return x86(55,a,b);}
enc addsubps(XMMREG a,R_M128 b){return x86(55,a,b);}
enc and(REG8 a,REG8 b){return x86(56,a,b);}
enc and(MEM8 a,REG8 b){return x86(56,a,b);}
enc and(R_M8 a,REG8 b){return x86(56,a,b);}
enc and(REG16 a,REG16 b){return x86(57,a,b);}
enc and(MEM16 a,REG16 b){return x86(57,a,b);}
enc and(R_M16 a,REG16 b){return x86(57,a,b);}
enc and(REG32 a,REG32 b){return x86(58,a,b);}
enc and(MEM32 a,REG32 b){return x86(58,a,b);}
enc and(R_M32 a,REG32 b){return x86(58,a,b);}
enc lock_and(MEM8 a,REG8 b){return x86(59,a,b);}
enc lock_and(MEM16 a,REG16 b){return x86(60,a,b);}
enc lock_and(MEM32 a,REG32 b){return x86(61,a,b);}
enc and(REG8 a,MEM8 b){return x86(62,a,b);}
enc and(REG8 a,R_M8 b){return x86(62,a,b);}
enc and(REG16 a,MEM16 b){return x86(63,a,b);}
enc and(REG16 a,R_M16 b){return x86(63,a,b);}
enc and(REG32 a,MEM32 b){return x86(64,a,b);}
enc and(REG32 a,R_M32 b){return x86(64,a,b);}
enc and(REG8 a,char b){return x86(65,a,(IMM)b);}
enc and(AL a,char b){return x86(65,a,(IMM)b);}
enc and(CL a,char b){return x86(65,a,(IMM)b);}
enc and(MEM8 a,char b){return x86(65,a,(IMM)b);}
enc and(R_M8 a,char b){return x86(65,a,(IMM)b);}
enc and(REG16 a,char b){return x86(66,a,(IMM)b);}
enc and(REG16 a,short b){return x86(66,a,(IMM)b);}
enc and(MEM16 a,char b){return x86(66,a,(IMM)b);}
enc and(MEM16 a,short b){return x86(66,a,(IMM)b);}
enc and(R_M16 a,char b){return x86(66,a,(IMM)b);}
enc and(R_M16 a,short b){return x86(66,a,(IMM)b);}
enc and(REG32 a,REF b){return x86(67,a,b);}
enc and(REG32 a,int b){return x86(67,a,(IMM)b);}
enc and(MEM32 a,REF b){return x86(67,a,b);}
enc and(MEM32 a,int b){return x86(67,a,(IMM)b);}
enc and(R_M32 a,REF b){return x86(67,a,b);}
enc and(R_M32 a,int b){return x86(67,a,(IMM)b);}
enc lock_and(MEM8 a,char b){return x86(70,a,(IMM)b);}
enc lock_and(MEM16 a,char b){return x86(71,a,(IMM)b);}
enc lock_and(MEM16 a,short b){return x86(71,a,(IMM)b);}
enc lock_and(MEM32 a,REF b){return x86(72,a,b);}
enc lock_and(MEM32 a,int b){return x86(72,a,(IMM)b);}
enc andnpd(XMMREG a,XMMREG b){return x86(78,a,b);}
enc andnpd(XMMREG a,MEM128 b){return x86(78,a,b);}
enc andnpd(XMMREG a,R_M128 b){return x86(78,a,b);}
enc andnps(XMMREG a,XMMREG b){return x86(79,a,b);}
enc andnps(XMMREG a,MEM128 b){return x86(79,a,b);}
enc andnps(XMMREG a,R_M128 b){return x86(79,a,b);}
enc andpd(XMMREG a,XMMREG b){return x86(80,a,b);}
enc andpd(XMMREG a,MEM128 b){return x86(80,a,b);}
enc andpd(XMMREG a,R_M128 b){return x86(80,a,b);}
enc andps(XMMREG a,XMMREG b){return x86(81,a,b);}
enc andps(XMMREG a,MEM128 b){return x86(81,a,b);}
enc andps(XMMREG a,R_M128 b){return x86(81,a,b);}
enc bound(REG16 a,MEM8 b){return x86(82,a,b);}
enc bound(REG16 a,MEM16 b){return x86(82,a,b);}
enc bound(REG16 a,MEM32 b){return x86(82,a,b);}
enc bound(REG16 a,MEM64 b){return x86(82,a,b);}
enc bound(REG16 a,MEM128 b){return x86(82,a,b);}
enc bound(REG32 a,MEM8 b){return x86(83,a,b);}
enc bound(REG32 a,MEM16 b){return x86(83,a,b);}
enc bound(REG32 a,MEM32 b){return x86(83,a,b);}
enc bound(REG32 a,MEM64 b){return x86(83,a,b);}
enc bound(REG32 a,MEM128 b){return x86(83,a,b);}
enc bsf(REG16 a,REG16 b){return x86(84,a,b);}
enc bsf(REG16 a,MEM16 b){return x86(84,a,b);}
enc bsf(REG16 a,R_M16 b){return x86(84,a,b);}
enc bsf(REG32 a,REG32 b){return x86(85,a,b);}
enc bsf(REG32 a,MEM32 b){return x86(85,a,b);}
enc bsf(REG32 a,R_M32 b){return x86(85,a,b);}
enc bsr(REG16 a,REG16 b){return x86(86,a,b);}
enc bsr(REG16 a,MEM16 b){return x86(86,a,b);}
enc bsr(REG16 a,R_M16 b){return x86(86,a,b);}
enc bsr(REG32 a,REG32 b){return x86(87,a,b);}
enc bsr(REG32 a,MEM32 b){return x86(87,a,b);}
enc bsr(REG32 a,R_M32 b){return x86(87,a,b);}
enc bswap(REG32 a){return x86(88,a);}
enc bt(REG16 a,REG16 b){return x86(89,a,b);}
enc bt(MEM16 a,REG16 b){return x86(89,a,b);}
enc bt(R_M16 a,REG16 b){return x86(89,a,b);}
enc bt(REG32 a,REG32 b){return x86(90,a,b);}
enc bt(MEM32 a,REG32 b){return x86(90,a,b);}
enc bt(R_M32 a,REG32 b){return x86(90,a,b);}
enc bt(REG16 a,char b){return x86(91,a,(IMM)b);}
enc bt(MEM16 a,char b){return x86(91,a,(IMM)b);}
enc bt(R_M16 a,char b){return x86(91,a,(IMM)b);}
enc bt(REG32 a,char b){return x86(92,a,(IMM)b);}
enc bt(MEM32 a,char b){return x86(92,a,(IMM)b);}
enc bt(R_M32 a,char b){return x86(92,a,(IMM)b);}
enc btc(REG16 a,REG16 b){return x86(93,a,b);}
enc btc(MEM16 a,REG16 b){return x86(93,a,b);}
enc btc(R_M16 a,REG16 b){return x86(93,a,b);}
enc btc(REG32 a,REG32 b){return x86(94,a,b);}
enc btc(MEM32 a,REG32 b){return x86(94,a,b);}
enc btc(R_M32 a,REG32 b){return x86(94,a,b);}
enc btc(REG16 a,char b){return x86(95,a,(IMM)b);}
enc btc(MEM16 a,char b){return x86(95,a,(IMM)b);}
enc btc(R_M16 a,char b){return x86(95,a,(IMM)b);}
enc btc(REG32 a,char b){return x86(96,a,(IMM)b);}
enc btc(MEM32 a,char b){return x86(96,a,(IMM)b);}
enc btc(R_M32 a,char b){return x86(96,a,(IMM)b);}
enc btr(REG16 a,REG16 b){return x86(97,a,b);}
enc btr(MEM16 a,REG16 b){return x86(97,a,b);}
enc btr(R_M16 a,REG16 b){return x86(97,a,b);}
enc btr(REG32 a,REG32 b){return x86(98,a,b);}
enc btr(MEM32 a,REG32 b){return x86(98,a,b);}
enc btr(R_M32 a,REG32 b){return x86(98,a,b);}
enc btr(REG16 a,char b){return x86(99,a,(IMM)b);}
enc btr(MEM16 a,char b){return x86(99,a,(IMM)b);}
enc btr(R_M16 a,char b){return x86(99,a,(IMM)b);}
enc btr(REG32 a,char b){return x86(100,a,(IMM)b);}
enc btr(MEM32 a,char b){return x86(100,a,(IMM)b);}
enc btr(R_M32 a,char b){return x86(100,a,(IMM)b);}
enc bts(REG16 a,REG16 b){return x86(101,a,b);}
enc bts(MEM16 a,REG16 b){return x86(101,a,b);}
enc bts(R_M16 a,REG16 b){return x86(101,a,b);}
enc bts(REG32 a,REG32 b){return x86(102,a,b);}
enc bts(MEM32 a,REG32 b){return x86(102,a,b);}
enc bts(R_M32 a,REG32 b){return x86(102,a,b);}
enc bts(REG16 a,char b){return x86(103,a,(IMM)b);}
enc bts(MEM16 a,char b){return x86(103,a,(IMM)b);}
enc bts(R_M16 a,char b){return x86(103,a,(IMM)b);}
enc bts(REG32 a,char b){return x86(104,a,(IMM)b);}
enc bts(MEM32 a,char b){return x86(104,a,(IMM)b);}
enc bts(R_M32 a,char b){return x86(104,a,(IMM)b);}
enc lock_btc(MEM16 a,REG16 b){return x86(105,a,b);}
enc lock_btc(MEM32 a,REG32 b){return x86(106,a,b);}
enc lock_btc(MEM16 a,char b){return x86(107,a,(IMM)b);}
enc lock_btc(MEM32 a,char b){return x86(108,a,(IMM)b);}
enc lock_btr(MEM16 a,REG16 b){return x86(109,a,b);}
enc lock_btr(MEM32 a,REG32 b){return x86(110,a,b);}
enc lock_btr(MEM16 a,char b){return x86(111,a,(IMM)b);}
enc lock_btr(MEM32 a,char b){return x86(112,a,(IMM)b);}
enc lock_bts(MEM16 a,REG16 b){return x86(113,a,b);}
enc lock_bts(MEM32 a,REG32 b){return x86(114,a,b);}
enc lock_bts(MEM16 a,char b){return x86(115,a,(IMM)b);}
enc lock_bts(MEM32 a,char b){return x86(116,a,(IMM)b);}
enc call(REF a){return x86(117,a);}
enc call(int a){return x86(117,(IMM)a);}
enc call(REG16 a){return x86(118,a);}
enc call(MEM16 a){return x86(118,a);}
enc call(R_M16 a){return x86(118,a);}
enc call(REG32 a){return x86(119,a);}
enc call(MEM32 a){return x86(119,a);}
enc call(R_M32 a){return x86(119,a);}
enc cbw(){return x86(120);}
enc cwd(){return x86(121);}
enc cdq(){return x86(122);}
enc cwde(){return x86(123);}
enc clc(){return x86(124);}
enc cld(){return x86(125);}
enc cli(){return x86(126);}
enc clflush(MEM8 a){return x86(127,a);}
enc clflush(MEM16 a){return x86(127,a);}
enc clflush(MEM32 a){return x86(127,a);}
enc clflush(MEM64 a){return x86(127,a);}
enc clflush(MEM128 a){return x86(127,a);}
enc cmc(){return x86(128);}
enc cmovo(REG16 a,REG16 b){return x86(129,a,b);}
enc cmovo(REG16 a,MEM16 b){return x86(129,a,b);}
enc cmovo(REG16 a,R_M16 b){return x86(129,a,b);}
enc cmovno(REG16 a,REG16 b){return x86(130,a,b);}
enc cmovno(REG16 a,MEM16 b){return x86(130,a,b);}
enc cmovno(REG16 a,R_M16 b){return x86(130,a,b);}
enc cmovb(REG16 a,REG16 b){return x86(131,a,b);}
enc cmovb(REG16 a,MEM16 b){return x86(131,a,b);}
enc cmovb(REG16 a,R_M16 b){return x86(131,a,b);}
enc cmovc(REG16 a,REG16 b){return x86(132,a,b);}
enc cmovc(REG16 a,MEM16 b){return x86(132,a,b);}
enc cmovc(REG16 a,R_M16 b){return x86(132,a,b);}
enc cmovnea(REG16 a,REG16 b){return x86(133,a,b);}
enc cmovnea(REG16 a,MEM16 b){return x86(133,a,b);}
enc cmovnea(REG16 a,R_M16 b){return x86(133,a,b);}
enc cmovae(REG16 a,REG16 b){return x86(134,a,b);}
enc cmovae(REG16 a,MEM16 b){return x86(134,a,b);}
enc cmovae(REG16 a,R_M16 b){return x86(134,a,b);}
enc cmovnb(REG16 a,REG16 b){return x86(135,a,b);}
enc cmovnb(REG16 a,MEM16 b){return x86(135,a,b);}
enc cmovnb(REG16 a,R_M16 b){return x86(135,a,b);}
enc cmovnc(REG16 a,REG16 b){return x86(136,a,b);}
enc cmovnc(REG16 a,MEM16 b){return x86(136,a,b);}
enc cmovnc(REG16 a,R_M16 b){return x86(136,a,b);}
enc cmove(REG16 a,REG16 b){return x86(137,a,b);}
enc cmove(REG16 a,MEM16 b){return x86(137,a,b);}
enc cmove(REG16 a,R_M16 b){return x86(137,a,b);}
enc cmovz(REG16 a,REG16 b){return x86(138,a,b);}
enc cmovz(REG16 a,MEM16 b){return x86(138,a,b);}
enc cmovz(REG16 a,R_M16 b){return x86(138,a,b);}
enc cmovne(REG16 a,REG16 b){return x86(139,a,b);}
enc cmovne(REG16 a,MEM16 b){return x86(139,a,b);}
enc cmovne(REG16 a,R_M16 b){return x86(139,a,b);}
enc cmovnz(REG16 a,REG16 b){return x86(140,a,b);}
enc cmovnz(REG16 a,MEM16 b){return x86(140,a,b);}
enc cmovnz(REG16 a,R_M16 b){return x86(140,a,b);}
enc cmovbe(REG16 a,REG16 b){return x86(141,a,b);}
enc cmovbe(REG16 a,MEM16 b){return x86(141,a,b);}
enc cmovbe(REG16 a,R_M16 b){return x86(141,a,b);}
enc cmovna(REG16 a,REG16 b){return x86(142,a,b);}
enc cmovna(REG16 a,MEM16 b){return x86(142,a,b);}
enc cmovna(REG16 a,R_M16 b){return x86(142,a,b);}
enc cmova(REG16 a,REG16 b){return x86(143,a,b);}
enc cmova(REG16 a,MEM16 b){return x86(143,a,b);}
enc cmova(REG16 a,R_M16 b){return x86(143,a,b);}
enc cmovnbe(REG16 a,REG16 b){return x86(144,a,b);}
enc cmovnbe(REG16 a,MEM16 b){return x86(144,a,b);}
enc cmovnbe(REG16 a,R_M16 b){return x86(144,a,b);}
enc cmovs(REG16 a,REG16 b){return x86(145,a,b);}
enc cmovs(REG16 a,MEM16 b){return x86(145,a,b);}
enc cmovs(REG16 a,R_M16 b){return x86(145,a,b);}
enc cmovns(REG16 a,REG16 b){return x86(146,a,b);}
enc cmovns(REG16 a,MEM16 b){return x86(146,a,b);}
enc cmovns(REG16 a,R_M16 b){return x86(146,a,b);}
enc cmovp(REG16 a,REG16 b){return x86(147,a,b);}
enc cmovp(REG16 a,MEM16 b){return x86(147,a,b);}
enc cmovp(REG16 a,R_M16 b){return x86(147,a,b);}
enc cmovpe(REG16 a,REG16 b){return x86(148,a,b);}
enc cmovpe(REG16 a,MEM16 b){return x86(148,a,b);}
enc cmovpe(REG16 a,R_M16 b){return x86(148,a,b);}
enc cmovnp(REG16 a,REG16 b){return x86(149,a,b);}
enc cmovnp(REG16 a,MEM16 b){return x86(149,a,b);}
enc cmovnp(REG16 a,R_M16 b){return x86(149,a,b);}
enc cmovpo(REG16 a,REG16 b){return x86(150,a,b);}
enc cmovpo(REG16 a,MEM16 b){return x86(150,a,b);}
enc cmovpo(REG16 a,R_M16 b){return x86(150,a,b);}
enc cmovl(REG16 a,REG16 b){return x86(151,a,b);}
enc cmovl(REG16 a,MEM16 b){return x86(151,a,b);}
enc cmovl(REG16 a,R_M16 b){return x86(151,a,b);}
enc cmovnge(REG16 a,REG16 b){return x86(152,a,b);}
enc cmovnge(REG16 a,MEM16 b){return x86(152,a,b);}
enc cmovnge(REG16 a,R_M16 b){return x86(152,a,b);}
enc cmovge(REG16 a,REG16 b){return x86(153,a,b);}
enc cmovge(REG16 a,MEM16 b){return x86(153,a,b);}
enc cmovge(REG16 a,R_M16 b){return x86(153,a,b);}
enc cmovnl(REG16 a,REG16 b){return x86(154,a,b);}
enc cmovnl(REG16 a,MEM16 b){return x86(154,a,b);}
enc cmovnl(REG16 a,R_M16 b){return x86(154,a,b);}
enc cmovle(REG16 a,REG16 b){return x86(155,a,b);}
enc cmovle(REG16 a,MEM16 b){return x86(155,a,b);}
enc cmovle(REG16 a,R_M16 b){return x86(155,a,b);}
enc cmovng(REG16 a,REG16 b){return x86(156,a,b);}
enc cmovng(REG16 a,MEM16 b){return x86(156,a,b);}
enc cmovng(REG16 a,R_M16 b){return x86(156,a,b);}
enc cmovg(REG16 a,REG16 b){return x86(157,a,b);}
enc cmovg(REG16 a,MEM16 b){return x86(157,a,b);}
enc cmovg(REG16 a,R_M16 b){return x86(157,a,b);}
enc cmovnle(REG16 a,REG16 b){return x86(158,a,b);}
enc cmovnle(REG16 a,MEM16 b){return x86(158,a,b);}
enc cmovnle(REG16 a,R_M16 b){return x86(158,a,b);}
enc cmovo(REG32 a,REG32 b){return x86(159,a,b);}
enc cmovo(REG32 a,MEM32 b){return x86(159,a,b);}
enc cmovo(REG32 a,R_M32 b){return x86(159,a,b);}
enc cmovno(REG32 a,REG32 b){return x86(160,a,b);}
enc cmovno(REG32 a,MEM32 b){return x86(160,a,b);}
enc cmovno(REG32 a,R_M32 b){return x86(160,a,b);}
enc cmovb(REG32 a,REG32 b){return x86(161,a,b);}
enc cmovb(REG32 a,MEM32 b){return x86(161,a,b);}
enc cmovb(REG32 a,R_M32 b){return x86(161,a,b);}
enc cmovc(REG32 a,REG32 b){return x86(162,a,b);}
enc cmovc(REG32 a,MEM32 b){return x86(162,a,b);}
enc cmovc(REG32 a,R_M32 b){return x86(162,a,b);}
enc cmovnea(REG32 a,REG32 b){return x86(163,a,b);}
enc cmovnea(REG32 a,MEM32 b){return x86(163,a,b);}
enc cmovnea(REG32 a,R_M32 b){return x86(163,a,b);}
enc cmovae(REG32 a,REG32 b){return x86(164,a,b);}
enc cmovae(REG32 a,MEM32 b){return x86(164,a,b);}
enc cmovae(REG32 a,R_M32 b){return x86(164,a,b);}
enc cmovnb(REG32 a,REG32 b){return x86(165,a,b);}
enc cmovnb(REG32 a,MEM32 b){return x86(165,a,b);}
enc cmovnb(REG32 a,R_M32 b){return x86(165,a,b);}
enc cmovnc(REG32 a,REG32 b){return x86(166,a,b);}
enc cmovnc(REG32 a,MEM32 b){return x86(166,a,b);}
enc cmovnc(REG32 a,R_M32 b){return x86(166,a,b);}
enc cmove(REG32 a,REG32 b){return x86(167,a,b);}
enc cmove(REG32 a,MEM32 b){return x86(167,a,b);}
enc cmove(REG32 a,R_M32 b){return x86(167,a,b);}
enc cmovz(REG32 a,REG32 b){return x86(168,a,b);}
enc cmovz(REG32 a,MEM32 b){return x86(168,a,b);}
enc cmovz(REG32 a,R_M32 b){return x86(168,a,b);}
enc cmovne(REG32 a,REG32 b){return x86(169,a,b);}
enc cmovne(REG32 a,MEM32 b){return x86(169,a,b);}
enc cmovne(REG32 a,R_M32 b){return x86(169,a,b);}
enc cmovnz(REG32 a,REG32 b){return x86(170,a,b);}
enc cmovnz(REG32 a,MEM32 b){return x86(170,a,b);}
enc cmovnz(REG32 a,R_M32 b){return x86(170,a,b);}
enc cmovbe(REG32 a,REG32 b){return x86(171,a,b);}
enc cmovbe(REG32 a,MEM32 b){return x86(171,a,b);}
enc cmovbe(REG32 a,R_M32 b){return x86(171,a,b);}
enc cmovna(REG32 a,REG32 b){return x86(172,a,b);}
enc cmovna(REG32 a,MEM32 b){return x86(172,a,b);}
enc cmovna(REG32 a,R_M32 b){return x86(172,a,b);}
enc cmova(REG32 a,REG32 b){return x86(173,a,b);}
enc cmova(REG32 a,MEM32 b){return x86(173,a,b);}
enc cmova(REG32 a,R_M32 b){return x86(173,a,b);}
enc cmovnbe(REG32 a,REG32 b){return x86(174,a,b);}
enc cmovnbe(REG32 a,MEM32 b){return x86(174,a,b);}
enc cmovnbe(REG32 a,R_M32 b){return x86(174,a,b);}
enc cmovs(REG32 a,REG32 b){return x86(175,a,b);}
enc cmovs(REG32 a,MEM32 b){return x86(175,a,b);}
enc cmovs(REG32 a,R_M32 b){return x86(175,a,b);}
enc cmovns(REG32 a,REG32 b){return x86(176,a,b);}
enc cmovns(REG32 a,MEM32 b){return x86(176,a,b);}
enc cmovns(REG32 a,R_M32 b){return x86(176,a,b);}
enc cmovp(REG32 a,REG32 b){return x86(177,a,b);}
enc cmovp(REG32 a,MEM32 b){return x86(177,a,b);}
enc cmovp(REG32 a,R_M32 b){return x86(177,a,b);}
enc cmovpe(REG32 a,REG32 b){return x86(178,a,b);}
enc cmovpe(REG32 a,MEM32 b){return x86(178,a,b);}
enc cmovpe(REG32 a,R_M32 b){return x86(178,a,b);}
enc cmovnp(REG32 a,REG32 b){return x86(179,a,b);}
enc cmovnp(REG32 a,MEM32 b){return x86(179,a,b);}
enc cmovnp(REG32 a,R_M32 b){return x86(179,a,b);}
enc cmovpo(REG32 a,REG32 b){return x86(180,a,b);}
enc cmovpo(REG32 a,MEM32 b){return x86(180,a,b);}
enc cmovpo(REG32 a,R_M32 b){return x86(180,a,b);}
enc cmovl(REG32 a,REG32 b){return x86(181,a,b);}
enc cmovl(REG32 a,MEM32 b){return x86(181,a,b);}
enc cmovl(REG32 a,R_M32 b){return x86(181,a,b);}
enc cmovnge(REG32 a,REG32 b){return x86(182,a,b);}
enc cmovnge(REG32 a,MEM32 b){return x86(182,a,b);}
enc cmovnge(REG32 a,R_M32 b){return x86(182,a,b);}
enc cmovge(REG32 a,REG32 b){return x86(183,a,b);}
enc cmovge(REG32 a,MEM32 b){return x86(183,a,b);}
enc cmovge(REG32 a,R_M32 b){return x86(183,a,b);}
enc cmovnl(REG32 a,REG32 b){return x86(184,a,b);}
enc cmovnl(REG32 a,MEM32 b){return x86(184,a,b);}
enc cmovnl(REG32 a,R_M32 b){return x86(184,a,b);}
enc cmovle(REG32 a,REG32 b){return x86(185,a,b);}
enc cmovle(REG32 a,MEM32 b){return x86(185,a,b);}
enc cmovle(REG32 a,R_M32 b){return x86(185,a,b);}
enc cmovng(REG32 a,REG32 b){return x86(186,a,b);}
enc cmovng(REG32 a,MEM32 b){return x86(186,a,b);}
enc cmovng(REG32 a,R_M32 b){return x86(186,a,b);}
enc cmovg(REG32 a,REG32 b){return x86(187,a,b);}
enc cmovg(REG32 a,MEM32 b){return x86(187,a,b);}
enc cmovg(REG32 a,R_M32 b){return x86(187,a,b);}
enc cmovnle(REG32 a,REG32 b){return x86(188,a,b);}
enc cmovnle(REG32 a,MEM32 b){return x86(188,a,b);}
enc cmovnle(REG32 a,R_M32 b){return x86(188,a,b);}
enc cmp(REG8 a,REG8 b){return x86(189,a,b);}
enc cmp(MEM8 a,REG8 b){return x86(189,a,b);}
enc cmp(R_M8 a,REG8 b){return x86(189,a,b);}
enc cmp(REG16 a,REG16 b){return x86(190,a,b);}
enc cmp(MEM16 a,REG16 b){return x86(190,a,b);}
enc cmp(R_M16 a,REG16 b){return x86(190,a,b);}
enc cmp(REG32 a,REG32 b){return x86(191,a,b);}
enc cmp(MEM32 a,REG32 b){return x86(191,a,b);}
enc cmp(R_M32 a,REG32 b){return x86(191,a,b);}
enc cmp(REG8 a,MEM8 b){return x86(192,a,b);}
enc cmp(REG8 a,R_M8 b){return x86(192,a,b);}
enc cmp(REG16 a,MEM16 b){return x86(193,a,b);}
enc cmp(REG16 a,R_M16 b){return x86(193,a,b);}
enc cmp(REG32 a,MEM32 b){return x86(194,a,b);}
enc cmp(REG32 a,R_M32 b){return x86(194,a,b);}
enc cmp(REG8 a,char b){return x86(195,a,(IMM)b);}
enc cmp(AL a,char b){return x86(195,a,(IMM)b);}
enc cmp(CL a,char b){return x86(195,a,(IMM)b);}
enc cmp(MEM8 a,char b){return x86(195,a,(IMM)b);}
enc cmp(R_M8 a,char b){return x86(195,a,(IMM)b);}
enc cmp(REG16 a,char b){return x86(196,a,(IMM)b);}
enc cmp(REG16 a,short b){return x86(196,a,(IMM)b);}
enc cmp(MEM16 a,char b){return x86(196,a,(IMM)b);}
enc cmp(MEM16 a,short b){return x86(196,a,(IMM)b);}
enc cmp(R_M16 a,char b){return x86(196,a,(IMM)b);}
enc cmp(R_M16 a,short b){return x86(196,a,(IMM)b);}
enc cmp(REG32 a,REF b){return x86(197,a,b);}
enc cmp(REG32 a,int b){return x86(197,a,(IMM)b);}
enc cmp(MEM32 a,REF b){return x86(197,a,b);}
enc cmp(MEM32 a,int b){return x86(197,a,(IMM)b);}
enc cmp(R_M32 a,REF b){return x86(197,a,b);}
enc cmp(R_M32 a,int b){return x86(197,a,(IMM)b);}
enc cmppd(XMMREG a,XMMREG b,char c){return x86(203,a,b,(IMM)c);}
enc cmppd(XMMREG a,MEM128 b,char c){return x86(203,a,b,(IMM)c);}
enc cmppd(XMMREG a,R_M128 b,char c){return x86(203,a,b,(IMM)c);}
enc cmpeqpd(XMMREG a,XMMREG b){return x86(204,a,b);}
enc cmpeqpd(XMMREG a,MEM128 b){return x86(204,a,b);}
enc cmpeqpd(XMMREG a,R_M128 b){return x86(204,a,b);}
enc cmpltpd(XMMREG a,XMMREG b){return x86(205,a,b);}
enc cmpltpd(XMMREG a,MEM128 b){return x86(205,a,b);}
enc cmpltpd(XMMREG a,R_M128 b){return x86(205,a,b);}
enc cmplepd(XMMREG a,XMMREG b){return x86(206,a,b);}
enc cmplepd(XMMREG a,MEM128 b){return x86(206,a,b);}
enc cmplepd(XMMREG a,R_M128 b){return x86(206,a,b);}
enc cmpunordpd(XMMREG a,XMMREG b){return x86(207,a,b);}
enc cmpunordpd(XMMREG a,MEM128 b){return x86(207,a,b);}
enc cmpunordpd(XMMREG a,R_M128 b){return x86(207,a,b);}
enc cmpneqpd(XMMREG a,XMMREG b){return x86(208,a,b);}
enc cmpneqpd(XMMREG a,MEM128 b){return x86(208,a,b);}
enc cmpneqpd(XMMREG a,R_M128 b){return x86(208,a,b);}
enc cmpnltpd(XMMREG a,XMMREG b){return x86(209,a,b);}
enc cmpnltpd(XMMREG a,MEM128 b){return x86(209,a,b);}
enc cmpnltpd(XMMREG a,R_M128 b){return x86(209,a,b);}
enc cmpnlepd(XMMREG a,XMMREG b){return x86(210,a,b);}
enc cmpnlepd(XMMREG a,MEM128 b){return x86(210,a,b);}
enc cmpnlepd(XMMREG a,R_M128 b){return x86(210,a,b);}
enc cmpordpd(XMMREG a,XMMREG b){return x86(211,a,b);}
enc cmpordpd(XMMREG a,MEM128 b){return x86(211,a,b);}
enc cmpordpd(XMMREG a,R_M128 b){return x86(211,a,b);}
enc cmpps(XMMREG a,XMMREG b,char c){return x86(212,a,b,(IMM)c);}
enc cmpps(XMMREG a,MEM128 b,char c){return x86(212,a,b,(IMM)c);}
enc cmpps(XMMREG a,R_M128 b,char c){return x86(212,a,b,(IMM)c);}
enc cmpeqps(XMMREG a,XMMREG b){return x86(213,a,b);}
enc cmpeqps(XMMREG a,MEM128 b){return x86(213,a,b);}
enc cmpeqps(XMMREG a,R_M128 b){return x86(213,a,b);}
enc cmpleps(XMMREG a,XMMREG b){return x86(214,a,b);}
enc cmpleps(XMMREG a,MEM128 b){return x86(214,a,b);}
enc cmpleps(XMMREG a,R_M128 b){return x86(214,a,b);}
enc cmpltps(XMMREG a,XMMREG b){return x86(215,a,b);}
enc cmpltps(XMMREG a,MEM128 b){return x86(215,a,b);}
enc cmpltps(XMMREG a,R_M128 b){return x86(215,a,b);}
enc cmpneqps(XMMREG a,XMMREG b){return x86(216,a,b);}
enc cmpneqps(XMMREG a,MEM128 b){return x86(216,a,b);}
enc cmpneqps(XMMREG a,R_M128 b){return x86(216,a,b);}
enc cmpnleps(XMMREG a,XMMREG b){return x86(217,a,b);}
enc cmpnleps(XMMREG a,MEM128 b){return x86(217,a,b);}
enc cmpnleps(XMMREG a,R_M128 b){return x86(217,a,b);}
enc cmpnltps(XMMREG a,XMMREG b){return x86(218,a,b);}
enc cmpnltps(XMMREG a,MEM128 b){return x86(218,a,b);}
enc cmpnltps(XMMREG a,R_M128 b){return x86(218,a,b);}
enc cmpordps(XMMREG a,XMMREG b){return x86(219,a,b);}
enc cmpordps(XMMREG a,MEM128 b){return x86(219,a,b);}
enc cmpordps(XMMREG a,R_M128 b){return x86(219,a,b);}
enc cmpunordps(XMMREG a,XMMREG b){return x86(220,a,b);}
enc cmpunordps(XMMREG a,MEM128 b){return x86(220,a,b);}
enc cmpunordps(XMMREG a,R_M128 b){return x86(220,a,b);}
enc cmpsb(){return x86(221);}
enc cmpsw(){return x86(222);}
enc cmpsd(){return x86(223);}
enc repe_cmpsb(){return x86(224);}
enc repe_cmpsw(){return x86(225);}
enc repe_cmpsd(){return x86(226);}
enc repne_cmpsb(){return x86(227);}
enc repne_cmpsw(){return x86(228);}
enc repne_cmpsd(){return x86(229);}
enc repz_cmpsb(){return x86(230);}
enc repz_cmpsw(){return x86(231);}
enc repz_cmpsd(){return x86(232);}
enc repnz_cmpsb(){return x86(233);}
enc repnz_cmpsw(){return x86(234);}
enc repnz_cmpsd(){return x86(235);}
enc cmpsd(XMMREG a,XMMREG b,char c){return x86(236,a,b,(IMM)c);}
enc cmpsd(XMMREG a,MEM64 b,char c){return x86(236,a,b,(IMM)c);}
enc cmpsd(XMMREG a,XMM64 b,char c){return x86(236,a,b,(IMM)c);}
enc cmpeqsd(XMMREG a,XMMREG b){return x86(237,a,b);}
enc cmpeqsd(XMMREG a,MEM64 b){return x86(237,a,b);}
enc cmpeqsd(XMMREG a,XMM64 b){return x86(237,a,b);}
enc cmpltsd(XMMREG a,XMMREG b){return x86(238,a,b);}
enc cmpltsd(XMMREG a,MEM64 b){return x86(238,a,b);}
enc cmpltsd(XMMREG a,XMM64 b){return x86(238,a,b);}
enc cmplesd(XMMREG a,XMMREG b){return x86(239,a,b);}
enc cmplesd(XMMREG a,MEM64 b){return x86(239,a,b);}
enc cmplesd(XMMREG a,XMM64 b){return x86(239,a,b);}
enc cmpunordsd(XMMREG a,XMMREG b){return x86(240,a,b);}
enc cmpunordsd(XMMREG a,MEM64 b){return x86(240,a,b);}
enc cmpunordsd(XMMREG a,XMM64 b){return x86(240,a,b);}
enc cmpneqsd(XMMREG a,XMMREG b){return x86(241,a,b);}
enc cmpneqsd(XMMREG a,MEM64 b){return x86(241,a,b);}
enc cmpneqsd(XMMREG a,XMM64 b){return x86(241,a,b);}
enc cmpnltsd(XMMREG a,XMMREG b){return x86(242,a,b);}
enc cmpnltsd(XMMREG a,MEM64 b){return x86(242,a,b);}
enc cmpnltsd(XMMREG a,XMM64 b){return x86(242,a,b);}
enc cmpnlesd(XMMREG a,XMMREG b){return x86(243,a,b);}
enc cmpnlesd(XMMREG a,MEM64 b){return x86(243,a,b);}
enc cmpnlesd(XMMREG a,XMM64 b){return x86(243,a,b);}
enc cmpordsd(XMMREG a,XMMREG b){return x86(244,a,b);}
enc cmpordsd(XMMREG a,MEM64 b){return x86(244,a,b);}
enc cmpordsd(XMMREG a,XMM64 b){return x86(244,a,b);}
enc cmpss(XMMREG a,XMMREG b,char c){return x86(245,a,b,(IMM)c);}
enc cmpss(XMMREG a,MEM32 b,char c){return x86(245,a,b,(IMM)c);}
enc cmpss(XMMREG a,XMM32 b,char c){return x86(245,a,b,(IMM)c);}
enc cmpeqss(XMMREG a,XMMREG b){return x86(246,a,b);}
enc cmpeqss(XMMREG a,MEM32 b){return x86(246,a,b);}
enc cmpeqss(XMMREG a,XMM32 b){return x86(246,a,b);}
enc cmpless(XMMREG a,XMMREG b){return x86(247,a,b);}
enc cmpless(XMMREG a,MEM32 b){return x86(247,a,b);}
enc cmpless(XMMREG a,XMM32 b){return x86(247,a,b);}
enc cmpltss(XMMREG a,XMMREG b){return x86(248,a,b);}
enc cmpltss(XMMREG a,MEM32 b){return x86(248,a,b);}
enc cmpltss(XMMREG a,XMM32 b){return x86(248,a,b);}
enc cmpneqss(XMMREG a,XMMREG b){return x86(249,a,b);}
enc cmpneqss(XMMREG a,MEM32 b){return x86(249,a,b);}
enc cmpneqss(XMMREG a,XMM32 b){return x86(249,a,b);}
enc cmpnless(XMMREG a,XMMREG b){return x86(250,a,b);}
enc cmpnless(XMMREG a,MEM32 b){return x86(250,a,b);}
enc cmpnless(XMMREG a,XMM32 b){return x86(250,a,b);}
enc cmpnltss(XMMREG a,XMMREG b){return x86(251,a,b);}
enc cmpnltss(XMMREG a,MEM32 b){return x86(251,a,b);}
enc cmpnltss(XMMREG a,XMM32 b){return x86(251,a,b);}
enc cmpordss(XMMREG a,XMMREG b){return x86(252,a,b);}
enc cmpordss(XMMREG a,MEM32 b){return x86(252,a,b);}
enc cmpordss(XMMREG a,XMM32 b){return x86(252,a,b);}
enc cmpunordss(XMMREG a,XMMREG b){return x86(253,a,b);}
enc cmpunordss(XMMREG a,MEM32 b){return x86(253,a,b);}
enc cmpunordss(XMMREG a,XMM32 b){return x86(253,a,b);}
enc cmpxchg(REG8 a,REG8 b){return x86(254,a,b);}
enc cmpxchg(MEM8 a,REG8 b){return x86(254,a,b);}
enc cmpxchg(R_M8 a,REG8 b){return x86(254,a,b);}
enc cmpxchg(REG16 a,REG16 b){return x86(255,a,b);}
enc cmpxchg(MEM16 a,REG16 b){return x86(255,a,b);}
enc cmpxchg(R_M16 a,REG16 b){return x86(255,a,b);}
enc cmpxchg(REG32 a,REG32 b){return x86(256,a,b);}
enc cmpxchg(MEM32 a,REG32 b){return x86(256,a,b);}
enc cmpxchg(R_M32 a,REG32 b){return x86(256,a,b);}
enc lock_cmpxchg(MEM8 a,REG8 b){return x86(257,a,b);}
enc lock_cmpxchg(MEM16 a,REG16 b){return x86(258,a,b);}
enc lock_cmpxchg(MEM32 a,REG32 b){return x86(259,a,b);}
enc cmpxchg8b(MEM8 a){return x86(260,a);}
enc cmpxchg8b(MEM16 a){return x86(260,a);}
enc cmpxchg8b(MEM32 a){return x86(260,a);}
enc cmpxchg8b(MEM64 a){return x86(260,a);}
enc cmpxchg8b(MEM128 a){return x86(260,a);}
enc lock_cmpxchg8b(MEM8 a){return x86(261,a);}
enc lock_cmpxchg8b(MEM16 a){return x86(261,a);}
enc lock_cmpxchg8b(MEM32 a){return x86(261,a);}
enc lock_cmpxchg8b(MEM64 a){return x86(261,a);}
enc lock_cmpxchg8b(MEM128 a){return x86(261,a);}
enc comisd(XMMREG a,XMMREG b){return x86(262,a,b);}
enc comisd(XMMREG a,MEM64 b){return x86(262,a,b);}
enc comisd(XMMREG a,XMM64 b){return x86(262,a,b);}
enc comiss(XMMREG a,XMMREG b){return x86(263,a,b);}
enc comiss(XMMREG a,MEM32 b){return x86(263,a,b);}
enc comiss(XMMREG a,XMM32 b){return x86(263,a,b);}
enc cpuid(){return x86(264);}
enc cvtdq2pd(XMMREG a,XMMREG b){return x86(265,a,b);}
enc cvtdq2pd(XMMREG a,MEM64 b){return x86(265,a,b);}
enc cvtdq2pd(XMMREG a,XMM64 b){return x86(265,a,b);}
enc cvtdq2ps(XMMREG a,XMMREG b){return x86(266,a,b);}
enc cvtdq2ps(XMMREG a,MEM128 b){return x86(266,a,b);}
enc cvtdq2ps(XMMREG a,R_M128 b){return x86(266,a,b);}
enc cvtpd2dq(XMMREG a,XMMREG b){return x86(267,a,b);}
enc cvtpd2dq(XMMREG a,MEM128 b){return x86(267,a,b);}
enc cvtpd2dq(XMMREG a,R_M128 b){return x86(267,a,b);}
enc cvtpd2pi(MMREG a,XMMREG b){return x86(268,a,b);}
enc cvtpd2pi(MMREG a,MEM128 b){return x86(268,a,b);}
enc cvtpd2pi(MMREG a,R_M128 b){return x86(268,a,b);}
enc cvtpd2ps(XMMREG a,XMMREG b){return x86(269,a,b);}
enc cvtpd2ps(XMMREG a,MEM128 b){return x86(269,a,b);}
enc cvtpd2ps(XMMREG a,R_M128 b){return x86(269,a,b);}
enc cvtpi2pd(XMMREG a,MMREG b){return x86(270,a,b);}
enc cvtpi2pd(XMMREG a,MEM64 b){return x86(270,a,b);}
enc cvtpi2pd(XMMREG a,R_M64 b){return x86(270,a,b);}
enc cvtps2dq(XMMREG a,XMMREG b){return x86(271,a,b);}
enc cvtps2dq(XMMREG a,MEM128 b){return x86(271,a,b);}
enc cvtps2dq(XMMREG a,R_M128 b){return x86(271,a,b);}
enc cvtps2pd(XMMREG a,XMMREG b){return x86(272,a,b);}
enc cvtps2pd(XMMREG a,MEM64 b){return x86(272,a,b);}
enc cvtps2pd(XMMREG a,XMM64 b){return x86(272,a,b);}
enc cvtsd2si(REG32 a,XMMREG b){return x86(273,a,b);}
enc cvtsd2si(REG32 a,MEM64 b){return x86(273,a,b);}
enc cvtsd2si(REG32 a,XMM64 b){return x86(273,a,b);}
enc cvtsi2sd(XMMREG a,REG32 b){return x86(274,a,b);}
enc cvtsi2sd(XMMREG a,MEM32 b){return x86(274,a,b);}
enc cvtsi2sd(XMMREG a,R_M32 b){return x86(274,a,b);}
enc cvtss2sd(XMMREG a,XMMREG b){return x86(275,a,b);}
enc cvtss2sd(XMMREG a,MEM32 b){return x86(275,a,b);}
enc cvtss2sd(XMMREG a,XMM32 b){return x86(275,a,b);}
enc cvttpd2dq(XMMREG a,XMMREG b){return x86(276,a,b);}
enc cvttpd2dq(XMMREG a,MEM128 b){return x86(276,a,b);}
enc cvttpd2dq(XMMREG a,R_M128 b){return x86(276,a,b);}
enc cvttpd2pi(MMREG a,XMMREG b){return x86(277,a,b);}
enc cvttpd2pi(MMREG a,MEM128 b){return x86(277,a,b);}
enc cvttpd2pi(MMREG a,R_M128 b){return x86(277,a,b);}
enc cvttps2dq(XMMREG a,XMMREG b){return x86(278,a,b);}
enc cvttps2dq(XMMREG a,MEM128 b){return x86(278,a,b);}
enc cvttps2dq(XMMREG a,R_M128 b){return x86(278,a,b);}
enc cvttsd2si(REG32 a,XMMREG b){return x86(279,a,b);}
enc cvttsd2si(REG32 a,MEM64 b){return x86(279,a,b);}
enc cvttsd2si(REG32 a,XMM64 b){return x86(279,a,b);}
enc cvtpi2ps(XMMREG a,MMREG b){return x86(280,a,b);}
enc cvtpi2ps(XMMREG a,MEM64 b){return x86(280,a,b);}
enc cvtpi2ps(XMMREG a,R_M64 b){return x86(280,a,b);}
enc cvtps2pi(MMREG a,XMMREG b){return x86(281,a,b);}
enc cvtps2pi(MMREG a,MEM64 b){return x86(281,a,b);}
enc cvtps2pi(MMREG a,XMM64 b){return x86(281,a,b);}
enc cvttps2pi(MMREG a,XMMREG b){return x86(282,a,b);}
enc cvttps2pi(MMREG a,MEM64 b){return x86(282,a,b);}
enc cvttps2pi(MMREG a,XMM64 b){return x86(282,a,b);}
enc cvtsi2ss(XMMREG a,REG32 b){return x86(283,a,b);}
enc cvtsi2ss(XMMREG a,MEM32 b){return x86(283,a,b);}
enc cvtsi2ss(XMMREG a,R_M32 b){return x86(283,a,b);}
enc cvtss2si(REG32 a,XMMREG b){return x86(284,a,b);}
enc cvtss2si(REG32 a,MEM32 b){return x86(284,a,b);}
enc cvtss2si(REG32 a,XMM32 b){return x86(284,a,b);}
enc cvttss2si(REG32 a,XMMREG b){return x86(285,a,b);}
enc cvttss2si(REG32 a,MEM32 b){return x86(285,a,b);}
enc cvttss2si(REG32 a,XMM32 b){return x86(285,a,b);}
enc daa(){return x86(286);}
enc das(){return x86(287);}
enc dec(REG16 a){return x86(288,a);}
enc dec(REG32 a){return x86(289,a);}
enc dec(REG8 a){return x86(290,a);}
enc dec(MEM8 a){return x86(290,a);}
enc dec(R_M8 a){return x86(290,a);}
enc dec(MEM16 a){return x86(291,a);}
enc dec(R_M16 a){return x86(291,a);}
enc dec(MEM32 a){return x86(292,a);}
enc dec(R_M32 a){return x86(292,a);}
enc lock_dec(MEM8 a){return x86(293,a);}
enc lock_dec(MEM16 a){return x86(294,a);}
enc lock_dec(MEM32 a){return x86(295,a);}
enc div(REG8 a){return x86(296,a);}
enc div(MEM8 a){return x86(296,a);}
enc div(R_M8 a){return x86(296,a);}
enc div(REG16 a){return x86(297,a);}
enc div(MEM16 a){return x86(297,a);}
enc div(R_M16 a){return x86(297,a);}
enc div(REG32 a){return x86(298,a);}
enc div(MEM32 a){return x86(298,a);}
enc div(R_M32 a){return x86(298,a);}
enc divpd(XMMREG a,XMMREG b){return x86(299,a,b);}
enc divpd(XMMREG a,MEM128 b){return x86(299,a,b);}
enc divpd(XMMREG a,R_M128 b){return x86(299,a,b);}
enc divps(XMMREG a,XMMREG b){return x86(300,a,b);}
enc divps(XMMREG a,MEM128 b){return x86(300,a,b);}
enc divps(XMMREG a,R_M128 b){return x86(300,a,b);}
enc divsd(XMMREG a,XMMREG b){return x86(301,a,b);}
enc divsd(XMMREG a,MEM64 b){return x86(301,a,b);}
enc divsd(XMMREG a,XMM64 b){return x86(301,a,b);}
enc divss(XMMREG a,XMMREG b){return x86(302,a,b);}
enc divss(XMMREG a,MEM32 b){return x86(302,a,b);}
enc divss(XMMREG a,XMM32 b){return x86(302,a,b);}
enc emms(){return x86(303);}
enc f2xm1(){return x86(304);}
enc fabs(){return x86(305);}
enc fadd(MEM32 a){return x86(306,a);}
enc fadd(MEM64 a){return x86(307,a);}
enc fadd(FPUREG a){return x86(308,a);}
enc fadd(ST0 a,FPUREG b){return x86(309,a,b);}
enc fadd(FPUREG a,ST0 b){return x86(310,a,b);}
enc faddp(){return x86(311);}
enc faddp(FPUREG a){return x86(312,a);}
enc faddp(FPUREG a,ST0 b){return x86(313,a,b);}
enc fchs(){return x86(314);}
enc fclex(){return x86(315);}
enc fnclex(){return x86(316);}
enc fcmovb(FPUREG a){return x86(317,a);}
enc fcmovb(ST0 a,FPUREG b){return x86(318,a,b);}
enc fcmovbe(FPUREG a){return x86(319,a);}
enc fcmovbe(ST0 a,FPUREG b){return x86(320,a,b);}
enc fcmove(FPUREG a){return x86(321,a);}
enc fcmove(ST0 a,FPUREG b){return x86(322,a,b);}
enc fcmovnb(FPUREG a){return x86(323,a);}
enc fcmovnb(ST0 a,FPUREG b){return x86(324,a,b);}
enc fcmovnbe(FPUREG a){return x86(325,a);}
enc fcmovnbe(ST0 a,FPUREG b){return x86(326,a,b);}
enc fcmovne(FPUREG a){return x86(327,a);}
enc fcmovne(ST0 a,FPUREG b){return x86(328,a,b);}
enc fcmovnu(FPUREG a){return x86(329,a);}
enc fcmovnu(ST0 a,FPUREG b){return x86(330,a,b);}
enc fcmovu(FPUREG a){return x86(331,a);}
enc fcmovu(ST0 a,FPUREG b){return x86(332,a,b);}
enc fcom(MEM32 a){return x86(333,a);}
enc fcom(MEM64 a){return x86(334,a);}
enc fcom(FPUREG a){return x86(335,a);}
enc fcom(ST0 a,FPUREG b){return x86(336,a,b);}
enc fcomp(MEM32 a){return x86(337,a);}
enc fcomp(MEM64 a){return x86(338,a);}
enc fcomp(FPUREG a){return x86(339,a);}
enc fcomp(ST0 a,FPUREG b){return x86(340,a,b);}
enc fcompp(){return x86(341);}
enc fcomi(FPUREG a){return x86(342,a);}
enc fcomi(ST0 a,FPUREG b){return x86(343,a,b);}
enc fcomip(FPUREG a){return x86(344,a);}
enc fcomip(ST0 a,FPUREG b){return x86(345,a,b);}
enc fcos(){return x86(346);}
enc fdecstp(){return x86(347);}
enc fdisi(){return x86(348);}
enc fndisi(){return x86(349);}
enc feni(){return x86(350);}
enc fneni(){return x86(351);}
enc fdiv(MEM32 a){return x86(352,a);}
enc fdiv(MEM64 a){return x86(353,a);}
enc fdiv(FPUREG a){return x86(354,a);}
enc fdiv(ST0 a,FPUREG b){return x86(355,a,b);}
enc fdiv(FPUREG a,ST0 b){return x86(356,a,b);}
enc fdivr(MEM32 a){return x86(357,a);}
enc fdivr(MEM64 a){return x86(358,a);}
enc fdivr(FPUREG a){return x86(359,a);}
enc fdivr(ST0 a,FPUREG b){return x86(360,a,b);}
enc fdivr(FPUREG a,ST0 b){return x86(361,a,b);}
enc fdivp(){return x86(362);}
enc fdivp(FPUREG a){return x86(363,a);}
enc fdivp(FPUREG a,ST0 b){return x86(364,a,b);}
enc fdivrp(){return x86(365);}
enc fdivrp(FPUREG a){return x86(366,a);}
enc fdivrp(FPUREG a,ST0 b){return x86(367,a,b);}
enc femms(){return x86(368);}
enc ffree(FPUREG a){return x86(369,a);}
enc fiadd(MEM16 a){return x86(370,a);}
enc fiadd(MEM32 a){return x86(371,a);}
enc ficom(MEM16 a){return x86(372,a);}
enc ficom(MEM32 a){return x86(373,a);}
enc ficomp(MEM16 a){return x86(374,a);}
enc ficomp(MEM32 a){return x86(375,a);}
enc fidiv(MEM16 a){return x86(376,a);}
enc fidiv(MEM32 a){return x86(377,a);}
enc fidivr(MEM16 a){return x86(378,a);}
enc fidivr(MEM32 a){return x86(379,a);}
enc fild(MEM16 a){return x86(380,a);}
enc fild(MEM32 a){return x86(381,a);}
enc fild(MEM64 a){return x86(382,a);}
enc fist(MEM16 a){return x86(383,a);}
enc fist(MEM32 a){return x86(384,a);}
enc fistp(MEM16 a){return x86(385,a);}
enc fistp(MEM32 a){return x86(386,a);}
enc fistp(MEM64 a){return x86(387,a);}
enc fisttp(MEM16 a){return x86(388,a);}
enc fisttp(MEM32 a){return x86(389,a);}
enc fisttp(MEM64 a){return x86(390,a);}
enc fimul(MEM16 a){return x86(391,a);}
enc fimul(MEM32 a){return x86(392,a);}
enc fincstp(){return x86(393);}
enc finit(){return x86(394);}
enc fninit(){return x86(395);}
enc fisub(MEM16 a){return x86(396,a);}
enc fisub(MEM32 a){return x86(397,a);}
enc fisubr(MEM16 a){return x86(398,a);}
enc fisubr(MEM32 a){return x86(399,a);}
enc fld(MEM32 a){return x86(400,a);}
enc fld(MEM64 a){return x86(401,a);}
enc fld(FPUREG a){return x86(402,a);}
enc fld1(){return x86(403);}
enc fldl2e(){return x86(404);}
enc fldl2t(){return x86(405);}
enc fldlg2(){return x86(406);}
enc fldln2(){return x86(407);}
enc fldpi(){return x86(408);}
enc fldz(){return x86(409);}
enc fldcw(MEM16 a){return x86(410,a);}
enc fldenv(MEM8 a){return x86(411,a);}
enc fldenv(MEM16 a){return x86(411,a);}
enc fldenv(MEM32 a){return x86(411,a);}
enc fldenv(MEM64 a){return x86(411,a);}
enc fldenv(MEM128 a){return x86(411,a);}
enc fmul(MEM32 a){return x86(412,a);}
enc fmul(MEM64 a){return x86(413,a);}
enc fmul(){return x86(414);}
enc fmul(FPUREG a){return x86(415,a);}
enc fmul(ST0 a,FPUREG b){return x86(416,a,b);}
enc fmul(FPUREG a,ST0 b){return x86(417,a,b);}
enc fmulp(FPUREG a){return x86(418,a);}
enc fmulp(FPUREG a,ST0 b){return x86(419,a,b);}
enc fmulp(){return x86(420);}
enc fnop(){return x86(421);}
enc fpatan(){return x86(422);}
enc fptan(){return x86(423);}
enc fprem(){return x86(424);}
enc fprem1(){return x86(425);}
enc frndint(){return x86(426);}
enc fsave(MEM8 a){return x86(427,a);}
enc fsave(MEM16 a){return x86(427,a);}
enc fsave(MEM32 a){return x86(427,a);}
enc fsave(MEM64 a){return x86(427,a);}
enc fsave(MEM128 a){return x86(427,a);}
enc fnsave(MEM8 a){return x86(428,a);}
enc fnsave(MEM16 a){return x86(428,a);}
enc fnsave(MEM32 a){return x86(428,a);}
enc fnsave(MEM64 a){return x86(428,a);}
enc fnsave(MEM128 a){return x86(428,a);}
enc frstor(MEM8 a){return x86(429,a);}
enc frstor(MEM16 a){return x86(429,a);}
enc frstor(MEM32 a){return x86(429,a);}
enc frstor(MEM64 a){return x86(429,a);}
enc frstor(MEM128 a){return x86(429,a);}
enc fscale(){return x86(430);}
enc fsetpm(){return x86(431);}
enc fsin(){return x86(432);}
enc fsincos(){return x86(433);}
enc fsqrt(){return x86(434);}
enc fst(MEM32 a){return x86(435,a);}
enc fst(MEM64 a){return x86(436,a);}
enc fst(FPUREG a){return x86(437,a);}
enc fstp(MEM32 a){return x86(438,a);}
enc fstp(MEM64 a){return x86(439,a);}
enc fstp(FPUREG a){return x86(440,a);}
enc fstcw(MEM16 a){return x86(441,a);}
enc fnstcw(MEM16 a){return x86(442,a);}
enc fstenv(MEM8 a){return x86(443,a);}
enc fstenv(MEM16 a){return x86(443,a);}
enc fstenv(MEM32 a){return x86(443,a);}
enc fstenv(MEM64 a){return x86(443,a);}
enc fstenv(MEM128 a){return x86(443,a);}
enc fnstenv(MEM8 a){return x86(444,a);}
enc fnstenv(MEM16 a){return x86(444,a);}
enc fnstenv(MEM32 a){return x86(444,a);}
enc fnstenv(MEM64 a){return x86(444,a);}
enc fnstenv(MEM128 a){return x86(444,a);}
enc fstsw(MEM16 a){return x86(445,a);}
enc fstsw(AX a){return x86(446,a);}
enc fnstsw(MEM16 a){return x86(447,a);}
enc fnstsw(AX a){return x86(448,a);}
enc fsub(MEM32 a){return x86(449,a);}
enc fsub(MEM64 a){return x86(450,a);}
enc fsub(FPUREG a){return x86(451,a);}
enc fsub(ST0 a,FPUREG b){return x86(452,a,b);}
enc fsub(FPUREG a,ST0 b){return x86(453,a,b);}
enc fsubr(MEM32 a){return x86(454,a);}
enc fsubr(MEM64 a){return x86(455,a);}
enc fsubr(FPUREG a){return x86(456,a);}
enc fsubr(ST0 a,FPUREG b){return x86(457,a,b);}
enc fsubr(FPUREG a,ST0 b){return x86(458,a,b);}
enc fsubp(){return x86(459);}
enc fsubp(FPUREG a){return x86(460,a);}
enc fsubp(FPUREG a,ST0 b){return x86(461,a,b);}
enc fsubrp(){return x86(462);}
enc fsubrp(FPUREG a){return x86(463,a);}
enc fsubrp(FPUREG a,ST0 b){return x86(464,a,b);}
enc ftst(){return x86(465);}
enc fucom(FPUREG a){return x86(466,a);}
enc fucom(ST0 a,FPUREG b){return x86(467,a,b);}
enc fucomp(FPUREG a){return x86(468,a);}
enc fucomp(ST0 a,FPUREG b){return x86(469,a,b);}
enc fucompp(){return x86(470);}
enc fucomi(FPUREG a){return x86(471,a);}
enc fucomi(ST0 a,FPUREG b){return x86(472,a,b);}
enc fucomip(FPUREG a){return x86(473,a);}
enc fucomip(ST0 a,FPUREG b){return x86(474,a,b);}
enc fwait(){return x86(475);}
enc fxam(){return x86(476);}
enc fxch(){return x86(477);}
enc fxch(FPUREG a){return x86(478,a);}
enc fxch(FPUREG a,ST0 b){return x86(479,a,b);}
enc fxch(ST0 a,FPUREG b){return x86(480,a,b);}
enc fxtract(){return x86(481);}
enc fyl2x(){return x86(482);}
enc fyl2xp1(){return x86(483);}
enc hlt(){return x86(484);}
enc haddpd(XMMREG a,XMMREG b){return x86(485,a,b);}
enc haddpd(XMMREG a,MEM128 b){return x86(485,a,b);}
enc haddpd(XMMREG a,R_M128 b){return x86(485,a,b);}
enc haddps(XMMREG a,XMMREG b){return x86(486,a,b);}
enc haddps(XMMREG a,MEM128 b){return x86(486,a,b);}
enc haddps(XMMREG a,R_M128 b){return x86(486,a,b);}
enc hsubpd(XMMREG a,XMMREG b){return x86(487,a,b);}
enc hsubpd(XMMREG a,MEM128 b){return x86(487,a,b);}
enc hsubpd(XMMREG a,R_M128 b){return x86(487,a,b);}
enc hsubps(XMMREG a,XMMREG b){return x86(488,a,b);}
enc hsubps(XMMREG a,MEM128 b){return x86(488,a,b);}
enc hsubps(XMMREG a,R_M128 b){return x86(488,a,b);}
enc idiv(REG8 a){return x86(489,a);}
enc idiv(MEM8 a){return x86(489,a);}
enc idiv(R_M8 a){return x86(489,a);}
enc idiv(REG16 a){return x86(490,a);}
enc idiv(MEM16 a){return x86(490,a);}
enc idiv(R_M16 a){return x86(490,a);}
enc idiv(REG32 a){return x86(491,a);}
enc idiv(MEM32 a){return x86(491,a);}
enc idiv(R_M32 a){return x86(491,a);}
enc imul(REG8 a){return x86(492,a);}
enc imul(MEM8 a){return x86(492,a);}
enc imul(R_M8 a){return x86(492,a);}
enc imul(REG16 a){return x86(493,a);}
enc imul(MEM16 a){return x86(493,a);}
enc imul(R_M16 a){return x86(493,a);}
enc imul(REG32 a){return x86(494,a);}
enc imul(MEM32 a){return x86(494,a);}
enc imul(R_M32 a){return x86(494,a);}
enc imul(REG16 a,REG16 b){return x86(495,a,b);}
enc imul(REG16 a,MEM16 b){return x86(495,a,b);}
enc imul(REG16 a,R_M16 b){return x86(495,a,b);}
enc imul(REG32 a,REG32 b){return x86(496,a,b);}
enc imul(REG32 a,MEM32 b){return x86(496,a,b);}
enc imul(REG32 a,R_M32 b){return x86(496,a,b);}
enc imul(REG16 a,char b){return x86(497,a,(IMM)b);}
enc imul(REG16 a,short b){return x86(498,a,(IMM)b);}
enc imul(REG32 a,char b){return x86(499,a,(IMM)b);}
enc imul(REG32 a,REF b){return x86(500,a,b);}
enc imul(REG32 a,int b){return x86(500,a,(IMM)b);}
enc imul(REG16 a,REG16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(REG16 a,AX b,char c){return x86(501,a,b,(IMM)c);}
enc imul(REG16 a,DX b,char c){return x86(501,a,b,(IMM)c);}
enc imul(REG16 a,CX b,char c){return x86(501,a,b,(IMM)c);}
enc imul(REG16 a,MEM16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(REG16 a,R_M16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(AX a,REG16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(AX a,MEM16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(AX a,R_M16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(DX a,REG16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(DX a,MEM16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(DX a,R_M16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(CX a,REG16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(CX a,MEM16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(CX a,R_M16 b,char c){return x86(501,a,b,(IMM)c);}
enc imul(REG16 a,REG16 b,short c){return x86(502,a,b,(IMM)c);}
enc imul(REG16 a,MEM16 b,short c){return x86(502,a,b,(IMM)c);}
enc imul(REG16 a,R_M16 b,short c){return x86(502,a,b,(IMM)c);}
enc imul(REG32 a,REG32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(REG32 a,EAX b,char c){return x86(503,a,b,(IMM)c);}
enc imul(REG32 a,ECX b,char c){return x86(503,a,b,(IMM)c);}
enc imul(REG32 a,MEM32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(REG32 a,R_M32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(EAX a,REG32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(EAX a,MEM32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(EAX a,R_M32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(ECX a,REG32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(ECX a,MEM32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(ECX a,R_M32 b,char c){return x86(503,a,b,(IMM)c);}
enc imul(REG32 a,REG32 b,REF c){return x86(504,a,b,c);}
enc imul(REG32 a,REG32 b,int c){return x86(504,a,b,(IMM)c);}
enc imul(REG32 a,MEM32 b,REF c){return x86(504,a,b,c);}
enc imul(REG32 a,MEM32 b,int c){return x86(504,a,b,(IMM)c);}
enc imul(REG32 a,R_M32 b,REF c){return x86(504,a,b,c);}
enc imul(REG32 a,R_M32 b,int c){return x86(504,a,b,(IMM)c);}
enc in(AL a,char b){return x86(505,a,(IMM)b);}
enc in(AX a,char b){return x86(506,a,(IMM)b);}
enc in(EAX a,char b){return x86(507,a,(IMM)b);}
enc in(AL a,DX b){return x86(508,a,b);}
enc in(AX a,DX b){return x86(509,a,b);}
enc in(EAX a,DX b){return x86(510,a,b);}
enc inc(REG16 a){return x86(511,a);}
enc inc(REG32 a){return x86(512,a);}
enc inc(REG8 a){return x86(513,a);}
enc inc(MEM8 a){return x86(513,a);}
enc inc(R_M8 a){return x86(513,a);}
enc inc(MEM16 a){return x86(514,a);}
enc inc(R_M16 a){return x86(514,a);}
enc inc(MEM32 a){return x86(515,a);}
enc inc(R_M32 a){return x86(515,a);}
enc lock_inc(MEM8 a){return x86(516,a);}
enc lock_inc(MEM16 a){return x86(517,a);}
enc lock_inc(MEM32 a){return x86(518,a);}
enc insb(){return x86(519);}
enc insw(){return x86(520);}
enc insd(){return x86(521);}
enc rep_insb(){return x86(522);}
enc rep_insw(){return x86(523);}
enc rep_insd(){return x86(524);}
enc int3(){return x86(525);}
enc int03(){return x86(526);}
enc into(){return x86(527);}
enc jcxz(char a){return x86(528,(IMM)a);}
enc jecxz(char a){return x86(529,(IMM)a);}
enc jmp(REF a){return x86(530,a);}
enc jmp(int a){return x86(530,(IMM)a);}
enc jmp(MEM8 a){return x86(532,a);}
enc jmp(MEM16 a){return x86(532,a);}
enc jmp(MEM32 a){return x86(532,a);}
enc jmp(MEM64 a){return x86(532,a);}
enc jmp(MEM128 a){return x86(532,a);}
enc jmp(REG16 a){return x86(533,a);}
enc jmp(R_M16 a){return x86(533,a);}
enc jmp(REG32 a){return x86(534,a);}
enc jmp(R_M32 a){return x86(534,a);}
enc jo(char a){return x86(535,(IMM)a);}
enc jno(char a){return x86(536,(IMM)a);}
enc jb(char a){return x86(537,(IMM)a);}
enc jc(char a){return x86(538,(IMM)a);}
enc jnae(char a){return x86(539,(IMM)a);}
enc jae(char a){return x86(540,(IMM)a);}
enc jnb(char a){return x86(541,(IMM)a);}
enc jnc(char a){return x86(542,(IMM)a);}
enc je(char a){return x86(543,(IMM)a);}
enc jz(char a){return x86(544,(IMM)a);}
enc jne(char a){return x86(545,(IMM)a);}
enc jnz(char a){return x86(546,(IMM)a);}
enc jbe(char a){return x86(547,(IMM)a);}
enc jna(char a){return x86(548,(IMM)a);}
enc ja(char a){return x86(549,(IMM)a);}
enc jnbe(char a){return x86(550,(IMM)a);}
enc js(char a){return x86(551,(IMM)a);}
enc jns(char a){return x86(552,(IMM)a);}
enc jp(char a){return x86(553,(IMM)a);}
enc jpe(char a){return x86(554,(IMM)a);}
enc jnp(char a){return x86(555,(IMM)a);}
enc jpo(char a){return x86(556,(IMM)a);}
enc jl(char a){return x86(557,(IMM)a);}
enc jnge(char a){return x86(558,(IMM)a);}
enc jge(char a){return x86(559,(IMM)a);}
enc jnl(char a){return x86(560,(IMM)a);}
enc jle(char a){return x86(561,(IMM)a);}
enc jng(char a){return x86(562,(IMM)a);}
enc jg(char a){return x86(563,(IMM)a);}
enc jnle(char a){return x86(564,(IMM)a);}
enc jo(REF a){return x86(565,a);}
enc jo(int a){return x86(565,(IMM)a);}
enc jno(REF a){return x86(566,a);}
enc jno(int a){return x86(566,(IMM)a);}
enc jb(REF a){return x86(567,a);}
enc jb(int a){return x86(567,(IMM)a);}
enc jc(REF a){return x86(568,a);}
enc jc(int a){return x86(568,(IMM)a);}
enc jnae(REF a){return x86(569,a);}
enc jnae(int a){return x86(569,(IMM)a);}
enc jae(REF a){return x86(570,a);}
enc jae(int a){return x86(570,(IMM)a);}
enc jnb(REF a){return x86(571,a);}
enc jnb(int a){return x86(571,(IMM)a);}
enc jnc(REF a){return x86(572,a);}
enc jnc(int a){return x86(572,(IMM)a);}
enc je(REF a){return x86(573,a);}
enc je(int a){return x86(573,(IMM)a);}
enc jz(REF a){return x86(574,a);}
enc jz(int a){return x86(574,(IMM)a);}
enc jne(REF a){return x86(575,a);}
enc jne(int a){return x86(575,(IMM)a);}
enc jnz(REF a){return x86(576,a);}
enc jnz(int a){return x86(576,(IMM)a);}
enc jbe(REF a){return x86(577,a);}
enc jbe(int a){return x86(577,(IMM)a);}
enc jna(REF a){return x86(578,a);}
enc jna(int a){return x86(578,(IMM)a);}
enc ja(REF a){return x86(579,a);}
enc ja(int a){return x86(579,(IMM)a);}
enc jnbe(REF a){return x86(580,a);}
enc jnbe(int a){return x86(580,(IMM)a);}
enc js(REF a){return x86(581,a);}
enc js(int a){return x86(581,(IMM)a);}
enc jns(REF a){return x86(582,a);}
enc jns(int a){return x86(582,(IMM)a);}
enc jp(REF a){return x86(583,a);}
enc jp(int a){return x86(583,(IMM)a);}
enc jpe(REF a){return x86(584,a);}
enc jpe(int a){return x86(584,(IMM)a);}
enc jnp(REF a){return x86(585,a);}
enc jnp(int a){return x86(585,(IMM)a);}
enc jpo(REF a){return x86(586,a);}
enc jpo(int a){return x86(586,(IMM)a);}
enc jl(REF a){return x86(587,a);}
enc jl(int a){return x86(587,(IMM)a);}
enc jnge(REF a){return x86(588,a);}
enc jnge(int a){return x86(588,(IMM)a);}
enc jge(REF a){return x86(589,a);}
enc jge(int a){return x86(589,(IMM)a);}
enc jnl(REF a){return x86(590,a);}
enc jnl(int a){return x86(590,(IMM)a);}
enc jle(REF a){return x86(591,a);}
enc jle(int a){return x86(591,(IMM)a);}
enc jng(REF a){return x86(592,a);}
enc jng(int a){return x86(592,(IMM)a);}
enc jg(REF a){return x86(593,a);}
enc jg(int a){return x86(593,(IMM)a);}
enc jnle(REF a){return x86(594,a);}
enc jnle(int a){return x86(594,(IMM)a);}
enc lahf(){return x86(595);}
enc lds(REG16 a,MEM8 b){return x86(596,a,b);}
enc lds(REG16 a,MEM16 b){return x86(596,a,b);}
enc lds(REG16 a,MEM32 b){return x86(596,a,b);}
enc lds(REG16 a,MEM64 b){return x86(596,a,b);}
enc lds(REG16 a,MEM128 b){return x86(596,a,b);}
enc lds(REG32 a,MEM8 b){return x86(597,a,b);}
enc lds(REG32 a,MEM16 b){return x86(597,a,b);}
enc lds(REG32 a,MEM32 b){return x86(597,a,b);}
enc lds(REG32 a,MEM64 b){return x86(597,a,b);}
enc lds(REG32 a,MEM128 b){return x86(597,a,b);}
enc les(REG16 a,MEM8 b){return x86(598,a,b);}
enc les(REG16 a,MEM16 b){return x86(598,a,b);}
enc les(REG16 a,MEM32 b){return x86(598,a,b);}
enc les(REG16 a,MEM64 b){return x86(598,a,b);}
enc les(REG16 a,MEM128 b){return x86(598,a,b);}
enc les(REG32 a,MEM8 b){return x86(599,a,b);}
enc les(REG32 a,MEM16 b){return x86(599,a,b);}
enc les(REG32 a,MEM32 b){return x86(599,a,b);}
enc les(REG32 a,MEM64 b){return x86(599,a,b);}
enc les(REG32 a,MEM128 b){return x86(599,a,b);}
enc lfs(REG16 a,MEM8 b){return x86(600,a,b);}
enc lfs(REG16 a,MEM16 b){return x86(600,a,b);}
enc lfs(REG16 a,MEM32 b){return x86(600,a,b);}
enc lfs(REG16 a,MEM64 b){return x86(600,a,b);}
enc lfs(REG16 a,MEM128 b){return x86(600,a,b);}
enc lfs(REG32 a,MEM8 b){return x86(601,a,b);}
enc lfs(REG32 a,MEM16 b){return x86(601,a,b);}
enc lfs(REG32 a,MEM32 b){return x86(601,a,b);}
enc lfs(REG32 a,MEM64 b){return x86(601,a,b);}
enc lfs(REG32 a,MEM128 b){return x86(601,a,b);}
enc lgs(REG16 a,MEM8 b){return x86(602,a,b);}
enc lgs(REG16 a,MEM16 b){return x86(602,a,b);}
enc lgs(REG16 a,MEM32 b){return x86(602,a,b);}
enc lgs(REG16 a,MEM64 b){return x86(602,a,b);}
enc lgs(REG16 a,MEM128 b){return x86(602,a,b);}
enc lgs(REG32 a,MEM8 b){return x86(603,a,b);}
enc lgs(REG32 a,MEM16 b){return x86(603,a,b);}
enc lgs(REG32 a,MEM32 b){return x86(603,a,b);}
enc lgs(REG32 a,MEM64 b){return x86(603,a,b);}
enc lgs(REG32 a,MEM128 b){return x86(603,a,b);}
enc lss(REG16 a,MEM8 b){return x86(604,a,b);}
enc lss(REG16 a,MEM16 b){return x86(604,a,b);}
enc lss(REG16 a,MEM32 b){return x86(604,a,b);}
enc lss(REG16 a,MEM64 b){return x86(604,a,b);}
enc lss(REG16 a,MEM128 b){return x86(604,a,b);}
enc lss(REG32 a,MEM8 b){return x86(605,a,b);}
enc lss(REG32 a,MEM16 b){return x86(605,a,b);}
enc lss(REG32 a,MEM32 b){return x86(605,a,b);}
enc lss(REG32 a,MEM64 b){return x86(605,a,b);}
enc lss(REG32 a,MEM128 b){return x86(605,a,b);}
enc ldmxcsr(MEM32 a){return x86(606,a);}
enc lea(REG16 a,MEM8 b){return x86(607,a,b);}
enc lea(REG16 a,MEM16 b){return x86(607,a,b);}
enc lea(REG16 a,MEM32 b){return x86(607,a,b);}
enc lea(REG16 a,MEM64 b){return x86(607,a,b);}
enc lea(REG16 a,MEM128 b){return x86(607,a,b);}
enc lea(REG32 a,MEM8 b){return x86(608,a,b);}
enc lea(REG32 a,MEM16 b){return x86(608,a,b);}
enc lea(REG32 a,MEM32 b){return x86(608,a,b);}
enc lea(REG32 a,MEM64 b){return x86(608,a,b);}
enc lea(REG32 a,MEM128 b){return x86(608,a,b);}
enc leave(){return x86(609);}
enc lfence(){return x86(610);}
enc lodsb(){return x86(611);}
enc lodsw(){return x86(612);}
enc lodsd(){return x86(613);}
enc rep_lodsb(){return x86(614);}
enc rep_lodsw(){return x86(615);}
enc rep_lodsd(){return x86(616);}
enc loop(REF a){return x86(617,a);}
enc loop(int a){return x86(617,(IMM)a);}
enc loop(REF a,CX b){return x86(618,a,b);}
enc loop(int a,CX b){return x86(618,(IMM)a,b);}
enc loop(REF a,ECX b){return x86(619,a,b);}
enc loop(int a,ECX b){return x86(619,(IMM)a,b);}
enc loope(REF a){return x86(620,a);}
enc loope(int a){return x86(620,(IMM)a);}
enc loope(REF a,CX b){return x86(621,a,b);}
enc loope(int a,CX b){return x86(621,(IMM)a,b);}
enc loope(REF a,ECX b){return x86(622,a,b);}
enc loope(int a,ECX b){return x86(622,(IMM)a,b);}
enc loopz(REF a){return x86(623,a);}
enc loopz(int a){return x86(623,(IMM)a);}
enc loopz(REF a,CX b){return x86(624,a,b);}
enc loopz(int a,CX b){return x86(624,(IMM)a,b);}
enc loopz(REF a,ECX b){return x86(625,a,b);}
enc loopz(int a,ECX b){return x86(625,(IMM)a,b);}
enc loopne(REF a){return x86(626,a);}
enc loopne(int a){return x86(626,(IMM)a);}
enc loopne(REF a,CX b){return x86(627,a,b);}
enc loopne(int a,CX b){return x86(627,(IMM)a,b);}
enc loopne(REF a,ECX b){return x86(628,a,b);}
enc loopne(int a,ECX b){return x86(628,(IMM)a,b);}
enc loopnz(REF a){return x86(629,a);}
enc loopnz(int a){return x86(629,(IMM)a);}
enc loopnz(REF a,CX b){return x86(630,a,b);}
enc loopnz(int a,CX b){return x86(630,(IMM)a,b);}
enc loopnz(REF a,ECX b){return x86(631,a,b);}
enc loopnz(int a,ECX b){return x86(631,(IMM)a,b);}
enc maskmovdqu(XMMREG a,XMMREG b){return x86(632,a,b);}
enc maskmovq(MMREG a,MMREG b){return x86(633,a,b);}
enc maxpd(XMMREG a,XMMREG b){return x86(634,a,b);}
enc maxpd(XMMREG a,MEM128 b){return x86(634,a,b);}
enc maxpd(XMMREG a,R_M128 b){return x86(634,a,b);}
enc maxps(XMMREG a,XMMREG b){return x86(635,a,b);}
enc maxps(XMMREG a,MEM128 b){return x86(635,a,b);}
enc maxps(XMMREG a,R_M128 b){return x86(635,a,b);}
enc maxsd(XMMREG a,XMMREG b){return x86(636,a,b);}
enc maxsd(XMMREG a,MEM64 b){return x86(636,a,b);}
enc maxsd(XMMREG a,XMM64 b){return x86(636,a,b);}
enc maxss(XMMREG a,XMMREG b){return x86(637,a,b);}
enc maxss(XMMREG a,MEM32 b){return x86(637,a,b);}
enc maxss(XMMREG a,XMM32 b){return x86(637,a,b);}
enc mfence(){return x86(638);}
enc minpd(XMMREG a,XMMREG b){return x86(639,a,b);}
enc minpd(XMMREG a,MEM128 b){return x86(639,a,b);}
enc minpd(XMMREG a,R_M128 b){return x86(639,a,b);}
enc minps(XMMREG a,XMMREG b){return x86(640,a,b);}
enc minps(XMMREG a,MEM128 b){return x86(640,a,b);}
enc minps(XMMREG a,R_M128 b){return x86(640,a,b);}
enc minsd(XMMREG a,XMMREG b){return x86(641,a,b);}
enc minsd(XMMREG a,MEM64 b){return x86(641,a,b);}
enc minsd(XMMREG a,XMM64 b){return x86(641,a,b);}
enc minss(XMMREG a,XMMREG b){return x86(642,a,b);}
enc minss(XMMREG a,MEM32 b){return x86(642,a,b);}
enc minss(XMMREG a,XMM32 b){return x86(642,a,b);}
enc monitor(){return x86(643);}
enc mwait(){return x86(644);}
enc mov(REG8 a,REG8 b){return x86(645,a,b);}
enc mov(MEM8 a,REG8 b){return x86(645,a,b);}
enc mov(R_M8 a,REG8 b){return x86(645,a,b);}
enc mov(REG16 a,REG16 b){return x86(646,a,b);}
enc mov(MEM16 a,REG16 b){return x86(646,a,b);}
enc mov(R_M16 a,REG16 b){return x86(646,a,b);}
enc mov(REG32 a,REG32 b){return x86(647,a,b);}
enc mov(MEM32 a,REG32 b){return x86(647,a,b);}
enc mov(R_M32 a,REG32 b){return x86(647,a,b);}
enc mov(REG8 a,MEM8 b){return x86(648,a,b);}
enc mov(REG8 a,R_M8 b){return x86(648,a,b);}
enc mov(REG16 a,MEM16 b){return x86(649,a,b);}
enc mov(REG16 a,R_M16 b){return x86(649,a,b);}
enc mov(REG32 a,MEM32 b){return x86(650,a,b);}
enc mov(REG32 a,R_M32 b){return x86(650,a,b);}
enc mov(REG8 a,char b){return x86(651,a,(IMM)b);}
enc mov(AL a,char b){return x86(651,a,(IMM)b);}
enc mov(CL a,char b){return x86(651,a,(IMM)b);}
enc mov(REG16 a,char b){return x86(652,a,(IMM)b);}
enc mov(REG16 a,short b){return x86(652,a,(IMM)b);}
enc mov(REG32 a,REF b){return x86(653,a,b);}
enc mov(REG32 a,int b){return x86(653,a,(IMM)b);}
enc mov(MEM8 a,char b){return x86(654,a,(IMM)b);}
enc mov(R_M8 a,char b){return x86(654,a,(IMM)b);}
enc mov(MEM16 a,char b){return x86(655,a,(IMM)b);}
enc mov(MEM16 a,short b){return x86(655,a,(IMM)b);}
enc mov(R_M16 a,char b){return x86(655,a,(IMM)b);}
enc mov(R_M16 a,short b){return x86(655,a,(IMM)b);}
enc mov(MEM32 a,REF b){return x86(656,a,b);}
enc mov(MEM32 a,int b){return x86(656,a,(IMM)b);}
enc mov(R_M32 a,REF b){return x86(656,a,b);}
enc mov(R_M32 a,int b){return x86(656,a,(IMM)b);}
enc movapd(XMMREG a,XMMREG b){return x86(657,a,b);}
enc movapd(XMMREG a,MEM128 b){return x86(657,a,b);}
enc movapd(XMMREG a,R_M128 b){return x86(657,a,b);}
enc movapd(MEM128 a,XMMREG b){return x86(658,a,b);}
enc movapd(R_M128 a,XMMREG b){return x86(658,a,b);}
enc movaps(XMMREG a,XMMREG b){return x86(659,a,b);}
enc movaps(XMMREG a,MEM128 b){return x86(659,a,b);}
enc movaps(XMMREG a,R_M128 b){return x86(659,a,b);}
enc movaps(MEM128 a,XMMREG b){return x86(660,a,b);}
enc movaps(R_M128 a,XMMREG b){return x86(660,a,b);}
enc movd(MMREG a,REG32 b){return x86(661,a,b);}
enc movd(MMREG a,MEM32 b){return x86(661,a,b);}
enc movd(MMREG a,R_M32 b){return x86(661,a,b);}
enc movd(REG32 a,MMREG b){return x86(662,a,b);}
enc movd(MEM32 a,MMREG b){return x86(662,a,b);}
enc movd(R_M32 a,MMREG b){return x86(662,a,b);}
enc movd(XMMREG a,REG32 b){return x86(663,a,b);}
enc movd(XMMREG a,MEM32 b){return x86(663,a,b);}
enc movd(XMMREG a,R_M32 b){return x86(663,a,b);}
enc movd(REG32 a,XMMREG b){return x86(664,a,b);}
enc movd(MEM32 a,XMMREG b){return x86(664,a,b);}
enc movd(R_M32 a,XMMREG b){return x86(664,a,b);}
enc movdq2q(MMREG a,XMMREG b){return x86(665,a,b);}
enc movdqa(XMMREG a,XMMREG b){return x86(666,a,b);}
enc movdqa(XMMREG a,MEM128 b){return x86(666,a,b);}
enc movdqa(XMMREG a,R_M128 b){return x86(666,a,b);}
enc movdqa(MEM128 a,XMMREG b){return x86(667,a,b);}
enc movdqa(R_M128 a,XMMREG b){return x86(667,a,b);}
enc movdqu(XMMREG a,XMMREG b){return x86(668,a,b);}
enc movdqu(XMMREG a,MEM128 b){return x86(668,a,b);}
enc movdqu(XMMREG a,R_M128 b){return x86(668,a,b);}
enc movdqu(MEM128 a,XMMREG b){return x86(669,a,b);}
enc movdqu(R_M128 a,XMMREG b){return x86(669,a,b);}
enc lddqu(XMMREG a,MEM8 b){return x86(670,a,b);}
enc lddqu(XMMREG a,MEM16 b){return x86(670,a,b);}
enc lddqu(XMMREG a,MEM32 b){return x86(670,a,b);}
enc lddqu(XMMREG a,MEM64 b){return x86(670,a,b);}
enc lddqu(XMMREG a,MEM128 b){return x86(670,a,b);}
enc movhpd(XMMREG a,MEM64 b){return x86(671,a,b);}
enc movhpd(MEM64 a,XMMREG b){return x86(672,a,b);}
enc movhlps(XMMREG a,XMMREG b){return x86(673,a,b);}
enc movlpd(XMMREG a,MEM64 b){return x86(674,a,b);}
enc movlpd(MEM64 a,XMMREG b){return x86(675,a,b);}
enc movhps(XMMREG a,MEM64 b){return x86(676,a,b);}
enc movhps(MEM64 a,XMMREG b){return x86(677,a,b);}
enc movhps(XMMREG a,XMMREG b){return x86(678,a,b);}
enc movlhps(XMMREG a,XMMREG b){return x86(679,a,b);}
enc movlps(XMMREG a,MEM64 b){return x86(680,a,b);}
enc movlps(MEM64 a,XMMREG b){return x86(681,a,b);}
enc movmskpd(REG32 a,XMMREG b){return x86(682,a,b);}
enc movmskps(REG32 a,XMMREG b){return x86(683,a,b);}
enc movntdq(MEM128 a,XMMREG b){return x86(684,a,b);}
enc movnti(MEM32 a,REG32 b){return x86(685,a,b);}
enc movntpd(MEM128 a,XMMREG b){return x86(686,a,b);}
enc movntps(MEM128 a,XMMREG b){return x86(687,a,b);}
enc movntq(MEM64 a,MMREG b){return x86(688,a,b);}
enc movq(MMREG a,MMREG b){return x86(689,a,b);}
enc movq(MMREG a,MEM64 b){return x86(689,a,b);}
enc movq(MMREG a,R_M64 b){return x86(689,a,b);}
enc movq(MEM64 a,MMREG b){return x86(690,a,b);}
enc movq(R_M64 a,MMREG b){return x86(690,a,b);}
enc movq(XMMREG a,XMMREG b){return x86(691,a,b);}
enc movq(XMMREG a,MEM64 b){return x86(691,a,b);}
enc movq(XMMREG a,XMM64 b){return x86(691,a,b);}
enc movq(MEM64 a,XMMREG b){return x86(692,a,b);}
enc movq(XMM64 a,XMMREG b){return x86(692,a,b);}
enc movq2dq(XMMREG a,MMREG b){return x86(693,a,b);}
enc movsb(){return x86(694);}
enc movsw(){return x86(695);}
enc movsd(){return x86(696);}
enc rep_movsb(){return x86(697);}
enc rep_movsw(){return x86(698);}
enc rep_movsd(){return x86(699);}
enc movsd(XMMREG a,XMMREG b){return x86(700,a,b);}
enc movsd(XMMREG a,MEM64 b){return x86(700,a,b);}
enc movsd(XMMREG a,XMM64 b){return x86(700,a,b);}
enc movsd(MEM64 a,XMMREG b){return x86(701,a,b);}
enc movsd(XMM64 a,XMMREG b){return x86(701,a,b);}
enc movss(XMMREG a,XMMREG b){return x86(702,a,b);}
enc movss(XMMREG a,MEM32 b){return x86(702,a,b);}
enc movss(XMMREG a,XMM32 b){return x86(702,a,b);}
enc movss(MEM32 a,XMMREG b){return x86(703,a,b);}
enc movss(XMM32 a,XMMREG b){return x86(703,a,b);}
enc movsx(REG16 a,REG8 b){return x86(704,a,b);}
enc movsx(REG16 a,MEM8 b){return x86(704,a,b);}
enc movsx(REG16 a,R_M8 b){return x86(704,a,b);}
enc movsx(REG32 a,REG8 b){return x86(705,a,b);}
enc movsx(REG32 a,MEM8 b){return x86(705,a,b);}
enc movsx(REG32 a,R_M8 b){return x86(705,a,b);}
enc movsx(REG32 a,REG16 b){return x86(706,a,b);}
enc movsx(REG32 a,MEM16 b){return x86(706,a,b);}
enc movsx(REG32 a,R_M16 b){return x86(706,a,b);}
enc movshdup(XMMREG a,XMMREG b){return x86(707,a,b);}
enc movshdup(XMMREG a,MEM128 b){return x86(707,a,b);}
enc movshdup(XMMREG a,R_M128 b){return x86(707,a,b);}
enc movsldup(XMMREG a,XMMREG b){return x86(708,a,b);}
enc movsldup(XMMREG a,MEM128 b){return x86(708,a,b);}
enc movsldup(XMMREG a,R_M128 b){return x86(708,a,b);}
enc movddup(XMMREG a,XMMREG b){return x86(709,a,b);}
enc movddup(XMMREG a,MEM128 b){return x86(709,a,b);}
enc movddup(XMMREG a,R_M128 b){return x86(709,a,b);}
enc movzx(REG16 a,REG8 b){return x86(710,a,b);}
enc movzx(REG16 a,MEM8 b){return x86(710,a,b);}
enc movzx(REG16 a,R_M8 b){return x86(710,a,b);}
enc movzx(REG32 a,REG8 b){return x86(711,a,b);}
enc movzx(REG32 a,MEM8 b){return x86(711,a,b);}
enc movzx(REG32 a,R_M8 b){return x86(711,a,b);}
enc movzx(REG32 a,REG16 b){return x86(712,a,b);}
enc movzx(REG32 a,MEM16 b){return x86(712,a,b);}
enc movzx(REG32 a,R_M16 b){return x86(712,a,b);}
enc movupd(XMMREG a,XMMREG b){return x86(713,a,b);}
enc movupd(XMMREG a,MEM128 b){return x86(713,a,b);}
enc movupd(XMMREG a,R_M128 b){return x86(713,a,b);}
enc movupd(MEM128 a,XMMREG b){return x86(714,a,b);}
enc movupd(R_M128 a,XMMREG b){return x86(714,a,b);}
enc movups(XMMREG a,XMMREG b){return x86(715,a,b);}
enc movups(XMMREG a,MEM128 b){return x86(715,a,b);}
enc movups(XMMREG a,R_M128 b){return x86(715,a,b);}
enc movups(MEM128 a,XMMREG b){return x86(716,a,b);}
enc movups(R_M128 a,XMMREG b){return x86(716,a,b);}
enc mul(REG8 a){return x86(717,a);}
enc mul(MEM8 a){return x86(717,a);}
enc mul(R_M8 a){return x86(717,a);}
enc mul(REG16 a){return x86(718,a);}
enc mul(MEM16 a){return x86(718,a);}
enc mul(R_M16 a){return x86(718,a);}
enc mul(REG32 a){return x86(719,a);}
enc mul(MEM32 a){return x86(719,a);}
enc mul(R_M32 a){return x86(719,a);}
enc mulpd(XMMREG a,XMMREG b){return x86(720,a,b);}
enc mulpd(XMMREG a,MEM128 b){return x86(720,a,b);}
enc mulpd(XMMREG a,R_M128 b){return x86(720,a,b);}
enc mulps(XMMREG a,XMMREG b){return x86(721,a,b);}
enc mulps(XMMREG a,MEM128 b){return x86(721,a,b);}
enc mulps(XMMREG a,R_M128 b){return x86(721,a,b);}
enc mulsd(XMMREG a,XMMREG b){return x86(722,a,b);}
enc mulsd(XMMREG a,MEM64 b){return x86(722,a,b);}
enc mulsd(XMMREG a,XMM64 b){return x86(722,a,b);}
enc mulss(XMMREG a,XMMREG b){return x86(723,a,b);}
enc mulss(XMMREG a,MEM32 b){return x86(723,a,b);}
enc mulss(XMMREG a,XMM32 b){return x86(723,a,b);}
enc neg(REG8 a){return x86(724,a);}
enc neg(MEM8 a){return x86(724,a);}
enc neg(R_M8 a){return x86(724,a);}
enc neg(REG16 a){return x86(725,a);}
enc neg(MEM16 a){return x86(725,a);}
enc neg(R_M16 a){return x86(725,a);}
enc neg(REG32 a){return x86(726,a);}
enc neg(MEM32 a){return x86(726,a);}
enc neg(R_M32 a){return x86(726,a);}
enc lock_neg(MEM8 a){return x86(727,a);}
enc lock_neg(MEM16 a){return x86(728,a);}
enc lock_neg(MEM32 a){return x86(729,a);}
enc not(REG8 a){return x86(730,a);}
enc not(MEM8 a){return x86(730,a);}
enc not(R_M8 a){return x86(730,a);}
enc not(REG16 a){return x86(731,a);}
enc not(MEM16 a){return x86(731,a);}
enc not(R_M16 a){return x86(731,a);}
enc not(REG32 a){return x86(732,a);}
enc not(MEM32 a){return x86(732,a);}
enc not(R_M32 a){return x86(732,a);}
enc lock_not(MEM8 a){return x86(733,a);}
enc lock_not(MEM16 a){return x86(734,a);}
enc lock_not(MEM32 a){return x86(735,a);}
enc nop(){return x86(736);}
enc or(REG8 a,REG8 b){return x86(737,a,b);}
enc or(MEM8 a,REG8 b){return x86(737,a,b);}
enc or(R_M8 a,REG8 b){return x86(737,a,b);}
enc or(REG16 a,REG16 b){return x86(738,a,b);}
enc or(MEM16 a,REG16 b){return x86(738,a,b);}
enc or(R_M16 a,REG16 b){return x86(738,a,b);}
enc or(REG32 a,REG32 b){return x86(739,a,b);}
enc or(MEM32 a,REG32 b){return x86(739,a,b);}
enc or(R_M32 a,REG32 b){return x86(739,a,b);}
enc lock_or(MEM8 a,REG8 b){return x86(740,a,b);}
enc lock_or(MEM16 a,REG16 b){return x86(741,a,b);}
enc lock_or(MEM32 a,REG32 b){return x86(742,a,b);}
enc or(REG8 a,MEM8 b){return x86(743,a,b);}
enc or(REG8 a,R_M8 b){return x86(743,a,b);}
enc or(REG16 a,MEM16 b){return x86(744,a,b);}
enc or(REG16 a,R_M16 b){return x86(744,a,b);}
enc or(REG32 a,MEM32 b){return x86(745,a,b);}
enc or(REG32 a,R_M32 b){return x86(745,a,b);}
enc or(REG8 a,char b){return x86(746,a,(IMM)b);}
enc or(AL a,char b){return x86(746,a,(IMM)b);}
enc or(CL a,char b){return x86(746,a,(IMM)b);}
enc or(MEM8 a,char b){return x86(746,a,(IMM)b);}
enc or(R_M8 a,char b){return x86(746,a,(IMM)b);}
enc or(REG16 a,char b){return x86(747,a,(IMM)b);}
enc or(REG16 a,short b){return x86(747,a,(IMM)b);}
enc or(MEM16 a,char b){return x86(747,a,(IMM)b);}
enc or(MEM16 a,short b){return x86(747,a,(IMM)b);}
enc or(R_M16 a,char b){return x86(747,a,(IMM)b);}
enc or(R_M16 a,short b){return x86(747,a,(IMM)b);}
enc or(REG32 a,REF b){return x86(748,a,b);}
enc or(REG32 a,int b){return x86(748,a,(IMM)b);}
enc or(MEM32 a,REF b){return x86(748,a,b);}
enc or(MEM32 a,int b){return x86(748,a,(IMM)b);}
enc or(R_M32 a,REF b){return x86(748,a,b);}
enc or(R_M32 a,int b){return x86(748,a,(IMM)b);}
enc lock_or(MEM8 a,char b){return x86(751,a,(IMM)b);}
enc lock_or(MEM16 a,char b){return x86(752,a,(IMM)b);}
enc lock_or(MEM16 a,short b){return x86(752,a,(IMM)b);}
enc lock_or(MEM32 a,REF b){return x86(753,a,b);}
enc lock_or(MEM32 a,int b){return x86(753,a,(IMM)b);}
enc orpd(XMMREG a,XMMREG b){return x86(759,a,b);}
enc orpd(XMMREG a,MEM128 b){return x86(759,a,b);}
enc orpd(XMMREG a,R_M128 b){return x86(759,a,b);}
enc orps(XMMREG a,XMMREG b){return x86(760,a,b);}
enc orps(XMMREG a,MEM128 b){return x86(760,a,b);}
enc orps(XMMREG a,R_M128 b){return x86(760,a,b);}
enc out(char a,AL b){return x86(761,(IMM)a,b);}
enc out(char a,AX b){return x86(762,(IMM)a,b);}
enc out(char a,EAX b){return x86(763,(IMM)a,b);}
enc out(DX a,AL b){return x86(764,a,b);}
enc out(DX a,AX b){return x86(765,a,b);}
enc out(DX a,EAX b){return x86(766,a,b);}
enc outsb(){return x86(767);}
enc outsw(){return x86(768);}
enc outsd(){return x86(769);}
enc rep_outsb(){return x86(770);}
enc rep_outsw(){return x86(771);}
enc rep_outsd(){return x86(772);}
enc packssdw(MMREG a,MMREG b){return x86(773,a,b);}
enc packssdw(MMREG a,MEM64 b){return x86(773,a,b);}
enc packssdw(MMREG a,R_M64 b){return x86(773,a,b);}
enc packsswb(MMREG a,MMREG b){return x86(774,a,b);}
enc packsswb(MMREG a,MEM64 b){return x86(774,a,b);}
enc packsswb(MMREG a,R_M64 b){return x86(774,a,b);}
enc packuswb(MMREG a,MMREG b){return x86(775,a,b);}
enc packuswb(MMREG a,MEM64 b){return x86(775,a,b);}
enc packuswb(MMREG a,R_M64 b){return x86(775,a,b);}
enc packssdw(XMMREG a,XMMREG b){return x86(776,a,b);}
enc packssdw(XMMREG a,MEM128 b){return x86(776,a,b);}
enc packssdw(XMMREG a,R_M128 b){return x86(776,a,b);}
enc packsswb(XMMREG a,XMMREG b){return x86(777,a,b);}
enc packsswb(XMMREG a,MEM128 b){return x86(777,a,b);}
enc packsswb(XMMREG a,R_M128 b){return x86(777,a,b);}
enc packuswb(XMMREG a,XMMREG b){return x86(778,a,b);}
enc packuswb(XMMREG a,MEM128 b){return x86(778,a,b);}
enc packuswb(XMMREG a,R_M128 b){return x86(778,a,b);}
enc paddb(MMREG a,MMREG b){return x86(779,a,b);}
enc paddb(MMREG a,MEM64 b){return x86(779,a,b);}
enc paddb(MMREG a,R_M64 b){return x86(779,a,b);}
enc paddw(MMREG a,MMREG b){return x86(780,a,b);}
enc paddw(MMREG a,MEM64 b){return x86(780,a,b);}
enc paddw(MMREG a,R_M64 b){return x86(780,a,b);}
enc paddd(MMREG a,MMREG b){return x86(781,a,b);}
enc paddd(MMREG a,MEM64 b){return x86(781,a,b);}
enc paddd(MMREG a,R_M64 b){return x86(781,a,b);}
enc paddb(XMMREG a,XMMREG b){return x86(782,a,b);}
enc paddb(XMMREG a,MEM128 b){return x86(782,a,b);}
enc paddb(XMMREG a,R_M128 b){return x86(782,a,b);}
enc paddw(XMMREG a,XMMREG b){return x86(783,a,b);}
enc paddw(XMMREG a,MEM128 b){return x86(783,a,b);}
enc paddw(XMMREG a,R_M128 b){return x86(783,a,b);}
enc paddd(XMMREG a,XMMREG b){return x86(784,a,b);}
enc paddd(XMMREG a,MEM128 b){return x86(784,a,b);}
enc paddd(XMMREG a,R_M128 b){return x86(784,a,b);}
enc paddq(MMREG a,MMREG b){return x86(785,a,b);}
enc paddq(MMREG a,MEM64 b){return x86(785,a,b);}
enc paddq(MMREG a,R_M64 b){return x86(785,a,b);}
enc paddq(XMMREG a,XMMREG b){return x86(786,a,b);}
enc paddq(XMMREG a,MEM128 b){return x86(786,a,b);}
enc paddq(XMMREG a,R_M128 b){return x86(786,a,b);}
enc paddsb(MMREG a,MMREG b){return x86(787,a,b);}
enc paddsb(MMREG a,MEM64 b){return x86(787,a,b);}
enc paddsb(MMREG a,R_M64 b){return x86(787,a,b);}
enc paddsw(MMREG a,MMREG b){return x86(788,a,b);}
enc paddsw(MMREG a,MEM64 b){return x86(788,a,b);}
enc paddsw(MMREG a,R_M64 b){return x86(788,a,b);}
enc paddsb(XMMREG a,XMMREG b){return x86(789,a,b);}
enc paddsb(XMMREG a,MEM128 b){return x86(789,a,b);}
enc paddsb(XMMREG a,R_M128 b){return x86(789,a,b);}
enc paddsw(XMMREG a,XMMREG b){return x86(790,a,b);}
enc paddsw(XMMREG a,MEM128 b){return x86(790,a,b);}
enc paddsw(XMMREG a,R_M128 b){return x86(790,a,b);}
enc paddusb(MMREG a,MMREG b){return x86(791,a,b);}
enc paddusb(MMREG a,MEM64 b){return x86(791,a,b);}
enc paddusb(MMREG a,R_M64 b){return x86(791,a,b);}
enc paddusw(MMREG a,MMREG b){return x86(792,a,b);}
enc paddusw(MMREG a,MEM64 b){return x86(792,a,b);}
enc paddusw(MMREG a,R_M64 b){return x86(792,a,b);}
enc paddusb(XMMREG a,XMMREG b){return x86(793,a,b);}
enc paddusb(XMMREG a,MEM128 b){return x86(793,a,b);}
enc paddusb(XMMREG a,R_M128 b){return x86(793,a,b);}
enc paddusw(XMMREG a,XMMREG b){return x86(794,a,b);}
enc paddusw(XMMREG a,MEM128 b){return x86(794,a,b);}
enc paddusw(XMMREG a,R_M128 b){return x86(794,a,b);}
enc paddsiw(MMREG a,MMREG b){return x86(795,a,b);}
enc paddsiw(MMREG a,MEM64 b){return x86(795,a,b);}
enc paddsiw(MMREG a,R_M64 b){return x86(795,a,b);}
enc pand(MMREG a,MMREG b){return x86(796,a,b);}
enc pand(MMREG a,MEM64 b){return x86(796,a,b);}
enc pand(MMREG a,R_M64 b){return x86(796,a,b);}
enc pandn(MMREG a,MMREG b){return x86(797,a,b);}
enc pandn(MMREG a,MEM64 b){return x86(797,a,b);}
enc pandn(MMREG a,R_M64 b){return x86(797,a,b);}
enc pand(XMMREG a,XMMREG b){return x86(798,a,b);}
enc pand(XMMREG a,MEM128 b){return x86(798,a,b);}
enc pand(XMMREG a,R_M128 b){return x86(798,a,b);}
enc pandn(XMMREG a,XMMREG b){return x86(799,a,b);}
enc pandn(XMMREG a,MEM128 b){return x86(799,a,b);}
enc pandn(XMMREG a,R_M128 b){return x86(799,a,b);}
enc pause(){return x86(800);}
enc paveb(MMREG a,MMREG b){return x86(801,a,b);}
enc paveb(MMREG a,MEM64 b){return x86(801,a,b);}
enc paveb(MMREG a,R_M64 b){return x86(801,a,b);}
enc pavgb(MMREG a,MMREG b){return x86(802,a,b);}
enc pavgb(MMREG a,MEM64 b){return x86(802,a,b);}
enc pavgb(MMREG a,R_M64 b){return x86(802,a,b);}
enc pavgw(MMREG a,MMREG b){return x86(803,a,b);}
enc pavgw(MMREG a,MEM64 b){return x86(803,a,b);}
enc pavgw(MMREG a,R_M64 b){return x86(803,a,b);}
enc pavgb(XMMREG a,XMMREG b){return x86(804,a,b);}
enc pavgb(XMMREG a,MEM128 b){return x86(804,a,b);}
enc pavgb(XMMREG a,R_M128 b){return x86(804,a,b);}
enc pavgw(XMMREG a,XMMREG b){return x86(805,a,b);}
enc pavgw(XMMREG a,MEM128 b){return x86(805,a,b);}
enc pavgw(XMMREG a,R_M128 b){return x86(805,a,b);}
enc pavgusb(MMREG a,MMREG b){return x86(806,a,b);}
enc pavgusb(MMREG a,MEM64 b){return x86(806,a,b);}
enc pavgusb(MMREG a,R_M64 b){return x86(806,a,b);}
enc pcmpeqb(MMREG a,MMREG b){return x86(807,a,b);}
enc pcmpeqb(MMREG a,MEM64 b){return x86(807,a,b);}
enc pcmpeqb(MMREG a,R_M64 b){return x86(807,a,b);}
enc pcmpeqw(MMREG a,MMREG b){return x86(808,a,b);}
enc pcmpeqw(MMREG a,MEM64 b){return x86(808,a,b);}
enc pcmpeqw(MMREG a,R_M64 b){return x86(808,a,b);}
enc pcmpeqd(MMREG a,MMREG b){return x86(809,a,b);}
enc pcmpeqd(MMREG a,MEM64 b){return x86(809,a,b);}
enc pcmpeqd(MMREG a,R_M64 b){return x86(809,a,b);}
enc pcmpgtb(MMREG a,MMREG b){return x86(810,a,b);}
enc pcmpgtb(MMREG a,MEM64 b){return x86(810,a,b);}
enc pcmpgtb(MMREG a,R_M64 b){return x86(810,a,b);}
enc pcmpgtw(MMREG a,MMREG b){return x86(811,a,b);}
enc pcmpgtw(MMREG a,MEM64 b){return x86(811,a,b);}
enc pcmpgtw(MMREG a,R_M64 b){return x86(811,a,b);}
enc pcmpgtd(MMREG a,MMREG b){return x86(812,a,b);}
enc pcmpgtd(MMREG a,MEM64 b){return x86(812,a,b);}
enc pcmpgtd(MMREG a,R_M64 b){return x86(812,a,b);}
enc pcmpeqb(XMMREG a,XMMREG b){return x86(813,a,b);}
enc pcmpeqb(XMMREG a,MEM128 b){return x86(813,a,b);}
enc pcmpeqb(XMMREG a,R_M128 b){return x86(813,a,b);}
enc pcmpeqw(XMMREG a,XMMREG b){return x86(814,a,b);}
enc pcmpeqw(XMMREG a,MEM128 b){return x86(814,a,b);}
enc pcmpeqw(XMMREG a,R_M128 b){return x86(814,a,b);}
enc pcmpeqd(XMMREG a,XMMREG b){return x86(815,a,b);}
enc pcmpeqd(XMMREG a,MEM128 b){return x86(815,a,b);}
enc pcmpeqd(XMMREG a,R_M128 b){return x86(815,a,b);}
enc pcmpgtb(XMMREG a,XMMREG b){return x86(816,a,b);}
enc pcmpgtb(XMMREG a,MEM128 b){return x86(816,a,b);}
enc pcmpgtb(XMMREG a,R_M128 b){return x86(816,a,b);}
enc pcmpgtw(XMMREG a,XMMREG b){return x86(817,a,b);}
enc pcmpgtw(XMMREG a,MEM128 b){return x86(817,a,b);}
enc pcmpgtw(XMMREG a,R_M128 b){return x86(817,a,b);}
enc pcmpgtd(XMMREG a,XMMREG b){return x86(818,a,b);}
enc pcmpgtd(XMMREG a,MEM128 b){return x86(818,a,b);}
enc pcmpgtd(XMMREG a,R_M128 b){return x86(818,a,b);}
enc pdistib(MMREG a,MEM64 b){return x86(819,a,b);}
enc pextrw(REG32 a,MMREG b,char c){return x86(820,a,b,(IMM)c);}
enc pextrw(EAX a,MMREG b,char c){return x86(820,a,b,(IMM)c);}
enc pextrw(ECX a,MMREG b,char c){return x86(820,a,b,(IMM)c);}
enc pextrw(REG32 a,XMMREG b,char c){return x86(821,a,b,(IMM)c);}
enc pextrw(EAX a,XMMREG b,char c){return x86(821,a,b,(IMM)c);}
enc pextrw(ECX a,XMMREG b,char c){return x86(821,a,b,(IMM)c);}
enc pf2id(MMREG a,MMREG b){return x86(822,a,b);}
enc pf2id(MMREG a,MEM64 b){return x86(822,a,b);}
enc pf2id(MMREG a,R_M64 b){return x86(822,a,b);}
enc pf2iw(MMREG a,MMREG b){return x86(823,a,b);}
enc pf2iw(MMREG a,MEM64 b){return x86(823,a,b);}
enc pf2iw(MMREG a,R_M64 b){return x86(823,a,b);}
enc pfacc(MMREG a,MMREG b){return x86(824,a,b);}
enc pfacc(MMREG a,MEM64 b){return x86(824,a,b);}
enc pfacc(MMREG a,R_M64 b){return x86(824,a,b);}
enc pfadd(MMREG a,MMREG b){return x86(825,a,b);}
enc pfadd(MMREG a,MEM64 b){return x86(825,a,b);}
enc pfadd(MMREG a,R_M64 b){return x86(825,a,b);}
enc pfcmpeq(MMREG a,MMREG b){return x86(826,a,b);}
enc pfcmpeq(MMREG a,MEM64 b){return x86(826,a,b);}
enc pfcmpeq(MMREG a,R_M64 b){return x86(826,a,b);}
enc pfcmpge(MMREG a,MMREG b){return x86(827,a,b);}
enc pfcmpge(MMREG a,MEM64 b){return x86(827,a,b);}
enc pfcmpge(MMREG a,R_M64 b){return x86(827,a,b);}
enc pfcmpgt(MMREG a,MMREG b){return x86(828,a,b);}
enc pfcmpgt(MMREG a,MEM64 b){return x86(828,a,b);}
enc pfcmpgt(MMREG a,R_M64 b){return x86(828,a,b);}
enc pfmax(MMREG a,MMREG b){return x86(829,a,b);}
enc pfmax(MMREG a,MEM64 b){return x86(829,a,b);}
enc pfmax(MMREG a,R_M64 b){return x86(829,a,b);}
enc pfmin(MMREG a,MMREG b){return x86(830,a,b);}
enc pfmin(MMREG a,MEM64 b){return x86(830,a,b);}
enc pfmin(MMREG a,R_M64 b){return x86(830,a,b);}
enc pfmul(MMREG a,MMREG b){return x86(831,a,b);}
enc pfmul(MMREG a,MEM64 b){return x86(831,a,b);}
enc pfmul(MMREG a,R_M64 b){return x86(831,a,b);}
enc pfnacc(MMREG a,MMREG b){return x86(832,a,b);}
enc pfnacc(MMREG a,MEM64 b){return x86(832,a,b);}
enc pfnacc(MMREG a,R_M64 b){return x86(832,a,b);}
enc pfpnacc(MMREG a,MMREG b){return x86(833,a,b);}
enc pfpnacc(MMREG a,MEM64 b){return x86(833,a,b);}
enc pfpnacc(MMREG a,R_M64 b){return x86(833,a,b);}
enc pfrcp(MMREG a,MMREG b){return x86(834,a,b);}
enc pfrcp(MMREG a,MEM64 b){return x86(834,a,b);}
enc pfrcp(MMREG a,R_M64 b){return x86(834,a,b);}
enc pfrcpit1(MMREG a,MMREG b){return x86(835,a,b);}
enc pfrcpit1(MMREG a,MEM64 b){return x86(835,a,b);}
enc pfrcpit1(MMREG a,R_M64 b){return x86(835,a,b);}
enc pfrcpit2(MMREG a,MMREG b){return x86(836,a,b);}
enc pfrcpit2(MMREG a,MEM64 b){return x86(836,a,b);}
enc pfrcpit2(MMREG a,R_M64 b){return x86(836,a,b);}
enc pfrsqit1(MMREG a,MMREG b){return x86(837,a,b);}
enc pfrsqit1(MMREG a,MEM64 b){return x86(837,a,b);}
enc pfrsqit1(MMREG a,R_M64 b){return x86(837,a,b);}
enc pfrsqrt(MMREG a,MMREG b){return x86(838,a,b);}
enc pfrsqrt(MMREG a,MEM64 b){return x86(838,a,b);}
enc pfrsqrt(MMREG a,R_M64 b){return x86(838,a,b);}
enc pfsub(MMREG a,MMREG b){return x86(839,a,b);}
enc pfsub(MMREG a,MEM64 b){return x86(839,a,b);}
enc pfsub(MMREG a,R_M64 b){return x86(839,a,b);}
enc pfsubr(MMREG a,MMREG b){return x86(840,a,b);}
enc pfsubr(MMREG a,MEM64 b){return x86(840,a,b);}
enc pfsubr(MMREG a,R_M64 b){return x86(840,a,b);}
enc pi2fd(MMREG a,MMREG b){return x86(841,a,b);}
enc pi2fd(MMREG a,MEM64 b){return x86(841,a,b);}
enc pi2fd(MMREG a,R_M64 b){return x86(841,a,b);}
enc pi2fw(MMREG a,MMREG b){return x86(842,a,b);}
enc pi2fw(MMREG a,MEM64 b){return x86(842,a,b);}
enc pi2fw(MMREG a,R_M64 b){return x86(842,a,b);}
enc pinsrw(MMREG a,REG16 b,char c){return x86(843,a,b,(IMM)c);}
enc pinsrw(MMREG a,AX b,char c){return x86(843,a,b,(IMM)c);}
enc pinsrw(MMREG a,DX b,char c){return x86(843,a,b,(IMM)c);}
enc pinsrw(MMREG a,CX b,char c){return x86(843,a,b,(IMM)c);}
enc pinsrw(MMREG a,MEM16 b,char c){return x86(843,a,b,(IMM)c);}
enc pinsrw(MMREG a,R_M16 b,char c){return x86(843,a,b,(IMM)c);}
enc pinsrw(XMMREG a,REG16 b,char c){return x86(844,a,b,(IMM)c);}
enc pinsrw(XMMREG a,AX b,char c){return x86(844,a,b,(IMM)c);}
enc pinsrw(XMMREG a,DX b,char c){return x86(844,a,b,(IMM)c);}
enc pinsrw(XMMREG a,CX b,char c){return x86(844,a,b,(IMM)c);}
enc pinsrw(XMMREG a,MEM16 b,char c){return x86(844,a,b,(IMM)c);}
enc pinsrw(XMMREG a,R_M16 b,char c){return x86(844,a,b,(IMM)c);}
enc pmachriw(MMREG a,MEM64 b){return x86(845,a,b);}
enc pmaddwd(MMREG a,MMREG b){return x86(846,a,b);}
enc pmaddwd(MMREG a,MEM64 b){return x86(846,a,b);}
enc pmaddwd(MMREG a,R_M64 b){return x86(846,a,b);}
enc pmaddwd(XMMREG a,XMMREG b){return x86(847,a,b);}
enc pmaddwd(XMMREG a,MEM128 b){return x86(847,a,b);}
enc pmaddwd(XMMREG a,R_M128 b){return x86(847,a,b);}
enc pmagw(MMREG a,MMREG b){return x86(848,a,b);}
enc pmagw(MMREG a,MEM64 b){return x86(848,a,b);}
enc pmagw(MMREG a,R_M64 b){return x86(848,a,b);}
enc pmaxsw(XMMREG a,XMMREG b){return x86(849,a,b);}
enc pmaxsw(XMMREG a,MEM128 b){return x86(849,a,b);}
enc pmaxsw(XMMREG a,R_M128 b){return x86(849,a,b);}
enc pmaxsw(MMREG a,MMREG b){return x86(850,a,b);}
enc pmaxsw(MMREG a,MEM64 b){return x86(850,a,b);}
enc pmaxsw(MMREG a,R_M64 b){return x86(850,a,b);}
enc pmaxub(MMREG a,MMREG b){return x86(851,a,b);}
enc pmaxub(MMREG a,MEM64 b){return x86(851,a,b);}
enc pmaxub(MMREG a,R_M64 b){return x86(851,a,b);}
enc pmaxub(XMMREG a,XMMREG b){return x86(852,a,b);}
enc pmaxub(XMMREG a,MEM128 b){return x86(852,a,b);}
enc pmaxub(XMMREG a,R_M128 b){return x86(852,a,b);}
enc pminsw(MMREG a,MMREG b){return x86(853,a,b);}
enc pminsw(MMREG a,MEM64 b){return x86(853,a,b);}
enc pminsw(MMREG a,R_M64 b){return x86(853,a,b);}
enc pminsw(XMMREG a,XMMREG b){return x86(854,a,b);}
enc pminsw(XMMREG a,MEM128 b){return x86(854,a,b);}
enc pminsw(XMMREG a,R_M128 b){return x86(854,a,b);}
enc pminub(MMREG a,MMREG b){return x86(855,a,b);}
enc pminub(MMREG a,MEM64 b){return x86(855,a,b);}
enc pminub(MMREG a,R_M64 b){return x86(855,a,b);}
enc pminub(XMMREG a,XMMREG b){return x86(856,a,b);}
enc pminub(XMMREG a,MEM128 b){return x86(856,a,b);}
enc pminub(XMMREG a,R_M128 b){return x86(856,a,b);}
enc pmovmskb(REG32 a,MMREG b){return x86(857,a,b);}
enc pmovmskb(REG32 a,XMMREG b){return x86(858,a,b);}
enc pmulhrwa(MMREG a,MMREG b){return x86(859,a,b);}
enc pmulhrwa(MMREG a,MEM64 b){return x86(859,a,b);}
enc pmulhrwa(MMREG a,R_M64 b){return x86(859,a,b);}
enc pmulhrwc(MMREG a,MMREG b){return x86(860,a,b);}
enc pmulhrwc(MMREG a,MEM64 b){return x86(860,a,b);}
enc pmulhrwc(MMREG a,R_M64 b){return x86(860,a,b);}
enc pmulhriw(MMREG a,MMREG b){return x86(861,a,b);}
enc pmulhriw(MMREG a,MEM64 b){return x86(861,a,b);}
enc pmulhriw(MMREG a,R_M64 b){return x86(861,a,b);}
enc pmulhuw(MMREG a,MMREG b){return x86(862,a,b);}
enc pmulhuw(MMREG a,MEM64 b){return x86(862,a,b);}
enc pmulhuw(MMREG a,R_M64 b){return x86(862,a,b);}
enc pmulhuw(XMMREG a,XMMREG b){return x86(863,a,b);}
enc pmulhuw(XMMREG a,MEM128 b){return x86(863,a,b);}
enc pmulhuw(XMMREG a,R_M128 b){return x86(863,a,b);}
enc pmulhw(MMREG a,MMREG b){return x86(864,a,b);}
enc pmulhw(MMREG a,MEM64 b){return x86(864,a,b);}
enc pmulhw(MMREG a,R_M64 b){return x86(864,a,b);}
enc pmullw(MMREG a,MMREG b){return x86(865,a,b);}
enc pmullw(MMREG a,MEM64 b){return x86(865,a,b);}
enc pmullw(MMREG a,R_M64 b){return x86(865,a,b);}
enc pmulhw(XMMREG a,XMMREG b){return x86(866,a,b);}
enc pmulhw(XMMREG a,MEM128 b){return x86(866,a,b);}
enc pmulhw(XMMREG a,R_M128 b){return x86(866,a,b);}
enc pmullw(XMMREG a,XMMREG b){return x86(867,a,b);}
enc pmullw(XMMREG a,MEM128 b){return x86(867,a,b);}
enc pmullw(XMMREG a,R_M128 b){return x86(867,a,b);}
enc pmuludq(MMREG a,MMREG b){return x86(868,a,b);}
enc pmuludq(MMREG a,MEM64 b){return x86(868,a,b);}
enc pmuludq(MMREG a,R_M64 b){return x86(868,a,b);}
enc pmuludq(XMMREG a,XMMREG b){return x86(869,a,b);}
enc pmuludq(XMMREG a,MEM128 b){return x86(869,a,b);}
enc pmuludq(XMMREG a,R_M128 b){return x86(869,a,b);}
enc pmvzb(MMREG a,MEM64 b){return x86(870,a,b);}
enc pmvnzb(MMREG a,MEM64 b){return x86(871,a,b);}
enc pmvlzb(MMREG a,MEM64 b){return x86(872,a,b);}
enc pmvgezb(MMREG a,MEM64 b){return x86(873,a,b);}
enc pop(REG16 a){return x86(874,a);}
enc pop(REG32 a){return x86(875,a);}
enc pop(MEM16 a){return x86(876,a);}
enc pop(R_M16 a){return x86(876,a);}
enc pop(MEM32 a){return x86(877,a);}
enc pop(R_M32 a){return x86(877,a);}
enc popa(){return x86(878);}
enc popaw(){return x86(879);}
enc popad(){return x86(880);}
enc popf(){return x86(881);}
enc popfw(){return x86(882);}
enc popfd(){return x86(883);}
enc por(MMREG a,MMREG b){return x86(884,a,b);}
enc por(MMREG a,MEM64 b){return x86(884,a,b);}
enc por(MMREG a,R_M64 b){return x86(884,a,b);}
enc por(XMMREG a,XMMREG b){return x86(885,a,b);}
enc por(XMMREG a,MEM128 b){return x86(885,a,b);}
enc por(XMMREG a,R_M128 b){return x86(885,a,b);}
enc prefetch(MEM8 a){return x86(886,a);}
enc prefetch(MEM16 a){return x86(886,a);}
enc prefetch(MEM32 a){return x86(886,a);}
enc prefetch(MEM64 a){return x86(886,a);}
enc prefetch(MEM128 a){return x86(886,a);}
enc prefetchw(MEM8 a){return x86(887,a);}
enc prefetchw(MEM16 a){return x86(887,a);}
enc prefetchw(MEM32 a){return x86(887,a);}
enc prefetchw(MEM64 a){return x86(887,a);}
enc prefetchw(MEM128 a){return x86(887,a);}
enc prefetchnta(MEM8 a){return x86(888,a);}
enc prefetchnta(MEM16 a){return x86(888,a);}
enc prefetchnta(MEM32 a){return x86(888,a);}
enc prefetchnta(MEM64 a){return x86(888,a);}
enc prefetchnta(MEM128 a){return x86(888,a);}
enc prefetcht0(MEM8 a){return x86(889,a);}
enc prefetcht0(MEM16 a){return x86(889,a);}
enc prefetcht0(MEM32 a){return x86(889,a);}
enc prefetcht0(MEM64 a){return x86(889,a);}
enc prefetcht0(MEM128 a){return x86(889,a);}
enc prefetcht1(MEM8 a){return x86(890,a);}
enc prefetcht1(MEM16 a){return x86(890,a);}
enc prefetcht1(MEM32 a){return x86(890,a);}
enc prefetcht1(MEM64 a){return x86(890,a);}
enc prefetcht1(MEM128 a){return x86(890,a);}
enc prefetcht2(MEM8 a){return x86(891,a);}
enc prefetcht2(MEM16 a){return x86(891,a);}
enc prefetcht2(MEM32 a){return x86(891,a);}
enc prefetcht2(MEM64 a){return x86(891,a);}
enc prefetcht2(MEM128 a){return x86(891,a);}
enc psadbw(MMREG a,MMREG b){return x86(892,a,b);}
enc psadbw(MMREG a,MEM64 b){return x86(892,a,b);}
enc psadbw(MMREG a,R_M64 b){return x86(892,a,b);}
enc psadbw(XMMREG a,XMMREG b){return x86(893,a,b);}
enc psadbw(XMMREG a,MEM128 b){return x86(893,a,b);}
enc psadbw(XMMREG a,R_M128 b){return x86(893,a,b);}
enc pshufd(XMMREG a,XMMREG b,char c){return x86(894,a,b,(IMM)c);}
enc pshufd(XMMREG a,MEM128 b,char c){return x86(894,a,b,(IMM)c);}
enc pshufd(XMMREG a,R_M128 b,char c){return x86(894,a,b,(IMM)c);}
enc pshufhw(XMMREG a,XMMREG b,char c){return x86(895,a,b,(IMM)c);}
enc pshufhw(XMMREG a,MEM128 b,char c){return x86(895,a,b,(IMM)c);}
enc pshufhw(XMMREG a,R_M128 b,char c){return x86(895,a,b,(IMM)c);}
enc pshuflw(XMMREG a,XMMREG b,char c){return x86(896,a,b,(IMM)c);}
enc pshuflw(XMMREG a,MEM128 b,char c){return x86(896,a,b,(IMM)c);}
enc pshuflw(XMMREG a,R_M128 b,char c){return x86(896,a,b,(IMM)c);}
enc pshufw(MMREG a,MMREG b,char c){return x86(897,a,b,(IMM)c);}
enc pshufw(MMREG a,MEM64 b,char c){return x86(897,a,b,(IMM)c);}
enc pshufw(MMREG a,R_M64 b,char c){return x86(897,a,b,(IMM)c);}
enc psllw(MMREG a,MMREG b){return x86(898,a,b);}
enc psllw(MMREG a,MEM64 b){return x86(898,a,b);}
enc psllw(MMREG a,R_M64 b){return x86(898,a,b);}
enc psllw(MMREG a,char b){return x86(899,a,(IMM)b);}
enc psllw(XMMREG a,XMMREG b){return x86(900,a,b);}
enc psllw(XMMREG a,MEM128 b){return x86(900,a,b);}
enc psllw(XMMREG a,R_M128 b){return x86(900,a,b);}
enc psllw(XMMREG a,char b){return x86(901,a,(IMM)b);}
enc pslld(MMREG a,MMREG b){return x86(902,a,b);}
enc pslld(MMREG a,MEM64 b){return x86(902,a,b);}
enc pslld(MMREG a,R_M64 b){return x86(902,a,b);}
enc pslld(MMREG a,char b){return x86(903,a,(IMM)b);}
enc pslld(XMMREG a,XMMREG b){return x86(904,a,b);}
enc pslld(XMMREG a,MEM128 b){return x86(904,a,b);}
enc pslld(XMMREG a,R_M128 b){return x86(904,a,b);}
enc pslld(XMMREG a,char b){return x86(905,a,(IMM)b);}
enc psllq(MMREG a,MMREG b){return x86(906,a,b);}
enc psllq(MMREG a,MEM64 b){return x86(906,a,b);}
enc psllq(MMREG a,R_M64 b){return x86(906,a,b);}
enc psllq(MMREG a,char b){return x86(907,a,(IMM)b);}
enc psllq(XMMREG a,XMMREG b){return x86(908,a,b);}
enc psllq(XMMREG a,MEM128 b){return x86(908,a,b);}
enc psllq(XMMREG a,R_M128 b){return x86(908,a,b);}
enc psllq(XMMREG a,char b){return x86(909,a,(IMM)b);}
enc psraw(MMREG a,MMREG b){return x86(910,a,b);}
enc psraw(MMREG a,MEM64 b){return x86(910,a,b);}
enc psraw(MMREG a,R_M64 b){return x86(910,a,b);}
enc psraw(MMREG a,char b){return x86(911,a,(IMM)b);}
enc psraw(XMMREG a,XMMREG b){return x86(912,a,b);}
enc psraw(XMMREG a,MEM128 b){return x86(912,a,b);}
enc psraw(XMMREG a,R_M128 b){return x86(912,a,b);}
enc psraw(XMMREG a,char b){return x86(913,a,(IMM)b);}
enc psrad(MMREG a,MMREG b){return x86(914,a,b);}
enc psrad(MMREG a,MEM64 b){return x86(914,a,b);}
enc psrad(MMREG a,R_M64 b){return x86(914,a,b);}
enc psrad(MMREG a,char b){return x86(915,a,(IMM)b);}
enc psrad(XMMREG a,XMMREG b){return x86(916,a,b);}
enc psrad(XMMREG a,MEM128 b){return x86(916,a,b);}
enc psrad(XMMREG a,R_M128 b){return x86(916,a,b);}
enc psrad(XMMREG a,char b){return x86(917,a,(IMM)b);}
enc psrlw(MMREG a,MMREG b){return x86(918,a,b);}
enc psrlw(MMREG a,MEM64 b){return x86(918,a,b);}
enc psrlw(MMREG a,R_M64 b){return x86(918,a,b);}
enc psrlw(MMREG a,char b){return x86(919,a,(IMM)b);}
enc psrlw(XMMREG a,XMMREG b){return x86(920,a,b);}
enc psrlw(XMMREG a,MEM128 b){return x86(920,a,b);}
enc psrlw(XMMREG a,R_M128 b){return x86(920,a,b);}
enc psrlw(XMMREG a,char b){return x86(921,a,(IMM)b);}
enc psrld(MMREG a,MMREG b){return x86(922,a,b);}
enc psrld(MMREG a,MEM64 b){return x86(922,a,b);}
enc psrld(MMREG a,R_M64 b){return x86(922,a,b);}
enc psrld(MMREG a,char b){return x86(923,a,(IMM)b);}
enc psrld(XMMREG a,XMMREG b){return x86(924,a,b);}
enc psrld(XMMREG a,MEM128 b){return x86(924,a,b);}
enc psrld(XMMREG a,R_M128 b){return x86(924,a,b);}
enc psrld(XMMREG a,char b){return x86(925,a,(IMM)b);}
enc psrlq(MMREG a,MMREG b){return x86(926,a,b);}
enc psrlq(MMREG a,MEM64 b){return x86(926,a,b);}
enc psrlq(MMREG a,R_M64 b){return x86(926,a,b);}
enc psrlq(MMREG a,char b){return x86(927,a,(IMM)b);}
enc psrlq(XMMREG a,XMMREG b){return x86(928,a,b);}
enc psrlq(XMMREG a,MEM128 b){return x86(928,a,b);}
enc psrlq(XMMREG a,R_M128 b){return x86(928,a,b);}
enc psrlq(XMMREG a,char b){return x86(929,a,(IMM)b);}
enc psrldq(XMMREG a,char b){return x86(930,a,(IMM)b);}
enc psubb(MMREG a,MMREG b){return x86(931,a,b);}
enc psubb(MMREG a,MEM64 b){return x86(931,a,b);}
enc psubb(MMREG a,R_M64 b){return x86(931,a,b);}
enc psubw(MMREG a,MMREG b){return x86(932,a,b);}
enc psubw(MMREG a,MEM64 b){return x86(932,a,b);}
enc psubw(MMREG a,R_M64 b){return x86(932,a,b);}
enc psubd(MMREG a,MMREG b){return x86(933,a,b);}
enc psubd(MMREG a,MEM64 b){return x86(933,a,b);}
enc psubd(MMREG a,R_M64 b){return x86(933,a,b);}
enc psubq(MMREG a,MMREG b){return x86(934,a,b);}
enc psubq(MMREG a,MEM64 b){return x86(934,a,b);}
enc psubq(MMREG a,R_M64 b){return x86(934,a,b);}
enc psubb(XMMREG a,XMMREG b){return x86(935,a,b);}
enc psubb(XMMREG a,MEM128 b){return x86(935,a,b);}
enc psubb(XMMREG a,R_M128 b){return x86(935,a,b);}
enc psubw(XMMREG a,XMMREG b){return x86(936,a,b);}
enc psubw(XMMREG a,MEM128 b){return x86(936,a,b);}
enc psubw(XMMREG a,R_M128 b){return x86(936,a,b);}
enc psubd(XMMREG a,XMMREG b){return x86(937,a,b);}
enc psubd(XMMREG a,MEM128 b){return x86(937,a,b);}
enc psubd(XMMREG a,R_M128 b){return x86(937,a,b);}
enc psubq(XMMREG a,XMMREG b){return x86(938,a,b);}
enc psubq(XMMREG a,MEM128 b){return x86(938,a,b);}
enc psubq(XMMREG a,R_M128 b){return x86(938,a,b);}
enc psubsb(MMREG a,MMREG b){return x86(939,a,b);}
enc psubsb(MMREG a,MEM64 b){return x86(939,a,b);}
enc psubsb(MMREG a,R_M64 b){return x86(939,a,b);}
enc psubsw(MMREG a,MMREG b){return x86(940,a,b);}
enc psubsw(MMREG a,MEM64 b){return x86(940,a,b);}
enc psubsw(MMREG a,R_M64 b){return x86(940,a,b);}
enc psubsb(XMMREG a,XMMREG b){return x86(941,a,b);}
enc psubsb(XMMREG a,MEM128 b){return x86(941,a,b);}
enc psubsb(XMMREG a,R_M128 b){return x86(941,a,b);}
enc psubsw(XMMREG a,XMMREG b){return x86(942,a,b);}
enc psubsw(XMMREG a,MEM128 b){return x86(942,a,b);}
enc psubsw(XMMREG a,R_M128 b){return x86(942,a,b);}
enc psubusb(MMREG a,MMREG b){return x86(943,a,b);}
enc psubusb(MMREG a,MEM64 b){return x86(943,a,b);}
enc psubusb(MMREG a,R_M64 b){return x86(943,a,b);}
enc psubusw(MMREG a,MMREG b){return x86(944,a,b);}
enc psubusw(MMREG a,MEM64 b){return x86(944,a,b);}
enc psubusw(MMREG a,R_M64 b){return x86(944,a,b);}
enc psubusb(XMMREG a,XMMREG b){return x86(945,a,b);}
enc psubusb(XMMREG a,MEM128 b){return x86(945,a,b);}
enc psubusb(XMMREG a,R_M128 b){return x86(945,a,b);}
enc psubusw(XMMREG a,XMMREG b){return x86(946,a,b);}
enc psubusw(XMMREG a,MEM128 b){return x86(946,a,b);}
enc psubusw(XMMREG a,R_M128 b){return x86(946,a,b);}
enc psubsiw(MMREG a,MMREG b){return x86(947,a,b);}
enc psubsiw(MMREG a,MEM64 b){return x86(947,a,b);}
enc psubsiw(MMREG a,R_M64 b){return x86(947,a,b);}
enc pswapd(MMREG a,MMREG b){return x86(948,a,b);}
enc pswapd(MMREG a,MEM64 b){return x86(948,a,b);}
enc pswapd(MMREG a,R_M64 b){return x86(948,a,b);}
enc punpckhbw(MMREG a,MMREG b){return x86(949,a,b);}
enc punpckhbw(MMREG a,MEM64 b){return x86(949,a,b);}
enc punpckhbw(MMREG a,R_M64 b){return x86(949,a,b);}
enc punpckhwd(MMREG a,MMREG b){return x86(950,a,b);}
enc punpckhwd(MMREG a,MEM64 b){return x86(950,a,b);}
enc punpckhwd(MMREG a,R_M64 b){return x86(950,a,b);}
enc punpckhdq(MMREG a,MMREG b){return x86(951,a,b);}
enc punpckhdq(MMREG a,MEM64 b){return x86(951,a,b);}
enc punpckhdq(MMREG a,R_M64 b){return x86(951,a,b);}
enc punpckhbw(XMMREG a,XMMREG b){return x86(952,a,b);}
enc punpckhbw(XMMREG a,MEM128 b){return x86(952,a,b);}
enc punpckhbw(XMMREG a,R_M128 b){return x86(952,a,b);}
enc punpckhwd(XMMREG a,XMMREG b){return x86(953,a,b);}
enc punpckhwd(XMMREG a,MEM128 b){return x86(953,a,b);}
enc punpckhwd(XMMREG a,R_M128 b){return x86(953,a,b);}
enc punpckhdq(XMMREG a,XMMREG b){return x86(954,a,b);}
enc punpckhdq(XMMREG a,MEM128 b){return x86(954,a,b);}
enc punpckhdq(XMMREG a,R_M128 b){return x86(954,a,b);}
enc punpckhqdq(XMMREG a,XMMREG b){return x86(955,a,b);}
enc punpckhqdq(XMMREG a,MEM128 b){return x86(955,a,b);}
enc punpckhqdq(XMMREG a,R_M128 b){return x86(955,a,b);}
enc punpcklbw(MMREG a,MMREG b){return x86(956,a,b);}
enc punpcklbw(MMREG a,MEM64 b){return x86(956,a,b);}
enc punpcklbw(MMREG a,R_M64 b){return x86(956,a,b);}
enc punpcklwd(MMREG a,MMREG b){return x86(957,a,b);}
enc punpcklwd(MMREG a,MEM64 b){return x86(957,a,b);}
enc punpcklwd(MMREG a,R_M64 b){return x86(957,a,b);}
enc punpckldq(MMREG a,MMREG b){return x86(958,a,b);}
enc punpckldq(MMREG a,MEM64 b){return x86(958,a,b);}
enc punpckldq(MMREG a,R_M64 b){return x86(958,a,b);}
enc punpcklbw(XMMREG a,XMMREG b){return x86(959,a,b);}
enc punpcklbw(XMMREG a,MEM128 b){return x86(959,a,b);}
enc punpcklbw(XMMREG a,R_M128 b){return x86(959,a,b);}
enc punpcklwd(XMMREG a,XMMREG b){return x86(960,a,b);}
enc punpcklwd(XMMREG a,MEM128 b){return x86(960,a,b);}
enc punpcklwd(XMMREG a,R_M128 b){return x86(960,a,b);}
enc punpckldq(XMMREG a,XMMREG b){return x86(961,a,b);}
enc punpckldq(XMMREG a,MEM128 b){return x86(961,a,b);}
enc punpckldq(XMMREG a,R_M128 b){return x86(961,a,b);}
enc punpcklqdq(XMMREG a,XMMREG b){return x86(962,a,b);}
enc punpcklqdq(XMMREG a,MEM128 b){return x86(962,a,b);}
enc punpcklqdq(XMMREG a,R_M128 b){return x86(962,a,b);}
enc push(REG16 a){return x86(963,a);}
enc push(REG32 a){return x86(964,a);}
enc push(MEM16 a){return x86(965,a);}
enc push(R_M16 a){return x86(965,a);}
enc push(MEM32 a){return x86(966,a);}
enc push(R_M32 a){return x86(966,a);}
enc push(char a){return x86(967,(IMM)a);}
enc push(short a){return x86(968,(IMM)a);}
enc push(REF a){return x86(969,a);}
enc push(int a){return x86(969,(IMM)a);}
enc pusha(){return x86(970);}
enc pushad(){return x86(971);}
enc pushaw(){return x86(972);}
enc pushf(){return x86(973);}
enc pushfd(){return x86(974);}
enc pushfw(){return x86(975);}
enc pxor(MMREG a,MMREG b){return x86(976,a,b);}
enc pxor(MMREG a,MEM64 b){return x86(976,a,b);}
enc pxor(MMREG a,R_M64 b){return x86(976,a,b);}
enc pxor(XMMREG a,XMMREG b){return x86(977,a,b);}
enc pxor(XMMREG a,MEM128 b){return x86(977,a,b);}
enc pxor(XMMREG a,R_M128 b){return x86(977,a,b);}
enc rcl(REG8 a,CL b){return x86(979,a,b);}
enc rcl(MEM8 a,CL b){return x86(979,a,b);}
enc rcl(R_M8 a,CL b){return x86(979,a,b);}
enc rcl(REG8 a,char b){return x86(980,a,(IMM)b);}
enc rcl(AL a,char b){return x86(980,a,(IMM)b);}
enc rcl(CL a,char b){return x86(980,a,(IMM)b);}
enc rcl(MEM8 a,char b){return x86(980,a,(IMM)b);}
enc rcl(R_M8 a,char b){return x86(980,a,(IMM)b);}
enc rcl(REG16 a,CL b){return x86(982,a,b);}
enc rcl(MEM16 a,CL b){return x86(982,a,b);}
enc rcl(R_M16 a,CL b){return x86(982,a,b);}
enc rcl(REG16 a,char b){return x86(983,a,(IMM)b);}
enc rcl(MEM16 a,char b){return x86(983,a,(IMM)b);}
enc rcl(R_M16 a,char b){return x86(983,a,(IMM)b);}
enc rcl(REG32 a,CL b){return x86(985,a,b);}
enc rcl(MEM32 a,CL b){return x86(985,a,b);}
enc rcl(R_M32 a,CL b){return x86(985,a,b);}
enc rcl(REG32 a,char b){return x86(986,a,(IMM)b);}
enc rcl(MEM32 a,char b){return x86(986,a,(IMM)b);}
enc rcl(R_M32 a,char b){return x86(986,a,(IMM)b);}
enc rcr(REG8 a,CL b){return x86(988,a,b);}
enc rcr(MEM8 a,CL b){return x86(988,a,b);}
enc rcr(R_M8 a,CL b){return x86(988,a,b);}
enc rcr(REG8 a,char b){return x86(989,a,(IMM)b);}
enc rcr(AL a,char b){return x86(989,a,(IMM)b);}
enc rcr(CL a,char b){return x86(989,a,(IMM)b);}
enc rcr(MEM8 a,char b){return x86(989,a,(IMM)b);}
enc rcr(R_M8 a,char b){return x86(989,a,(IMM)b);}
enc rcr(REG16 a,CL b){return x86(991,a,b);}
enc rcr(MEM16 a,CL b){return x86(991,a,b);}
enc rcr(R_M16 a,CL b){return x86(991,a,b);}
enc rcr(REG16 a,char b){return x86(992,a,(IMM)b);}
enc rcr(MEM16 a,char b){return x86(992,a,(IMM)b);}
enc rcr(R_M16 a,char b){return x86(992,a,(IMM)b);}
enc rcr(REG32 a,CL b){return x86(994,a,b);}
enc rcr(MEM32 a,CL b){return x86(994,a,b);}
enc rcr(R_M32 a,CL b){return x86(994,a,b);}
enc rcr(REG32 a,char b){return x86(995,a,(IMM)b);}
enc rcr(MEM32 a,char b){return x86(995,a,(IMM)b);}
enc rcr(R_M32 a,char b){return x86(995,a,(IMM)b);}
enc rcpps(XMMREG a,XMMREG b){return x86(996,a,b);}
enc rcpps(XMMREG a,MEM128 b){return x86(996,a,b);}
enc rcpps(XMMREG a,R_M128 b){return x86(996,a,b);}
enc rcpss(XMMREG a,XMMREG b){return x86(997,a,b);}
enc rcpss(XMMREG a,MEM32 b){return x86(997,a,b);}
enc rcpss(XMMREG a,XMM32 b){return x86(997,a,b);}
enc rdmsr(){return x86(998);}
enc rdpmc(){return x86(999);}
enc rdtsc(){return x86(1000);}
enc ret(){return x86(1001);}
enc ret(char a){return x86(1002,(IMM)a);}
enc ret(short a){return x86(1002,(IMM)a);}
enc rol(REG8 a,CL b){return x86(1004,a,b);}
enc rol(MEM8 a,CL b){return x86(1004,a,b);}
enc rol(R_M8 a,CL b){return x86(1004,a,b);}
enc rol(REG8 a,char b){return x86(1005,a,(IMM)b);}
enc rol(AL a,char b){return x86(1005,a,(IMM)b);}
enc rol(CL a,char b){return x86(1005,a,(IMM)b);}
enc rol(MEM8 a,char b){return x86(1005,a,(IMM)b);}
enc rol(R_M8 a,char b){return x86(1005,a,(IMM)b);}
enc rol(REG16 a,CL b){return x86(1007,a,b);}
enc rol(MEM16 a,CL b){return x86(1007,a,b);}
enc rol(R_M16 a,CL b){return x86(1007,a,b);}
enc rol(REG16 a,char b){return x86(1008,a,(IMM)b);}
enc rol(MEM16 a,char b){return x86(1008,a,(IMM)b);}
enc rol(R_M16 a,char b){return x86(1008,a,(IMM)b);}
enc rol(REG32 a,CL b){return x86(1010,a,b);}
enc rol(MEM32 a,CL b){return x86(1010,a,b);}
enc rol(R_M32 a,CL b){return x86(1010,a,b);}
enc rol(REG32 a,char b){return x86(1011,a,(IMM)b);}
enc rol(MEM32 a,char b){return x86(1011,a,(IMM)b);}
enc rol(R_M32 a,char b){return x86(1011,a,(IMM)b);}
enc ror(REG8 a,CL b){return x86(1013,a,b);}
enc ror(MEM8 a,CL b){return x86(1013,a,b);}
enc ror(R_M8 a,CL b){return x86(1013,a,b);}
enc ror(REG8 a,char b){return x86(1014,a,(IMM)b);}
enc ror(AL a,char b){return x86(1014,a,(IMM)b);}
enc ror(CL a,char b){return x86(1014,a,(IMM)b);}
enc ror(MEM8 a,char b){return x86(1014,a,(IMM)b);}
enc ror(R_M8 a,char b){return x86(1014,a,(IMM)b);}
enc ror(REG16 a,CL b){return x86(1016,a,b);}
enc ror(MEM16 a,CL b){return x86(1016,a,b);}
enc ror(R_M16 a,CL b){return x86(1016,a,b);}
enc ror(REG16 a,char b){return x86(1017,a,(IMM)b);}
enc ror(MEM16 a,char b){return x86(1017,a,(IMM)b);}
enc ror(R_M16 a,char b){return x86(1017,a,(IMM)b);}
enc ror(REG32 a,CL b){return x86(1019,a,b);}
enc ror(MEM32 a,CL b){return x86(1019,a,b);}
enc ror(R_M32 a,CL b){return x86(1019,a,b);}
enc ror(REG32 a,char b){return x86(1020,a,(IMM)b);}
enc ror(MEM32 a,char b){return x86(1020,a,(IMM)b);}
enc ror(R_M32 a,char b){return x86(1020,a,(IMM)b);}
enc rsm(){return x86(1021);}
enc rsqrtps(XMMREG a,XMMREG b){return x86(1022,a,b);}
enc rsqrtps(XMMREG a,MEM128 b){return x86(1022,a,b);}
enc rsqrtps(XMMREG a,R_M128 b){return x86(1022,a,b);}
enc rsqrtss(XMMREG a,XMMREG b){return x86(1023,a,b);}
enc rsqrtss(XMMREG a,MEM32 b){return x86(1023,a,b);}
enc rsqrtss(XMMREG a,XMM32 b){return x86(1023,a,b);}
enc sahf(){return x86(1024);}
enc sal(REG8 a,CL b){return x86(1026,a,b);}
enc sal(MEM8 a,CL b){return x86(1026,a,b);}
enc sal(R_M8 a,CL b){return x86(1026,a,b);}
enc sal(REG8 a,char b){return x86(1027,a,(IMM)b);}
enc sal(AL a,char b){return x86(1027,a,(IMM)b);}
enc sal(CL a,char b){return x86(1027,a,(IMM)b);}
enc sal(MEM8 a,char b){return x86(1027,a,(IMM)b);}
enc sal(R_M8 a,char b){return x86(1027,a,(IMM)b);}
enc sal(REG16 a,CL b){return x86(1029,a,b);}
enc sal(MEM16 a,CL b){return x86(1029,a,b);}
enc sal(R_M16 a,CL b){return x86(1029,a,b);}
enc sal(REG16 a,char b){return x86(1030,a,(IMM)b);}
enc sal(MEM16 a,char b){return x86(1030,a,(IMM)b);}
enc sal(R_M16 a,char b){return x86(1030,a,(IMM)b);}
enc sal(REG32 a,CL b){return x86(1032,a,b);}
enc sal(MEM32 a,CL b){return x86(1032,a,b);}
enc sal(R_M32 a,CL b){return x86(1032,a,b);}
enc sal(REG32 a,char b){return x86(1033,a,(IMM)b);}
enc sal(MEM32 a,char b){return x86(1033,a,(IMM)b);}
enc sal(R_M32 a,char b){return x86(1033,a,(IMM)b);}
enc sar(REG8 a,CL b){return x86(1035,a,b);}
enc sar(MEM8 a,CL b){return x86(1035,a,b);}
enc sar(R_M8 a,CL b){return x86(1035,a,b);}
enc sar(REG8 a,char b){return x86(1036,a,(IMM)b);}
enc sar(AL a,char b){return x86(1036,a,(IMM)b);}
enc sar(CL a,char b){return x86(1036,a,(IMM)b);}
enc sar(MEM8 a,char b){return x86(1036,a,(IMM)b);}
enc sar(R_M8 a,char b){return x86(1036,a,(IMM)b);}
enc sar(REG16 a,CL b){return x86(1038,a,b);}
enc sar(MEM16 a,CL b){return x86(1038,a,b);}
enc sar(R_M16 a,CL b){return x86(1038,a,b);}
enc sar(REG16 a,char b){return x86(1039,a,(IMM)b);}
enc sar(MEM16 a,char b){return x86(1039,a,(IMM)b);}
enc sar(R_M16 a,char b){return x86(1039,a,(IMM)b);}
enc sar(REG32 a,CL b){return x86(1041,a,b);}
enc sar(MEM32 a,CL b){return x86(1041,a,b);}
enc sar(R_M32 a,CL b){return x86(1041,a,b);}
enc sar(REG32 a,char b){return x86(1042,a,(IMM)b);}
enc sar(MEM32 a,char b){return x86(1042,a,(IMM)b);}
enc sar(R_M32 a,char b){return x86(1042,a,(IMM)b);}
enc sbb(REG8 a,REG8 b){return x86(1043,a,b);}
enc sbb(MEM8 a,REG8 b){return x86(1043,a,b);}
enc sbb(R_M8 a,REG8 b){return x86(1043,a,b);}
enc sbb(REG16 a,REG16 b){return x86(1044,a,b);}
enc sbb(MEM16 a,REG16 b){return x86(1044,a,b);}
enc sbb(R_M16 a,REG16 b){return x86(1044,a,b);}
enc sbb(REG32 a,REG32 b){return x86(1045,a,b);}
enc sbb(MEM32 a,REG32 b){return x86(1045,a,b);}
enc sbb(R_M32 a,REG32 b){return x86(1045,a,b);}
enc lock_sbb(MEM8 a,REG8 b){return x86(1046,a,b);}
enc lock_sbb(MEM16 a,REG16 b){return x86(1047,a,b);}
enc lock_sbb(MEM32 a,REG32 b){return x86(1048,a,b);}
enc sbb(REG8 a,MEM8 b){return x86(1049,a,b);}
enc sbb(REG8 a,R_M8 b){return x86(1049,a,b);}
enc sbb(REG16 a,MEM16 b){return x86(1050,a,b);}
enc sbb(REG16 a,R_M16 b){return x86(1050,a,b);}
enc sbb(REG32 a,MEM32 b){return x86(1051,a,b);}
enc sbb(REG32 a,R_M32 b){return x86(1051,a,b);}
enc sbb(REG8 a,char b){return x86(1052,a,(IMM)b);}
enc sbb(AL a,char b){return x86(1052,a,(IMM)b);}
enc sbb(CL a,char b){return x86(1052,a,(IMM)b);}
enc sbb(MEM8 a,char b){return x86(1052,a,(IMM)b);}
enc sbb(R_M8 a,char b){return x86(1052,a,(IMM)b);}
enc sbb(REG16 a,char b){return x86(1053,a,(IMM)b);}
enc sbb(REG16 a,short b){return x86(1053,a,(IMM)b);}
enc sbb(MEM16 a,char b){return x86(1053,a,(IMM)b);}
enc sbb(MEM16 a,short b){return x86(1053,a,(IMM)b);}
enc sbb(R_M16 a,char b){return x86(1053,a,(IMM)b);}
enc sbb(R_M16 a,short b){return x86(1053,a,(IMM)b);}
enc sbb(REG32 a,REF b){return x86(1054,a,b);}
enc sbb(REG32 a,int b){return x86(1054,a,(IMM)b);}
enc sbb(MEM32 a,REF b){return x86(1054,a,b);}
enc sbb(MEM32 a,int b){return x86(1054,a,(IMM)b);}
enc sbb(R_M32 a,REF b){return x86(1054,a,b);}
enc sbb(R_M32 a,int b){return x86(1054,a,(IMM)b);}
enc lock_sbb(MEM8 a,char b){return x86(1057,a,(IMM)b);}
enc lock_sbb(MEM16 a,char b){return x86(1058,a,(IMM)b);}
enc lock_sbb(MEM16 a,short b){return x86(1058,a,(IMM)b);}
enc lock_sbb(MEM32 a,REF b){return x86(1059,a,b);}
enc lock_sbb(MEM32 a,int b){return x86(1059,a,(IMM)b);}
enc scasb(){return x86(1065);}
enc scasw(){return x86(1066);}
enc scasd(){return x86(1067);}
enc rep_scasb(){return x86(1068);}
enc rep_scasw(){return x86(1069);}
enc rep_scasd(){return x86(1070);}
enc repe_scasb(){return x86(1071);}
enc repe_scasw(){return x86(1072);}
enc repe_scasd(){return x86(1073);}
enc repne_scasb(){return x86(1074);}
enc repne_scasw(){return x86(1075);}
enc repne_scasd(){return x86(1076);}
enc repz_scasb(){return x86(1077);}
enc repz_scasw(){return x86(1078);}
enc repz_scasd(){return x86(1079);}
enc repnz_scasb(){return x86(1080);}
enc repnz_scasw(){return x86(1081);}
enc repnz_scasd(){return x86(1082);}
enc seto(REG8 a){return x86(1083,a);}
enc seto(MEM8 a){return x86(1083,a);}
enc seto(R_M8 a){return x86(1083,a);}
enc setno(REG8 a){return x86(1084,a);}
enc setno(MEM8 a){return x86(1084,a);}
enc setno(R_M8 a){return x86(1084,a);}
enc setb(REG8 a){return x86(1085,a);}
enc setb(MEM8 a){return x86(1085,a);}
enc setb(R_M8 a){return x86(1085,a);}
enc setc(REG8 a){return x86(1086,a);}
enc setc(MEM8 a){return x86(1086,a);}
enc setc(R_M8 a){return x86(1086,a);}
enc setnea(REG8 a){return x86(1087,a);}
enc setnea(MEM8 a){return x86(1087,a);}
enc setnea(R_M8 a){return x86(1087,a);}
enc setae(REG8 a){return x86(1088,a);}
enc setae(MEM8 a){return x86(1088,a);}
enc setae(R_M8 a){return x86(1088,a);}
enc setnb(REG8 a){return x86(1089,a);}
enc setnb(MEM8 a){return x86(1089,a);}
enc setnb(R_M8 a){return x86(1089,a);}
enc setnc(REG8 a){return x86(1090,a);}
enc setnc(MEM8 a){return x86(1090,a);}
enc setnc(R_M8 a){return x86(1090,a);}
enc sete(REG8 a){return x86(1091,a);}
enc sete(MEM8 a){return x86(1091,a);}
enc sete(R_M8 a){return x86(1091,a);}
enc setz(REG8 a){return x86(1092,a);}
enc setz(MEM8 a){return x86(1092,a);}
enc setz(R_M8 a){return x86(1092,a);}
enc setne(REG8 a){return x86(1093,a);}
enc setne(MEM8 a){return x86(1093,a);}
enc setne(R_M8 a){return x86(1093,a);}
enc setnz(REG8 a){return x86(1094,a);}
enc setnz(MEM8 a){return x86(1094,a);}
enc setnz(R_M8 a){return x86(1094,a);}
enc setbe(REG8 a){return x86(1095,a);}
enc setbe(MEM8 a){return x86(1095,a);}
enc setbe(R_M8 a){return x86(1095,a);}
enc setna(REG8 a){return x86(1096,a);}
enc setna(MEM8 a){return x86(1096,a);}
enc setna(R_M8 a){return x86(1096,a);}
enc seta(REG8 a){return x86(1097,a);}
enc seta(MEM8 a){return x86(1097,a);}
enc seta(R_M8 a){return x86(1097,a);}
enc setnbe(REG8 a){return x86(1098,a);}
enc setnbe(MEM8 a){return x86(1098,a);}
enc setnbe(R_M8 a){return x86(1098,a);}
enc sets(REG8 a){return x86(1099,a);}
enc sets(MEM8 a){return x86(1099,a);}
enc sets(R_M8 a){return x86(1099,a);}
enc setns(REG8 a){return x86(1100,a);}
enc setns(MEM8 a){return x86(1100,a);}
enc setns(R_M8 a){return x86(1100,a);}
enc setp(REG8 a){return x86(1101,a);}
enc setp(MEM8 a){return x86(1101,a);}
enc setp(R_M8 a){return x86(1101,a);}
enc setpe(REG8 a){return x86(1102,a);}
enc setpe(MEM8 a){return x86(1102,a);}
enc setpe(R_M8 a){return x86(1102,a);}
enc setnp(REG8 a){return x86(1103,a);}
enc setnp(MEM8 a){return x86(1103,a);}
enc setnp(R_M8 a){return x86(1103,a);}
enc setpo(REG8 a){return x86(1104,a);}
enc setpo(MEM8 a){return x86(1104,a);}
enc setpo(R_M8 a){return x86(1104,a);}
enc setl(REG8 a){return x86(1105,a);}
enc setl(MEM8 a){return x86(1105,a);}
enc setl(R_M8 a){return x86(1105,a);}
enc setnge(REG8 a){return x86(1106,a);}
enc setnge(MEM8 a){return x86(1106,a);}
enc setnge(R_M8 a){return x86(1106,a);}
enc setge(REG8 a){return x86(1107,a);}
enc setge(MEM8 a){return x86(1107,a);}
enc setge(R_M8 a){return x86(1107,a);}
enc setnl(REG8 a){return x86(1108,a);}
enc setnl(MEM8 a){return x86(1108,a);}
enc setnl(R_M8 a){return x86(1108,a);}
enc setle(REG8 a){return x86(1109,a);}
enc setle(MEM8 a){return x86(1109,a);}
enc setle(R_M8 a){return x86(1109,a);}
enc setng(REG8 a){return x86(1110,a);}
enc setng(MEM8 a){return x86(1110,a);}
enc setng(R_M8 a){return x86(1110,a);}
enc setg(REG8 a){return x86(1111,a);}
enc setg(MEM8 a){return x86(1111,a);}
enc setg(R_M8 a){return x86(1111,a);}
enc setnle(REG8 a){return x86(1112,a);}
enc setnle(MEM8 a){return x86(1112,a);}
enc setnle(R_M8 a){return x86(1112,a);}
enc sfence(){return x86(1113);}
enc shl(REG8 a,CL b){return x86(1115,a,b);}
enc shl(MEM8 a,CL b){return x86(1115,a,b);}
enc shl(R_M8 a,CL b){return x86(1115,a,b);}
enc shl(REG8 a,char b){return x86(1116,a,(IMM)b);}
enc shl(AL a,char b){return x86(1116,a,(IMM)b);}
enc shl(CL a,char b){return x86(1116,a,(IMM)b);}
enc shl(MEM8 a,char b){return x86(1116,a,(IMM)b);}
enc shl(R_M8 a,char b){return x86(1116,a,(IMM)b);}
enc shl(REG16 a,CL b){return x86(1118,a,b);}
enc shl(MEM16 a,CL b){return x86(1118,a,b);}
enc shl(R_M16 a,CL b){return x86(1118,a,b);}
enc shl(REG16 a,char b){return x86(1119,a,(IMM)b);}
enc shl(MEM16 a,char b){return x86(1119,a,(IMM)b);}
enc shl(R_M16 a,char b){return x86(1119,a,(IMM)b);}
enc shl(REG32 a,CL b){return x86(1121,a,b);}
enc shl(MEM32 a,CL b){return x86(1121,a,b);}
enc shl(R_M32 a,CL b){return x86(1121,a,b);}
enc shl(REG32 a,char b){return x86(1122,a,(IMM)b);}
enc shl(MEM32 a,char b){return x86(1122,a,(IMM)b);}
enc shl(R_M32 a,char b){return x86(1122,a,(IMM)b);}
enc shr(REG8 a,CL b){return x86(1124,a,b);}
enc shr(MEM8 a,CL b){return x86(1124,a,b);}
enc shr(R_M8 a,CL b){return x86(1124,a,b);}
enc shr(REG8 a,char b){return x86(1125,a,(IMM)b);}
enc shr(AL a,char b){return x86(1125,a,(IMM)b);}
enc shr(CL a,char b){return x86(1125,a,(IMM)b);}
enc shr(MEM8 a,char b){return x86(1125,a,(IMM)b);}
enc shr(R_M8 a,char b){return x86(1125,a,(IMM)b);}
enc shr(REG16 a,CL b){return x86(1127,a,b);}
enc shr(MEM16 a,CL b){return x86(1127,a,b);}
enc shr(R_M16 a,CL b){return x86(1127,a,b);}
enc shr(REG16 a,char b){return x86(1128,a,(IMM)b);}
enc shr(MEM16 a,char b){return x86(1128,a,(IMM)b);}
enc shr(R_M16 a,char b){return x86(1128,a,(IMM)b);}
enc shr(REG32 a,CL b){return x86(1130,a,b);}
enc shr(MEM32 a,CL b){return x86(1130,a,b);}
enc shr(R_M32 a,CL b){return x86(1130,a,b);}
enc shr(REG32 a,char b){return x86(1131,a,(IMM)b);}
enc shr(MEM32 a,char b){return x86(1131,a,(IMM)b);}
enc shr(R_M32 a,char b){return x86(1131,a,(IMM)b);}
enc shld(REG16 a,REG16 b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(REG16 a,AX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(REG16 a,DX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(REG16 a,CX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(AX a,REG16 b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(DX a,REG16 b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(CX a,REG16 b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(MEM16 a,REG16 b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(MEM16 a,AX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(MEM16 a,DX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(MEM16 a,CX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(R_M16 a,REG16 b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(R_M16 a,AX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(R_M16 a,DX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(R_M16 a,CX b,char c){return x86(1132,a,b,(IMM)c);}
enc shld(REG32 a,REG32 b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(REG32 a,EAX b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(REG32 a,ECX b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(EAX a,REG32 b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(ECX a,REG32 b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(MEM32 a,REG32 b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(MEM32 a,EAX b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(MEM32 a,ECX b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(R_M32 a,REG32 b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(R_M32 a,EAX b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(R_M32 a,ECX b,char c){return x86(1133,a,b,(IMM)c);}
enc shld(REG16 a,REG16 b,CL c){return x86(1134,a,b,c);}
enc shld(MEM16 a,REG16 b,CL c){return x86(1134,a,b,c);}
enc shld(R_M16 a,REG16 b,CL c){return x86(1134,a,b,c);}
enc shld(REG32 a,REG32 b,CL c){return x86(1135,a,b,c);}
enc shld(MEM32 a,REG32 b,CL c){return x86(1135,a,b,c);}
enc shld(R_M32 a,REG32 b,CL c){return x86(1135,a,b,c);}
enc shrd(REG16 a,REG16 b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(REG16 a,AX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(REG16 a,DX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(REG16 a,CX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(AX a,REG16 b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(DX a,REG16 b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(CX a,REG16 b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(MEM16 a,REG16 b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(MEM16 a,AX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(MEM16 a,DX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(MEM16 a,CX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(R_M16 a,REG16 b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(R_M16 a,AX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(R_M16 a,DX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(R_M16 a,CX b,char c){return x86(1136,a,b,(IMM)c);}
enc shrd(REG32 a,REG32 b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(REG32 a,EAX b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(REG32 a,ECX b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(EAX a,REG32 b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(ECX a,REG32 b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(MEM32 a,REG32 b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(MEM32 a,EAX b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(MEM32 a,ECX b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(R_M32 a,REG32 b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(R_M32 a,EAX b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(R_M32 a,ECX b,char c){return x86(1137,a,b,(IMM)c);}
enc shrd(REG16 a,REG16 b,CL c){return x86(1138,a,b,c);}
enc shrd(MEM16 a,REG16 b,CL c){return x86(1138,a,b,c);}
enc shrd(R_M16 a,REG16 b,CL c){return x86(1138,a,b,c);}
enc shrd(REG32 a,REG32 b,CL c){return x86(1139,a,b,c);}
enc shrd(MEM32 a,REG32 b,CL c){return x86(1139,a,b,c);}
enc shrd(R_M32 a,REG32 b,CL c){return x86(1139,a,b,c);}
enc shufpd(XMMREG a,XMMREG b,char c){return x86(1140,a,b,(IMM)c);}
enc shufpd(XMMREG a,MEM128 b,char c){return x86(1140,a,b,(IMM)c);}
enc shufpd(XMMREG a,R_M128 b,char c){return x86(1140,a,b,(IMM)c);}
enc shufps(XMMREG a,XMMREG b,char c){return x86(1141,a,b,(IMM)c);}
enc shufps(XMMREG a,MEM128 b,char c){return x86(1141,a,b,(IMM)c);}
enc shufps(XMMREG a,R_M128 b,char c){return x86(1141,a,b,(IMM)c);}
enc smint(){return x86(1142);}
enc smintold(){return x86(1143);}
enc sqrtpd(XMMREG a,XMMREG b){return x86(1144,a,b);}
enc sqrtpd(XMMREG a,MEM128 b){return x86(1144,a,b);}
enc sqrtpd(XMMREG a,R_M128 b){return x86(1144,a,b);}
enc sqrtps(XMMREG a,XMMREG b){return x86(1145,a,b);}
enc sqrtps(XMMREG a,MEM128 b){return x86(1145,a,b);}
enc sqrtps(XMMREG a,R_M128 b){return x86(1145,a,b);}
enc sqrtsd(XMMREG a,XMMREG b){return x86(1146,a,b);}
enc sqrtsd(XMMREG a,MEM64 b){return x86(1146,a,b);}
enc sqrtsd(XMMREG a,XMM64 b){return x86(1146,a,b);}
enc sqrtss(XMMREG a,XMMREG b){return x86(1147,a,b);}
enc sqrtss(XMMREG a,MEM32 b){return x86(1147,a,b);}
enc sqrtss(XMMREG a,XMM32 b){return x86(1147,a,b);}
enc stc(){return x86(1148);}
enc std(){return x86(1149);}
enc sti(){return x86(1150);}
enc stmxcsr(MEM32 a){return x86(1151,a);}
enc stosb(){return x86(1152);}
enc stosw(){return x86(1153);}
enc stosd(){return x86(1154);}
enc rep_stosb(){return x86(1155);}
enc rep_stosw(){return x86(1156);}
enc rep_stosd(){return x86(1157);}
enc sub(REG8 a,REG8 b){return x86(1158,a,b);}
enc sub(MEM8 a,REG8 b){return x86(1158,a,b);}
enc sub(R_M8 a,REG8 b){return x86(1158,a,b);}
enc sub(REG16 a,REG16 b){return x86(1159,a,b);}
enc sub(MEM16 a,REG16 b){return x86(1159,a,b);}
enc sub(R_M16 a,REG16 b){return x86(1159,a,b);}
enc sub(REG32 a,REG32 b){return x86(1160,a,b);}
enc sub(MEM32 a,REG32 b){return x86(1160,a,b);}
enc sub(R_M32 a,REG32 b){return x86(1160,a,b);}
enc lock_sub(MEM8 a,REG8 b){return x86(1161,a,b);}
enc lock_sub(MEM16 a,REG16 b){return x86(1162,a,b);}
enc lock_sub(MEM32 a,REG32 b){return x86(1163,a,b);}
enc sub(REG8 a,MEM8 b){return x86(1164,a,b);}
enc sub(REG8 a,R_M8 b){return x86(1164,a,b);}
enc sub(REG16 a,MEM16 b){return x86(1165,a,b);}
enc sub(REG16 a,R_M16 b){return x86(1165,a,b);}
enc sub(REG32 a,MEM32 b){return x86(1166,a,b);}
enc sub(REG32 a,R_M32 b){return x86(1166,a,b);}
enc sub(REG8 a,char b){return x86(1167,a,(IMM)b);}
enc sub(AL a,char b){return x86(1167,a,(IMM)b);}
enc sub(CL a,char b){return x86(1167,a,(IMM)b);}
enc sub(MEM8 a,char b){return x86(1167,a,(IMM)b);}
enc sub(R_M8 a,char b){return x86(1167,a,(IMM)b);}
enc sub(REG16 a,char b){return x86(1168,a,(IMM)b);}
enc sub(REG16 a,short b){return x86(1168,a,(IMM)b);}
enc sub(MEM16 a,char b){return x86(1168,a,(IMM)b);}
enc sub(MEM16 a,short b){return x86(1168,a,(IMM)b);}
enc sub(R_M16 a,char b){return x86(1168,a,(IMM)b);}
enc sub(R_M16 a,short b){return x86(1168,a,(IMM)b);}
enc sub(REG32 a,REF b){return x86(1169,a,b);}
enc sub(REG32 a,int b){return x86(1169,a,(IMM)b);}
enc sub(MEM32 a,REF b){return x86(1169,a,b);}
enc sub(MEM32 a,int b){return x86(1169,a,(IMM)b);}
enc sub(R_M32 a,REF b){return x86(1169,a,b);}
enc sub(R_M32 a,int b){return x86(1169,a,(IMM)b);}
enc lock_sub(MEM8 a,char b){return x86(1172,a,(IMM)b);}
enc lock_sub(MEM16 a,char b){return x86(1173,a,(IMM)b);}
enc lock_sub(MEM16 a,short b){return x86(1173,a,(IMM)b);}
enc lock_sub(MEM32 a,REF b){return x86(1174,a,b);}
enc lock_sub(MEM32 a,int b){return x86(1174,a,(IMM)b);}
enc subpd(XMMREG a,XMMREG b){return x86(1180,a,b);}
enc subpd(XMMREG a,MEM128 b){return x86(1180,a,b);}
enc subpd(XMMREG a,R_M128 b){return x86(1180,a,b);}
enc subps(XMMREG a,XMMREG b){return x86(1181,a,b);}
enc subps(XMMREG a,MEM128 b){return x86(1181,a,b);}
enc subps(XMMREG a,R_M128 b){return x86(1181,a,b);}
enc subsd(XMMREG a,XMMREG b){return x86(1182,a,b);}
enc subsd(XMMREG a,MEM64 b){return x86(1182,a,b);}
enc subsd(XMMREG a,XMM64 b){return x86(1182,a,b);}
enc subss(XMMREG a,XMMREG b){return x86(1183,a,b);}
enc subss(XMMREG a,MEM32 b){return x86(1183,a,b);}
enc subss(XMMREG a,XMM32 b){return x86(1183,a,b);}
enc sysenter(){return x86(1184);}
enc test(REG8 a,REG8 b){return x86(1185,a,b);}
enc test(MEM8 a,REG8 b){return x86(1185,a,b);}
enc test(R_M8 a,REG8 b){return x86(1185,a,b);}
enc test(REG16 a,REG16 b){return x86(1186,a,b);}
enc test(MEM16 a,REG16 b){return x86(1186,a,b);}
enc test(R_M16 a,REG16 b){return x86(1186,a,b);}
enc test(REG32 a,REG32 b){return x86(1187,a,b);}
enc test(MEM32 a,REG32 b){return x86(1187,a,b);}
enc test(R_M32 a,REG32 b){return x86(1187,a,b);}
enc test(REG8 a,char b){return x86(1188,a,(IMM)b);}
enc test(AL a,char b){return x86(1188,a,(IMM)b);}
enc test(CL a,char b){return x86(1188,a,(IMM)b);}
enc test(MEM8 a,char b){return x86(1188,a,(IMM)b);}
enc test(R_M8 a,char b){return x86(1188,a,(IMM)b);}
enc test(REG16 a,char b){return x86(1189,a,(IMM)b);}
enc test(REG16 a,short b){return x86(1189,a,(IMM)b);}
enc test(MEM16 a,char b){return x86(1189,a,(IMM)b);}
enc test(MEM16 a,short b){return x86(1189,a,(IMM)b);}
enc test(R_M16 a,char b){return x86(1189,a,(IMM)b);}
enc test(R_M16 a,short b){return x86(1189,a,(IMM)b);}
enc test(REG32 a,REF b){return x86(1190,a,b);}
enc test(REG32 a,int b){return x86(1190,a,(IMM)b);}
enc test(MEM32 a,REF b){return x86(1190,a,b);}
enc test(MEM32 a,int b){return x86(1190,a,(IMM)b);}
enc test(R_M32 a,REF b){return x86(1190,a,b);}
enc test(R_M32 a,int b){return x86(1190,a,(IMM)b);}
enc ucomisd(XMMREG a,XMMREG b){return x86(1194,a,b);}
enc ucomisd(XMMREG a,MEM64 b){return x86(1194,a,b);}
enc ucomisd(XMMREG a,XMM64 b){return x86(1194,a,b);}
enc ucomiss(XMMREG a,XMMREG b){return x86(1195,a,b);}
enc ucomiss(XMMREG a,MEM32 b){return x86(1195,a,b);}
enc ucomiss(XMMREG a,XMM32 b){return x86(1195,a,b);}
enc ud2(){return x86(1196);}
enc unpckhpd(XMMREG a,XMMREG b){return x86(1197,a,b);}
enc unpckhpd(XMMREG a,MEM128 b){return x86(1197,a,b);}
enc unpckhpd(XMMREG a,R_M128 b){return x86(1197,a,b);}
enc unpckhps(XMMREG a,XMMREG b){return x86(1198,a,b);}
enc unpckhps(XMMREG a,MEM128 b){return x86(1198,a,b);}
enc unpckhps(XMMREG a,R_M128 b){return x86(1198,a,b);}
enc unpcklpd(XMMREG a,XMMREG b){return x86(1199,a,b);}
enc unpcklpd(XMMREG a,MEM128 b){return x86(1199,a,b);}
enc unpcklpd(XMMREG a,R_M128 b){return x86(1199,a,b);}
enc unpcklps(XMMREG a,XMMREG b){return x86(1200,a,b);}
enc unpcklps(XMMREG a,MEM128 b){return x86(1200,a,b);}
enc unpcklps(XMMREG a,R_M128 b){return x86(1200,a,b);}
enc wait(){return x86(1201);}
enc wrmsr(){return x86(1202);}
enc xadd(REG8 a,REG8 b){return x86(1203,a,b);}
enc xadd(MEM8 a,REG8 b){return x86(1203,a,b);}
enc xadd(R_M8 a,REG8 b){return x86(1203,a,b);}
enc xadd(REG16 a,REG16 b){return x86(1204,a,b);}
enc xadd(MEM16 a,REG16 b){return x86(1204,a,b);}
enc xadd(R_M16 a,REG16 b){return x86(1204,a,b);}
enc xadd(REG32 a,REG32 b){return x86(1205,a,b);}
enc xadd(MEM32 a,REG32 b){return x86(1205,a,b);}
enc xadd(R_M32 a,REG32 b){return x86(1205,a,b);}
enc lock_xadd(MEM8 a,REG8 b){return x86(1206,a,b);}
enc lock_xadd(MEM16 a,REG16 b){return x86(1207,a,b);}
enc lock_xadd(MEM32 a,REG32 b){return x86(1208,a,b);}
enc xchg(REG8 a,REG8 b){return x86(1209,a,b);}
enc xchg(REG8 a,MEM8 b){return x86(1209,a,b);}
enc xchg(REG8 a,R_M8 b){return x86(1209,a,b);}
enc xchg(REG16 a,REG16 b){return x86(1210,a,b);}
enc xchg(REG16 a,MEM16 b){return x86(1210,a,b);}
enc xchg(REG16 a,R_M16 b){return x86(1210,a,b);}
enc xchg(REG32 a,REG32 b){return x86(1211,a,b);}
enc xchg(REG32 a,MEM32 b){return x86(1211,a,b);}
enc xchg(REG32 a,R_M32 b){return x86(1211,a,b);}
enc xchg(MEM8 a,REG8 b){return x86(1212,a,b);}
enc xchg(R_M8 a,REG8 b){return x86(1212,a,b);}
enc xchg(MEM16 a,REG16 b){return x86(1213,a,b);}
enc xchg(R_M16 a,REG16 b){return x86(1213,a,b);}
enc xchg(MEM32 a,REG32 b){return x86(1214,a,b);}
enc xchg(R_M32 a,REG32 b){return x86(1214,a,b);}
enc lock_xchg(MEM8 a,REG8 b){return x86(1215,a,b);}
enc lock_xchg(MEM16 a,REG16 b){return x86(1216,a,b);}
enc lock_xchg(MEM32 a,REG32 b){return x86(1217,a,b);}
enc xlatb(){return x86(1222);}
enc xor(REG8 a,REG8 b){return x86(1223,a,b);}
enc xor(MEM8 a,REG8 b){return x86(1223,a,b);}
enc xor(R_M8 a,REG8 b){return x86(1223,a,b);}
enc xor(REG16 a,REG16 b){return x86(1224,a,b);}
enc xor(MEM16 a,REG16 b){return x86(1224,a,b);}
enc xor(R_M16 a,REG16 b){return x86(1224,a,b);}
enc xor(REG32 a,REG32 b){return x86(1225,a,b);}
enc xor(MEM32 a,REG32 b){return x86(1225,a,b);}
enc xor(R_M32 a,REG32 b){return x86(1225,a,b);}
enc lock_xor(MEM8 a,REG8 b){return x86(1226,a,b);}
enc lock_xor(MEM16 a,REG16 b){return x86(1227,a,b);}
enc lock_xor(MEM32 a,REG32 b){return x86(1228,a,b);}
enc xor(REG8 a,MEM8 b){return x86(1229,a,b);}
enc xor(REG8 a,R_M8 b){return x86(1229,a,b);}
enc xor(REG16 a,MEM16 b){return x86(1230,a,b);}
enc xor(REG16 a,R_M16 b){return x86(1230,a,b);}
enc xor(REG32 a,MEM32 b){return x86(1231,a,b);}
enc xor(REG32 a,R_M32 b){return x86(1231,a,b);}
enc xor(REG8 a,char b){return x86(1232,a,(IMM)b);}
enc xor(AL a,char b){return x86(1232,a,(IMM)b);}
enc xor(CL a,char b){return x86(1232,a,(IMM)b);}
enc xor(MEM8 a,char b){return x86(1232,a,(IMM)b);}
enc xor(R_M8 a,char b){return x86(1232,a,(IMM)b);}
enc xor(REG16 a,char b){return x86(1233,a,(IMM)b);}
enc xor(REG16 a,short b){return x86(1233,a,(IMM)b);}
enc xor(MEM16 a,char b){return x86(1233,a,(IMM)b);}
enc xor(MEM16 a,short b){return x86(1233,a,(IMM)b);}
enc xor(R_M16 a,char b){return x86(1233,a,(IMM)b);}
enc xor(R_M16 a,short b){return x86(1233,a,(IMM)b);}
enc xor(REG32 a,REF b){return x86(1234,a,b);}
enc xor(REG32 a,int b){return x86(1234,a,(IMM)b);}
enc xor(MEM32 a,REF b){return x86(1234,a,b);}
enc xor(MEM32 a,int b){return x86(1234,a,(IMM)b);}
enc xor(R_M32 a,REF b){return x86(1234,a,b);}
enc xor(R_M32 a,int b){return x86(1234,a,(IMM)b);}
enc lock_xor(MEM8 a,char b){return x86(1237,a,(IMM)b);}
enc lock_xor(MEM16 a,char b){return x86(1238,a,(IMM)b);}
enc lock_xor(MEM16 a,short b){return x86(1238,a,(IMM)b);}
enc lock_xor(MEM32 a,REF b){return x86(1239,a,b);}
enc lock_xor(MEM32 a,int b){return x86(1239,a,(IMM)b);}
enc xorps(XMMREG a,XMMREG b){return x86(1245,a,b);}
enc xorps(XMMREG a,MEM128 b){return x86(1245,a,b);}
enc xorps(XMMREG a,R_M128 b){return x86(1245,a,b);}
enc db(){return x86(1246);}
enc dw(){return x86(1247);}
enc dd(){return x86(1248);}
enc db(char a){return x86(1249,(IMM)a);}
enc dw(char a){return x86(1250,(IMM)a);}
enc dw(short a){return x86(1250,(IMM)a);}
enc dd(REF a){return x86(1251,a);}
enc dd(int a){return x86(1251,(IMM)a);}
enc db(MEM8 a){return x86(1252,a);}
enc db(MEM16 a){return x86(1252,a);}
enc db(MEM32 a){return x86(1252,a);}
enc db(MEM64 a){return x86(1252,a);}
enc db(MEM128 a){return x86(1252,a);}
enc dw(MEM8 a){return x86(1253,a);}
enc dw(MEM16 a){return x86(1253,a);}
enc dw(MEM32 a){return x86(1253,a);}
enc dw(MEM64 a){return x86(1253,a);}
enc dw(MEM128 a){return x86(1253,a);}
enc dd(MEM8 a){return x86(1254,a);}
enc dd(MEM16 a){return x86(1254,a);}
enc dd(MEM32 a){return x86(1254,a);}
enc dd(MEM64 a){return x86(1254,a);}
enc dd(MEM128 a){return x86(1254,a);}
enc db(REF a){return x86(1255,a);}
enc db(char* a){return x86(1255,(STR)a);}
enc align(REF a){return x86(1256,a);}
enc align(int a){return x86(1256,(IMM)a);}

#undef enc

#endif   // SOFTWIRE_NO_INTRINSICS
