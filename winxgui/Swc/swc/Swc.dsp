# Microsoft Developer Studio Project File - Name="Swc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Swc - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Swc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Swc.mak" CFG="Swc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Swc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Swc - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Swc - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "." /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D WINVER=0x0500 /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\lib\swc.lib"

!ELSEIF  "$(CFG)" == "Swc - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /Gm /GX /ZI /Od /I "." /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D WINVER=0x0500 /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /WX /Fr
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\lib\swcd.lib"

!ENDIF 

# Begin Target

# Name "Swc - Win32 Release"
# Name "Swc - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CComboBoxExt.cpp
# End Source File
# Begin Source File

SOURCE=.\CContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\CFolder.cpp
# End Source File
# Begin Source File

SOURCE=.\CHeaderCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\CMainFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\CMainWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CMenuSpawn.cpp
# End Source File
# Begin Source File

SOURCE=.\CMMedia.cpp
# End Source File
# Begin Source File

SOURCE=.\COutLook.cpp
# End Source File
# Begin Source File

SOURCE=.\CSplitter.cpp
# End Source File
# Begin Source File

SOURCE=.\CTabbed.cpp
# End Source File
# Begin Source File

SOURCE=.\CToolButton.cpp
# End Source File
# Begin Source File

SOURCE=.\CWinDock.cpp
# End Source File
# Begin Source File

SOURCE=.\CWorkTab.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CApp.h
# End Source File
# Begin Source File

SOURCE=.\CCommonCtrl.h
# End Source File
# Begin Source File

SOURCE=.\CDialogControls.h
# End Source File
# Begin Source File

SOURCE=.\CFrame.h
# End Source File
# Begin Source File

SOURCE=.\CGdi.h
# End Source File
# Begin Source File

SOURCE=.\CMacrodefine.h
# End Source File
# Begin Source File

SOURCE=.\CMenuSpawn.h
# End Source File
# Begin Source File

SOURCE=.\CWin.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Swc.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Readme.txt
# End Source File
# End Target
# End Project
