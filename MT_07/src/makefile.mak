#******************************************************************************
#*
#*  makefile.mak
#*    makefile for building with WDK
#*
#*  Copyright (C) 2011-2012 XhmikosR
#*
#*  This program is free software: you can redistribute it and/or modify
#*  it under the terms of the GNU General Public License as published by
#*  the Free Software Foundation, either version 3 of the License, or
#*  (at your option) any later version.
#*
#*  This program is distributed in the hope that it will be useful,
#*  but WITHOUT ANY WARRANTY; without even the implied warranty of
#*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#*  GNU General Public License for more details.
#*
#*  You should have received a copy of the GNU General Public License
#*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#*
#*
#*  Use build_wdk.bat and set there your WDK directory.
#*
#******************************************************************************


# Remove the .SILENT directive in order to display all the commands
.SILENT:


CC = cl.exe
LD = link.exe
RC = rc.exe

SRC       = .
BINDIR    = WDK
OBJDIR    = $(BINDIR)\obj
EXE       = $(BINDIR)\MT.dll


DEFINES   = /D "_WINDOWS" /D "NDEBUG" /D "WIN32" /D "_WIN32_WINNT=0x0500" /D "_UNICODE" \
            /D "UNICODE"
CPPFLAGS  = /nologo /c /Fo"$(OBJDIR)/" /W3 /EHsc /MD /O2 /Oy /GL /MP /arch:SSE $(DEFINES)
LDFLAGS   = /NOLOGO /WX /INCREMENTAL:NO /RELEASE /OPT:REF /OPT:ICF /SUBSYSTEM:WINDOWS,5.0 \
            /LARGEADDRESSAWARE /DLL /MACHINE:X86 /LTCG msvcrt_win2000.obj
RFLAGS    = /l 0x0409 /d "WIN32" /d "NDEBUG"


# Targets
BUILD:	CHECKDIRS $(EXE)

CHECKDIRS:
	IF NOT EXIST "$(OBJDIR)" MD "$(OBJDIR)"

CLEAN:
	ECHO Cleaning... & ECHO.
	IF EXIST "$(EXE)"            DEL "$(EXE)"
	IF EXIST "$(OBJDIR)\*.obj"   DEL "$(OBJDIR)\*.obj"
	IF EXIST "$(BINDIR)\MT.lib"  DEL "$(BINDIR)\MT.lib"
	IF EXIST "$(BINDIR)\MT.exp"  DEL "$(BINDIR)\MT.exp"
	IF EXIST "$(BINDIR)\MT.pdb"  DEL "$(BINDIR)\MT.pdb"
	IF EXIST "$(OBJDIR)\MT.res"  DEL "$(OBJDIR)\MT.res"
	-IF EXIST "$(OBJDIR)"        RD /Q "$(OBJDIR)"
	-IF EXIST "$(BINDIR)"        RD /Q "$(BINDIR)"

REBUILD:	CLEAN BUILD


# Object files
OBJECTS = \
    $(OBJDIR)\MT.obj \
    $(OBJDIR)\MT.res \
    $(OBJDIR)\MTi.obj \
    $(OBJDIR)\MTsource.obj \
    $(OBJDIR)\stdafx.obj \
    $(OBJDIR)\utility.obj


# Batch rule
{$(SRC)\}.cpp{$(OBJDIR)}.obj::
    $(CC) $(CPPFLAGS) /Tp $<


# Commands
$(EXE): $(OBJECTS)
	$(RC) $(RFLAGS) /fo"$(OBJDIR)\MT.res" "$(SRC)\MT.rc" >NUL
	$(LD) $(LDFLAGS) /OUT:"$(EXE)" $(OBJECTS)


# Dependencies
$(OBJDIR)\MT.obj: \
    $(SRC)\MT.cpp \
    $(SRC)\stdafx.h \
    $(SRC)\MT.h \
    $(SRC)\MTi.h \
    $(SRC)\MTsource.h \
    $(SRC)\utility.h

$(OBJDIR)\MTi.obj: \
    $(SRC)\MTi.cpp \
    $(SRC)\stdafx.h \
    $(SRC)\MTi.h \
    $(SRC)\utility.h

$(OBJDIR)\MTsource.obj: \
    $(SRC)\MTsource.cpp \
    $(SRC)\stdafx.h \
    $(SRC)\MTsource.h \
    $(SRC)\utility.h

$(OBJDIR)\stdafx.obj: \
    $(SRC)\stdafx.cpp \
    $(SRC)\stdafx.h

$(OBJDIR)\utility.obj: \
    $(SRC)\utility.cpp \
    $(SRC)\utility.h

$(OBJDIR)\MT.res: \
    $(SRC)\MT.rc \
    $(SRC)\resource.h
