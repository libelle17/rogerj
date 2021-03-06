; Package information (taken from configure)
!define PACKAGE_NAME "Roger Router"
!define PACKAGE_VERSION "1.9.3"
!define PACKAGE_PUBLISHER "The Tabos Team"
!define PACKAGE_WEB_SITE "http://www.tabos.org"

; Include Modern UI
!include "MUI2.nsh"

; MUI Settings / Icons
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\orange-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\orange-uninstall.ico"
 
; MUI Settings / Header
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_RIGHT
!define MUI_HEADERIMAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Header\orange-r.bmp"
!define MUI_HEADERIMAGE_UNBITMAP "${NSISDIR}\Contrib\Graphics\Header\orange-uninstall-r.bmp"
 
; MUI Settings / Wizard
!define MUI_WELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange.bmp"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Wizard\orange-uninstall.bmp"

Name "${PACKAGE_NAME} ${PACKAGE_VERSION}"
OutFile "${PACKAGE_NAME}-${PACKAGE_VERSION}.exe"

SetCompressor /SOLID lzma

; Run the installer with admin privileges
RequestExecutionLevel admin

!define MUI_ABORTWARNING

!define MUI_LANGDLL_ALLLANGUAGES

; Set default installation directory
InstallDir "$PROGRAMFILES\${PACKAGE_NAME}"

; Pages
; Welcome page
!insertmacro MUI_PAGE_WELCOME
; License page
!insertmacro MUI_PAGE_LICENSE "../COPYING"
; Components page
!insertmacro MUI_PAGE_COMPONENTS
; Directory page
!insertmacro MUI_PAGE_DIRECTORY
; Instfiles page
!insertmacro MUI_PAGE_INSTFILES
; Finish page
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_FINISHPAGE_RUN	"$INSTDIR\roger.exe"
!define MUI_FINISHPAGE_RUN_NOTCHECKED
!define MUI_FINISHPAGE_LINK	"Tabos.org homepage"
!define MUI_FINISHPAGE_LINK_LOCATION	"http://www.tabos.org"
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "German" ;first language is the default language
!insertmacro MUI_LANGUAGE "English"

!insertmacro MUI_RESERVEFILE_LANGDLL

Function .onInit
	!insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

Function un.onInit
	!insertmacro MUI_UNGETLANGUAGE
FunctionEnd

Section -Prerequisites
	SetOutPath $INSTDIR\3rdparty
	MessageBox MB_YESNO "Ghostscript is needed for the fax transfer. Do you want to install it?" /SD IDYES IDNO endGhostscript
		File "packages\gs919w32.exe"
		ExecWait "$INSTDIR\3rdparty\gs919w32.exe"
	endGhostscript:
SectionEnd

Section RogerRouter
	; Install license file
	SetOutPath "$INSTDIR"
	File "../COPYING"
	File "printer/*"

	; Install program and libraries
	SetOutPath "$INSTDIR"

	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/roger.exe"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/roger_cli.exe"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/gspawn-win32-helper-console.exe"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/gspawn-win32-helper.exe"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libroger_core.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libroutermanager.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libatk-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libcairo-2.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libcairo-gobject-2.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgdk-3-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libepoxy-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgdk_pixbuf-2.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgio-2.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libglib-2.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgmodule-2.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgobject-2.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgthread-2.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgtk-3-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/iconv.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libintl-8.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpango-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpangocairo-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpangowin32-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpixman-1-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpng16-16.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libsndfile-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libspeex-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libxml2-2.dll"
	;File "/usr/i686-w64-mingw32/sys-root/mingw/bin/pango-querymodules.exe"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/gdk-pixbuf-query-loaders.exe"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/zlib1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libjasper-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libcapi20-3.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libdl.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libspandsp-2.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libspeexdsp-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libtiff-5.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libjpeg-62.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libffi-6.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpangoft2-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libfontconfig-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libfreetype-6.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libexpat-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgcc_s_sjlj-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libbz2-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libharfbuzz-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpeas-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libpeas-gtk-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgirepository-1.0-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libsoup-2.4-1.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libsqlite3-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libcroco-0.6-3.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/librsvg-2-2.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libwinpthread-1.dll"

	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgssdp-1.0-3.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgupnp-1.0-4.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libjson-glib-1.0-0.dll"

	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstreamer-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstallocators-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstaudio-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstcontroller-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstnet-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstreamer-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstrtp-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstsdp-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstvideo-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstapp-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstbase-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstfft-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstpbutils-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstriff-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgstrtsp-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libgsttag-1.0-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libogg-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/liborc-0.4-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libvorbis-0.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libvorbisenc-2.dll"
	File "/usr/i686-w64-mingw32/sys-root/mingw/bin/libwavpack-1.dll"

	; Install data files
	SetOutPath "$INSTDIR\etc"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/etc/fonts"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/etc/gtk-3.0"
	CreateDirectory "$INSTDIR\etc\pango"

	SetOutPath "$INSTDIR\etc\gtk-3.0"
	File "settings.ini"

	SetOutPath "$INSTDIR\lib"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/lib/gtk-3.0"
	;File /r "/usr/i686-w64-mingw32/sys-root/mingw/lib/pango"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/lib/gdk-pixbuf-2.0"

	SetOutPath "$INSTDIR\lib\capi"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/lib/capi/*fritz*.dll"

	SetOutPath "$INSTDIR\lib\roger"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/lib/roger/"

	SetOutPath "$INSTDIR\lib\routermanager"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/lib/routermanager/"

	SetOutPath "$INSTDIR\lib\gstreamer-1.0"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/lib/gstreamer-1.0/"

	SetOutPath "$INSTDIR\share\"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/share/roger"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/share/glib-2.0"
	;File /r "themes"

	SetOutPath "$INSTDIR\share\icons\Adwaita"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/share/icons/Adwaita/*"
	File "/usr/share/icons/Adwaita/index.theme"

	SetOutPath "$INSTDIR\share\icons\hicolor"
	File /r "/usr/i686-w64-mingw32/sys-root/mingw/share/icons/hicolor/*"
	File "/usr/share/icons/hicolor/index.theme"

	SetOutPath "$INSTDIR\share\locale\de\LC_MESSAGES\"
	File "/usr/i686-w64-mingw32/sys-root/mingw/share/locale/de/LC_MESSAGES/roger.mo"
	File "/usr/i686-w64-mingw32/sys-root/mingw/share/locale/de/LC_MESSAGES/atk10.mo"
	File "/usr/i686-w64-mingw32/sys-root/mingw/share/locale/de/LC_MESSAGES/gtk30.mo"
	File "/usr/i686-w64-mingw32/sys-root/mingw/share/locale/de/LC_MESSAGES/glib20.mo"
	File "/usr/i686-w64-mingw32/sys-root/mingw/lib/locale/de/LC_MESSAGES/libpeas.mo"

	ReadEnvStr $0 COMSPEC

	SetOutPath "$INSTDIR"
	DetailPrint "Creating loaders.cache"
	;nsExec::ExecToLog '"$0" /C .\pango-querymodules.exe > etc\pango\pango.modules'
	nsExec::ExecToLog '"$0" /C .\gdk-pixbuf-query-loaders.exe > lib\gdk-pixbuf-2.0\2.10.0\loaders.cache'

	WriteUninstaller "$INSTDIR\uninstall.exe"

	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\RogerRouter" "DisplayName" "Roger Router"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\RogerRouter" "DisplayVersion" "${PACKAGE_VERSION}"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\RogerRouter" "Publisher" "Tabos.org"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\RogerRouter" "HelpLink" "http://www.tabos.org"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\RogerRouter" "URLInfoAbout" "http://www.tabos.org"
	WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\RogerRouter" "UninstallString" "$\"$INSTDIR\uninstall.exe$\""
SectionEnd

Section "Start Menu Shortcuts"
	CreateShortCut "$SMPROGRAMS\RogerRouter.lnk" "$INSTDIR\roger.exe"
SectionEnd

Section "Desktop Icons"
	CreateShortCut "$DESKTOP\RogerRouter.lnk" "$INSTDIR\roger.exe"
SectionEnd

Section "Uninstall"
	DeleteRegKey HKCU "Software\GSettings\org\tabos"
	Delete /rebootok "$DESKTOP\RogerRouter.lnk"
	Delete /rebootok "$SMPROGRAMS\RogerRouter\RogerRouter.lnk"
	Delete /rebootok "$SMPROGRAMS\RogerRouter\Uninstall.lnk"
	RMDir "$SMPROGRAMS\RogerRouter"
	RMDir /r "$INSTDIR"

	; Removing printers
	SetDetailsPrint textonly
	DetailPrint "Removing Roger Router Fax printer"
	SetDetailsPrint none
	ExecWait 'rundll32 printui.dll,PrintUIEntry /dl /n "Roger Router (Fax)" /q'

	DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\RogerRouter"
SectionEnd

;Add printer ports to registry
Section -RegistryFiles SEC05
	SetDetailsPrint textonly
	DetailPrint "Adding printer port to registry"
	SetDetailsPrint none
 
	;Include the results from Reg2NSIS utility
	!include printer.nsh
	sleep 1
SectionEnd

;Restart Print Spooler service (needed to load new ports)
Section -RestartSpooler SEC10
	;Display text above progress bar
	SetDetailsPrint textonly
	DetailPrint "Restarting Print Spooler service"
	SetDetailsPrint none
 
	;Run command to restart services
	nsExec::Exec "net stop Spooler"
	sleep 2
	nsExec::Exec "net start Spooler"
	sleep 2
SectionEnd

;Execute rundll to install printers
; NOTE: ExecWait requires quotes in single-double-double-single format (' " " ') for this to work
Section -ExecBatchFiles SEC15
	SetOutPath $INSTDIR
 
	;Display text above progress bar
	SetDetailsPrint textonly
	DetailPrint "Removing existing Roger Router Fax printer"
	SetDetailsPrint none

	; Removing printers
	ExecWait 'rundll32 printui.dll,PrintUIEntry /dl /n "Roger Router (Fax)" /q'
	sleep 2

	;Display text above progress bar
	SetDetailsPrint textonly
	DetailPrint "Installing new Roger Router Fax printer"
	SetDetailsPrint none

	; Installing printers
	ExecWait 'rundll32 printui.dll,PrintUIEntry /if /b "Roger Router (Fax)" /f "$INSTDIR\ghostpdf.inf" /q /r "RogerRouterFax" /m "Ghostscript PDF" /z'
	sleep 1

	;Display text above progress bar
	SetDetailsPrint textonly
	DetailPrint "Applying details to new Roger Router Fax printer"
	SetDetailsPrint none

	; Adding Printer comments
	ExecWait 'rundll32 printui.dll,PrintUIEntry /Xs /q /n "Roger Router (Fax)" comment "Fax-Printer of Roger Router"  location "Router"'
SectionEnd
