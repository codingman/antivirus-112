# Microsoft Developer Studio Project File - Name="KLUtil" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=KLUtil - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "KLUtil.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "KLUtil.mak" CFG="KLUtil - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "KLUtil - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "KLUtil - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "KLUtil - Win32 Debugport" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "KLUtil - Win32 Releaseport" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Release/Kaspersky Anti-Virus Personal 5.0/CommonFiles/KLUtil", UBVFBAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "KLUtil - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\temp\Release\KLUtil"
# PROP Intermediate_Dir "..\..\temp\Release\KLUtil"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe -lib
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "KLUTIL_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /O2 /Ob2 /I "..\\" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BUILD_KLUTIL_DLL" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /i ".." /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib advapi32.lib ole32.lib Mpr.lib Version.lib /nologo /base:"@..\..\dll_bases.txt,KLUtil" /dll /pdb:"..\..\out\Release/KLUtil.pdb" /debug /machine:I386 /out:"..\..\out\Release/KLUtil.dll" /implib:"..\..\out\Release/KLUtil.lib" /pdbtype:sept /opt:ref
# SUBTRACT LINK32 /pdb:none
# Begin Special Build Tool
TargetPath=\Projects\KAVP\out\Release\KLUtil.dll
SOURCE="$(InputPath)"
PostBuild_Cmds=tsigner "$(TargetPath)"
# End Special Build Tool

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\temp\Debug\KLUtil"
# PROP Intermediate_Dir "..\..\temp\Debug\KLUtil"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe -lib
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "KLUTIL_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /G5 /MDd /W3 /Gm /GX /ZI /Od /I "..\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BUILD_KLUTIL_DLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /i ".." /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib advapi32.lib ole32.lib Mpr.lib Version.lib /nologo /base:"@..\..\dll_bases.txt,KLUtil" /dll /pdb:"..\..\out\Debug/KLUtil.pdb" /debug /machine:I386 /out:"..\..\out\Debug/KLUtil.dll" /implib:"..\..\out\Debug/KLUtil.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "KLUtil___Win32_Debugport"
# PROP BASE Intermediate_Dir "KLUtil___Win32_Debugport"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\temp\Debug\KLUtilP"
# PROP Intermediate_Dir "..\..\temp\Debug\KLUtilP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe -lib
# ADD BASE CPP /nologo /G5 /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BUILD_KLUTIL_DLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /G5 /MDd /W3 /Gm /GX /ZI /Od /I "../../CS AdminKit/development2/include/stlport/stlport" /I "..\\" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BUILD_KLUTIL_DLL" /D "_STLP_NEW_PLATFORM_SDK" /D "_STLP_DEBUG" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /i ".." /d "_DEBUG"
# ADD RSC /l 0x419 /i ".." /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Rpcrt4.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"@..\..\dll_bases.txt,KLUtil" /dll /pdb:"..\..\out\Debug/KLUtil.pdb" /debug /machine:I386 /out:"..\..\out\Debug/KLUtil.dll" /implib:"..\..\out\Debug/KLUtil.lib" /pdbtype:sept
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Rpcrt4.lib gdi32.lib winspool.lib comdlg32.lib shell32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib klcsrt.lib kernel32.lib user32.lib advapi32.lib ole32.lib Mpr.lib Version.lib /nologo /base:"@..\..\dll_bases.txt,KLUtil" /dll /pdb:"..\..\out\Debug/KLUtilP.pdb" /debug /machine:I386 /out:"..\..\out\Debug/KLUtilP.dll" /implib:"..\..\out\Debug/KLUtilP.lib" /pdbtype:sept /libpath:"../../cs adminkit/development2/lib/debug"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "KLUtil___Win32_Releaseport"
# PROP BASE Intermediate_Dir "KLUtil___Win32_Releaseport"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\temp\Release\KLUtilP"
# PROP Intermediate_Dir "..\..\temp\Release\KLUtilP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe -lib
# ADD BASE CPP /nologo /G5 /MD /W3 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BUILD_KLUTIL_DLL" /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /G5 /MD /W3 /GX /Zi /O2 /I "../../CS AdminKit/development2/include/stlport/stlport" /I "..\\" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BUILD_KLUTIL_DLL" /D "_STLP_NEW_PLATFORM_SDK" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /i ".." /d "NDEBUG"
# ADD RSC /l 0x419 /i ".." /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Rpcrt4.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"@..\..\dll_bases.txt,KLUtil" /dll /pdb:"..\..\out\Release/KLUtil.pdb" /debug /machine:I386 /out:"..\..\out\Release/KLUtil.dll" /implib:"..\..\out\Release/KLUtil.lib" /pdbtype:sept
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Rpcrt4.lib gdi32.lib winspool.lib comdlg32.lib shell32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib klcsrt.lib kernel32.lib user32.lib advapi32.lib ole32.lib Mpr.lib Version.lib /nologo /base:"@..\..\dll_bases.txt,KLUtil" /dll /pdb:"..\..\out\Release/KLUtilP.pdb" /debug /machine:I386 /out:"..\..\out\Release/KLUtilP.dll" /implib:"..\..\out\Release/KLUtilP.lib" /pdbtype:sept /libpath:"../../cs adminkit/development2/lib/release"
# SUBTRACT LINK32 /pdb:none
# Begin Special Build Tool
TargetPath=\Projects\KAVP\out\Release\KLUtilP.dll
SOURCE="$(InputPath)"
PostBuild_Cmds=tsigner "$(TargetPath)"
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "KLUtil - Win32 Release"
# Name "KLUtil - Win32 Debug"
# Name "KLUtil - Win32 Debugport"
# Name "KLUtil - Win32 Releaseport"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\block.cpp
# End Source File
# Begin Source File

SOURCE=.\Clipboard.cpp
# End Source File
# Begin Source File

SOURCE=.\CrashHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\CRC32.cpp
# ADD CPP /Yu"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\Stuff\csystem.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DllHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\except.cpp
# End Source File
# Begin Source File

SOURCE=.\Filename.cpp
# End Source File
# Begin Source File

SOURCE=.\FormatTimeString.cpp
# End Source File
# Begin Source File

SOURCE=.\guid.cpp
# End Source File
# Begin Source File

SOURCE=..\StuffIO\Ioutil_FinishCopying.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\StuffIO\Ioutil_FinishCopyingW.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\StuffIO\Ioutil_IsSubstDrive.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\StuffIO\Ioutil_IsSubstDriveW.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\StuffIO\IoutilUNC.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\KLUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\log.cpp
# End Source File
# Begin Source File

SOURCE=.\md5.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ObjectName.cpp
# End Source File
# Begin Source File

SOURCE=.\operationInProgressManager.cpp
# End Source File
# Begin Source File

SOURCE=.\OsVersion.cpp
# End Source File
# Begin Source File

SOURCE=.\Registry.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SubstHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\SysInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\SysTime.cpp
# End Source File
# Begin Source File

SOURCE=.\thread.cpp
# End Source File
# Begin Source File

SOURCE=.\ThreadPool.cpp
# End Source File
# Begin Source File

SOURCE=.\UnicodeConv.cpp
# End Source File
# Begin Source File

SOURCE=..\StuffIO\XErrors.cpp

!IF  "$(CFG)" == "KLUtil - Win32 Release"

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Debugport"

# SUBTRACT CPP /YX /Yc /Yu

!ELSEIF  "$(CFG)" == "KLUtil - Win32 Releaseport"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\block.h
# End Source File
# Begin Source File

SOURCE=.\Clipboard.h
# End Source File
# Begin Source File

SOURCE=.\CrashHandler.h
# End Source File
# Begin Source File

SOURCE=.\CRC32.h
# End Source File
# Begin Source File

SOURCE=.\defs.h
# End Source File
# Begin Source File

SOURCE=.\DllHelper.h
# End Source File
# Begin Source File

SOURCE=.\except.h
# End Source File
# Begin Source File

SOURCE=.\Filename.h
# End Source File
# Begin Source File

SOURCE=.\FormatTimeString.h
# End Source File
# Begin Source File

SOURCE=.\guid.h
# End Source File
# Begin Source File

SOURCE=.\KLUtil.h
# End Source File
# Begin Source File

SOURCE=.\log.h
# End Source File
# Begin Source File

SOURCE=.\log_media.h
# End Source File
# Begin Source File

SOURCE=.\md5.h
# End Source File
# Begin Source File

SOURCE=.\ObjectName.h
# End Source File
# Begin Source File

SOURCE=.\operationInProgressManager.h
# End Source File
# Begin Source File

SOURCE=.\OsVersion.h
# End Source File
# Begin Source File

SOURCE=.\polistorageblock.h
# End Source File
# Begin Source File

SOURCE=.\Registry.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SubstHelper.h
# End Source File
# Begin Source File

SOURCE=.\SysInfo.h
# End Source File
# Begin Source File

SOURCE=.\SysTime.h
# End Source File
# Begin Source File

SOURCE=.\thread.h
# End Source File
# Begin Source File

SOURCE=.\ThreadPool.h
# End Source File
# Begin Source File

SOURCE=.\UnicodeConv.h
# End Source File
# Begin Source File

SOURCE=.\ver_mod.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\KLUtil.rc
# End Source File
# End Group
# Begin Group "Inline Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\inl\debug.h
# End Source File
# Begin Source File

SOURCE=.\inl\PoliStorage.h
# End Source File
# Begin Source File

SOURCE=.\inl\PoliType.h
# End Source File
# Begin Source File

SOURCE=.\inl\smart_ptr.hpp
# End Source File
# Begin Source File

SOURCE=.\inl\synchro.h
# End Source File
# Begin Source File

SOURCE=.\inl\tmutil.h
# End Source File
# End Group
# Begin Group "Ext"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Service\sa.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=..\Service\SA.H
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
