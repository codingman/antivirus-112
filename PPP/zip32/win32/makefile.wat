# WMAKE makefile for Windows 95 and Windows NT (Intel only)
# using Watcom C/C++ v11.0+, by Paul Kienitz, last revised 22 Feb 05.
# Makes Zip.exe, ZipNote.exe, ZipCloak.exe, and ZipSplit.exe.
#
# Invoke from Zip source dir with "WMAKE -F WIN32\MAKEFILE.WAT [targets]"
# To build with debug info use "WMAKE DEBUG=1 ..."
# To build without any assembly modules use "WMAKE NOASM=1 ..."
#
# Other options to be fed to the compiler can be specified in an environment
# variable called LOCAL_ZIP.  One possibility "-DDYN_ALLOC", but currently
# this is not supported unless NOASM is also used.

variation = $(%LOCAL_ZIP)

# Stifle annoying "Delete this file?" questions when errors occur:
.ERASE

.EXTENSIONS:
.EXTENSIONS: .exe .obj .c .h .asm

# We maintain multiple sets of object files in different directories so that
# we can compile msdos, dos/4gw, and win32 versions of Zip without their
# object files interacting.  The following var must be a directory name
# ending with a backslash.  All object file names must include this macro
# at the beginning, for example "$(O)foo.obj".

!ifdef DEBUG
OBDIR = od32w
!else
OBDIR = ob32w
!endif
O = $(OBDIR)\   # comment here so backslash won't continue the line

# The assembly hot-spot code in crc_i386.asm and match32.asm is optional.
# This section controls its usage.

!ifdef NOASM
asmob = $(O)crc32.obj           # C source
cvars = $+$(cvars)$- -DNO_ASM   # otherwise ASM_CRC might default on!
# "$+$(foo)$-" means expand foo as it has been defined up to now; normally,
# this make defers inner expansion until the outer macro is expanded.
!else  # !NOASM
asmob = $(O)match32.obj $(O)crc_i386.obj
cvars = $+$(cvars)$- -DASMV -DASM_CRC
!endif

# Our object files.  OBJZ is for Zip, OBJC is for ZipCloak, OBJN is for
# ZipNote, and OBJS is for ZipSplit:

OBJZ3 = $(O)zip.obj $(O)crypt.obj $(O)ttyio.obj $(O)trees.obj $(O)zipup.obj
OBJZ2 = $(OBJZ3) $(O)util.obj $(O)zipfile.obj $(O)fileio.obj $(O)deflate.obj
OBJZ1 = $(OBJZ2) $(O)globals.obj $(O)crctab.obj $(asmob)
OBJZ  = $(OBJZ1) $(O)win32zip.obj $(O)win32.obj $(O)nt.obj

OBJU1 = $(O)zipfile_.obj $(O)fileio_.obj $(O)util_.obj $(O)globals.obj
OBJ_U = $(OBJU1) $(O)win32_.obj

OBJC  = $(O)zipcloak.obj $(O)crctab.obj $(O)crypt_.obj $(O)ttyio.obj $(OBJ_U)

OBJN  = $(O)zipnote.obj $(OBJ_U)

OBJS  = $(O)zipsplit.obj $(OBJ_U)

# Common header files included by all C sources:

ZIP_H = zip.h ziperr.h tailor.h win32\osdep.h

# Now we have to pick out the proper compiler and options for it.

cc     = wcc386
link   = wlink
asm    = wasm
# Use Pentium Pro timings, register args, static strings in code:
cflags = -bt=NT -6r -zt -zq
aflags = -bt=NT -mf -3 -zq
lflags = sys NT
cvars  = $+$(cvars)$- -DWIN32 $(variation)
avars  = $+$(avars)$- $(variation)

# Specify optimizations, or a nonoptimized debugging version:

!ifdef DEBUG
cdebug = -od -d2
ldebug = d w all op symf
!else
cdebug = -s -obhikl+rt -oe=100 -zp8
# -oa helps slightly but might be dangerous.
ldebug = op el
!endif

# How to compile sources:
.c.obj:
	$(cc) $(cdebug) $(cflags) $(cvars) $[@ -fo=$@

# Here we go!  By default, make all targets:
all: Zip.exe ZipNote.exe ZipCloak.exe ZipSplit.exe

# Convenient shorthand options for single targets:
z:   Zip.exe       .SYMBOLIC
n:   ZipNote.exe   .SYMBOLIC
c:   ZipCloak.exe  .SYMBOLIC
s:   ZipSplit.exe  .SYMBOLIC

Zip.exe:	$(OBDIR) $(OBJZ)
	$(link) $(lflags) $(ldebug) name $@ file {$(OBJZ)}

ZipNote.exe:	$(OBDIR) $(OBJN)
	$(link) $(lflags) $(ldebug) name $@ file {$(OBJN)}

ZipCloak.exe:	$(OBDIR) $(OBJC)
	$(link) $(lflags) $(ldebug) name $@ file {$(OBJC)}

ZipSplit.exe:	$(OBDIR) $(OBJS)
	$(link) $(lflags) $(ldebug) name $@ file {$(OBJS)}

# Source dependencies:

$(O)crctab.obj:   crctab.c $(ZIP_H)
$(O)crc32.obj:    crc32.c $(ZIP_H)          # only used if NOASM
$(O)crypt.obj:    crypt.c $(ZIP_H) crypt.h ttyio.h
$(O)deflate.obj:  deflate.c $(ZIP_H)
$(O)fileio.obj:   fileio.c $(ZIP_H)
$(O)globals.obj:  globals.c $(ZIP_H)
$(O)trees.obj:    trees.c $(ZIP_H)
$(O)ttyio.obj:    ttyio.c $(ZIP_H) crypt.h ttyio.h
$(O)util.obj:     util.c $(ZIP_H)
$(O)zip.obj:      zip.c $(ZIP_H) crypt.h revision.h ttyio.h
$(O)zipfile.obj:  zipfile.c $(ZIP_H)
$(O)zipup.obj:    zipup.c $(ZIP_H) revision.h crypt.h win32\zipup.h
$(O)zipnote.obj:  zipnote.c $(ZIP_H) revision.h
$(O)zipcloak.obj: zipcloak.c $(ZIP_H) revision.h crypt.h ttyio.h
$(O)zipsplit.obj: zipsplit.c $(ZIP_H) revision.h

# Special case object files:

$(O)win32.obj:    win32\win32.c $(ZIP_H) win32\win32zip.h
	$(cc) $(cdebug) $(cflags) $(cvars) win32\win32.c -fo=$@

$(O)win32zip.obj: win32\win32zip.c $(ZIP_H) win32\win32zip.h win32\nt.h
	$(cc) $(cdebug) $(cflags) $(cvars) win32\win32zip.c -fo=$@

$(O)nt.obj:       win32\nt.c $(ZIP_H) win32\nt.h
	$(cc) $(cdebug) $(cflags) $(cvars) win32\nt.c -fo=$@

$(O)match32.obj:  win32\match32.asm
	$(asm) $(aflags) $(avars) win32\match32.asm -fo=$@

$(O)crc_i386.obj: win32\crc_i386.asm
	$(asm) $(aflags) $(avars) win32\crc_i386.asm -fo=$@

# Variant object files for ZipNote, ZipCloak, and ZipSplit:

$(O)zipfile_.obj: zipfile.c $(ZIP_H)
	$(cc) $(cdebug) $(cflags) $(cvars) -DUTIL zipfile.c -fo=$@

$(O)fileio_.obj:  fileio.c $(ZIP_H)
	$(cc) $(cdebug) $(cflags) $(cvars) -DUTIL fileio.c -fo=$@

$(O)util_.obj:    util.c $(ZIP_H)
	$(cc) $(cdebug) $(cflags) $(cvars) -DUTIL util.c -fo=$@

$(O)crypt_.obj:   crypt.c $(ZIP_H) crypt.h ttyio.h
	$(cc) $(cdebug) $(cflags) $(cvars) -DUTIL crypt.c -fo=$@

$(O)win32_.obj:   win32\win32.c $(ZIP_H) win32\win32zip.h
	$(cc) $(cdebug) $(cflags) $(cvars) -DUTIL win32\win32.c -fo=$@

# Creation of subdirectory for intermediate files
$(OBDIR):
	-mkdir $@

# Unwanted file removal:

clean:     .SYMBOLIC
	del $(O)*.obj

cleaner:   clean  .SYMBOLIC
	del Zip.exe
	del ZipNote.exe
	del ZipCloak.exe
	del ZipSplit.exe
