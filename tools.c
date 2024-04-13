//@see <h2><a href="modules.html">Modules</a></h2> ** Lizenz : Apache Lizenz 2.0  @name tools.c
/**
 @todo codelite
 @todo uname domain füllen
 @todo letzer Tag im Monat einpflegen
 @todo tooltest mit/für dump's
 @todo tooltest mit/für cfilename etc
 @todo __x86_64__ &| _WIN64 für time_ nutzen
 @todo Date_Is_DST weekday Sontag Uhrzeit berücksichtigen
 @todo define TIME_STR_5LU "%I64u" 5.5 !!

 @file tools.c
 @brief Beschreibung des Tools.c Projekt
*/
/**
 @mainpage tools.c Projektuebergreifende Funktionen
<table cellspacing	="10"
       cellpadding	="0"
       width		="100%"
       border		="0"
><tr><td valign="top" width="25%">
 @author   [Heiko Stoevesandt [HS] Hesti](mailto:hstools@t-online.de)
 @date     01.03.92 Start der Tools in C siehe @ref r_revisionshistorie "Revisionshistorie"
 @copyright <a href="https://www.gnu.de/documents/gpl-2.0.de.html">GPL 2.0</a>

Weiterfuehrung der tools.c seit 1992

EMail: mailto:hstools@t-online.de
HP:    http://hstools.sourceforge.net

</td><td width="20%" style="background-image:URL(hstools_C.png); background-repeat: no-repeat; background-size: 100% auto;">
</td><td width="55%" valign="top" style="padding-left: 10px; padding-top: 0px;">

<div class="textblock"><dl class="section see"><dt>Hier eine Module/Guids</dt></dl></div>
<div style="padding-left: 10px;">
<a class="e1" href="modules.html">Index</a> <br>

@ref c_base_history	"HStools History"<br>
@ref InitTools "HStools Init"<br>
@ref lprintf   "HStools lprintf"<br>
@ref c_uname   "uname für Windows"<br>
@ref strexpr   "strexpr Ausdruecke auswerten"<br>
@ref c_chainlist "Einfach verkettete Listen"<br>

</div>
</td></tr></table>

<table cellspacing	="10"
       cellpadding	="0"
       width		="100%"
       border		="0"
><tr><td valign="top" width="50%">

 ### Verzeichnis der grundlegenden Funktionsgruppen in tools.c

 @subpage c_init_tools <br>
 @subpage c_args <br>
 @subpage c_lprintf <br>
 @subpage c_uname <br>
 @subpage c_strchr <br>
 @subpage c_malloc <br>
 @subpage c_tempfile <br>
 @subpage c_timerfunc <br>
 @subpage c_dumpfunc <br>
 @subpage c_iofunc <br>
 @subpage c_links <br>
 @subpage c_chainlist <br>

</td><td valign="top" width="50%">

 ### Verzeichnis externer Module

 @subpage c_crc32 <br>
 @subpage c_multi_args <br>
 @subpage c_rgbcolor <br>
 @subpage c_vars <br>
 @subpage c_cset <br>
 @subpage c_json <br>
 @subpage c_vector <br>
</td></tr></table>

*/

/**
 @addtogroup c_base_history
 @{
 @brief Alle Informationen und Änderungen

 Alle Informationen zu Änderungen in den einzelnen Funktionen werden dort direkt in der Revsionshistorie aufgelistet.

 @anchor r_revisionshistorie
___[ Revision ]______________________________________________________________

 **       1992 HS Ursprünglich von in und für Borland/Turbo C entwickelt
 **       1994 HS Komplette Überarbeitung und Implementierung nach Linux
 **       1997 HS Überarbeitung: Nun auch wieder unter MS-DOS/Windows einsetzbar
                  Weiterentwicklung auch in CPP einsetzbar
 ** 02.04.06 HS RE_Create von einer alten Headerdatei. Alles "neu" geschrieben
                  Alter Source war nicht mehr lesbar. Nur der Borland C-Source
 ** 01.04.10 HS Neue Funktionen für eine Prüfsummenberechnung
 ** 05.07.13 HS Angepasst an den aktuellen gcc Compiler
 ** 27.11.17 HS Nochmal implementiert __linux__ und __WIN32__ Versionen
                für den Raspberry
 ** 30.12.17 HS strchg new
 ** 08.04.18 HS Impl. strmtch
 ** 08.04.18 HS Impl. ParseFmtTime
 ** 10.04.18 HS TinyC ist als Compiler auch vorgesehen
 ** 02.11.18 HS Implementiert copyfiletime auch für Windows
 ** 13.11.18 HS Kalendarfunktionen mktime_t neu
 ** 14.11.18 HS Kalendarfunktionen mktime_s neu
                isLeapYear neu
 ** 05.02.19 HS uname implementierung unter Windows (unter Linux schon drin)
 ** 10.02.19 HS strtohexstr neu
 ** 03.03.19 HS strstradd - strcat mit pointer neu
                HSLnum2Str hat jetzt einen Parameter mehr pad, der füller
                strftimeR - strftime hatte mal einen "Mrz" statt Mar zurückgegeben
                da flog die glibc_strftime raus und strftimeR kam rein
 ** 19.04.19 HS Neue m_PRG_ Strings
 ** 23.04.19 HS aChkARG ohne args, da diese ja bereitsabgelegt wurden
 ** 05.03.20 HS FileCopy mit Prozentanzeige möglich
 ** 10.03.20 HS Human2Num & Num2Human neu
 ** 22.03.20 HS ChkARGlong um --long Parameter übergeben zu können
 ** 23.03.20 HS DoxyGen Dokumentation
 ** 28.03.20 HS neu strsetto In so manchen Bibliotheken gibt es ähnliches
 ** 01.04.20 HS NEU: Codeblocks 20.03
 ** 01.04.20 HS time_t kann jetzt 8 Bit sein oder 4 Bit
 ** 06.04.20 HS Neue dynamische (malloc) Stringgrundfunktionen
 ** 07.04.20 HS c_strchr in der Dokumentation unterteilt für eine besser Lesart
 ** 10.05.20 HS filesize64 neu. Beim Filecopy von Dateien mit Dateien >4GB
                  liefert stat nur bis long ( 2 147 483 647 Bytes )
 ** 25.06.20 HS Nach Prüfungsphase von strprintf jetzt für lprintf eingesetzt
 ** 26.06.20 HS temp/random Funktionen
 **            HS llx I64x in strprintf auf __int64 angepasst Test 81.09
                  sollte somit einwandfrei sein
 ** 27.06.20 HS verschiedene lprintf Anpassungen
 ** 07.07.20 HS InitTools kann jetzt nur noch durch INITTOOLS_MSG_MAX begrenzt
                Meldungen mit %c bekommen. Außerdem können die Meldungen jetzt
                auch direkt im OPTS übergeben werden.
             HS lprintf wird Zeilenumbrüche berücksichtigen
             HS *neu* CFilevault wie CDirvault aber mit filenamen
 ** 09.07.20 HS *neu* aChkARGlong
 ** 10.07.20 HS ChkARG kann im Find-Teil das '*' haben.
 ** 18.08.20 HS isOneString neu
 ** 19.10.20 HS unter Linux verfeinert
 ** 29.11.20 HS RCread und das finden des LogFilenamens überarbeitet
 ** 06.11.20 HS In einzelne Module verfrachtet crc32 / multi_args
 ** 25.07.22 HS sprintf -> sprintf_ex usw. für GCC 11.2 usw. ausgetauscht
                sprintf über strprintf
 ** 10.11.22 HS strGetCWD ist nur ein malloc Speicher strgetCWD gibts nicht mehr
 ** 15.11.22 HS RCread ueberarbeitet
                Online Dokumentation mit Darkmode (*aufgehübscht*)
 ** 29.08.23 HS timezone nicht unter UART
                LLD_STR LLD_STR_LU8 für GCC 13.1
 ** xx.12.23 HS Linux main
 ** 28.01.24 HS fopen_readall gibt *char bei erfolg oder NULL fopen_getline
 ** 22.03.24 HS strlstadd / strlstfree neu
 ** 24.03.24 HS strquoute / strunquote neu
 ** 02.04.24 HS rotierende Buffer die sich selbst oder auf Kommando freeen...
             HS Jedes Datum von vier auf zweistellig umgestellt

_____________________________________________________________________________

@} */

///@noop  %{time dd.mm.yy} HS

/**
 @addtogroup c_tools_globalvars
 @{
 @brief Alle Variablen die global definiert sind
 @}
*/

/*
 @addtogroup c_tools_c Grundlegende Funktionen
 @{
*/

/**
 @addtogroup c_init_tools
 @{
 @brief Siehe Funktion @ref InitTools OPTS @ref InitTools_OPTS
*/ /*
 @brief Init der tools.c Basisaufruf ist @ref InitTools

 Eine ausfühliche Beschreibung Beschreibung des Inits

 Der Init ist die zentrale BasisInitialisierung aller globalen Variablen.

Variable          | typischer Inhalt
------------------|--------------------
HSDIR             | C:\\HS
Logtype           | 00001010
LogFileName       | C:\\HS\\Log\\tooltest-2020-03-23.log
LogExtra          | tooltest
LogAtExitFlush    | false
SYSLOGFILE        | C:\\Users\\Hesti\\AppData\\Local\\SYSLOG.log
m_Workfile        | C:\\HS\\Log\\tooltest-2020-03-23.log
m_PRGNAME         | tooltest
m_PRG_INFO        | tooltest V10.19.752 Beta

m_PRG_COPY        | \\rtooltest V10.19.752 Beta  (c)  1999-2020 by Heiko Stoevesandt\\n\\n
m_PRG_COPYCLEAN   |  1999-2020 by Heiko Stoevesandt
PRG_INFO          | tooltest V10.19.752 Beta\\nCompiled at Mar 23 2020 13:14:34 with GnuCC V5.01.00 (Windows)\\nCode written 1996-2020 by Hesti, Germany
m_PRG_COMPILE_TIME | Mar 23 2020 13:14:34
m_PRG_COMPILER    | GnuCC V5.01.00 (Windows)
m_PRG_BETA        | 10.19.752 Beta

https://stackoverflow.com/questions/11697820/how-to-use-date-and-time-predefined-macros-in-as-two-integers-then-stri
#define BUILD_YEAR_CH0 (__DATE__[ 7])
#define BUILD_YEAR_CH1 (__DATE__[ 8])
#define BUILD_YEAR_CH2 (__DATE__[ 9])
#define BUILD_YEAR_CH3 (__DATE__[10])
#define BUILD_YEAR BUILD_YEAR_CH0##BUILD_YEAR_CH1##BUILD_YEAR_CH2##BUILD_YEAR_CH3

VERSION.h:
#define I_AUTH_AUTOR_NAME  "Heiko Stoevesandt"
#define I_AUTH_AUTOR_TOKEN "HS"
#define I_AUTH_AUTOR_NICK  "Hesti"

make preoptions:
hsmakevers.exe -p I_ -r Beta -a AUTH_AUTOR

_WIN32 Dieser Wert wird als 1 definiert, wenn das Kompilierungsziel 32-Bit-ARM, 64-Bit-ARM, x86 oder x64 ist. Andernfalls wird der Wert nicht definiert.
_WIN64 Dieser Wert wird als 1 definiert, wenn das Kompilierungsziel 64-Bit-ARM oder x64 ist. Andernfalls wird der Wert nicht definiert.

IS64BIT
IS32BIT

*/

#ifdef  __cplusplus
extern "C"
{
#endif

#define toolsmainmodul
#include "tools.h"
#undef toolsmainmodul

#ifdef OS_WINDOWS
#ifdef __TINYC__
#include "tcc/dirent_win32_tinyc.c"
#endif // __TINYC__
#endif // OS_WINDOWS

#ifndef OS_LINUX
#ifndef OS_WINDOWS
//#define OS_WINDOWS
#endif
#endif

/*
 iLogInfo kann das Aussehen des LogFiles ggf. auch des Syslogs erheblich beeinflussen.

 Es gibt folgende Parameter, die Auswirkungen auf die Startphase haben, bzw. das Aufzeichnen
 der Lognachrichten beeinflussen können.

 iLogInfo-Flag       | Funktion
 --------------------|-----------------------------------------------------------
 INIT_NOSTARTmsg     | Der Programmstart erfolgt ohne Konsolennachricht
 INIT_NOLOG          | Es wird explizit nochmal der das LogFile-Bit im LogType gelöscht
 INIT_DATELOG        | Ein LogFilename wird zusätzlich mit dem aktuellen Datum geschrieben
 INIT_SYSLOG_ISODATE | Das Syslog wird wird mit IsoDate statt mit dem Syslogformat gefüllt. @ref LogSyslogIso
 INIT_LOG_ISODATE	 | Alle anderen Logs (außer dem Syslog) werden mit ISO-Datum gefüllt. @ref LogFileIso
 INIT_LOG_NOLOGEXTRA | Außer im Syslog wird das LogExtra (enthält im Normalfall den Programmnamen) unterdrückt @ref LogFileNoExtra

 @param PRGName     Programmname, darf NULL sein, dann wird der Programmname an arguv[0] ermittelt
 @param iMAJOR		Programm FinalRevision
 @param iMINOR      Programm SubRevision
 @param iBUILD      Build Version
 @param iBeta       Beta-Status, im Prinzip ein beliegiger String
 @param iLogInfo    Früher nur Switches zur initialen LogInfo siehe INIT_ Switches
*/
/// Anzahl der möglichen Anhänge an m_PRG_INFO
#define INITTOOLS_MSG_MAX 25

/**
 @brief tools.c initialisieren

 Der zentrale BasisInit. Er legt die Defaultwerte fest und steuert das Aussehen der Fehlerausgaben mit lprintf/lmsg.

 Sofern die Environment-Variable @ref HSDIR gesetzt ist, wird diese auch übernommen.

 Der Basisinit kann minmalistisch mit

 @code
 InitTools(0,NULL,"");
 @endcode

 erfolgen. Es werden alle grundsätzlichen Variablen vernünftig belegt, aber es fehlen Variablen, wie @ref LogFileName etc. Für Minimalprojekte aber denkbar.

 Ebenso minimalistisch geht es mit:

 @code
 InitTools(argc,argv,"");
 @endcode

 Es wird so aber der Programmname erkannt usw.. Auch der LogFileName sollte so richtig
 sein, aber per default sind nur STDERR und SYSLOG als Ausgabe vorgesehen.

 Mit den @b opts können Parameter übergeben oder Flags geändert werden.

 opts werden von links nach rechts abgearbeitet und erwarten die Parameter auch so.

 typisch wäre so eine <dfn> "%v %m %t" </dfn> Variante. Diese Übergibt die Versionkontrolle, schaltet die Startnachricht aus und übergibt die Logfiletype.
 Im Ganzen sieht das so aus:

 @code
 if (InitTools(argc , argv, "%v %m %t", I_MAJOR, I_MINOR, I_BUILD, I_BETA, LOG_STDERR)) return 1;
 @endcode

 Andere Variante:
 @code
 if (InitTools(argc , argv, "%t'(c) '%c' bei MIR", LOG_STDERR, &__DATE__[7] )) return 1;
 @endcode

 Das wird dann z.B. zu einer Startnachricht (auch in m_PRG_INFO) expandiert:

 tooltest V0.0.0 (c) 2020 by MIR

 Sieht im ersten Augenblick nach viel Aufwand für die kleine Zeile aus, aber "MIR" läßt sich auch mit einer @b "#define" Variablen austauschen. Damit
 können ganze Nachrichtenblöcke, in diesem Fall Copyright, ausgetauscht werden. m_PRG_INFO kann im ABOUT-Dialog Verwendung finden.

 <br>@anchor InitTools_OPTS

 optparam | type           | Beschreibung
 ---------|----------------|-------------
    @b  ' |                | hat kein einleitendes '%%' Zeichen, der folgende Text bis zum nächsten @b ' wird 1:1 übernommen
        c | char *         | mögliche ExtraMsg beim Start bzw. für @ref m_PRG_INFO. Möglichkeit 1 auf %c folgen ein Zeichen != '='
        d | -              | @ref LogFileName mit zusätzlichen Datum
        e | -              | @ref LogFileWithExtra auf true setzen, per default ist es auf false
        l | char*          | logs in diesem DatumsFormat darstellen ( siehe @ref strftimeR ) wird intern nach @ref LogDateFormat, wird NULL als Parameter übergeben wird es auf @ref SyslogDateFormat gesetzt
        m | -              | StartMessage übergehen
        o | -              | Kein CR/LF in lprintf auflösen @ref lprintfConvertCRLF
        p | char*          | Programmname wird in @ref m_PRGNAME gespeichert -- @ref LogExtra zeigt darauf
        s | char*          | syslog mit diesem DatumsFormat speichern (siehe @ref strftimeR), nur unter Windows, wird sonst ignoriert -- intern nach @ref SyslogDateFormat
        t | int( 0-255 )   | LogType @ref LOG_Ausgabekanaele in welche die Nachrichten von lprintf gespeichert werden
        v | 3 Ints 1 char* | Version 1.2.3 Beta -- wird in @ref m_MAJOR etc. gespeichert

 @return 0 oder das Programm muss abgebrochen werden
 @param arguc		Parameter von main Anzahl
 @param arguv       Parameter von main StringFeld
 @param opts        Modifkator der Optionen
 @param ...         Parameter für die Optionen

 @see c_lprintf

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 16.11.16 HS Neue Listeverwaltung
 ** 20.01.17 HS Logfiles werden nicht mehr dem Datum Voran, sondern mit dem
                Datum hinter dem Programmnamen geschrieben.
 ** 19.02.18 HS HSDIR ist global verfügbar; wenn HSDIR[0]==0 dann unbesetzt
 ** 13.01.19 HS m_PRG_argc & m_PRG_arguv global verfügbar
 ** 27.06.20 HS Dokumentation aufgearbeitet
 ** 28.06.20 HS LogFile Operatoren können im iLogInfo grundsätzlich eingerichtet werden
 ** 29.06.20 HS Ganz neue Version, da mich verschiedene Optionen juckten
 ** 06.07.20 HS aus den opts sind Nachrichten jetzt direkt möglich.
             HS %1-%9 wird ersetzt durch %c und ist durch INITTOOLS_MSG_MAX begrenzt
_____________________________________________________________________________
*/ // 0123456789 - ab   fghijk  no qr  u wxyz

int InitTools ( int arguc, char *arguv[] , char* opts, ... )
{
    bool printStartMessage;                                     // bestimmt ob eine Nachricht beim Programmstart automatsch ausgegeben wird
    bool LogfileNameWithDate;                                   // Jeden Tag einen anderen Namen erstellen
    char *msg[INITTOOLS_MSG_MAX];                               // Nachrichten die an m_PRG_INFO angehängt werden, so dass es eine individuelle Nachricht ergibt
    char tmpd[PATH_MAX];

    int i;
    char *tmp;
    char *opt_pos;                                              // zeiger in den opts
    va_list argpnt;                                             // variablelist ...

    if (opts==NULL) return 1;                                   // nicht erlaubt. muss "" oder andere gültige charkette sein

    tmp = getenv("HSDIR");                                      // ---- > HSDIR auswerten oder nullen
    if (tmp) strcpy_ex (HSDIR, tmp);
    else                HSDIR[0]=0;

    m_PRG_argc  = arguc;                                        // Args Intern merken
    m_PRG_arguv = arguv;

    // Defaults, nur wenn geändert, dann anders
    //_________________________________________________________

    printStartMessage   = true;
    LogfileNameWithDate = false;

    LogAtExitFlush      = false;
    LogType             = LOG_STDERR + LOG_LOGFILE + LOG_SYSLLOG;
    LogFileName         = NULL;
    LogExtra            = NULL;
    LogFileWithExtra    = false;
    lprintfConvertCRLF  = true;

    LogDateFormat       = "%Y-%m-%d %H:%M:%S ";                 // 2020-06-29 15:33:21
    SyslogDateFormat    = "%b %d %H:%M:%S ";                    // Jun 29 15:33:21

    m_MAJOR = 0;                                                // Revisionskontrolle; kann muß nicht
    m_MINOR = 0;
    m_BUILD = 0;
    m_BETA  = "";

    for (i=0;i<INITTOOLS_MSG_MAX;i++) msg[i] = NULL;            // Alle Zusatznachrichten NULLen

    strcpy (m_PRGNAME, "");                                     // default=leer

#ifdef OS_WINDOWS
    sprintf_ex(SYSLOGFILE,"%s" DIR_SEP "SYSLOG.log",getenv("LOCALAPPDATA"));
#endif

    va_start (argpnt, opts);                                    // ... auf erstes Argument positionieren
    for (opt_pos=opts;;opt_pos++)                               // Zähler ist das in opt vermerkte
    {
        if (*opt_pos==0) break;                                 // Keine opts mehr
        if (*opt_pos=='\'')
        {
              tmp = malloc0(strlen(opt_pos)+2);
              for (opt_pos++,i=0;;opt_pos++,i++)
              {
                  if (*opt_pos==0) return EXIT_FAILURE;         // Syntax einhalten
                  if (*opt_pos=='\'') break;
                  tmp[i]=*opt_pos;
              }
              for (i=0;;i++)                                    // MsgFeld erweitern
              {
                  if (i>=INITTOOLS_MSG_MAX)
                  {
                      free(tmp);
                      break;
                  }
                  if (msg[i]==NULL)
                  {
                      msg[i] = tmp;
                      break;
                  }
              }
              continue;
        }

        if (*opt_pos!='%') continue;                            // Einleitung
        opt_pos++;                                              // Zeiger auf Argument
        if (*opt_pos==0) return EXIT_FAILURE;                   // ERROR, nach '%' muss ein Zeichen folgen

        switch (*opt_pos)                                       // welche Option verändert werden soll
        {                                                       // Nachrichten
          case 'c':
              tmp = strdup(va_arg(argpnt, char *));
              for (i=0;;i++)
              {
                  if (i>=INITTOOLS_MSG_MAX)                     // MsgFeld erweitern
                  {
                      free(tmp);
                      break;
                  }
                  if (msg[i]==NULL)
                  {
                      msg[i] = tmp;
                      break;
                  }
              }
              break;

          case 'd':                                             // LogfileNameWithDate (kein Paramete in ...)
              LogfileNameWithDate = true;
              break;

          case 'e':                                             // LogFileWithExtra
              LogFileWithExtra = true;
              break;

          case 'l':                                             // LogDateFormat
              LogDateFormat = va_arg(argpnt, char *);
              if (LogDateFormat==NULL) LogDateFormat = SyslogDateFormat;
              break;

          case 'm':                                             // printStartMessage
              printStartMessage = false;
              break;

          case 'o':                                             // printStartMessage
              lprintfConvertCRLF = false;
              break;

          case 'p':                                             // Programmname
              strcpy_ex (m_PRGNAME, va_arg(argpnt, char *));
              break;

          case 's':                                             // SyslogDateFormat not used if not Windows; but can't ignored
              SyslogDateFormat = va_arg(argpnt, char *);
              break;

          case 't':                                             // LogType
              LogType = va_arg(argpnt, int);
              break;

          case 'v':                                             // Versionskontrolle ( es werden 4 Parameter in ... erwartet )
              m_MAJOR = va_arg(argpnt, int);
              m_MINOR = va_arg(argpnt, int);
              m_BUILD = va_arg(argpnt, int);
              m_BETA  = va_arg(argpnt, char *);
              break;

          default:                                              // Nicht erkanntes Zeichen
              lprintf ("Error; while parameter in InitTools does not work");
              return EXIT_FAILURE;
        }
    }
    va_end(argpnt);                                             // Ende alle Variablen in ...

    // Programmnamen erstellen
    //_________________________________________________________

    if (arguv)
    {
        strcpy_ex (m_Workfile,Cbasename(arguv[0]));		        // (C:\\HS\bin\) -> HStool.exe
        tmp = strrchr(m_Workfile,'.');      			        // -> .exe
        if (tmp) *tmp=0;                				        // HStool - ohne .exe
    }else{                                                      // Dieser Part ist nur schwer vorstellbar, aber ....
        if (m_PRGNAME[0]) strcpy_ex (m_Workfile,m_PRGNAME);
        else              strcpy_ex (m_Workfile,"anytool");
    }
    if (!m_PRGNAME[0]) strcpy_ex (m_PRGNAME, m_Workfile);       // Programmnamen kopieren, falls bis jetzt keiner existiert

    // Logfilenamen erstellen
    //_________________________________________________________

    // Globales Config lesen
    RConfig = NULL;
#ifdef OS_WINDOWS
    RConfig =               RCread(opt_RCdir_HSDIR_etc|opt_RCdir_silence|opt_RCdir_nodflt, NULL, "hsrc");
#endif // OS_WINDOWS
    if (!RConfig) RConfig = RCread(opt_RCdir_root_etc|opt_RCdir_silence|opt_RCdir_nodflt, NULL, "hsrc");

    // Ab hier wird Filename des Logs gesucht
    // _________________________________________________________

    //mit HSDIR muss ein Verzeichnis Log existieren
    //tmp = NULL;

    tmp = RCfind( RConfig, "LOGDIR" );                          // In der RConfig suchen nach LOGDIR=....
    if (tmp) if (!DirOK(tmp)) tmp = NULL;                       // Wenn gefunden und ein gültiges Verzeichnis
    if ((!tmp) && (HSDIR[0]!=0))                                // Noch kein Ergebnis, aber HSDIR im Environment
    {
        sprintf_ex (tmpd, "%s" DIR_SEP "Log", HSDIR);                     // Prüfe ab das Verzeinis existiert
        if (DirOK(tmpd)) tmp=tmpd;
    }
#ifdef OS_LINUX
    if (!tmp) tmp = getenv("HOME");					            // Wenn nicht dann wird "HOME=/home/pi" angenommen
    if (!tmp) tmp = "/var/log";                                 // oder fallback
#else
    if (!tmp) tmp = Cdirvault ("%LOCALAPPDATA%\\");               // unter Windows wird [USERDIR]/Appdata/Local als fallback genommen
#endif
    strcpy_ex(LogDir, tmp);
    if (LogfileNameWithDate) sprintf_ex (m_PRG_INFO, "%s-%s.log",  m_PRGNAME, datestr(unixtime()));
    else                     sprintf_ex (m_PRG_INFO, "%s.log",  m_PRGNAME);
    sprintf_ex (m_Workfile, "%s" DIR_SEP "%s", tmp, m_PRG_INFO);
    LogFileName = m_Workfile;

#if 0
// later stuff
    if (!LogFileName)
    {

// #ifdef OS_WINDOWS
        if (*HSDIR)
        {
            sprintf_ex (m_Workfile, "%s" DIR_SEP "Log" DIR_SEP "%s", HSDIR, m_PRG_INFO);
        }else{
            tmp = getenv("LOCALAPPDATA");			            // LOCALAPPDATA=C:\Users\Hesti\AppData\Local
            sprintf_ex (m_Workfile, "%s" DIR_SEP "%s", tmp, m_PRG_INFO);
        }
// #endif
// #ifdef OS_LINUX
// else

//ifdef compile4me Idee ist nicht flexibel genug
        char host[128];
        char dir2use[PATH_MAX];
        if ( gethostname (host, sizeof (host))==EXIT_SUCCESS)
        {
            if (strlen(host)>4)
            {
                strdel (host,0,3);
                strlwr(host);
                sprintf_ex(dir2use,"/pub/logs/%s", host);
                tmp = dir2use;
            }
        }
//#endif
        // # /etc/hsrc
        // #------ comment ---------
        // log=/pub/logs/hesti
        // etc=/hs/etc
        // map00=ä;ae
        // map01=ü;ue

        tmp = RCfind( RConfig, "LOGDIR" );
        if (tmp) if (!DirOK(tmp)) tmp = NULL;
        if (!tmp) tmp = getenv("HOME");					        // HOME=/home/pi
        if (!tmp) tmp = "/var/log";
        sprintf_ex (m_Workfile, "%s" DIR_SEP "%s", tmp, m_PRG_INFO);
//#endif
        LogFileName = m_Workfile;
    }
#endif

    // Vorbelegen einiger Variablen
    //_________________________________________________________

    LogExtra = m_PRGNAME;                                       // inbesondere für das syslog
    NODE_HEAD = NULL;                                           // Einige defaults
    DumpInit (DUMP_STDERR);

    // Die Infonachricht bauen X64/X86 14.12.20 HS
    //_________________________________________________________

    sprintf_ex (m_PRG_INFO, "%s V%u.%u.%u %s %s", m_PRGNAME, m_MAJOR, m_MINOR, m_BUILD, m_BETA,
#ifdef IS64BIT
        "X64"
#else
        "X86"
#endif
    );
    if (m_BETA) if (m_BETA[0]) strcat_ex (m_PRG_INFO," ");
    for (i=0;i<INITTOOLS_MSG_MAX;i++)
    {
        if (msg[i])
        {
            strcat_ex(m_PRG_INFO, msg[i]);
            free(msg[i]);
    //_________________________________________________________
        }
    }

    // Grundsätzlich abfangen und Programm beenden --date --version
    // 09.03.24 HS printf statt lprintf
    // 12.03.24 HS domian mit eincopiliert

    for (i=1;i<arguc;i++)
    {
        //printf ("ARGV = \"%s\"\n", arguv[i]);
        if ((!strcasecmp(arguv[i], "--date")) ||
            (!strcasecmp(arguv[i], "--version"))
           ){
              struct utsname utsbuf;

              printf ("%s\n",m_PRG_INFO);
              printf ("%14s\t%s %s\n", "Compiled at:", __DATE__, __TIME__);
              printf ("%14s\t%s V%i.%02i.%02i (%s)\n", "Compiled with:",
                       __COMPILER__, __COMPILER_VERSION__ / 10000,
                       (__COMPILER_VERSION__ / 100) % 100,
                       __COMPILER_VERSION__ % 100, OS_VERSION );

              if (uname(&utsbuf) >= 0)
              {
//                 printf("      Machine:\t%s\n      Sysname:\t%s\nRelease:\t%s\nVersion:\t%s\nNode:   \t%s\n", //Domain: \t%s\n",
//                    utsbuf.machine, utsbuf.sysname, utsbuf.release, utsbuf.version, utsbuf.nodename
//                    //,utsbuf.domainname
//                    );

                 printf ("%s\n",strfiller('-',80));
                 printf("%14s\t%s\n%14s\t%s\n%14s\t%s\n%14s\t%s\n%14s\t%s\n"
#ifdef OS_LINUX
                        "%14s\t%s\n"
#endif
                        ,"Machine:", utsbuf.machine
                        ,"Sysname:", utsbuf.sysname
                        ,"Release:", utsbuf.release
                        ,"Version:", utsbuf.version
                        ,"Node:", utsbuf.nodename
#ifdef OS_LINUX
                        ,"Domain:",
# ifdef __USE_GNU
                        utsbuf.domainname
# else
                        utsbuf.__domainname
# endif
#endif
                    );
              }
              fflush(stdout);
              exit (254);
        }
    }

    if (printStartMessage)
    {
        printf ("\r%s\n\n", m_PRG_INFO);
    }
    lmsg_init();    // Stufenbasierte LogNachrichten System
    return EXIT_SUCCESS;
}
///@}

/**
 @addtogroup c_args
 @{
 @brief Argumente von main() verwalten leicht gemacht

 ** ARG'S auswerten

 Typischer Weise wird folgendes Beispiel sein:
 @code
 InitARG (argc);                                // von main, kann weggelassen werden, wenn man arg_unused_print nicht braucht
 if (ChkARG("-b", argc, argv)) boom=true;       // wenn -b angegeben wird eine Variable gesetzt
 if (arg_unused_print(argc, argv)) return FAIL; // Anzahl der fehlerhaften Parameter. Detail liefert das logfile InitARG ist ein muss dann
 arg_Clean();                                   // Nur wenn InitARG aufgerufen wurde
 @endcode

___[ Revision ]______________________________________________________________

 ** 31.05.00 HS Create 31.05.1997
 ** 31.05.00 HS Portierung nach Unix 16.05.1999
 ** 01.08.16 HS Reimplemnted für Windows
 ** 17.11.16 HS InitArg arg_GetNext arc_Clean neu, um überprüfen zu können,
                ob unsinnige Parameter überprüfen zu können.
 ** 09.12.16 HS Rewrite von ChkARG
 ** 13.01.19 HS Neu: Mainparameter '#num' Direkter Zugriff auf einzelne
                Parameter mit Nummer
 ** 10.07.20 HS Wenn ChkARG im Find-Teil das '*' vorfindet, dann wird der erste
                nicht /- @ref ChkPar Parameter gefunden und korrekt verarbeitet.
_____________________________________________________________________________
*/

char *arg_used=NULL;

///@brief Init um Args später auswerten zu können, die nicht genutzt werden
void InitARG (int arguc)
{
    arg_used = malloc0(arguc+1);
    arg_used[0] = 1;
}

///@brief Sub für arg_unused_print
int arg_GetNext(int point, int arguc)
{
    int p;
    for (p=point;;p++)
    {
        if (p>=arguc) return -1;
        if (arg_used[p]==0) return p;
    }
}

///@brief Speicher von InitARG wieder freigeben
void arg_Clean (void)
{
    if (!arg_used) return;
    free (arg_used);
    arg_used=NULL;
    return;
}

int aarg_unused_print(void)
{
    return arg_unused_print(m_PRG_argc, m_PRG_arguv);
}
/**
 @brief über lprintf alle an main übergebenen _nicht_ genutzten Parameter ausgeben
 @return Anzahl der Fundstellen
*/
int arg_unused_print(int argc, char *argv[])
{
    int i;
    int e;
	if (arg_GetNext(0,argc)==-1) return 0;
    for (i=0,e=0;;e++)
    {
        i = arg_GetNext(i+1,argc);
        if (i==-1) break;
        lprintf ("unknown todo: %s", argv[i]);
    }
    return e;
}

#ifdef old_pars_version
#ifdef OS_WINDOWS
char *PARS="/-\\";
#else
char *PARS="-\\";
#endif

int ChkPar(int tmp)
{
    register int i;
    for (i=0;;i++)
    {
        if (PARS[i]==0)   return 0;
        if (tmp==PARS[i]) return PARS[i];
    }
    return -1; // Never reached
}
#endif // old_pars_version

/// @brief prüfen ob das Zeichen ein Parameter ist
/// @return das Zeichen das Verwendet wurde. 0 wenn nichts gefunden
int ChkPar(int val)
{
#ifdef OS_WINDOWS
    if (val=='/') return '/';
#endif
    if (val=='-') return '-';
    return 0;
}

/**
 @brief Mainparameter #1 bis # #9999 sh. ohne ParameterSlashes. Beim ersten Parameter der mit ChkPar gefunden wird abgebrochen
 @return  0 nichts gefunden 1-x Fundtstelle

___[ Revision ]______________________________________________________________

 ** 13.01.19 HS Create
___________________________________________________________________________*/

int ChkParMain (char *Find, int arguc, char *arguv[])
{
    int numToFind;
    int PosIHave;
    char *src;

    if (Find[0]!='#') return 0;
    numToFind = atoi(&Find[1]);
    if (numToFind<1)  return 0;
    for (PosIHave=0;;PosIHave++)
    {
        if (PosIHave>=arguc) break;
        src = arguv[PosIHave];                                                  // Durch die Übergebenen Parameter hangeln
        if (ChkPar(src[0])!=0) break;                                           // darf als Parameter __NICHT__ gültig sein
        if (numToFind==(PosIHave+1))                                            // Wenn gefunden Fundstelle mitteilen (1-xxx)
        {
            ARG = src;
            return numToFind;
        }
    }
    return 0;
}
/**
 @brief Auf den ersten Parameter zugreifen der ein Argument ohne ParameterSlashes ist $0 bis $9999. $0 ist wohl immer der eigene Dateiname
 @return  0 nichts gefunden 1-x Fundtstelle

___[ Revision ]______________________________________________________________

 ** 09.07.21 HS Create
___________________________________________________________________________*/

int ChkParWos (char *Find, int arguc, char *arguv[])
{
    int numToFind;
    int numFound;
    int PosIHave;
    char *src;

    if (Find[0]!='$') return 0;
    numToFind = atoi(&Find[1]);
    if (numToFind<0)  return 0;
    for (numFound=0,PosIHave=0;;PosIHave++)
    {
        if (PosIHave>=arguc) break;
        src = arguv[PosIHave];                                                  // Durch die Übergebenen Parameter hangeln
        if (ChkPar(src[0])!=0) continue;                                        // darf als Parameter __NICHT__ gültig sein
        if (numFound==numToFind)
        {
            ARG = src;
            return PosIHave;                                                    // Wenn gefunden Fundstelle mitteilen (1-xxx)
        }
        numFound++;
    }
    return 0;
}



/**
 @brief Auswertung eine single Parameters
 @return Bei Fehler wird 0 zurückgegeben, ansonsten die Position in argv -- ARG zeigt auf einen Parameter, wenn dieser angegeben wurde oder NULL, wenn kein Parameter angegeben
 @param Find    was zu finden ist. z.B. -a

 Parameterübergabe sollten möglich sein.

 Statt - kann unter Windows auch / benutzt werden. Ausgeschlossen sind mehrere Zeichen,
 -version ö.Ä. nur Buchstaben von a-z oder Zahlen sollten Anwendung finden.

 wenn dem Parameter ein . vorangestellt ist, dann ist der folgende Parameter ohne Werte und wird auch so handelt.

 @code
 -d
 -d DEST
 -d=DEST
 -dDEST
 @endcode

  Überprüfung der Parameter mit Slash oder Minus übergeben wurden

*/

int aChkARG(char *Find)
{
    return ChkARGwStart(Find, 1, m_PRG_argc, m_PRG_arguv);
}

/**
 @brief Auswertung eine single Parameters
 @return Bei Fehler wird 0 zurückgegeben, ansonsten die Position in argv -- ARG zeigt auf einen Parameter, wenn dieser angegeben wurde oder NULL, wenn kein Parameter angegeben
 @param Find    was zu finden ist. z.B. -a
 @param arguc   Anzahl der Argumente
 @param arguv   String Feld, das durchsucht wird

 @see aChkARG
______________________________________________________________________________*/

int ChkARG(char *Find, int arguc, char *arguv[])
{
    return ChkARGwStart(Find, 1, arguc, arguv);
}

/**
 @brief Auswertung eine single Parameters
 @return Bei Fehler wird 0 zurückgegeben, ansonsten die Position in argv -- ARG zeigt auf einen Parameter, wenn dieser angegeben wurde oder NULL, wenn kein Parameter angegeben
 @param Find    was zu finden ist. z.B. -a
 @param start   erst ab dieser Stelle suchen
 @param arguc   Anzahl der Argumente
 @param arguv   String Feld, das durchsucht wird

 @see aChkARG

___[ Revision ]______________________________________________________________

 ** 20.02.20 HS arg_used[p]=1 wurde an der falschen Stelle gesetzt
 ** 15.12.23 HS Anpassungen wg. -"0-9" und doppelt -e möglich
____________________________________________________________________________*/

int ChkARGwStart(char *Find, int start, int arguc, char *arguv[])
{
    int singlePar,numPar;
    int p;
    char *src;

    PNUM = -1;
    ARG = NULL;
    singlePar = 0;
    numPar = 0;

    if (Find[0]=='#') return ChkParMain (Find, arguc, arguv);                   // Mainparameter #0 bis # #9999 sh. ohne ParameterSlashes
    if (Find[0]=='$') return ChkParWos  (Find, arguc, arguv);                   // Mainparameter $0 bis $9999 sh. ohne ParameterSlashes

    if (Find[0]=='.')
    {
        singlePar = 1;
        Find++;
    }
    if (ChkPar(Find[0])) Find++;
    if (Find[0]==0)                                                             // Prüfe ob erstes Zeichen ein Parameter ist
    {                                                                           // und das zweite Zeichen ungleich 0 ist
        lprintf ("%s can't used as Checkupparameter", Find);
        return 0;
    }
    if (Find[0]=='0')
    {
        if (Find[1]=='-')
        {
            if (Find[2]=='9')
            {
                if (!arg_used)
                {
                    lprintf ("0-9 ohne InitArg not working");
                    return 0;
                }
                numPar++;
            }
        }
    }

    for (p=start;;p++)                                                          // Alle Parameter
    {
        if (p>=arguc) break;                                                    // Ende ?
        src = arguv[p];                                                         // Durch die Übergebenen Parameter hangeln
        if (ChkPar(src[0])==0)                                                  // Wenn es kein gültiger Parameter ist
        {
            if (*Find!='*') continue;                                           // der auch aktuell nicht gefunden werden soll
            if (arg_used) arg_used[p]=1;                                        // setzen falls vorhanden
            ARG = src;
            return p;
        }
        if (arg_used) if (arg_used[p]) continue;                                // nur verarbeiten, wenn parameter noch nicht benutzt
//      if (ChkPar(src[0])==0) continue;                                        // muss als Parameter gültig sein
        src++;

        if (numPar)                                                             // find = "0-9"
        {
            if (!isdigit(src[0])) continue;                                     // übergen ist ein Parameter wie -15= ?
            if (arg_used) if (arg_used[p]) continue;

            for (PNUM=0;isdigit(src[0]);src++)                                  // dann alle alle Zeichen (Zahlen) abarbeiten
            {
                PNUM=PNUM*10;                                                   // das übliche in eine integer wandel....
                PNUM=PNUM+(src[0]-'0');
            }
        }else{                                                                  // Keine Zahl -15 gefordert, sonden ein Zeichen
            if (tolower(Find[0])!=src[0]) continue;                             // dann müssen die beiden stimmen
            src++;                                                              // und src muss dahinter zeigen
        }

        if (arg_used) arg_used[p]=1;                                            // setzen falls vorhanden
        if (singlePar) return p;

        if (src[0]==0)                                                          // möglicher Single Parameter, dann auf folgenden _Parameter_ prüfen
        {
            if ((p+1)<arguc)                                                    // Gibt es noch Parameter ?
            {
                if (!ChkPar(arguv[p+1][0]))                                     // Ist es auch kein anderer Parameter ?
                {
                    if (arg_used) arg_used[p+1]=1;                              // setzen falls vorhanden
                    ARG = arguv[p+1];                                           // Parameter zur Argument machen
                }
            }
        }else{
            if (src[0]=='=')  src++;                                            // Gleichheitszeichen überlesen
            if (src[0]!=0)                                                      // Vorhandenes Argument ?
            {
                ARG = src;
            }
        }

        if ( (isupper(Find[0])) && (ARG==NULL) )
        {
            if (arg_used) arg_used[p]=0;                                       // zurücksetzen falls vorhanden
            lprintf ("ARG are not optional for %s", Find);
            return 0;
        }
        return p;

    }
    return 0;
}
/**
 @brief Auswertung eines long Parameters
 @return Bei Fehler wird 0 zurückgegeben, ansonsten die Position in argv

 Nach langer Überlegung das gesammte Konzept anzupassen, können
 long Parameter nun genauso flexibel, wird shortparameter verwendet
 werden.

 Es können in der long--version nur doppelte Minuszeichen verwendet werden.
 Folgende Schreibweisen sind zulässig:

 @code
 --day
 --buffer 128             # Besonderheit, das kann in 2 argv's stehen
                          # kann aber auch in einem stehen
 --text=Hugo
 --File =autoexec.bat
 --max  = 2048
 @endcode

 Wird der Parameter nicht gefunden, wird 0 zurückgegeben.
 Ansonsten, die Position des Parameters

 Aus dem Konzept heraus können jetzt Konstrukte wie

 if ( ChkARGlong("help", argc,argv) || ChkARG("-?", argc,argv) || (argc<2) )
 {
      printf_help();
      exit(1);
 }
 Systemreserviert ist --version und --date

___[ Revision ]______________________________________________________________

 ** 22.03.20 HS Create
_____________________________________________________________________________*/

int ChkARGlong(char *Find, int argc, char *argv[])
{
    int p;
    int l;
    int br;
    char *src;

    ARG = NULL;

    for (p=1;;p++)                                                              // Alle Parameter
    {
        if (p>=argc) break;                                                     // Ende ?
        src = argv[p];                                                          // Durch die Übergebenen Parameter hangeln
        if (strncmp(src,"--",2)) continue;                                      // Ist es ein long Parameter ?
        src += 2;                                                               // "--" überlesen
        br = 0;                                                                 // br = 0 = Kein angehängtes Argument
        for (l=0;;l++)
        {
            if (src[l]==0) break;
            if (src[l]==' ')                                                    // br = 1 = Als erstes ein Space gefunden
            {
                br = 1;
                break;
            }
            if (src[l]=='=')                                                    // br = 2 = Als erstes ein '=' gefunden
            {
                br = 2;
                break;
            }
        }
        if ((int)strlen(Find)!=l) continue;                                     // beide müssen gleich lang sein
        if (strncasecmp(src,Find,l)) continue;                                  // in dieser Form, da hinter dem Parameter noch das Argument kommen kann
        if (arg_used) arg_used[p]=1;                                            // setzen falls vorhanden
        if (br==0)
        {
            if ((p+1)<argc)                                                     // Gibt es noch Parameter ?
            {
                if (!ChkPar(argv[p+1][0]))                                      // Ist es auch kein anderer Parameter ?
                {
                    if (arg_used) arg_used[p+1]=1;                              // setzen falls vorhanden
                    ARG = argv[p+1];                                            // Parameter zur Argument machen
                }
            }
            return p;
        }
        src += l;                                                               // Länge korrigieren
        if (br==1)                                                              // war es ein Leerzeichen, dann lese bis nichtSpace
        {                                                                       // wenn es kein '=' ist, dann br=3 ansonsten br=2
            for (l=0;;l++)
            {
                if (src[l]==0) return p;                                        // Außer Leerzeichen nix gewesen
                if (src[l]==' ') continue;                                      // diese werden überlesen
                src += l;                                                       // src auf das Zeichen setzen setzen
                if (src[0]=='=') br=2;                                          // '=' hier? das br mitteilen, das src auf '=' sind
                else br=3;                                                      // oder das das Argument gefunden wurde
                break;
            }
        }
        if (br==2)                                                              // war es ein '=', dann dahinter und überlese Spaces
        {
            for (l=1;;l++)                                                      // dann wird nur noch ein ' ' überlesen
            {
                if (src[l]!=' ') break;
            }
            br = 3;                                                             // auf fertiges Argument setzen
            src += l;                                                           // src korrigieren auf das Argument
        }
        if (br==3)                                                              // br muss hier 3 sein! Aus Sicherheitsgründen abgefangen
        {
            ARG = src;
            return p;
        }
        lprintf ("Unknown todo: should not happens [] ChkARGlong");
        break;
    }
    return 0;
}

/**
 @brief  CMD Zeilenparameter in Variablen schreiben
 @see ChkARGlong

___[ Revision ]______________________________________________________________

 ** 09.07.20 HS neu
_____________________________________________________________________________*/

int aChkARGlong(char *Find)
{
    return ChkARGlong(Find, m_PRG_argc, m_PRG_arguv);
}
///@}


/**
 @addtogroup c_lprintf
 @{
 @brief Ausgeben von Lognachrichten (mit Datum und Uhrzeit) zu einem oder mehreren Ausgaben.

 mehr bei @see lprintf
 @see lmsg

 ** 02.04.06 HS ReCreate
*/ /**
 @brief Ausgeben von Lognachrichten (mit Datum und Uhrzeit) zu einem oder mehreren Ausgaben.
 @return EXIT_SUCCESS wenn alles OK war, sonst Fehler
 @param fmt wie bei printf
 @param ... die Parameter, wie bei printf

 Gesteuert wird lprintf über die Variable LogType, diese enthält
 Bitorientiert die Ausgabekanäle.

 @anchor LOG_Ausgabekanaele
 Mögliche Ausgabekanäle sind:

 Bit       | defVAL      | Ausgabe      | Bemerkung
 ----------|-------------|--------------|----------
 0000 0001 | LOG_STDOUT  | stdout       | normalerweise der Bildschirm
 0000 0010 | LOG_STDERR  | stderr       | normalerweise der Bildschirm
 0000 0100 | LOG_LOGFILE | logfile      | ein File - eine Logdatei dflt: ProgrammName.log wenn mit %d in den OPTS im @ref InitTools gestartet, dann mit Datum
 0000 1000 | LOG_SYSLLOG | syslog       | unter unix wie syslog, unter Windows im Userverzeichenis AppData\\Local ferne in der Variablen SYSLOGFILE
 0001 0000 | LOG_SIGNAL  | signalhandler| nicht mehr verfügbar --- war nur unter Windows verfügbar in Unix zZ. nicht implmentiert
 0010 0000 | LOG_CACHE   | special      | Hier wird nur in großen Blöcken ins LogFile geschrieben, um die I/O zu reduzieren.
 0100 0000 | LOG_WINMSG  | windebuglog  | Das Windowseigene Logsystem wird bedient; eignet sich sehr gut, wenn viele Programme ineinandergreifen

 @note LOG_SYSLOG ist unter Unix bereits in /usr/include/syslog.h definiert. DH. wird LOG_SYSLLOG als Variable benutzt.

 Alle Zeilen haben den gleichen, grundsätzlichen Aufbau, wie ein syslog unter Unix.
 @code
 Beispiel:
 Mar 18 10:54:59 KAFPRG Starte jetzt die Kaffeemaschine
 @endcode

 Ferner kann das Aussehen der Logzeile über die Variable @em LogExtra gesteuert werden. Kurze und präzise ExtraInformationen oder
 zusätzliche Modulinformationen lassen sich so informativ unterbringen. @em LogExtra kann auch mit anderen Informationen gefüttert werden
 Sollen diese Informationen ausgegeben werden, dann ist das mit dem ( bool @ref LogFileWithExtra ) ein-/aus-/umschaltbar.

 @code
 Beispiel:

 LogExtra = "CallerID";
 lprintf ("misplaced number");
 lprintf ("stack not empty");

 Wird im Logfile zu:
 Mar 18 12:43:03 CallerID misplaced number
 Mar 18 12:43:03 CallerID stack not empty
 @endcode

 Das Aussehen kann nahezu frei angepasst werden. Sowohl das Datum in der Logdatei, wie die Informationen selbst. Unter Windows kann auch dass Datum
 angepasst werden. Wird die Funktion @em syslog selbst aufgerufen ist die Datumsform nicht änderbar.

  @see InitTools

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 25.06.20 HS Nach Prüfungsphase von strprintf jetzt für lprintf eingesetzt
 ** 27.06.20 HS Windows Logging in der Ansi-Version realisiert
 ** 30.06.20 HS Anpassungen vom neuen InitTools übernommen
___________________________________________________________________________*/

int lprintf(char *fmt, ...)
{
    int     rtCode;                     // ReturnCode 0 ansonsten Fehler
    char    syslog_timestr[24];         // benutzt für syslog timestring
    char    isodate_timestr[24];        // benutzt für iso timestring
    char    *errtext;                   // buffer für strprintf
    char    *nextline;                  // buffer Zeichen nach CR/LF
    char    FileName[PATH_MAX];         // LogFileName
    char    *XFileName;                 // Pointer are schnelleres strcpy
    time_t  now;                        // aktuelle Zeit

    va_list argptr;                     // variablelist
    struct tm *mytime;                  // structure für strftime

    FILE *P;                            // Logfile

    nextline = NULL;

    rtCode  = EXIT_SUCCESS;             // default exit_success
    now     = unixtime();               // Aktuelle Systemzeit
    mytime  = localtime ( &now );       // nach mytime sichern


    // Nachricht Selbst erzeugen
    //_______________________________________________________________________

    va_start(argptr, fmt);
    errtext = vstrprintf(fmt, argptr);
    va_end(argptr);

    if (lprintfConvertCRLF == true)       //--->>    CleanUp erlaubt ??
    {
        char    *tmp;
        strdelchar(errtext,'\r');       // möglichen CR entfernen ....
        tmp = strchr(errtext,'\n');     // wenn LF, dann dort 0 Rest muss dann
        if (tmp)                        // LF gefunden ?
        {
            *tmp='\0';                  // dort 0 einpflanzen
            tmp++;                      // auf den rest der Zeile
            nextline = strdup(tmp);     // neuen Speicher, da errtext ja freigegeben wird
        }
    }

    // *_timestr mit dem aktuellen Datum / Zeit füllen
    // Syslog  sollte im Format "Mar 18 11:05:04 " sein.
    // IsoDate sollte im Format "2020-06-27 18 11:05:04 " sein.
    //                           012345678901234567890123456
    //_______________________________________________________________________


    strftimeR( syslog_timestr,  sizeof( syslog_timestr)-2 ,  SyslogDateFormat,  mytime);
    strftimeR(isodate_timestr,  sizeof(isodate_timestr)-2 ,  LogDateFormat,     mytime);


    // Nach Auswertung vom LogType Ausgabe starten
    //_______________________________________________________________________

    // printf ("LOGTYPE is %i\n", LogType);

    if (LogType & LOG_STDOUT)           // Ausgabe nach standardout
    {                                   //___________________________________
        printf("%s",isodate_timestr);
        if ( (LogExtra!=NULL) && (LogFileWithExtra) ) printf("%s ",LogExtra);
        printf("%s\n", errtext);
    }

    if (LogType & LOG_STDERR)           // Ausgabe nach  standarderror
    {                                   //___________________________________
        fprintf(stderr, "%s",isodate_timestr);
        if ( (LogExtra!=NULL) && (LogFileWithExtra) ) fprintf(stderr, "%s ",LogExtra);
        fprintf(stderr, "%s\n", errtext);
    }

    if (LogType & LOG_LOGFILE)          // Ausgabe in ein logfile
    {                                   //___________________________________
        if (LogFileName!=NULL)          // Name gegeben ?
        {
            if ((LogType & LOG_CACHE))
            {
                // atexit ggf. ausführen
                if (LogAtExitFlush==false)
                {
                    LogAtExitFlush=true; // Das sollte einzig sein, damit nur einmal atexit installiert wird
                    atexit (exitlprintfflush);
                }
                sprintf_ex (FileName,"%s-%ld", LogFileName, (long) getpid());
                XFileName=FileName;
            }else{
                XFileName=LogFileName;
            }
            if( ( P = fopen(XFileName , "at")) != NULL )
            {
                fprintf(P, "%s", isodate_timestr);
                if ( (LogExtra!=NULL) && (LogFileWithExtra) ) fprintf(P, "%s ",LogExtra);
                fprintf(P, "%s\n", errtext);
                fclose (P);
            }else{
                rtCode = EXIT_FAILURE;              // Fehler mitteilen
            }
        }else{
            rtCode = EXIT_FAILURE;                  // Fehler mitteilen
        }
    }

    if (LogType & LOG_SYSLLOG)          // printout to Windows-Syslog
    {

#ifdef OS_LINUX
        syslog (LOG_ERR, "%s", errtext);
        //syslog (LOG_CRIT , "%s", Str);
        //printf ("syslog (LOG_ERR, \"%s\", Str);\n", Str);
		//LOG_MAKEPRI(LOG_SYSLOG, "Hallo");
#endif

#ifdef OS_WINDOWS
        if( ( P = fopen(SYSLOGFILE , "at")) != NULL )
        {
            fprintf(P, "%s", syslog_timestr);
            if (LogExtra!=NULL) fprintf(P, "%s ",LogExtra);
            fprintf(P, "%s\n", errtext);
            fclose (P);
        }else{
            rtCode = EXIT_FAILURE;                  // Fehler mitteilen
        }
#endif
    }
#ifdef OS_WINDOWS
    if (LogType & LOG_WINMSG)
    {
        char *s;
        if (LogExtra!=NULL ) s = strprintf("%s %s", LogExtra, errtext);
        else                 s = strdup(errtext);
        OutputDebugStringA(s); //(LPCWSTR)
        free(s);
#ifdef OLD_STUFF
        char *s;
        char *t;

        if (LogExtra!=NULL )
        {
            s = strdup(LogExtra);
            t = stradd(s, " ");
            s = t;
        }else{
            s = NULL;
        }
        t = stradd (s, errtext);

        OutputDebugStringA(t); //(LPCWSTR)
        free(t);
#endif
    }
#endif
    free(errtext);
    if (nextline)                                                       // kann nur != NULL sein, wenn lprintfConvertCRLF auf true ist
    {
        if (rtCode==EXIT_SUCCESS) rtCode = lprintf ("%s",nextline);     // wenn bisher alles erfolgreich war, dann  nächste Zeile ausgeben
        free(nextline);
    }
    return(rtCode);
}

///@brief für atexit - kann nur mit void arbeiten
void exitlprintfflush(void){lprintfflush();}

/**
 @brief Zwischenspeicher von Lognachrichten flushen
 @return 0 wenn OK
 - -1 No Caching active
 - -2 Error ( Permisssion denied etc. opening LogFile)
 - -3 Error ( Cant Read TempFile, but they exists

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

int lprintfflush(void)
{
    char    FileName[PATH_MAX];                                                 // LogFileName
    char    *buffer;
    int     BufLen;
    FILE    *S,*D;

    if (!(LogType & LOG_CACHE)) return -1;                                      // Wenn Caching nicht aktiv
    // LogType &= ~LOG_CACHE;                                                      // Entferne Cache-Bit ??
    sprintf_ex (FileName,"%s-%ld", LogFileName, (long) getpid());               // Wie lautet der Filename für Caching
    if (!FileOK(FileName)) return 0;                                            // 0 Zeilen, aber keine Fehler, wenn keine Fehler vorhanden war

    if( ( D = fopen(LogFileName , "ab")) == NULL ) return -2;                   // can't write to LOG
    if( ( S = fopen(FileName    , "rb")) == NULL )
    {
        fclose (D);
        return -3;
    }
    buffer = malloc(1024);
    for (;;)
    {
        BufLen=fread(buffer, 1, 1024, S);
        if (BufLen==0) break;
        fwrite(buffer, 1, BufLen, D);
    }
    free (buffer);
    fclose (D);
    fclose (S);
    if (remove (FileName) != 0)                                                 // Cachezwischenspeicher löschen
    {
        //perror ("remove");
    }
    //lprintf ("FILENAME: \"%s\"", FileName);
    return 0;
}

/**
 @brief Initialisieren der Felder etc für @ref lmsg
 @return EXIT_SUCCESS zZ. kein anderer Level

___[ Revision ]______________________________________________________________

 ** 15.06.20 HS Create (tooltest)
 ** 08.07.20 HS Implementiert in tools.c
___________________________________________________________________________*/

int lmsg_init(void)
{
    lmsg_level  = LMSG_EVERY;
    lmsg_format = 0;

    lmsg_def[LMSG_SILENT]   = (lmsg_t) { .out = LOG_STDERR + LOG_LOGFILE + LOG_SYSLLOG + LOG_WINMSG,  .str="SILENT" };
    lmsg_def[LMSG_CRITICAL] = (lmsg_t) { .out = LOG_STDERR + LOG_LOGFILE + LOG_SYSLLOG,               .str="CRITICAL" };
    lmsg_def[LMSG_ERROR]    = (lmsg_t) { .out = LOG_STDERR + LOG_LOGFILE,                             .str="ERROR" };
    lmsg_def[LMSG_WARN]     = (lmsg_t) { .out = LOG_STDERR + LOG_LOGFILE,                             .str="WARN" };
    lmsg_def[LMSG_EVERY]    = (lmsg_t) { .out = LOG_STDOUT + LOG_LOGFILE,                             .str="EVERY" };
    lmsg_def[LMSG_MOST]     = (lmsg_t) { .out = LOG_STDOUT + LOG_LOGFILE,                             .str="MOST" };
    lmsg_def[LMSG_MAX]      = (lmsg_t) { .out = LOG_STDOUT + LOG_LOGFILE,                             .str="MAX" };
    return EXIT_SUCCESS;
}

// so nicht drin, aber Nostalgie ist auch was schönes
// lmsg_setup( LMSG_SET_LEVEL, LMSG_ERROR );
// int lmsg_setup( int do_what, int parm );

/**
 @brief Nachrichten, abhängig von der Entscheidung des Programmnutzer ausgeben
 @param behavior Nachrichtenlevel
 @param fmt wie bei printf
 @param ... die Parameter, wie bei printf
 @return EXIT_SUCCESS  EXIT_FAILURE nur, wenn die Nachricht nicht ausgegeben oder hätte ausgegeben werden können

 Ziel ist es Nachrichten auszugeben, welche der Benutzer in welcher Tiefe haben möchte. Das Aussehen wird aber im wesentlichen von @ref lprintf gesteuert.
 Einstellungen für lprintf werden @b nicht ver-/geändert ! Es ist durchaus möglich lmsg und lprintf gleichzeitig zu verwenden

 @note Es sollte eine Funktion geschaffen werden mit der der aktuelle @ref lmsg_level vom Benutzer festgelegt werden kann.

 @code
 lmsg ( LMSG_WARN, "Der Kaffee ist nur noch lauwarm");
 @endcode


___[ Revision ]______________________________________________________________

 ** 19.02.20 HS in HSbackup ( DMSG )
 ** 09.06.20 HS Das erste Mal strprintf genutzt
 ** 15.06.20 HS Create (tooltest)
 ** 08.07.20 HS Implementiert in tools.c
___________________________________________________________________________*/

int lmsg (int behavior, char *fmt, ...)
{
    char *buffer;
    char extra[16];

    va_list	argp;
    int old_logtype;

#ifndef HS_DEBUG
    if ( behavior == LMSG_SILENT) return EXIT_SUCCESS;
#endif // HS_DEBUG

    if ( behavior > LMSG_MAX)   return EXIT_FAILURE;
    if ( behavior > lmsg_level) return EXIT_SUCCESS;

    va_start(argp, fmt);
    buffer = vstrprintf(fmt, argp);
    va_end(argp);

    switch (lmsg_format) {
        case 1: sprintf_ex (extra,"[%i] ", behavior );
                break;
        case 2: sprintf_ex (extra,"[%s] ", lmsg_def[behavior].str );
                break;
        default: extra[0]=0;
                break;
    }

    old_logtype     = LogType;
    LogType = lmsg_def[behavior].out;

    lprintf ("%s%s", extra, buffer);

    LogType = old_logtype;
    free(buffer);
    return EXIT_SUCCESS;
}


///@}

/**
 @addtogroup c_uname
 @{
 @brief Füllt ein Struct utsname mit Informationen über die aktuelle Maschine
 @return -1 bei Fehlern ansonsten 0
 @param name Zeiger auf den utsname Buffer

 Unter Windows gibt es kein UName, aber die Informationen können trotzdem
 hilfreich rein.

 @code
 Folgender struct wird gefüllt.

 struct utsname {               // Beispiel
    char sysname[];             // Windows
    char nodename[];            // PC-HESTI
    char release[];             // 6.1
    char version[];             // #7601 07/22/2009
    char machine[];             // x86
    char domainname[];          // ?
 };
 @endcode

___[ Revision ]______________________________________________________________

 ** 05.02.19 Updated
 ** 06.02.19 Updated
___________________________________________________________________________*/

#ifdef OS_WINDOWS
int uname(struct utsname *name)
{
    int major;
    int minor;
    int build;
    char *ComputerName;
    DWORD number;

    major = 0;
    minor = 0;

    char SWT[] = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion";
    char buffer[256];
    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"CurrentVersion", buffer, sizeof(buffer)) == ERROR_SUCCESS)
    {
        char *s;
        s = strchr(buffer,'.');
        if (s)
        {
            *s = '\0';
            s++;
            minor = atoi(s);
        }
        major = atoi(buffer);
    }
    sprintf_ex(name->release, "%i.%i", major,minor);

    major = 99;
    minor = 99;
    build = 99;

    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"CurrentBuild", buffer, sizeof(buffer)) == ERROR_SUCCESS) build = atoi(buffer);
    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"CurrentMajorVersionNumber", (char *)&number, sizeof(number)) == ERROR_SUCCESS) major = number;
    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"CurrentMinorVersionNumber", (char *)&number, sizeof(number)) == ERROR_SUCCESS) minor = number;
    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"UBR", (char *)&number, sizeof(number)) != ERROR_SUCCESS) number=0;

    sprintf_ex(name->version, "%i.%i.%i.%i", major, minor, build, (int)number);

    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"InstallDate", (char *)&number, sizeof(number)) != ERROR_SUCCESS) number=0;
    if (number>0)
    {
        strcat_ex (name->version," ");
        strcat_ex (name->version,strtime((time_t)number,8));
    }

    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"DisplayVersion", buffer, sizeof(buffer)) == ERROR_SUCCESS)
    {
        strcat_ex (name->release," ");
        strcat_ex (name->release,buffer);
    }

    if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"ProductName", buffer, sizeof(buffer)) == ERROR_SUCCESS)
    {
        strcpy_ex(name->sysname, buffer);
    }else{
        strcpy_ex(name->sysname, "Windows");
    }


#if 0
    char *sysbuild;
    sysbuild = NULL;
    OSVERSIONINFO   osinfo;
    // Get Windows version info ( from HSsysInfo )
    ZeroMemory(&osinfo, sizeof(OSVERSIONINFO));
    osinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (!GetVersionEx(&osinfo)) return -1;

    major = osinfo.dwMajorVersion;
    minor = osinfo.dwMinorVersion;
    build = osinfo.dwBuildNumber;

// mehr auf https://en.wikipedia.org/wiki/Windows_10_version_history
sysbuild = NULL;
     if (build== 950) sysbuild = "08/24/1995"; // 4.0 WIN95
else if (build==2222) sysbuild = "06/25/1998"; // 4.1 WIN98
else if (build==2600) sysbuild = "10/25/2001"; // 5.1 WINXP
else if (build==3790) sysbuild = "04/25/2005"; // 5.2 WINXP Pro X64
else if (build==6002) sysbuild = "01/30/2007"; // 6.0 Windows Vista
else if (build==7601) sysbuild = "07/22/2009"; // 6.1 Windows 7
else if (build==9200) sysbuild = "10/26/2012"; // 6.2 Windows 8
else if (build==9600) sysbuild = "10/17/2013"; // 6.3 Windows 8.1
//===============

else if (build>=10240) {                        // WIN 10
                      sysbuild= "07/29/2015 * 1507";
    if (build>=10586) sysbuild= "10/10/2015 * 1511";
    if (build>=14393) sysbuild= "08/02/2016 * 1607";
    if (build>=15063) sysbuild= "04/05/2017 * 1703";
    if (build>=16299) sysbuild= "10/17/2017 * 1709";
    if (build>=17134) sysbuild= "04/30/2018 * 1803";
    if (build>=17763) sysbuild= "11/13/2018 * 1809";
    if (build>=18362) sysbuild= "03/28/2019 * 1903";
    if (build>=18363) sysbuild= "11/12/2019 * 1909";
    if (build>=19041) sysbuild= "05/27/2020 * 2004";
    if (build>=19042) sysbuild= "10/20/2020 * 20H2";
    if (build>=19043) sysbuild= "../../2021 * 2103";
}
#endif

    SYSTEM_INFO     sysInfo;
    ZeroMemory(&sysInfo, sizeof(SYSTEM_INFO));
    GetSystemInfo(&sysInfo);

    ComputerName=getenv("COMPUTERNAME");
    if (ComputerName) strcpy_ex (name->nodename, ComputerName);

    switch(sysInfo.wProcessorArchitecture)
    {
        case PROCESSOR_ARCHITECTURE_AMD64:
            strcpy(name->machine, "x86_64");
            break;
        case PROCESSOR_ARCHITECTURE_IA64:
            strcpy(name->machine, "ia64");
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            strcpy(name->machine, "x86");
            break;
        case PROCESSOR_ARCHITECTURE_ARM :
            strcpy(name->machine, "ARM");
            break;
        case PROCESSOR_ARCHITECTURE_UNKNOWN:
        default:
            strcpy(name->machine, "unknown");
    }

    //System
    //GetComputerNameExA(5,ComputerName,32);
    strcpy (name->domainname,"");
    //sprintf (name->domainname,"%x", _WIN32_WINNT);
    return 0;
}
/*
CString GetStringFromReg(HKEY keyParent, CString keyName, CString keyValName)
{
    CRegKey key;
    CString out;
    if (key.Open(keyParent, keyName, KEY_READ) == ERROR_SUCCESS)
    {
        ULONG len=256;
        key.QueryStringValue(keyValName, out.GetBuffer(256), &len);
        out.ReleaseBuffer();
        key.Close();
    }
    return out;
}
*/

/**
 @brief Registery Eintrag lesen.
 @return
 @param keyParent  HKEY z.B. der HKEY_LOCAL_MACHINE
 @param keyName    pointer auf den MainKey
 @param keyValName die Value
 @param buffer     pointer auf den Buffer
 @param bufsize    Größe des Buffers

 Buffer kann NULL sein, dann aber keinen Rückgabewert. Sinvoll, wenn nur die Existenz abgefragt werden soll

 An der bufsize-Groesse wird der RRF-Wert bestimmt.

 Beispiel:
 @code

 if ( readWindowsRegistery( HKEY_LOCAL_MACHINE, SWT, (char*)"CurrentMajorVersionNumber", (char *)&number, sizeof(number)) == ERROR_SUCCESS) major = number;
 else major=-1;

 @endcode



___[ Revision ]______________________________________________________________

 ** 23.12.20 HS Create
___________________________________________________________________________*/

int readWindowsRegistery(HKEY keyParent, char *keyName, char *keyValName, char *buffer, int bufsize)
{
    DWORD dataSize;
    DWORD RRF_word;
    dataSize = bufsize;

    RRF_word = RRF_RT_REG_SZ;
    if (bufsize==sizeof(DWORD)) RRF_word = RRF_RT_REG_DWORD;

    LONG ret = RegGetValueA(keyParent, keyName, keyValName, RRF_word, 0, buffer, &dataSize);
    return ret;
}
#endif // OS_WINDOWS
///@}

/**
 @addtogroup c_strchr
 @{
 @brief Funktionen mit und um Strings und chars

 <u>Strings in C</u>

 gibt es nicht. In C sind es eine Aneinandereihung von Zeichen. Oft auch als
 Zeichenketten bezeichnet. Ein Zeichen in C ist ein char. Das ist eine
 8-Bit grosse Zahl. Oft wird trotzdem von einem String gesprochen.
 Per Definition wird ein String mit einer abschließenden 0 in einem char Feld
 gespeichert.

 @note strupr & strlwr sind unter Windows implementiert unter Unix fehlten diese

*/

/**
 @addtogroup c_strchr_macros
 @{
 @brief Lokale Macrodefinitionen

*/

/// Wie gross der Zwischenbuffer zum escapen werden kann. Es handelt sich um einen Faktor. Es werden derzeit 120% des Orginalbuffers geschätzt @see strEsc <- wird hier verwendet
#define BIGBUFFER_FAKTOR 120
/// Größe der Zeichenkette für binstr  @see binstr <- wird hier verwendet
#define BIN_INT_SIZE (sizeof (unsigned int) *8)
/// defeniert wie gross der Buffer ist, bevor ein realloc gemacht werden muss siehe @ref y_charadd
#define YSTRING_BLOCKSIZE 64

///@}


/**
 @addtogroup c_strchr_manipulations
 @{
 @brief Zeichenkettenmanipulation

 @see CL     Von einem String links und rechts Leerzeichen entfernen
 @see stradd Einen String dynamisch erweitern

*/


/**
 @brief Wie oft ein Zeichen in einem String ist
 @return Anzahl der Zeichen
 @param STRING zu durchsuchende Zeichenkette
 @param FOUND  zu findendes Zeichen

___[ Revision ]______________________________________________________________

 ** 11.07.16 HS Create
___________________________________________________________________________*/

int strcount(char *STRING,char FOUND)
{
    int i;
    int f;

    for (i=0,f=0;;i++)
    {
        if (STRING[i]==0) break;
        if (STRING[i]==FOUND) f++;
    }
    return f;
}

/**
 @brief Position der Zeichenkette FIND im gegebenen String STRING ab position from
 @return Position der Fundstelle oder -1 bei nicht vorhanden sein.
 @param STRING zu durchsuchende Zeichenkette
 @param FIND   zu findende Zeichenkette
 @param from   ab Position suchen

___[ Revision ]______________________________________________________________

 ** 08.11.17 HS Create
___________________________________________________________________________*/

int strstrpos(char *STRING,char *FIND, int from)
{
    int k,p,l;

    if (STRING==NULL) return -1;                                                // verschiedene Fehlerszenario
    if (FIND==NULL)   return -1;
    if (from<0)       return -1;

    l = strlen(STRING);
    if (l<=0)         return -1;
    if (from>=l)      return -1;
    // doppelt if (from<0)       return -1;

    l = strlen(FIND);                                                           // zu findene Länge merken
    if (l<=0)              return -1;                                           // out of Range prüfen

    for (k=from;;k++)                                                           // Alle Zeichen in STRING abgegehen
    {
        if (STRING[k]==0) return -1;                                            // Wenn am Ende, dann Nicht gefunden melden
        for (p=0;;p++)
        {
            if (FIND[p]==0) return k;
            if (FIND[p]!=STRING[p+k]) break;
        }
    }
}


/**
 @brief Position des char FIND im gegebenen String STRING ab Position from
 @return Position der Fundstelle oder -1 bei nicht vorhanden sein.
 @param STRING zu durchsuchende Zeichenkette
 @param FIND   zu findende Zeichenkette
 @param from   ab Position suchen

___[ Revision ]______________________________________________________________

 ** 09.04.18 HS Create
___________________________________________________________________________*/

int strchrpos(char *STRING,char FIND, int from)
{
    int k,l;

    if (STRING==NULL) return -1;                                                // verschiedene Fehlerszenario
    if (from<0)       return -1;

    l = strlen(STRING);
    if (l<=0)         return -1;
    if (from>=l)      return -1;

    for (k=from;;k++)                                                           // Alle Zeichen in STRING abgegehen
    {
        if (STRING[k]==0) return -1;                                            // Wenn am Ende, dann Nicht gefunden melden
        if (STRING[k]==FIND) return k;                                          // gefunden !
    }
    return -1;
}


#ifdef OS_LINUX
/**
 @brief String Uppcase/lowerCase wandeln
 @return String
 @param STRING zu wandelnde Zeichenkette

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

char *strupr( char *Kette )
{
    unsigned int i;
    for (i=0;;i++)
    {
        if (Kette[i]==0) break;
        if (Kette[i] < 'a' ) continue;
        if (Kette[i] > 'z' ) continue;
        Kette[i]=Kette[i]-0x20;
    }
    return Kette;
}

///@copydoc strupr
char *strlwr( char *Kette )
{
    unsigned int i;
    for (i=0;;i++)
    {
        if (Kette[i]==0) break;
        if (Kette[i] < 'A' ) continue;
        if (Kette[i] > 'Z' ) continue;
        Kette[i]=Kette[i]+0x20;
    }
    return Kette;
}
#endif
#if 0
/* *
 @brief Gibt zurück, ob es sich um <b>EINEN</b> String handelt
 @return EXIT_SUCCESS / EXIT_FAILURE
 @param STRING zu prüfender String

 Gibt EXIT_SUCCESS im Erfolgsfall zurück. EXIT_FAILURE wenn es nicht ein einzelner String ist.

___[ Revision ]______________________________________________________________

 ** 18.08.20 HS Create
___________________________________________________________________________*/

int isOneString(char *STRING)
{
    char c;
    char Delim;
    int pos;

    Delim = 0;
    for (pos=0;;pos++)
    {
        c = STRING[pos];
        if (c == 0) break;
        if (isspace(c))
        {
            if (Delim==0) return EXIT_FAILURE;
            continue;
        }
        if (Delim==0)
        {
            if ( (c=='\"') || (c=='\'') )
            {
                Delim = c;
                continue;
            }
        }else{
            if ( c==Delim )
            {
                Delim = 0;
                continue;
            }
        }

    }
    if (Delim!=0) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
#endif

/**
 @brief Gibt definitiv einen String zurück bei NULL ""
 @return String
 @param C zu Prüfstring

___[ Revision ]______________________________________________________________

 ** 25.12.16 HS Create
___________________________________________________________________________*/

char *strNotNULL(char *C)
{
    if (C) return (C);
    return "";
}

/**
 @brief Aus einem String einen Teil entfernen
 @return String
 @param STRING die zu bearbeitende Zeichenkette
 @param pos    ab hier löschen
 @param len    Anzahl der Zeichen die gelöscht werden

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

char *strdel(char *STRING, int pos, int len)
{
    int i;

    if (len<=0) return STRING;                                                  // Mindestens 1 Zeichen löschen
    if (strlen(STRING)<=(size_t)pos) return STRING;                             // Nur wenn Position möglich ansonsten ..

    if (strlen(&STRING[pos]) <= (size_t)len )                                   // Nur wenn die Anzahl gelöscht werden können
    {
        STRING[pos]=0;                                                          // Groesse muss passen
        return STRING;
    }

    for (i=pos;;i++)
    {
        if (STRING[i]==0) break;                                                // Ende prüfen
        if (STRING[i+len]==0)                                                   // Ende des gesuchten
        {
            STRING[i]=0;
            break;                                                              // Auf Ende prüfen
        }
        STRING[i]=STRING[i+len];                                                // Kopiere Zeichen
    }
    return STRING;
}

/**
 @brief Fügt einen String in einen anderen ein
 @param STRING String der geändert werden soll
 @param INS    String der eingefügt werden soll
 @param pos    Ab welcher Position eingefügt werden soll

 @code

            012345678901
 String wie abcdefhijklm

 aufgerufen mit
 strins (*StringLikeAbove, "xyz", 3);

 wird werden zu:

         012345678901234
         abcxyzdefhijklm
           ^^^^^
 Nochmal eine übliche Form:

 STRING   = 1234567890
 INS      = abc
 pos      = 3
 STEP1    = 123...4567890
 STEP2    = 123abc4567890
 @endcode

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 11.07.20 HS mögliches MemoryLeak abgefangen
___________________________________________________________________________*/

void strins(char *STRING, char *INS, int pos)
{
    int i,l,s;
    l=strlen(INS);
    s=strlen(STRING);
    if (pos>s) return;
    for (i=s;i>=pos;i--)                                                        // Verschieben der restlichen Zeichenkette
    {
        STRING[i+l]=STRING[i];                                                  // um Platz für den Teil von "Insert" zu machen
    }
    for (i=pos,l=0;;i++,l++)                                                    // Jetzt den neuen Teil übertragen
    {
        if (INS[l]==0) break;
        STRING[i]=INS[l];
    }
}

/**
 @brief Fügt einen String an einen anderen an
 @param STRING String der geändert werden soll
 @param INS    String der angefügt werden soll


___[ Revision ]______________________________________________________________

 ** 18.03.24 HS First Release
___________________________________________________________________________*/

void strappend (char *STRING, char *INS)
{
    int i, l;
    if (!STRING) return;
    if (!INS) return;
    if (!INS[0]) return;
    l = strlen(STRING);
    for (i=0;;i++)
    {
        STRING[i+l]=INS[i];
        if (!INS[i]) break;
    }
    return;
}


/**
 @brief sowas ähnliches wie strcat
 @return 0 Error bzw. Anzahl der erfolgreich kopierten Zeichen
 @param [in]     start_ptr   Start Pointer
 @param [out]    end_ptr    Ende Pointer
 @param [in]     str         String der kopiert wird.
 @param [in,out] size_cnt    Anzahl der Zeichen

 Sowas ähnliches wie strcat, nur wird die Anzahl der kopierten Zeichen
 zurückgegeben und es wird ein pointer auf das letzte Zeichen positioniert
 im Fehlerfall wird 0 zurückgegeben. Im Erfolgsfall die Anzahl der kopierten
 Zeichen. Da auch das NULLbyte ein Zeichen ist kann auch ein Leerstring
 erfolgreich kopiert worden sein.

___[ Revision ]______________________________________________________________

 ** 02.03.19 HS Neu für strftimeR
___________________________________________________________________________*/

int strstradd (char *start_ptr, char **end_ptr, char *str, int *size_cnt)
{
    int  cnt;
    char *ptr;

    ptr = start_ptr;
    for (cnt=0;;cnt++,ptr++,str++)
    {
        if (*size_cnt<=0) return -1;
        *ptr=*str;
        if (*ptr==0) break;
        *size_cnt=(*size_cnt)-1;
    }
    *end_ptr=ptr;
    return cnt;
}

/**
 @brief String beliebig mit einem Zeichen füllen
 @param [out] dest    Zeichenkette, die geschrieben wird.
 @param [in]  filler  char mit dem gefüllt wird
 @param [in]  counter Anzahl die im String stehen sollen


___[ Revision ]______________________________________________________________

 ** 28.03.20 HS Neue Funktion
___________________________________________________________________________*/

void strsetto (char *dest, char filler, int counter)
{
    if (counter>0) memset_ex(dest,filler,counter);
    dest[counter]=0;
}

/**
 @brief String beliebig mit einem Zeichen füllen
 @return String gefüllte Zeichenkette
 @param [in]  filler  char mit dem gefüllt wird
 @param [in]  counter Anzahl die im String stehen sollen


___[ Revision ]______________________________________________________________

 ** 01.10.22 HS Neue Funktion
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char* strfiller (char filler, int counter)
{
    char* outfiller;
    outfiller = NULL;
    if (counter>=0)
    {
        outfiller = malloc_temp(counter+2);
        memset_ex(outfiller,filler,counter);
        outfiller[counter]=0;
    }
    return outfiller;
}

/**
 @brief Return Right Chars
 @return String (Kopie)
 @param STRING die zu bearbeitende Zeichenkette
 @param len    Anzahl der Zeichen die gelöscht werden

 Wenn im STRING weniger Zeichen als STRING_MAX sind, dann werden
 weniger Zeichen zurückgegeben

___[ Revision ]______________________________________________________________

 ** 29.11.16 HS Create
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *RightStr (char *STRING, int len)
{
    int l;
    int s;
    char *rslt;

    if (!STRING)                                            // Sicherheitsabfrage ob String gefüllt ist.
    {
        rslt=malloc_temp(2);                                // mit leeren String zurückkommen
        return rslt;
    }

    l = len;                                                // max. auf STRING_MAX begrenzen
    if (l>STRING_MAX) l=STRING_MAX;
    s = strlen(STRING);
    rslt=malloc_temp(s+1);
    if (s<=l)                                               // String ist kleiner als len
    {
        strcpy_ex (rslt,STRING);
        return rslt;
    }
    strcpy_ex (rslt,&STRING[s-l]);
    return rslt;
}

/**
 @brief Return Left Chars
 @return String (Kopie)
 @param STRING die zu bearbeitende Zeichenkette
 @param len    Anzahl der Zeichen die gelöscht werden

 Wenn im STRING weniger Zeichen als STRING_MAX sind, dann werden
 weniger Zeichen zurückgegeben

___[ Revision ]______________________________________________________________

 ** 29.11.16 HS Create
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *LeftStr (char *STRING, int len)
{
    int l,s;
    char *rslt;

    if (!STRING)                                            // Sicherheitsabfrage ob String gefüllt ist.
    {
        rslt=malloc_temp(2);                                // mit leeren String zurückkommen
        return rslt;
    }

    l = len;                                                // max. auf STRING_MAX begrenzen
    if (l>STRING_MAX) l=STRING_MAX;
    if (l<0) l=0;
    s = strlen(STRING);
    if (l>s) l=s+1;
    rslt = malloc_temp(l+2);
    memset_ex(rslt,'*',l+2);
    strncpy_ex (rslt,STRING,l);
    rslt[l]=0;
    return rslt;
}

/**
 @brief Strings an einen str mit realloc dranhängen
 @return Pointer auf den neuen String
 @param STRING die zu bearbeitende Zeichenkette
 @param AddStr Anzuhängender String

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

char *strstrcat(char *STRING, char *AddStr)
{
    //lprintf ("FSC1: (%s) %s", STRING, AddStr);
    if (AddStr[0]!=0)
    {
        if (STRING==NULL)
        {
            STRING=(char *)malloc(strlen (AddStr) + 16);
            strcpy_ex (STRING,AddStr);
        }else{
            STRING=(char *)realloc(STRING, strlen (STRING) + strlen (AddStr) + 16);
            strcat_ex (STRING, AddStr);
        }
    }
    return STRING;
}

/**
 @brief Linke Spaces und Tabs löschen
 @param C die zu bearbeitende Zeichenkette

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void strltrim(char *C)
{
    int i;
    for (;;)
    {
        if ((C[0]==9) || (C[0]==' '))  // Tabs und Spaces
        {
            for (i=0;;i++)
            {
                C[i]=C[i+1];
                if (C[i]==0) break;
            }
        }else{
            break;
        }
    }
}

/**
 @brief Rechte Spaces und Tabs löschen
 @param C die zu bearbeitende Zeichenkette

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void strrtrim(char *C)
{
    int i;
    for (;;)
    {
        i=strlen(C);
        if (i<1) break;
        i--;
        if ((unsigned char)C[i]>32) break;
        C[i]=0;
    }
}

/**
 @brief Rechte und Linkte Spaces und Tabs löschen
 @param C die zu bearbeitende Zeichenkette

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void strCL(char *C)
{
	strltrim(C);
    strrtrim(C);
}

/**
 @brief Alle chars die in RemoveAnyChar vorkommen aus SRC streichen
 @param SRC die zu bearbeitende Zeichenkette
 @param RemoveAnyChar Zeichenkette der zu entfernenden chars

 strpbrk übernimmt hier die Hauptarbeit

 @code
 char * strpbrk(char *string, char *spanset);
 @endcode

 strpbrk findet alle vorkommenden Zeichen in einem String, welche in spanset übergeben werden. Der Rückgabewert ist ein char Zeiger auf das gefundene Zeichen.

___[ Revision ]______________________________________________________________

 ** 01.08.16 HS ReCreate
 ** 16.12.16 HS Jetzt mit strpbrk realisiert
___________________________________________________________________________*/

void strclean (char *SRC, char *RemoveAnyChar)
{
    char *f;
    int n;
    for (;;)
    {
        f = strpbrk ( SRC, RemoveAnyChar );
        if (!f) return;
        for (n=0;;n++)
        {
            if (f[n]==0) break;
            f[n]=f[n+1];
        }
    }
#ifdef unusedstuffstrclen
    int i,j,k;
    for (i=0,j=0;;j++)
    {
        if (SRC[j]==0)
        {
            SRC[i]=0;
            break;
        }
        for (k=0;;k++)
        {
            if (RemoveAnyChar[k]==0)
            {
                SRC[i]=SRC[j];
                i++;
                break;
            }
            if (SRC[j]==RemoveAnyChar[k]) break;
        }
    }
#endif // unusedstuffstrclen
}

/**
 @brief Einzelnes Zeichen (rm) aus SRC löschen
 @param SRC die zu bearbeitende Zeichenkette
 @param rm char das entfernt werden soll

___[ Revision ]______________________________________________________________

 ** 16.12.16 HS ReCreate
___________________________________________________________________________*/

void strdelchar (char *SRC, char rm)
{
    char *f;
    int n;
    for (;;)
    {
        f = strchr (SRC, rm);
        if (!f) return;
        for (n=0;;n++)
        {
            if (f[n]==0) break;
            f[n]=f[n+1];
        }
    }
}

/**
 @brief Einzelnes Zeichen durch ein anderes Ersetzen
 @param C die zu bearbeitende Zeichenkette
 @param FROM char das ersetzt werden soll
 @param DEST char der stattdessen sein soll

___[ Revision ]______________________________________________________________

 ** 12.07.16 HS ReCreate
___________________________________________________________________________*/

void strReplace(char *C, char FROM, char DEST)
{
    int i;
    for (i=0;;i++)
    {
        if (C[i]==0) break;
        if (C[i]==FROM) C[i]=DEST;
    }
}

/**
 @brief Prüft das letzte Zeichen im String=Findchar
 @return gibt -1 Error oder Position zurück
 @param C die zu bearbeitende Zeichenkette
 @param Findchar char das geprüft wird

___[ Revision ]______________________________________________________________

 ** 15.11.16 HS Create
___________________________________________________________________________*/

int strright(char *C, char Findchar)
{
    int i;
    for (i=0;;i++)
    {
        if (C[i]==0) return -1;
        if (C[i]!=Findchar) continue;
        if (C[i+1]==0) return i;
    }
    return -1;
}

/**
 @brief String ohne Anführungszeichen
 @return 0 keine Änderungen
 @param Kette zu Ändernder String

 Quotes wie Anführungszeichen und Hochkommas entfernen
 Am Anfang und Ende die Quotes entfernen

___[ Revision ]______________________________________________________________

 ** 18.03.24 HS First Release
___________________________________________________________________________*/

int strunquote(char *Kette)
{

    int i;
    char Delim;
    if (!Kette) return 0;               // NULL uebergben
    if (!Kette[0]) return 0;            // Leerstring, es gibs also ein Kette[1];
    Delim = Kette[0];                   // Möglicher Begrenzer
    if ( (Delim!='\"') &&  (Delim!='\'') ) return 0;
    for (i=1;;i++)                      // Start hinter dem Delim
    {
        if (!Kette[i]) return 0;
        if ( (Kette[i]==Delim) && (!Kette[i+1]) ) break;
    }
    Kette[i]=0;
    strdel(Kette,0,1);
    return 1;
}

/**
 @brief String, wenn nötig mit Anführungszeichen oder Hochkommas modifizieren
 @return 0 keine Änderungen, -1=Leerstring, sonst Anzahl der Spaces
 @param Kette zu Ändernder String

 Quotes wie Anführungszeichen oder Hochkommas jeweils setzen um einen String
 zu begrenzen und als Singleparameter zu kennzeichnen. Setzt 2 Zeichen Platz
 in "kette" vorraus.

___[ Revision ]______________________________________________________________

 ** 24.03.24 HS First Release, extrahiert von hsmenugen
 ** 25.03.24 HS Leerstrings werden ebenfalls gequoted, aber -1 als return
___________________________________________________________________________*/

int strquote (char *Kette)
{
    int spaced;
    char *e;                                                // Position in Kette
    char usedQuoteMark[] = "\"";                            // Das Zeichen mit \" vorbesetzten wird durch \' ersetzt falls vorhanden
    spaced = 0;                                             // Auf kein Space gefunden setzen
    if (Kette[0]==0) spaced=-1;
    for (e=Kette;; e++)                                     // Kette Buchstabe fuer Buchstabe abarbeiten
    {
        if (*e=='\"')    usedQuoteMark[0] = '\'';           // Wenn innerhalb von Kette schon ein \" vorhanden, dann \' benutzen
        if (isspace(*e)) spaced++;                          // Wenn es ein space gibt ... schliesst auch tab ein
        if (*e=='\0')    break;                             // raus wenn Kette am letzten Buchstaben angekommen
    }
    if (spaced)
    {
        //strappend(Kette, usedQuoteMark);
        *e = usedQuoteMark[0];                              // Am Ende von Kette \0 überschreiben
        e++;                                                // und wieder
        *e = '\0';                                          // \0 einsetzen
        strins(Kette,usedQuoteMark,0);
    }
    return spaced;
}

/**
 @brief STRING durch Space aufsplitten und das durch idx benannte Element zurückgeben
 @return durch idx benannte Element oder ""
 @param STRING die zu bearbeitende Zeichenkette
 @param idx Welches Element

 Ein Argument (idx) aus eine String suchen
 gibt "" zurück falls nicht gefunden
 gibt das Argument zurück, falls Ergebnis vorliegt

___[ Revision ]______________________________________________________________

 ** 23.01.17 HS Create
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *stridx(char *STRING, int idx)
{
    char *rslt;

    int a;
    int p;
    int w;

    p=0;
    a=0;
    rslt = malloc_temp(strlen(STRING)+1);
    for (;;)
    {
        for (;;p++)                                                             // Finde im STRING den Beginn das erste (nächste) Argument
        {
            if (STRING[p]==0) return "";
            if (STRING[p]==' ') continue;
            if (isprint(STRING[p])) break;
        }
        for (w=0;;w++,p++)                                                      // Ende des Arguments finden
        {
            rslt[w]=STRING[p];
            if (STRING[p]==' ') break;
            if (!isprint(STRING[p])) break;
        }
        rslt[w]=0;
        if (a==idx) return rslt;
        a++;
    }
}

/**
 @brief in STRING Zeichenkette (FIND) austauschen gegen REPL
 @return ungeänderter Pointer auf STRING
 @param STRING die zu bearbeitende Zeichenkette
 @param FIND Zeichenkette die gefunden werden soll
 @param REPL Zeichenkette durch die ersetzt werden soll

___[ Revision ]______________________________________________________________

 ** 30.12.17 HS Create
 ** 06.01.18 HS umbenannt von strchg in strstrreplace
___________________________________________________________________________*/

char *strstrreplace (char *STRING,char *FIND, char *REPL)
{
    int pos;
    int from;

    if (!strcmp (FIND,REPL)) return STRING;

    for (from=0;;)
    {
        pos = strstrpos(STRING, FIND, from);
        if (pos<0) break;
        strdel(STRING, pos, strlen(FIND));
        strins(STRING, REPL, pos);
        from = pos;
    }
    return STRING;
}

/**
 @brief Src aufteilen und zwar nach dem ersten Auftauchen von (char)Delemiter
 @return -1 Fehler 0 OK , dann sind DLeft und DRight mit malloc geholter Speicher gefüllt
 @param [in]  Src die zu bearbeitende Zeichenkette
 @param [in]  delimiter Zeichen das gesucht wird
 @param [out] DLeft Linker Teil
 @param [out] DRight Rechter Teil

 Src aufteilen und zwar nach dem ersten Auftauchen von (char)Delemiter
 Bei Fehler wird !0 zurückgegeben. Bei Erfolg 0, dann sind DLeft und DRight
 mit malloc geholter Speicher gefüllt.

___[ Revision ]______________________________________________________________

 ** 08.07.18 HS Create
___________________________________________________________________________*/

int strsplit(char *Src, char delimiter, char **DLeft, char **DRight)
{
    char *L;                     // Links war static
    char *R;                     // Rechts war static
    int i;                              // Zeiger im String
    for (i=0;;i++)
    {
        if (Src[i]==0)                  // StringEnde, dann NULL als Rückgabewert
        {
            *DLeft  = NULL;
            *DRight = NULL;
            return -1;                  // und mit -1 markieren
        }
        if (Src[i]==delimiter) break;   // Wenn richtiger Trenner
    }
    //links und rechts .. sind mallociierte Speicher mit static unfug
    L = (char*)malloc0(i+2);            // Linken Teil i=Länge plus 2
    strncpy_ex(L,Src,i);                // reinkopieren
    R = strdup (&Src[i+1]);             // Rechten Teil vom Trenner behandlen
    CL(L);                              // Bereinigen
    CL(R);
    *DLeft  = L;                        // Übergeben
    *DRight = R;
    return 0;                           // Als OK, markieren
}

/**
 @brief Aus einem String ein Argumente lesen und zurückgeben
 @return STRING Kann NULL sein muss mit free freigegeben werden
 @param [in]  start_ptr Startposition
 @param [out] end_ptr   Endposition
 @param [in]  position  Position, die gesucht wird
 @param [in]  flags)    wir STRSTRSPLIT_SINGLE_QUOTES

 Aus einem String ein Argumente lesen und zurückgeben. Kann NULL sein.
 Das Verhalten welche Zeichen Trenner sind und ob Quotes erlaubt sind können
 über die flags gesteuert werden.

 @code
#define STRSTRSPLIT_SPACE_DELIMITTER 0x01
#define STRSTRSPLIT_TAB_DELIMITTER   0x02
#define STRSTRSPLIT_LF_DELIMITTER    0x04
#define STRSTRSPLIT_SINGLE_QUOTES    0x10
#define STRSTRSPLIT_DOUBLE_QUOTES    0x20
#define STRSTRSPLIT_NO_QUOTES_RETURN 0x80
#define STRSTRSPLIT_DEFAULT ( STRSTRSPLIT_SPACE_DELIMITTER | STRSTRSPLIT_TAB_DELIMITTER | STRSTRSPLIT_LF_DELIMITTER | STRSTRSPLIT_SINGLE_QUOTES | STRSTRSPLIT_DOUBLE_QUOTES )
 @endcode

___[ Revision ]______________________________________________________________

 ** 24.02.19 HS Create
___________________________________________________________________________*/

char *strstrsplit (char *start_ptr, char **end_ptr, int position, int flags)
{
	int isInStr;                                                                // 0 oder der Wert des Zeichens bis zu dem gelesen wird
	int strnum;                                                                 // auf welchen String wird zugegriffen ?
    int lastchar;                                                               // TRUE, wenn keine weiteren Zeichen mehr folgen

    char *rslt;                                                                 // das Ergebnis unserer Suchen, kann NULL sein
    char *piece;                                                                // Teilstück das durchsucht wird.
    char *p;                                                                    // aktuelles Zeichen

    p = start_ptr;                                                              // Startposition

	lastchar=FALSE;
	rslt = NULL;                                                                // Ergebis bei default NULL
    for (strnum=0;;strnum++)
    {
        for(;;p++) if ( (*p!=' ') && (*p!='\t') && (*p!='\n') ) break;          // Leerzeichen uä. am Anfang ignorieren
        piece=p;                                                                // Beginnend mit der ersten gültigen Zeichen
        isInStr=0;                                                              // und wird sind nicht zwischen Quotes

        for (;;p++)
        {
            //printf ("%i: %s\n",strnum,p);
            if (*p==0)                                                          // Ist die Zeichenkette zu Ende wird die Schleife abgebrochen
            {
                lastchar=TRUE;
                break;
            }

            if (   ( (*p=='\'') && ( flags & STRSTRSPLIT_SINGLE_QUOTES ) )      // Quotes ausfindig machen
                || ( (*p=='\"') && ( flags & STRSTRSPLIT_DOUBLE_QUOTES ) )
                )
            {
                if (isInStr==0)                                                 // Starte String, dabei wird das davor allerdings vergessen
                {                                                               // der String per"version" würde nur version zurück geben
                    isInStr=*p;                                                 // ansonsten Zeichen merken
                    if ( flags & STRSTRSPLIT_NO_QUOTES_RETURN ) piece++;        // Wenn keine Quotes gewünscht sind Startposition erhöhen
                    continue;
                }
                if (isInStr==*p)                                                // Wenn passendes Quote gefunden wird
                {
                    if ( flags & STRSTRSPLIT_NO_QUOTES_RETURN )                 // Ergebnis ohne Quotes darstellen
                    {
                        if (p[1]==0) lastchar=TRUE;                             // Hinter dem Quote das Ende ?
                    }else{
                        p++;
                        if (*p==0) lastchar=TRUE;
                    }
                    break;
                }
            }
            if (isInStr==0)                                                     // Nachschauen ob ein Trenner dabei ist.
            {
                if ((*p==' ') && (flags & STRSTRSPLIT_SPACE_DELIMITTER)) break;
                if ((*p=='\t') && (flags & STRSTRSPLIT_TAB_DELIMITTER)) break;
                if ((*p=='\n') && (flags & STRSTRSPLIT_LF_DELIMITTER)) break;
            }
        }
        if (strnum==position)                                                   // Richtige Position gelesen
        {
            rslt = malloc0 ((p-piece)+2);                                       // Passenden Speicher reservieren
            strncpy_ex(rslt,piece,p-piece);                                     // kopieren
            if ( flags & STRSTRSPLIT_NO_QUOTES_RETURN ) if (isInStr==*p) p++;   // Sonderfall mit Quotes
            break;
        }
        if (lastchar==TRUE) break;
        p++;
	}
	*end_ptr = p;                                                               // Ende
    return rslt;
}
/**
 @brief String Argumente aufteilen.
 @return Pointer auf Stringliste Sowohl die Liste als auch die Argumente müssen mit free freigegeben werden
 @param strin Liste, die aufgeteilt werden soll

 String Argumente aufteilen. Es wir eine Liste der Argumente zurückgegeben
 Sowohl die Liste als auch die Argumente müssen mit free freigegeben werden.
 Leerzeichen in Argumenten werden mit " oder ' realisiert.
 So ist - "Das wird ein Test" - als ein Argument zurückgeliefert. Wo bei
 die Anführungszeichen nicht entfernt werden. Das gilt auch für eine ID="307"

___[ Revision ]______________________________________________________________

 ** 24.02.19 HS Create
___________________________________________________________________________*/

char **strlst(char *strin)
{
    char **lst;                                                                 // Die Ergebnisliste
    char *piece;                                                                // Teil der Argumente
    char *wstr;                                                                 // pointer der start und ende markiert
	int strnum;                                                                 // aktuelles Argument

	lst = NULL;                                                                 // default NULL
	wstr = strin;                                                               // Start setzen
	for (strnum=0;;strnum++)
    {
        if (*wstr==0)   piece=NULL;                                             // Leerer Rest = Ende und damit nicht beachten
        else            piece = strstrsplit(wstr,&wstr,0,STRSTRSPLIT_DEFAULT);  // Sonst nächste Teilstück vom Stringin holen
        if (lst==NULL)  lst = malloc(     sizeof(char*)* (strnum+2));           // Speicher reservieren
        else            lst = realloc(lst,sizeof(char*)* (strnum+2));
        lst[strnum]=piece;                                                      // Argument merken
        if (!piece) break;
	}
	return lst;                                                                 // Liste zurückgeben
}

/**
 @brief String Argumente hinzufügen
 @return Pointer auf die geänderte Stringliste
 @param listin Pointer auf die "Stringliste"
 @param newitem anzufügendes pointer hinzufügen

 Sowohl die Liste als auch die Argumente müssen mit free freigegeben werden

___[ Revision ]______________________________________________________________

 ** 22.03.24 HS Create
___________________________________________________________________________*/

char **strlstadd(char** listin, char *newitem)
{
    int num;
    if (listin)
    {
        for (num=0;listin[num];num++);
        listin = realloc(listin,sizeof(char*) * (num+2));
    }else{
        num=0;
        listin = malloc( sizeof(char*) * 2);
    }
    listin[num]=newitem;
    listin[num+1]=NULL;
    return listin;
}

/**
 @brief String Argumente in einem Rutsch freigeben
 @return NULL
 @param listin Pointer auf die "Stringliste"

 Sowohl die Liste als auch die Argumente müssen mit free freigegeben werden

___[ Revision ]______________________________________________________________

 ** 22.03.24 HS Create
___________________________________________________________________________*/

char **strlstfree(char **listin)
{
    int i;
    if (!listin) return NULL;
    for (i=0;listin[i];i++)
    {
        free (listin[i]);
    }
    return free0(listin);
}

/**
 @brief sprintf ohne meckern
 @return negativ=Fehler ansonsten Stringlänge
 @param DST     Destination Pointer
 @param fmt     printf Format
 @param ...     wie printf

 macht das Gleiche wie sprintf, nur dass der GCC nicht meckert

___[ Revision ]______________________________________________________________

 ** 02.04.20 HS wg. GCC 8.1 umgehung der Fehlermeldung
___________________________________________________________________________*/

int sprintf_ex (char *DST, char *fmt, ...)
{
    char *r;
    va_list argp;
    va_start(argp, fmt);
    r = vstrprintf(fmt, argp);
    va_end(argp);
    strcpy_ex(DST,r);
    free0(r);
    return strlen(DST);
}

#ifdef OLD_STUFF
int sprintf_ex (char *DST, char *fmt, ...)
{
    va_list argptr;
    int rc;
    va_start (argptr, fmt);
    rc = vsprintf (DST, fmt, argptr);
    va_end(argptr);
    return rc;
}
#endif

/**
 @brief strcpy
 @return DST
 @param dst    Destination Pointer
 @param src    Source Pointer

 macht das Gleiche wie strcpy nur dass nicht gemeckert wird

___[ Revision ]______________________________________________________________

 ** 24.07.22 HS wg. GCC 11.2 umgehung der Fehlermeldung
___________________________________________________________________________*/

char *strcpy_ex(char *dst, const char *src)
{
    assert(dst!=NULL);
    assert(src!=NULL);
    return memcpy_ex(dst,src,strlen(src)+1);
}

/**
 @brief strcat
 @return DST
 @param dst    Destination Pointer
 @param src    Source Pointer

 macht das Gleiche wie strcat nur dass nicht gemeckert wird

___[ Revision ]______________________________________________________________

 ** 24.07.22 HS wg. GCC 11.2 umgehung der Fehlermeldung
___________________________________________________________________________*/

char *strcat_ex(char *dst, const char *src)
{
    char *d;

    assert(dst!=NULL);
    assert(src!=NULL);

    for (d=dst; *d; d++);
    memcpy_ex(d,src,strlen(src)+1);
    return dst;
}

/**
 @brief strncpy
 @return DST
 @param dst    Destination Pointer
 @param src    Source Pointer
 @param len    Anzahl der zu kopierende Zeichen (char)

 macht das Gleiche wie strcpy nur dass nicht gemeckert wird

___[ Revision ]______________________________________________________________

 ** 24.07.22 HS wg. GCC 11.2 umgehung der Fehlermeldung
___________________________________________________________________________*/

char *strncpy_ex(char *dst, const char *src, int len)
{
//    return strncpy(dst,src,len);

    const char *s;
    char *d;

    assert(dst!=NULL);
    assert(src!=NULL);

    if (len<=0) return dst;
    d = dst;                                                                // modifizierbare Kopie des Zeiger
    //for (; *d; d++); if strncat z.Z. nicht implementiert
    for (s=src;;s++,d++)                                                    // s=Kopie von src ,, source und dest increment
    {
        *d=*s;                                                              // Zeichen kopieren
        len--;                                                              // Laenge reduzieren
        if (len < 0) *d=0;                                                  // zu klein, dann ZielZeiger = 0
        if (!*d) break;                                                     // und wenn Zielzeiger erreicht ist, dann ende
    }
    return dst;
}

/**
 @brief strdup_ex
 @return DST
 @param src Source Pointer

 Anfertigen einer mit malloc reservierten Kopie eines String.

 Hier meckert keiner, aber strdup zickte rum und reservierte keinen
 Speicher, sondern legte einen Pointer an. Anschließender free(mem)
 wollte dann den Speicher freigeben, aber es gab einen Fehler
 "double free or corruption".

___[ Revision ]______________________________________________________________

 ** 01.02.24 HS wg. Fehlermeldung"double free or corruption"
___________________________________________________________________________*/

//#error "char *strdup_ex(const char *src)"
char *strdup_ex(const char *src)
{
	int len;
	char *dst;
	if (src == NULL) return NULL;
	len = strlen(src);
	dst = malloc (len + 1);
	memcpy_ex(dst, src, len);
	dst[len] = 0;
	return dst;
}

/**
 @brief Zeichenkette Matching prüft ob str mit dem Muster in pat übereinstimmt
 @return true / false
 @param pat Pattern das gescant wird
 @param str Prüfling
 @param flags kann nur 0 oder STRMTCH_CASE sein

 Geprüft wird der String in str
 Muster (pat) darf nur die Wildcards '*' und '?' enthalten

 Rückgabewert kann nur TRUE oder FALSE sein.

 @code
 strmtch ("H?rry*", "Horryble", 0) wird also TRUE ergeben.
 strmtch ("H?rry*a", "Horryble", 0) wird also FALSE ergeben.
 @endcode

___[ Revision ]______________________________________________________________

 ** 08.04.18 HS Create
 ** 24.06.18 HS Wenn Zeichen am Anfang, dann gings nicht mit case
___________________________________________________________________________*/


/* Match STRING against the filename pattern PATTERN, returning zero if
   it matches, nonzero if not.   ... so eine FreeWare-Funktion */

int strmtch (const char *pat, const char *str, int flags)
{
    const char *p;
    const char *n;

    register char c;
    register char d;

    p = pat;
    n = str;

    //printf ("\"%s\" <<>> \"%s\"\n",p,n);

    while ((c = *p++) != '\0')
    {
        switch (c)
        {
            case '?':
                if (*n == '\0') return FALSE ;
                break;

            case '*':
                for (c = *p++; (c == '?' || c == '*'); c = *p++, ++n)
                {
                    if ((c == '?' && *n == '\0')) return FALSE ;
                }
                if (c == '\0') return TRUE ;
                for (--p; *n != '\0'; ++n)
                {
                    d = *n;
                    if (flags & STRMTCH_CASE)
                    {
                        if ((d>='a')&& (d<='z')) d = d -0x20;
                        if ((c>='a')&& (c<='z')) c = c -0x20;
                    }
                    if (d == c)
                    {
                        if (strmtch(p, n, flags) == TRUE ) return TRUE ;
                    }
                }
                return FALSE ;

            default:
                d = *n;
                if (flags & STRMTCH_CASE)
                {
                    if ((d>='a')&& (d<='z')) d = d -0x20;
                    if ((c>='a')&& (c<='z')) c = c -0x20;
                }
                if (c!= d) return FALSE ;
        }
        ++n;
    }
    if (*n == '\0') return TRUE ;
    return FALSE ;
}

/**
 @brief In der Zeichenkette nach "Leerzeichen" getrennter Argumente durchsuchen
 @return Argument
 @param STRING      der zu durchsuchende String
 @param arg         Ab welcher Position gesucht wird
 @param STRARG_DEL  Delimitter

___[ Revision ]______________________________________________________________

 ** 06.01.18 HS Create
 ** 19.02.18 HS Um den Parameter STRARG_DEL erweitert
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *strstrarg (char *STRING, int arg, char STRARG_DEL)
{
    char *rslt;
    char *s;
    int k;
    int l;

    if (arg<=0) return STRING;                              // Argment muss 1 oder größer sein -> sollte das NULL sein ??
    s=STRING;
    rslt=malloc_temp(strlen(STRING)+1);
    for (l=1;l<=arg;l++)                                    // Im String [s=reststring] nach dem nächsten ARG suchen
    {                                                       // l ist das aktuelle Argument
        for (;;s++)                                         // s auf das nächste nicht delimiter setzen
        {
            if (s[0]!=STRARG_DEL) break;
        }
        if (s[0]==0) return NULL;                           // Keine Zeichen mehr
        for (k=0;;k++,s++)                                  // Hier beginnt das ARG number l
        {
            if (s[0]==0) break;                             // Stringende
            if (s[0]==STRARG_DEL) break;                    // oder Fundstelle nächstes delimiter
            rslt[k]=s[0];                                   // ansonsten aktuelles Zeichen kopieren
        }
        rslt[k]=0;                                          // Ergebnis mit 0 abschliessen
        if (l==arg) return rslt;                            // Argument richtig, dann String zurückgeben
    }
    return NULL;
}

/**
 @brief String in umkehren
 @param str der gekehrt werden soll

___[ Revision ]______________________________________________________________

 ** 23.07.16 HS ReCreate
___________________________________________________________________________*/

void revstr (char *str)
{
    int l,r;
    char d;

    if (!str) return;
    r = strlen(str);
    if (r<2) return;
    r--;
    for (l=0;;l++,r--)
    {
        if (l>r) return;
        d = str[l];
        str[l]=str[r];
        str[r]=d;
    }
}
///@}

/* *******************************************************************************************************************/
//
// Zahlen Strings
//
/* *******************************************************************************************************************/
/**
 @addtogroup c_strchr_numbers
 @{
 @brief Zeichenketten und Zahlen

*/

/**
 @brief Eine Zeichenkette aus einem INT machen
 @return Ergebnis Zeichenkette
 @param num welche Zahl

 Wrappt zu HSnum2Str

 Im Prinzip gibt es das als itoa. Aber ist nicht immer dabei

___[ Revision ]______________________________________________________________

 ** 04.01.17 HS erstellt
 ** 03.03.19 HS Noch ein Wrapper mit formatierter Zahl
___________________________________________________________________________*/

char *strnum(int num)
{
    return HSnum2Str(num,0,0,0);
}

/**
 @brief Eine Zeichenkette aus einem INT machen
 @return Ergebnis Zeichenkette
 @param num welche Zahl
 @param pad mit welchem char füllen
 @param sized Auf welche Größe

 Wrappt zu HSnum2Str

___[ Revision ]______________________________________________________________

 ** 04.01.17 HS erstellt
 ** 03.03.19 HS Noch ein Wrapper mit formatierter Zahl
___________________________________________________________________________*/

char *strnumformated(int num, char pad, int sized)
{
    return HSnum2Str(num,pad,0,sized);
}

/**
 @brief Eine Zeichenkette aus einem INT machen
 @return Ergebnis Zeichenkette
 @param Wert welche Zahl
 @param pad mit welchem char füllen
 @param trenn zeigt an das es einen trenner alle 3 Zahlen gibt
 @param maxsize Auf welche Größe

 Die Arbeitsroutine ....
 Wenn trenn NICHT 0, dann wird alle 3 Zeichen ein Trennzeichen zu besseren
 Lesbarkeit gesetzt.
 wenn maxsize 0 ist, dann Linksbündig formatiert
 wenn  maxsize>0 wird mit pad gefüllt,

___[ Revision ]______________________________________________________________

 ** 04.01.17 HS erstellt
 ** 03.03.19 HS Noch ein Wrapper mit formatierter Zahl
 **          HS Um pad erweitert
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *HSLnum2Str ( unsigned long long Wert, char pad, char trenn, int maxsize)
{
    unsigned long long  w,e,r;
    unsigned int        p,t;
    int                 l;

    char *rtstr;                // Return String
    rtstr = malloc_temp(64);

    if ( (maxsize>0) && (pad==0)) memset_ex(rtstr,' ',64); // ignore filler
    else                          memset_ex(rtstr,pad,64);
    p = 64-1; // sizeof(rtstr)-1;
    t = 0;
    w = Wert;
    rtstr[p]=0;
    p--;
    if (w==0)
    {
        rtstr[p]='0';
    }else{
        while (1)
        {
            if (w==0) break;
            if (trenn!=0)
            {
                t++;
                if (t>3)
                {
                    rtstr[p]=trenn;
                    p--;
                    t=1;
                }
            }
            e = w / 10;
            r = w - (e*10);
            rtstr[p]=(char) r+'0';
            p--;
            if (p<3) break;
            w = e;
        }
        p++;
    }

    if (maxsize<=0)
    {
        l = 0;
    }else{
        l = maxsize-(64-(p+1));  // negative maxsize wird nicht gefüllt   sizeof(rtstr)
        if (l<0) l = 0; // since 18.02.23 HS
    }

    //if (maxsize>0) i=maxsize-(sizeof(rtstr)-(p+1));  // negative maxsize wird nicht gefüllt
    //else i=0;

    //for (;p<sizeof(rtstr);l++,p++)
    for (;p<64;l++,p++)
    {
        rtstr[l]=rtstr[p];
    }
    return rtstr;
}

///@copydoc HSLnum2Str
char *HSnum2Str ( unsigned long Wert, char pad, char trenn, int maxsize)
{
    unsigned long long tmp;
    tmp = Wert;
    return HSLnum2Str ( tmp, pad, trenn, maxsize);
}

/**
 @brief Konvertiert eine Zal in einen String mit Punkten getrennt
 @param Kette Im Prinzip der Rückgabewert Kette gefüllt
 @param Wert Wert der umgerechnet wird.

___[ Revision ]______________________________________________________________

 ** 01.01.16 HS .
___________________________________________________________________________*/

void Long2IStr ( char *Kette, unsigned long Wert)
{
    strcpy_ex (Kette, HSnum2Str ( Wert,0, '.', 0));
}

///@copydoc Long2IStr
void LLong2IStr ( char *Kette, unsigned long long Wert)
{
    strcpy_ex (Kette, HSLnum2Str ( Wert,0, '.', 0));
}

/**
 @brief Unterroutine von Num2Human
 @return Kette
 @param Kette zu bearbeitende Zeichenkette

 Löscht unerwünschte Nullen oder falls notwendig sogar den Punkt in der Zahl

___[ Revision ]______________________________________________________________

 ** 09.03.20 HS Create
___________________________________________________________________________*/

char *CleanNumberAfterDot(char *Kette)
{
    int p;                                                  // auf den "Punkt" setzen
    int l;                                                  // auf letztes Zeichen
    if (!Kette) return Kette;
    for (p=0;;p++)
    {
        if (Kette[p]==0) return Kette;                      // Kein '.' gefunden
        if (Kette[p]=='.') break;
    }
                                                            // p ist die Punktposition
    for (l=p+1;;l++)                                        // Letztes Zeichen finden nach dem Punkt
    {
        if (Kette[l]==0) break;
    }
    for (l--;;l--)                                          // Letztes Zeichen gefunden
    {
        if (l==p)                                           // Wenn Punkt, dann kann der Punkt weg
        {
            Kette[p]=0;
            return Kette;
        }
        if (Kette[l]!='0') break;                           // Letztes Zeichen ist keine "0", dann Ende
        Kette[l]=0;                                         // Die Null löschen
    }
    return Kette;
}

/// Kilo Byte   Mega Byte   Giga Byte   Tera Byte   Peta Byte   Exa Byte   Zetta Byte   Yotta Byte
static char *HumanNames[] = {"KB","MB","GB","TB","PB","EB","ZB","YB"};
/**
 @brief Große Zahlen für Menschen <em>leserlich</em> darstellen
 @return String der die Zahl in num beschreibt
 @param num Zahl die beschrieben werden soll
 @param perc Genauigkeit nach dem Komma

 Große Zahlen so darstellen, dass max. 4 Zahlen mit einer Angabe von
 xfachen von Bytes (also KB/TB etc.) angegeben wird.

 Ergebnis wird in eine char* zurückgegeben.

 Der Buffer wird mit 128 Bytes allociert, wenn als erstes aufgerufen wird.

 @code
 char *n=Num2Human(1000000.32,3);
 printf ("%s\n",n);
 ergibt:
 976.563 KB
 @endcode

___[ Revision ]______________________________________________________________

 ** 09.03.20 HS Create
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *Num2Human(double num, int perc)
{
    double mNum;                                            // double für Nachkommastellen
    int i;                                                  // schleifenzähler
    int m = sizeof(HumanNames) / sizeof (char *);           // MaxHumanName
    char* HumanRead;                                        // pointer auf das Ergebnis

    HumanRead=malloc_temp(128);                             // Speicher nur wenn noch keiner da ist
    strcpy_ex (HumanRead, "Overflow");                      // auf ungültig setzen, falls die Schleife Ergebnis offen

    mNum = num;                                             // Die Zahl
    if (mNum<1024)                                          // Unter 1 K läuft NIX
    {
        sprintf_ex (HumanRead, "%.0lf", mNum);              // und Ergebnis speichern
        return HumanRead;
    }

    for (i=0;i<m;i++)                                       // Für Alle HumanNames
    {
        mNum /= 1024;                                       // Ansonsten mNum verkleiner und i+=1
        if (mNum < 1024)                                    // Kleiner 1024, dann passt das Ergebnis
        {
            sprintf_ex (HumanRead, "%.*lf %s", perc, mNum, HumanNames[i]); // und Ergebnis speichern
            break;
        }
    }
    //strrtrim(HumanRead);                                    // ggf. rechtes Space löschen
    return CleanNumberAfterDot(HumanRead);
}

/**
 @brief Berechnet eine Zahl aus einem String, wie "4 TB"
 @return double Zahl aus Kette
 @param Kette Zeichenkette die geparst werden soll

 Gegenpart zu @ref Num2Human nur wirdaus einem String eine Zahl macht

 @note Wenn man unvernüftige String parst, dann kommt auch eine komische Zahl raus

___[ Revision ]______________________________________________________________

 ** 09.03.20 HS Create
 ** 22.02.24 HS Auch ein Zeichen reicht völlig 100G = 100GB
___________________________________________________________________________*/

double Human2Num(char *Kette)
{
    double mNum;
    double rslt_multi;
    double multi;
    char *p;
    int slength;
    int k;
    int m = sizeof(HumanNames) / sizeof (char *);           // MaxHumanName
    p = strdup(Kette);                                      // manipulierbares Duplikat schaffen
    slength =strlen(p);                                     // Länge
    rslt_multi=0;                                           // Ergebnis Multiplikator
    if (slength>1)                                          // Mindestens 2 Zeichen
    {
        multi=1024;                                         // 0 KB 1 MB usw.
        for (k=0;k<m;k++)
        {
            if (tolower(p[slength-2])==tolower(HumanNames[k][0]))
            {
                if (tolower(p[slength-1])==tolower(HumanNames[k][1]))
                {                                           // Wenn beide Zeichen passen
                    rslt_multi = multi;
                    p[slength-2]=0;                         // löschen der Größenangabe
                    break;
                }
            }
            // and ... nur ein richtiges Zeichen reicht auch
            if (tolower(p[slength-1])==tolower(HumanNames[k][0]))
            {                                           // Wenn beide Zeichen passen
                rslt_multi = multi;
                p[slength-1]=0;                         // löschen der Größenangabe
                break;
            }
            multi = multi * 1024;
        }
    }
    mNum = atof(p);
    if (rslt_multi>0)
    {
        mNum = mNum * rslt_multi;
    }
    free(p);
    return mNum;
}

/**
 @brief Runden einer Zahl via String
 @return double
 @param num Zahl, die gerundet wird
 @param perc Genauikget hinter dem Komma

Da sich irgendwie keine andere saubere Lösung anbietet
- runden via String

___[ Revision ]______________________________________________________________

 ** 10.03.20 HS Create
___________________________________________________________________________*/

double simple_round(double num, int perc)
{
    double rslt;
    char *a;

    a = malloc(128);
    sprintf_ex (a, "%.*lf", perc, num);
    rslt = atof(a);
    free(a);

    return rslt;
}

/**
 @brief HexString konvertieren zu einer long long zahl
 @return EXIT_SUCCESS / EXIT_FAILURE
 @param [in]  start_p    Start des HexStrings hier
 @param [out] end_p      Ende des gelesenen Strings
 @param [in]  len        Max. Länge oder 0, dann kann er unendlich lang sein(theoretisch)
 @param [out] rslt       Ergebnis

___[ Revision ]______________________________________________________________

 ** 24.01.19 HS Create ursprünglich für HSjson
___________________________________________________________________________*/

int fromHex(char *start_p, char **end_p, int len, long long* rslt)
{
    int i;
    int c;
    char *p;

    p=start_p;
    *rslt =0;                                                           // start typischerweise mit null
    for (i=0;;i++)
    {
        *end_p=p;
        if (len>0)                                                      // maxlänge beachten ?
        {
            if (i>=len) break;                                          // überschritten ?
        }else{
            if (*p==0) break;                                           // ohne Länge, dann bei stringende ->
        }
        if (!isxdigit(*p)) return EXIT_FAILURE;                         // ist ein Hexdigit ? -> sonst ende
        if (*p>='0' && *p<='9') c=*p-'0';                               // 0-9
        else if (*p>='a' && *p<='f') c=*p-'a'+10;                       // a-z usw.
        else if (*p>='A' && *p<='F') c=*p-'A'+10;
        else c=0; // never happens                                      // wenn isxdigit richtig geht
        *rslt = (*rslt*16)+c;                                           // hex->Shift by 0x10
        p++;
    }
    return EXIT_SUCCESS;
}

/**
 @brief Konvertiert eine HexZahl von einem String zu einem long Wert
 @return number
 @param STRING Die zu bearbeitende Zeichenkette

___[ Revision ]______________________________________________________________

 **  02.04.06 HS ReCreate
 **  24.01.19 HS Rewritten, aber langsamer und komplexer, dafür flexibler
___________________________________________________________________________*/

//long hextol(char *STRING)
//{
//    signed long tmpl;
//    unsigned int i,j;
//
//    tmpl=0;
//    for (i=0;i<=8;i++)
//    {
//        j=STRING[i];
//
//        if (!isxdigit(j)) break;
//        tmpl=(tmpl*16);  // tmpl<<=1;
//        if (j>='A')
//        {
//            j=(((j&0xf)-1)+10);
//        }else{
//            j=(j & 0xf);
//        }
//        tmpl=tmpl+j;
//    }
//    return (tmpl);
//}

long hextol(char *STRING)
{
    char *e;
    long long y;
    fromHex(STRING, &e, 8, &y);
    return y;
}

/**
 @brief HexString aus einem Buffer machen
 @return Zeichenkette mit HexDump des Buffers
 @param from Buffer der gelesen wird
 @param size maximale länge ( bei NOZERO, oder 1 = unendlich >1 maxlänge )
 @param bytes_per_line Anzahl der Zellen pro Zeile
 @param format Flags [STRHEX .... ]

 Gedacht als Debughelfer zur Ausgabe in Datei oder Bildschirm
 aus dem Buffer "from" wird ein HexDump erzeugt, der wiederum in einem
 dynamischen String abgelegt wird. Wird strtohexstr("",0,0,0) aufgerufen, dann
 wird dieser Speicher freigegeben. Muss man aber nicht machen....

 * from     Speicher der auszubegeben ist. Hier kann man wenn die maxSize
            nicht stimmt schnell einen segfault auslösen
 * size     maximale Anzahl der Zeichen, dabei sind mindestens 2 Zeichen Pflicht
            0 wird nur verwendet um den Speicher frei zu geben
            1 wird verwendet, wenn ein String NULL terminiert wird.
 * bytes_p. Anzahl von Reihen des HexDumps

 format hat folgenden Aufbau:

 * nix / 0       = nur immer "00 " für jedes Byte (KEIN LF am Ende, nur ein Leerzeichen)
 * STRHEX_INDEX  = Jede Zeile mit Index  "0000: "
 * STRHEX_ASC    = mit ASC am Ende
 * STRHEX_NOZERO = ignoriere 0, dann size und maxhex in einer Zeile ausgeben

___[ Revision ]______________________________________________________________

 ** 10.02.19 HS Create
 ** 02.04.20 HS Neues Format mit 0x400 Es wird der Buffer in voller Länge
                ausgegeben, auch wenn eine NULL dabei ist, kann nicht
                mehrzeilig sein.
 ** 01.02.24 HS Neuer Aufruf
                Doku angepasst
 ** 02.04.24 HS malloc_temp statt NULL und malloc
___________________________________________________________________________*/


//char *strtohexstr(char *from, int format)
//char *strdump( void* fromAddr, size_t size, int format )
char *strtohexstr(char* from, size_t size, size_t bytes_per_line, int format )
{
    char *rslt;                                                                 // Init mit NULL
    int i;
    int haveNextLine=TRUE;                                                      // Zeigt, dass eine neue Zeile begonnen werden soll und Variable entsprechend gesetzt werden
    int maxHex;
    int linHex;
    char hex[32];
    char ascAdd[130];
    rslt=NULL;                                                                  // und für neues rslt vorbereiten

    if ( (size==0) && (*from == '\0') ) return from;                            // nix ausgeben, dann fertig

    linHex = 0;
    maxHex = bytes_per_line;                                                    // Anzahl der Maximalen Hexzahlen pro Zeile 0 = kein Ende
    if (maxHex<1)   maxHex=128;
    if (maxHex>128) maxHex=128;                                                 // Maximal 127

    for (i=0;;i++)
    {
        if (size>1) if (i>=size) { break; }
        if (format & STRHEX_NOZERO)
        {
            if (maxHex==0) break;
//            if (i>0)
//            {
//                if (haveNextLine) break;
//            }
        }else{
            if (from[i]==0) break;                                              // String Ende
        }

        if (haveNextLine)                                                       // Wenn neue Zeile
        {
            if (format & STRHEX_INDEX)                                          // Format mit Index anzeigt
            {
                sprintf_ex (hex,"%04x: ",i);                                    // einfach mit sprintf
                stradd(rslt, hex);                                              // un zum Ergebnis
            }
            memset_ex (ascAdd,0,sizeof(ascAdd));                                // "NULLEN"
            haveNextLine=FALSE;
            linHex = 0;
        }
        sprintf_ex (hex,"%02x",(unsigned char) from[i]);                        // aktuellen Teil "addieren"
        strcat_ex (hex, " ");
        stradd(rslt, hex);
        if (maxHex==0) continue;                                                // unendlich Zeile ?
        ascAdd[linHex]=isprint(from[i]) ? from[i] : '.';                        // Wenn darstellbar, dann als Asc dazu, sonst nur nen Punkt
        linHex++;
        if (linHex<maxHex) continue;                                            // Maximale Zeilen erreicht ?
        haveNextLine=TRUE;                                                      // Ja, dann Kennzeichnen
        if (format & STRHEX_ASC) stradd (rslt,ascAdd);                          // Wenn ASC gefordert, dann ...
        stradd (rslt,"\n");                                                     // Zeilenende...
    }
    if (!haveNextLine)                                                          // Wenn nicht gerade in einer neuen Zeile gelandet
    {
        if (format & STRHEX_ASC)                                                // und ascAdd gewünscht ist
        {
            if (maxHex>0)                                                       // und nicht endloszeile war .....
            {
                for (;linHex<maxHex;linHex++) stradd (rslt,"   ");              // dann den String auffüllen
            }
            stradd (rslt,ascAdd);                                               // ASC anfügen
        }
        if (format!=0) stradd (rslt,"\n");                                      // Zeilen Ende!!
    }
    return malloc_temp_string(rslt);
}

/**
 @brief src nimmt eine ipv4 Adresse in der form 111.222.333.444 an.
 @return ipv4_t
 @param src IPv4 Adresse in asc.

___[ Revision ]______________________________________________________________

 ** 12.02.24 HS Neu
___________________________________________________________________________*/

ipv4_t getipv4(char *src)
{
    ipv4_t r;
    int n;
    int l;
    r = 0;
    for (l=0;l<4;l++)                                                           // max. 4 Zahlen
    {
        for (n=0;;src++)                                                        // Jede Zahl wird nach n gepatcht
        {
            if ((*src==0) || (*src=='.')) break;                                // Zahl solle abgegrenzt sein
            if (isdigit(*src))                                                  // Nur zahlen sind zulässig
            {
                n = n * 10;                                                     // Zahl konstruieren
                n = n + ( *src - '0' );
            }
        }
        r = (r * 256) + n;                                                      // Jeder char a 8 Bit
        if (*src==0) break;                                                     // ende ?
        src++;
    }
    return r;
}

/**
 @brief num in Binärer Form in einen String schreiben
 @return String
 @param num Zahl die umgewandelt wird

___[ Revision ]______________________________________________________________

 ** 22.07.16 HS ReCreate
___________________________________________________________________________*/

//** 02.04.24 HS malloc_temp statt static
//    char *rslt;
//    rslt = strprintf ( "%4.4i%2.2i%2.2i%2.2i%2.2i%2.2i",
//    return malloc_temp_string(rslt);

char *binstr( unsigned int num )
{
    int i;
    int n;
    int b;
    int m;
    char *rslt;
    rslt = malloc_temp(BIN_INT_SIZE+1);       // 33
    n=num;
    //memset_ex (rslt,0,BIN_INT_SIZE+1);
    b = BIN_INT_SIZE-1;
    m = BIN_INT_SIZE;
    for (i=0;i<m;i++,b--)
    {
        if (n&1) rslt[b] = '1';
        else     rslt[b] = '0';
        n = n / 2;
    }
    return rslt;
}

/**
 @brief Schaut nach ob true,false,1,0 in String stehen
 @return true / false im Fehlerfall false
 @param STRING Die zu bearbeitende Zeichenkette

___[ Revision ]______________________________________________________________

 ** 13.11.16 HS reCreate
 ** 27.12.16 HS für SQLITE3 "Y" und "N" implemntiert
 ** 10.03.18 HS ON/OFF implementation
___________________________________________________________________________*/

int GetIntTrueFalsefromString(char *STRING)
{
    if (!strcmp(STRING, "Y"))        return True;
    if (!strcasecmp(STRING, "true")) return True;
    if (!strcasecmp(STRING, "on"))   return True;
    if (!strcmp(STRING, "1"))        return True;

    if (!strcmp(STRING, "N")) return False;
    if (!strcasecmp(STRING, "false")) return False;
    if (!strcasecmp(STRING, "off"))   return False;
    if (!strcmp(STRING, "0"))         return False;

    lprintf ("Error reading TrueFalse from \"%s\"", STRING);
    return False;
}

///@}
///@}

// Private Funktionen ...
double strexprAtom     (char** expr);
double strexprFactors  (char** expr);
double strexprSummands (char** expr);
int strexpr_brace_count;

/**
 @addtogroup c_strchr
 @{
    @addtogroup c_strchr_strexpr
    @{
    @brief String Expressions nach Zahlen parsen

*//**
 @brief Einlesen einer einzelnen Zahl oder eines Blocks in Klammern
 @return number
 @param expr STRING Die zu bearbeitende Zeichenkette

 Einen einfachen Parses für dezimale Ausdrücke

 Einfach Ausdrücke, wie  1280 + 340 oder 1280 + ( 2 * 170 ) oder 1280 + 4*85 führen zu
 gleichen Ergebnis. DH. sollen die Zeichenfolgen auswertet und das Ergenis richtig zurückgeben.

 Die vier arithmetischen Operatoren und Klammern sind im Ausdruck zulässig. Einfache und
 komplexe Aufgaben sollen in der Routine eingebettet werden.

 Die Aufgabe ist ein einfache Expressionen als auch komplexe Aufgaben in rekursive
 Abstiegsanalyse durchzuführen. Ein einfacher Parser liefert ggf. für 3 + 4 * 2 das Ergebnis 24.
 Mathematisch richtig ist aber die 4*2 zuerst und dann 3 zu addieren auszuführen. Abstiegsparsing!

 Auf der obersten Ebene besteht ein Ausdruck aus mehreren Summanden:

 @code
     4,5 + 6 + 3,4 * (25 - 4) / 2 - 8.
 @endcode
     Summanden sind:
 @code
    + 4,5
    + 6
    + 3,4 * (25 - 4) / 2
    - 8.
 @endcode

 Summanden werden durch die Zeichen "+" und "-" getrennt. Dem Wert 4,5 wird ein Plus gedanklich
 vorrausgestellt. Sie enthalten einzelne Zahlen (4,5, 6, 8) und den komplexen
 Ausdruck [3,4 * (25 - 4) / 2]. die -8 ist also ein negativer Summand.

 Jeder Summand besteht wiederum aus mehreren Faktoren die durch "*" und "/" getrennten 'Dinge'.
 3,4 * (25 - 4) / 2. Die Faktoren sind 3,4, (25 - 4) und 2. Die /2 ist ein Faktor. Mathematisch
 gesehen ist es das Gleiche wie *1/2 ausgerechnet 1/2 = 0,5. Auch Faktoren sind noch zerlegbar.
 Jeder Faktor ist ein Atom. Jedes Atom kann eine einzelne Zahl oder ein Unterausdruck in
 Klammern sein. Unterausdrücke können auf die gleiche Weise wie der gesamte Ausdruck analysiert
 werden ( es sind die Summanden in Klammern, dann Faktoren und dann Atome).

 Rekursives Abstiegsparsing!

 Zur Implementierung ist zu beachten, insbesondere weil auch mehrere Ausdrücke in einer
 Zeile vorkommen können:

 Snippet  | Beschreibung
 --------:|---------------------------
 15 20    | werden als 2 Zahlen -> 15 20
 15+20    | wird zur 35
 15 + 20  | ebenfalls 35 nach dem '+' kommt keine Zahl
 15 +20   | sind 2 Zahlen -> 15 und 20
 (15 +20) | Geklammert ist es nur eine Zahl -> 35


___[ Revision ]______________________________________________________________

 **  03.11.20 HS Erstellt
 **  05.11.20 HS Klammerausdrücke werden gecounted
___________________________________________________________________________*/

double strexpr(char* expr)
{
    strexpr_brace_count=0;
    return strexprSummands(&expr);
    // double r = strexprAtom(&expr);
    // double r = strexprSummands(&expr);
    // lprintf ("last expr = %s    rslt= %f", expr, r);
    // return r;
}

/// @see strexpr mit Rückgabe nach end_ptr
double strexpr_r(char* expr, char** end_ptr)
{
    strexpr_brace_count=0;
    *end_ptr = expr;
    return strexprSummands(end_ptr);
}
///@}
///@}

/// interne Funkktion - Auflösen eines Schnipsels (Atom) @see strexpr
double strexprAtom(char** expr)
{
    double rslt;
    char* end_ptr;
    char* p;
    bool negativ;

    //lprintf ("Incoming %s", p);
    for (p = *expr;;p++)                                    // suche erstes Zeichen hinter den Leerzeichen
    {
        if (*p == 0) return 0;
        if (!isspace(*p)) break;
    }
    //lprintf ("Value started at %s", p);

    if (*p=='-')                                            // Negatives Vorzeichen gefunden ?
    {
        negativ=true;                                       // markiere als negativ
        p++;                                                // überlese das Zeichen
    }else{
        negativ=false;                                      // ansonsten positiv
    }
    if (*p=='+') p++;                                       // Pluszeichen können überlesen werden

    // Prüfe auf Klammern, wenn wahr, dann direkter Ausstiegspunkt
    if(*p == '(')
    {
        *expr = p+1;
        strexpr_brace_count++;
        rslt = strexprSummands(expr);
        for (p = *expr;;p++)                                // suche erstes Zeichen hinter den Leerzeichen
        {
            if (!isspace(*p)) break;
        }
        if(*p != ')') return 0;                             // Möglicher Fehler wenn klammer zu fehlt
        strexpr_brace_count--;
        *expr = p+1;
        return (negativ) ? -rslt : rslt;
    }
    // Mögliche Hexadezimale Zahl prüfen ... kann noch um oktalbereicher erweitert werden
    // 28.11.20 HS p[1] sonst wird daraus nie eine hexzahl
    if ((p[0]=='0') && (p[1]=='x'))                         // 0x am anfang, dann eine Hexadzimale Zahl
    {
        long long y;                                        // für fromHex
        p+=2;                                               // '0x' kann dann mal weg
        fromHex(p, &end_ptr, 0, &y);                        // zahl auflösen und als long long speichern un y
        rslt = (double) y;                                  // was auch das Ergebnis ist
    }else{
        rslt = strtod(p, &end_ptr);                         // simple, einfach den Compiler bemühen
    }
    *expr = end_ptr;                                        // das "Ende" tzurück speichern
    if(end_ptr == p) return 0;                              // nichts gefunden ! Hier könnte eine Fehler ausgegeben werden
    //lprintf ("Outgoing %s", *expr);
    return (negativ) ? -rslt : rslt;                        // Ergebnis mit dem richtigen Vorzeichen
}

/// interne Funkktion - Auflösen eines Factors (Multiplizieren oder Dividieren) @see strexpr
double strexprFactors(char** expr)
{
    double num1;                                            // Erste Zahl
    double num2;                                            // Zeiter Zahl
    char *p;                                                // pnt nacht erster Zahl
    num1 = strexprAtom(expr);                               // auflösen und mit der Zahl zurückkommen
    for(;;)
    {
        p = *expr;
        if (isspace(*p))
        {
            for (;;p++)                                     // suche erstes Zeichen hinter den Leerzeichen
            {
                if (!isspace(*p)) break;
            }
            if (*p == '/')
                if (!isspace(p[1]))
                    if (!isdigit(p[1]))
                        if (strexpr_brace_count==0) return num1;
        }
        if  ((*p != '/') && (*p != '*')) return num1;       // wenn nicht multiplizieren oder division, dann fertig ( Austiegspunkt )
        *expr=p+1;                                          // hinter das Rechenzeichen
        num2 = strexprAtom(expr);                           // 2.Teil holen
        if (*p == '/') num1 /= num2;                        // und Operation durchführen
        else           num1 *= num2;
    }
}

/// interne Funkktion - Auflösen einer Summe (Addition und Subtraktion) @see strexpr
double strexprSummands(char** expr)
{
    double num1;                                            // Erste Zahl
    double num2;                                            // Zeiter Zahl
    char *p;                                                // pnt nacht erster Zahl
    num1 = strexprFactors(expr);                            // auflösen und mit der Zahl zurückkommen
    for(;;)
    {
        p = *expr;
        if (isspace(*p))
        {
            for (;;p++)                                     // suche erstes Zeichen hinter den Leerzeichen
            {
                if (!isspace(*p)) break;
            }
            if ((*p == '-') || (*p == '+'))
            {
                if (isdigit(p[1])) if (strexpr_brace_count==0) return num1; // ** Prüfen ob das so stimmt
            }
        }
        if ((*p != '-') && (*p != '+')) return num1;        // wenn nicht addieren oder subtrahieren ( Austiegspunkt )
        *expr=p+1;                                          // hinter das Rechenzeichen
        num2 = strexprFactors(expr);                        // 2.Teil holen
        if(*p == '-')  num1 -= num2;                        // und Operation durchführen
        else           num1 += num2;
    }
}

/**
 @addtogroup c_strchr
 @{

    @addtogroup c_strchr_escape
    @{
    @brief String (de-)escapen

*/

/**
 @brief Zeichenkette konvertieren um diese ASC in SQL zb. speichern zu können
 @return Konvertieten String
 @param Kette Zeichenkette die konvertiert wird

 - Zeichenkette konvertieren um diese ASC in SQL zb. speichern zu können
 - Auch CR/LF Konvert???
 - toDo: MaxSize

 strEsc und strDeEsc sind entstanden um Texte jeder Form in einem Textfeld in eine SQLite3 Datenbank zu speichern.
 Dabei stellten sich einige Probleme. Unter anderem kann beim strEsc der Buffer viel größer werden als der Orginaltext.
 Bei der Implementation ist dazu noch hinzugekommen, daß man in einem solchen Textfeld schwerlich ein " speichern kann.
 Realisation:
 Die üblichen EscapeZeichen können in \\n \\r usw. gespeichert werden. Zeichen die isprint aussortiert werden als \\000 wobei
 000 durch den ASC-Code gesetzt wird. Alle Zeichen von 001 bis 255 sind so möglich. Das 000 kennzeichnet das Stringende.

___[ Revision ]______________________________________________________________

 ** 16.10.18 HS Create
___________________________________________________________________________*/

char *strEsc(char *Kette)
{
    int szBuf;
    char *rslt;
    int s;
    int d;
    int k;
    unsigned char c;

    szBuf = strlen(Kette) + (( strlen(Kette) * BIGBUFFER_FAKTOR) / 100);        // Startbuffergroeße
    if (szBuf<256) szBuf = 256;                                                 // der Buffer sollte mindestens 256 Byte sein
    //lprintf ("szBuf =%i strlen=%i",szBuf,strlen(Kette));
    rslt = malloc0(szBuf);                                                      // Buffer reservieren

    for (s=0,d=0;;s++,d++)
    {
        if ((d+8)>szBuf)                                                        // Destgrösse sollte mindestens 8 Zeichen Extrabuffer hergeben
        {
            szBuf = szBuf + 128;                                                // Buffer um 128 Zeichen vergrößern
            rslt = realloc(rslt,szBuf);
            //lprintf ("realloc: d=%i szBuf =%i strlen=%i",d,szBuf,strlen(Kette));
            for (k=d;k<szBuf;k++) rslt[k]=0;                                    // den Rest des Buffers mit 0 füllen
        }
        c = Kette[s];                                                           // aktuelles Zeichen
        if (c==0)       { rslt[d]=0; break; }                                   // Ende ?
        if (c=='\\')    { rslt[d]='\\'; d++; rslt[d]='\\'; continue; }          // Backslash selbst
        if (c=='\'')    { rslt[d]='\\'; d++; rslt[d]='\''; continue; }          // Hochkomma
//        if (c=='\"')    { rslt[d]='\\'; d++; rslt[d]='\"'; continue; }        Hat leider nicht geklappt
//        if (isprint(c)) { rslt[d]=c; continue; }

        if (c!='\"') if (isprint(c)) { rslt[d]=c; continue; }                   // Wenn nicht ", dann auf darstelbares Zeichen prüfen

        if (c=='\n')    { rslt[d]='\\'; d++; rslt[d]='n'; continue; }           // LF
        if (c=='\r')    { rslt[d]='\\'; d++; rslt[d]='r'; continue; }           // CR
        if (c=='\t')    { rslt[d]='\\'; d++; rslt[d]='t'; continue; }           // TAB

        rslt[d]='\\'; d++;                                                      // Also ein Zeichen, das als Zahl dargestellt wird
        rslt[d]='0' + c / 100; d++; c = c % 100;
        rslt[d]='0' + c / 10;  d++; c = c % 10;
        rslt[d]='0' + c;
        continue;

        //lprintf ("unknown [strEsc] to %i", c);
        //d--;
    }
    return rslt;
}

/**
 @brief Zeichenkette konvertieren um diese ASC in SQL zb. speichern zu können
 @return Konvertieten String
 @param Kette Zeichenkette die konvertiert wird

 Das Geleiche nochmal rückwärts wie @ref strEsc
 Hier stellt sich das Problem mit dem größer werdenden Buffer nicht.

___[ Revision ]______________________________________________________________

 ** 16.10.18 HS Create
___________________________________________________________________________*/

char *strDeEsc(char *Kette)
{
    char *rslt;
    int s;
    int d;
    unsigned char c;

    rslt = malloc0(strlen(Kette)+16);                                           // Plus+1 hätte gereicht
    for (s=0,d=0;;s++,d++)
    {
        c = Kette[s];                                                           // aktuelles Zeichen
        if (c==0)    { rslt[d]=0; break; }                                      // Ende ?
        if (c!='\\') { rslt[d]=c; continue; }                                   // Backslash ?
        s++;
        c = Kette[s];
        if (c=='n') { rslt[d]='\n'; continue; }                                 // LF
        if (c=='r') { rslt[d]='\r'; continue; }                                 // CR
        if (c=='t') { rslt[d]='\t'; continue; }                                 // TAB
        if (c=='\\') { rslt[d]='\\'; continue; }                                // Backslah selbst
        if (c=='\'') { rslt[d]='\''; continue; }                                // Hochkomma
        if (c=='\"') { rslt[d]='\"'; continue; }                                // Sollte nicht vorkommen, da das mit \034 übersetzt wird

        if ((isdigit(Kette[s])) && (isdigit(Kette[s+1])) && (isdigit(Kette[s+2]))) // Ansonsten 3 Digits für sonstige Sonderzeichen
        {
            c =   (Kette[s]  -'0') * 100; s++;
            c = c+(Kette[s]-'0') * 10;    s++;
            c = c+(Kette[s]-'0');
            rslt[d]=c;
            continue;
        }

        lprintf ("unknown [strDeEsc] to %i", c);
        rslt[d]=0;
        break;
    }
    return rslt;
}
///@}

/* *************************************************
 *                                                 *
 *     Neue (2020) dynamische Stringfunktionen     *
 *                                                 *
 ***************************************************/

/** @addtogroup c_strchr_strstr
    @{
    @brief Dynamische Stringfunktionen mit malloc und das dynamische strprintf

*/

#ifdef HS_DEBUG
void y_dump(ty*y)
{
    printf ("ty-like var:\n");
    printf ("maxsize: %i\n", y->maxsize);
    printf ("pntr:    %i\n", y->pntr);
    //printf ("buffer[32]; %s", strtohexstr(y->buffer, 0x200 + 0x400 + 32));
    printf ("buffer[32]: %s", strtohexstr(y->buffer, 32, 32, STRHEX_NOZERO | STRHEX_ASC ));
}
#else
void y_dump(ty*y __attribute__ ((unused)) ){};
#endif // HS_DEBUG

/**
 @brief Buffer vom Typ @ref ty initialisieren
 @param [in,out] y        ein dynamischer Buffer vom type @ref ty
 @param [in]     b        Ein Buffer mit dem Initialisiert wird. _kann_ NULL sein.

 In buffer Es wird eine Kopie angelegt. DH. der Urspüngliche Buffer wird nicht verändert.

___[ Revision ]______________________________________________________________

 ** 09.04.20 HS Create
___________________________________________________________________________*/

void y_init(ty *y, char *b)
{
    if (b==NULL)
    {
        y->maxsize = YSTRING_BLOCKSIZE;
        y->buffer  = malloc(y->maxsize);
        y->pntr    = 0;
        return;
    }
    y->pntr    = strlen(b);
    for (y->maxsize=0;(y->maxsize)<(y->pntr);y->maxsize+=YSTRING_BLOCKSIZE);
    y->buffer = malloc(y->maxsize);
    memcpy_ex (y->buffer,b,y->pntr);
}

/**
 @brief Ein Bufferende markieren ohne den Zeichenpointer zu ändern
 @param [in,out] y        ein dynamischer Buffer vom type @ref ty

 Markiert nur ein Ende. Der Buffer kann direkt weiter benutzt werden.

___[ Revision ]______________________________________________________________

 ** 09.04.20 HS Create
___________________________________________________________________________*/

void y_end(ty *y)
{
    y_charadd (y, 0);
    y->pntr--;
}

/**
 @brief Per Definition die Funktion, die den Buffer freigibt und so herrichtet, daß er gleich wieder benutzt werden _kann_ .
 @param [in,out] y        ein dynamischer Buffer vom type @ref ty

___[ Revision ]______________________________________________________________

 ** 09.04.20 HS Create
___________________________________________________________________________*/

void y_free(ty *y)
{
    free (y->buffer);
    y->buffer=NULL;
}


/**
 @brief Zeichen dynamisch in einen String schreiben
 @param [in,out] y        ein dynamischer Buffer vom type @ref ty
 @param [in]     c        char der hinzukommt

 Unterste Funktion der dynamischen Stringverwaltung die immer auf den dynamischen Buffer Y zugreift.
 In diesem Fall wird ein einzelnes Zeichen in den Speicher geschrieben.

 Wird der maximale Speicher erreicht, dann wird mit realloc neuer Speicher hinzugeholt.

 Beim ersten Aufruf sollte buffer auf NULL zeigen oder besser mit @ref y_init initialisiert werden

___[ Revision ]______________________________________________________________

 ** 03.04.20 HS Erste Version
___________________________________________________________________________*/

void y_charadd (ty *y, char c)
{
    if (y->buffer==NULL) y_init(y,NULL);
    if ((y->pntr)>=(y->maxsize))
    {
        y->maxsize+=YSTRING_BLOCKSIZE;
        y->buffer=realloc(y->buffer,y->maxsize);
    }
    y->buffer[y->pntr]=c;
    y->pntr+=1;
}

/**
 @brief Ein Zeichen mehrfach dynamisch in einen String schreiben
 @param [in,out] y        ein dynamischer Buffer vom type @ref ty
 @param [in]     c        char der hinzukommt
 @param [in]     nsize    wie oft das Zeichen erzeugt werden soll

 @see y_charadd

___[ Revision ]______________________________________________________________

 ** 06.04.20 HS Create
___________________________________________________________________________*/

void y_multicharadd (ty *y, char c, int nsize)
{
    int n;
    if (nsize>0)
    {
        for (n=0;n<nsize;n++)
        {
            y_charadd( y, c);
        }
    }
}

/**
 @brief Einen String an einen dynamischen Buffer vom Typ ty anhängen
 @param [in,out] y        ein dynamischer Buffer vom type @ref ty
 @param [in]     s        String der hinzukommt

 @see y_charadd

___[ Revision ]______________________________________________________________

 ** 06.04.20 HS Create
___________________________________________________________________________*/

void y_stringadd (ty *y, char *s)
{
    int n;
    for (n=0;;n++)
    {
        if (s[n]==0) break;
        y_charadd( y, s[n]);
    }
}

/**
 @brief Eine Zahl formatiert in den Buffer schreiben
 @param [in,out] y          ein dynamischer Buffer vom type @ref ty
 @param [in]     u          Die Zahl als singend
 @param [in]     base       Die Basis der auszugebenden Zahl typisch sind 2,8,10 oder 16 (Sonderfall 11 zeigt eine unsigned zahl mit base 10 an)
 @param [in]     altformat  Alternatives Format, ob 0x oder 0b vor die Zahl kommen
 @param [in]     capitalize Ergebnis in Grossschrift ( Uppercase )
 @param [in]     num_size   Minimale Größe der Zahl
 @param [in]     num_prec   Genauigkeit
 @param [in]     num_padc   Füllzeichen kann 0,'0' oder auch ' ' sein
 @param [in]     num_adjustment_left Ob die Zahl links- oder rechtsbündig notiert wird
 @param [in]     add_plussign Welches Pluszeichen es sein soll. kann 0,' ' oder '+' sein, intern auch '-'

 Ist im Prinzip eine Unterfunktion von @ref strprintf , die alles aufgeschlüsselt hat.

___[ Revision ]______________________________________________________________

 ** 01.04.20 HS Create
 ** 10.04.20 HS ein overflow nach *-1 abzufragen geht nicht, wenn mit -O2
                kompiliert wird. stattdessen sind jetzt
                LLONG_MAX und LLONG_MIN drin.
___________________________________________________________________________*/

void y_numadd (ty *y, long long u, unsigned int base, bool altformat, bool capitalize, size_t num_size, int num_prec, char num_padc, bool num_adjustment_left, char add_plussign )
{
	ty numbuf;
	int n;
	int adj;
	bool minus;
	bool overflow;
	long long val;
	unsigned long long uval;

	char *digs[3];

    if (capitalize)
    {
        digs[0] = "0123456789ABCDEF";
        digs[1] = "0B";
        digs[2] = "0X";
    }else{
        digs[0] = "0123456789abcdef";
        digs[1] = "0b";
        digs[2] = "0x";
    }

	minus=false;
	overflow=false;
	adj=0;

	y_init(&numbuf,NULL);                                       // numbuf dynamisch

	val =u;

	if (u<0)                                                    // Wenn kleiner null
    {
        minus=true;                                             // setze Minusflag
        if (u!=LLONG_MIN)                                       // Prüfen ob es  0x8000000000000000 war
        {
            u = -u;                                             // Minuszeichen umkehren
        }else{
            u=LLONG_MAX;                                        // jetzt ist u+1 0x8000000000000001
            overflow=true;                                      // overflow setzen
        }
    }
    if (base!=10) add_plussign=0;
    if ((((minus==true) && (base!=10))) || (base==11) )         // Dieser Teil arbeitet mit unsignend values
    {
        if (base==11) base=10;
        uval = 0xffffffffffffffff + val;
        uval ++;
        for (;;)                                                // Zahl reverse ablegen
        {
            n = uval%base;                                      // das was überbleibt, wenn durch base geteilt wird
            y_charadd( &numbuf, digs[0][n]);                    // im Speicher ablegen
            uval /= base;                                       // jetzt teilen
            if (uval==0) break;
        }
        minus=false;
        //overflow=false;
    }else{                                                      // Dieser Teil arbeitet mit _signend_ values
        for (;;)                                                // Zahl reverse ablegen und Spezialbuffer füllen
        {
            n = u%base;                                         // das was überbleibt, wenn durch base geteilt wird
            y_charadd( &numbuf, digs[0][n]);                    // im Speicher ablegen
            u /= base;                                          // jetzt teilen
            if (u==0)                                           // wenn nichts mehr überbleibt
            {
                if (overflow) numbuf.buffer[0]++;               // wenn overflow, dann letzte Zahl um eins mehr
                break;
            }
        }
    }
    if (base==8)                                                // Octalzahlen beginnen immer mit einem 0
    {
        if (numbuf.buffer[numbuf.pntr-1]!='0')                  // wenn das erste Zeichen keine '0' ist, dann vorbauen
        {
            y_charadd(&numbuf, '0');
            altformat=false;
        }
    }

    if ( (minus==true) && (base==10) ) add_plussign='-';        // minus bei base 10 braucht ein Minus
    if (val==0) altformat=false;                                // bei '0' gibt es kein altformat
    if (altformat)                                              // adjustment addieren, nis hier noch nicht wichtig ob vor oder hinten
    {
        if (base==2) adj+=2;
        if (base==16) adj+=2;
    }
    if (num_prec>0)                                             // Genauigkeit muss ggf. mit '0' gefüllt werden
    {
        //bool br; // zum debuggen
        //printf ("size=%i prec=%i adj=%i\n",(int)num_size,num_prec,adj);
        //br = false;
        for(;;)
        {
            if ( (num_size<=0) && ((numbuf.pntr-1)>=(num_prec-(adj+1)))) break; //br=true;
            if ((numbuf.pntr-1)>=(num_prec-(   +1))) break; //br=true;
            //if (br) break;
            y_charadd( &numbuf, '0');
        }
        if (num_padc=='0') num_padc=' ';
    }
    if (!num_padc) num_padc=' ';                                // sicherstellen das padc gefüllt ist
    if (altformat)                                              // mit Angabe von "0x" etc
    {
        if ((num_padc=='0') && (base==2))  y_stringadd( y, digs[1]);
        if ((num_padc=='0') && (base==16)) y_stringadd( y, digs[2]);
    }
    if ( (!num_adjustment_left) && (num_size>0) )               // Fülle wenn Zahl rechts stehen soll
    {
        if (add_plussign && (num_padc=='0'))
        {
            y_charadd( y, add_plussign);
            adj++;
            add_plussign=0;
        }
        if (add_plussign) adj++;                                // adj korriegieren, wenn pluszeichen noch kommt
        n = num_size-(numbuf.pntr+adj);
        y_multicharadd(y, num_padc,n);
        if (add_plussign)
        {
            y_charadd( y, add_plussign);
            add_plussign=0;
        }
    }
    if (altformat)                                              //mit Angabe von 0x etc
    {
        if ((num_padc!='0') && (base==2))  y_stringadd( y, digs[1]);
        if ((num_padc!='0') && (base==16)) y_stringadd( y, digs[2]);
    }
    adj += (numbuf.pntr-1);
    if (add_plussign)
    {
        y_charadd( y, add_plussign);
        adj++;
        //add_plussign=0;
    }
	for (n=numbuf.pntr-1;n>=0;n--)                              // Jetzt den Buffer mit der Zahl umschreiben
    {
        y_charadd(y, numbuf.buffer[n]);
    }
    if ( (num_adjustment_left) && (num_size>0) )
    {
        n = num_size-(adj+1);
        y_multicharadd(y, ' ', n);
    }
    y_free(&numbuf);
}

// https://docs.microsoft.com/de-de/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019
/**
 @brief strprintf kopiert alle Zeichen in fmt nach buffer
 @return buffer ( Null terminiert )
 @param fmt  Format weitgehgend wie printf
 @param ...  Variablen, die zu fmt passen müssen

 strprintf kopiert alle Zeichen in fmt nach buffer, der sich dynamisch
 anpasst. und am Ende mit __free__ freigegeben werden muss.

 Wie in allen Strings gelten hier die üblichen Formatierungssymbole,
 die intern nur 1:1 übernommen werden.

 Als "Esc" wird die Zeichenfolge bezeichnet, die ein Sonderzeichen auslöst.

 Esc | Zeichenbeschreibung
 ----|--------------------
 \\n | (NextLine)   Sprung an den Anfang der folgenden Bildschirmzeile
 \\b | (Backspace)  Gehe ein Zeichen zurück
 \\a | (Akustic)    Akustisches Signal
 \\r | (return)     Sprung an den Anfang der aktuellen Bildschirmzeile
 \\\\ | (Backslash)  Ausgabe des Gegenschrägstrichs "\"
 \\\" | (double Quotes) Ausgabe eines Anführungszeichens
 \\t | (tab)        Sprung zur nächsten Tabulatorposition
 %%n |              Einleitung der formatierten Ausgabe von n bezeichnet. n kann dabei eine komplexe Beschreibung #-11.5llx  oder ein simples s sein.

 Die Beschreibung wie "%12.3s" wird in bis zu 4 Einzelteile zerlegt; siehe Tabelle unten.
 Die Einzelteile haben und müssen in der hier verwendeten Reihenfolge benutzt werden.

 %[flags][width][.[precision]]type

 Einer solchen Formatierungshilfe folgt in den Parametern (...)
 gewöhnlich eine Varaiable, die dazu passen muss. Ist das nicht
 der Fall, dann stürzt das Programm oft ganz unsanft ab.

 Formatierte Ausgabe hat folgende Syntax

 % 	          | @ref printf_Flags | minimaler Platz | Punkt 	| Genauigkeit   | Typ
 -------------|-------------------|-----------------|-----------|---------------|--------------
 erforderlich |	optional          | optional 	    | optional 	| optional 	    | erforderlich
 wie %        | - + ' ' #         | positive Zahl   | .         | positive Zahl | siehe @ref printf_Typ

 @anchor printf_Flags
 Das Feld Flags kann null oder mehr (in beliebiger Reihenfolge) sein und wird wie folgt behandelt

 Charakter   | Beschreibung
 ------------|--------------
 -           | (Minus) Richtet die Ausgabe dieses nach links aus. (Standardmäßig wird die Ausgabe rechtsbündig ausgerichtet.)
 +           | (Plus) Stellt ein Plus für positiv vorzeichenbehaftete numerische Typen voran. positiv = +, negativ = -. (Die Standardeinstellung stellt nichts vor positive Zahlen.)
 Leerzeichen | (Leerzeichen) Stellt ein Leerzeichen für positive vorzeichenbehaftete numerische Typen voran. positiv =, negativ = -. Dieses Flag wird ignoriert, wenn das Flag + vorhanden ist. (Die Standardeinstellung stellt nichts vor positive Zahlen.)
 0           | (Null) Wenn die Option 'Breite' angegeben ist, werden Nullen für numerische Typen vorangestellt. (Die Standardeinstellung stellt Leerzeichen voran.) Beispielsweise erzeugt printf ("%4i", 5) 5, während printf ("%03i", 5) 005 erzeugt.
 #           | (Hash) Alternative Form:
 # bei fF    | Bei f, F enthält die Ausgabe immer einen Dezimalpunkt ** die Type geE sind nicht implementiert **
 # bei bBoxX | Bei b, o, x und X wird der Text 0, 0b, 0B, 0x bzw. 0X Zahlen ungleich Null vorangestellt.

 *//* Derzeit noch nicht drin
 # bei gG    | Bei g und G werden nachgestellte Nullen nicht entfernt
 # bei fFeEg | Bei f, F, e, E und g  enthält die Ausgabe immer einen Dezimalpunkt ** die Type geE sind nicht implementiert **
 (Apostroph) | Auf die Ganzzahl oder den Exponenten einer Dezimalstelle wird das Tausendertrennzeichen angewendet.
 *//**

 @anchor printf_Typ

   Typ      | Beschreibung
 ----------|-------------
 %%d %%i   | Decimal signed number auch %%ld
 %%o	   | Octal integer. immer führende 0 für Oktal in manchen Version von printf auch ohne, hier immer mit
 %%x %%X   | Hex number.
 %%u	   | Unsigned number. wenn nicht llu angegeben, dann ist die die nummer nur einfach long (0xffffffff) llu ist doppel lang (0xffffffffffffffff)
 %%c	   | einfacher char
 %%s	   | String
 %%f	   | double
 %%e %%E   | double. ** not implement **
 %%g %%G   | double. ** not implement **
 %%p	   | zeiger
 %%n	   | Anzah von Chars die printf bisher geschrieben hat. Die Anzahl wird in die Variable geschrieben ** not implement **
 %%        | Ausgabe des Prozent-Zeichens

___[ Revision ]______________________________________________________________

 ** 01.04.20 HS Create
 ** 06.04.20 HS Weiterentwicklung
 ** 09.04.20 HS Auf dynamische Buffer umgestellt
 ** 13.04.20 HS Auf 32bit angepasst
___________________________________________________________________________*/

char *strprintf(const char *fmt, ...)
{
    char *r;
    va_list	argp;
    va_start(argp, fmt);
    r = vstrprintf(fmt, argp);
    va_end(argp);
    return r;
}

/**
 @brief Interna von @ref strprintf
 @return buffer (Null terminiert )
 @param fmt  Format weitgehgend wie printf
 @param argp Variablen, die zu fmt passen müssen

___[ Revision ]______________________________________________________________

 Siehe @ref strprintf
___________________________________________________________________________*/

char *vstrprintf(const char *fmt, va_list argp)
{
	int		length;
	int		prec;
	bool	ladjust;
	char	padc;
	long	nee;
	long long u;
	int		plus_sign;
	bool	altfmt;
	bool	capitals;
    int     islong;
    int		base;
    char    c;
    ty      rslt;
    double  d;
    bool    lenfrom_star;

    y_init(&rslt,NULL);

	for (;;)
    {
        c = *fmt;
        if (c=='\0')                                                            // Stringende
        {
            y_end(&rslt);                                                       // Nullbyte schreiben
            break;
        }
        fmt++;                                                                  // fmt schon mal ++
	    if (c != '%')                                                           // keine va Zeichen->
	    {
	        y_charadd(&rslt,c);                                                 // buffer schreiben
            continue;                                                           // nächstes
	    }

	    length      = 0;
	    prec        = -1;
	    ladjust     = false;
	    padc        = ' ';
	    plus_sign   = 0;
	    altfmt      = false;
        islong      = 0;
        lenfrom_star=false;

	    for(;;)                                                                 // Justierung der Ausgabe
        {
            c = *fmt;
                 if (c == '#') altfmt = true;
            else if (c == '-') ladjust = true;
            else if (c == '+') plus_sign = '+';
            else if (c == '0') padc = '0';
            else if (c == ' ')
            {
                if (plus_sign == 0)	plus_sign = ' ';
            }else{
                break;
            }
            fmt++;
	    }

	    if (isdigit(c))                                                         // Wenn Zahl dann Länge
        {
            while(isdigit(c))
            {
                length = 10 * length + (c - '0');
                fmt++;
                c = *fmt;
            }
	    }else if (c == '*')                                                     // Zahl aus dem nächsten va_arg lesen
	    {                                                                       // printf ("%*.*d",3,4,5.12); wäre ein 005.1200
            fmt++;                                                              // Hier nur das erste *
            c = *fmt;
            length = va_arg(argp, int);
            if (length < 0)
            {
                ladjust = !ladjust;
                length = -length;
            }
            lenfrom_star=true;
	    }

	    if (c == '.')                                                           // möglicher Punkt für folgende Genauigkeit
        {
            fmt++;
            c = *fmt;
            prec = 0;                                                           // kann auch ohne folgende Zahl sein !
            if (isdigit(c))
            {
                while(isdigit(c))                                               // Nochmal * für das 2. Sternchen
                {                                                               // oder
                    prec = 10 * prec + (c - '0');
                    fmt++;
                    c = *fmt;
                }
            }else if (c == '*')                                                 // oder als Parameter
            {
                prec = va_arg(argp, int);
                fmt++;
                c = *fmt;
            }
	    }

	    if (c == 'l')                                                           // l kann jetzt gelesen werden
        {
            for (;;)
            {
                if (c!='l') break;
                islong++;
                fmt++;                                                          // wird nur benötigt wenn sizeof(int)<sizeof(long)
                c = *fmt;
            }
        }

        //I64
        if (c == 'I')                                                           // Das Microsoftformat ist gleichwertig dem llx
        {
            if (!strncmp(fmt,"I64",3))
            {
                fmt+=3;
#ifdef GNU10
                if (!strncmp(fmt,"llu",3)) fmt+=2;                              // %I64llu wie I64u behandeln => GNU10
#endif
                c = *fmt;
                islong+=2;                                                      // beahandeln wie ll
            }
        }

	    capitals=false;	                                                        // Default ist lowercase
	    switch(c)

	    {
            case 'c':                                                           // Character
            {
                c = va_arg(argp, int);
                length--;
                if ((length > 0) && !ladjust)                                   // Links füllen
                {
                    y_multicharadd(&rslt,' ',length);
                }
                y_charadd(&rslt,c);
                if ((length > 0) && ladjust)                                    // rechts füllen
                {
                    y_multicharadd(&rslt,' ',length);
                }
                break;
            }

            case 's':                                                           // String
            {
                char *p;
                char *p2;
                if (prec == -1) prec = 0x7fffffff;                              // Maximumal für INT

                p = va_arg(argp, char *);
                if (p == (char *)0) p = "";

                nee=0;
                if (length > 0 && !ladjust)                                     // Links füllen
                {
                    p2 = p;
                    for (; *p != '\0' && nee < prec; p++) nee++;
                    p = p2;
                    y_multicharadd(&rslt,' ',length-nee);
                }
                if (prec>0)                                                     // wenn Genauikeit >0
                {
                    for (nee = 0;;nee++, p++)
                    {
                        if (*p == '\0') break;
                        if (nee >= prec) break;
                        y_charadd(&rslt,*p);
                    }
                }                                                               // Rechts füllen
                if (nee < length && ladjust) y_multicharadd(&rslt,' ',length-nee);
                break;
            }

            case 'B':                                                           // Binär ausgabe
                capitals=true;
                __attribute__((fallthrough));
            case 'b':
                if (islong<2) u = va_arg(argp, unsigned long);
                else          u = va_arg(argp, __int64);
                y_numadd(&rslt,u,2,altfmt,capitals,length,prec,padc,ladjust,plus_sign);
                break;

            case 'O':                                                           // Octal
            case 'o':
                if (islong<2) u = va_arg(argp, unsigned long);
                else          u = va_arg(argp, __int64);
                y_numadd(&rslt,u,8,altfmt,capitals,length,prec,padc,ladjust,plus_sign);
                break;

            case 'D':                                                           // Zahl ausgeben
            case 'i':
            case 'd':
                if (islong<2) u = va_arg(argp, signed int);   // unter Linux-x64  statt long 19.10.20 HS __int32 geht nicht immer
                else          u = va_arg(argp, __int64);
                y_numadd(&rslt,u,10,altfmt,capitals,length,prec,padc,ladjust,plus_sign);
                break;

            case 'U':                                                           // unsigned Zahl ausgeben
            case 'u':
                if (islong<2) u = va_arg(argp, unsigned long);
                else          u = va_arg(argp, __int64);
                y_numadd(&rslt,u,11,altfmt,capitals,length,prec,padc,ladjust,plus_sign);
                break;

            case 'p':                                                           // pointer ausgeben
                altfmt=true;
                __attribute__((fallthrough));
            case 'x':                                                           // Hex ausgeben
                if (islong<2) u = va_arg(argp, unsigned long);
                else          u = va_arg(argp, __int64);
                y_numadd(&rslt,u,16,altfmt,capitals,length,prec,padc,ladjust,plus_sign);
                break;

            case 'X':                                                           // Hes in Uppercase ausgeben
                capitals=true;
                if (islong<2) u = va_arg(argp, unsigned long);
                else          u = va_arg(argp, __int64);
                y_numadd(&rslt,u,16,altfmt,capitals,length,prec,padc,ladjust,plus_sign);
                break;

            case 'g':                                                           // zZ. nicht implementiert
            case 'E':
            case 'e':
                lprintf ("%%g %%e %%E sind zZ. nicht implementiert");
                //d =
                va_arg(argp, double);
                break;
            case 'F':                                                           // Floatingpoint
            case 'f':
                {
                    int len;
                    double l;
                    double r;
                    //if (islong<2) d = va_arg(argp, double); else
                    if (prec<0) prec=6;                                         // wenn prec nicht nicht angegeben, dann 6 Nachkommastellen
                    d = va_arg(argp, double);                                   // Wert
                    u = d;                                                      // vor dem komma
                    l = u;
                    r = d-l;                                                    // nach dem komma

                    if (lenfrom_star)                                           // %*.f
                    {
                        if (prec==0)  len=length;                               // %*.4f oder %*.*f
                        else          len=length-(1+prec);
                    }else{
                        len=0;
                    }
                    base = rslt.pntr;
                    if (prec==0)
                    {
                        if (r>=0.5) u++;
                    }
                    if (ladjust) y_numadd(&rslt,u,10,false,false,0  ,0,padc,ladjust,plus_sign);
                    else         y_numadd(&rslt,u,10,false,false,len,0,padc,ladjust,plus_sign);

                    if (prec!=0)                                                // Genauigkeit != 0
                    {
                        y_charadd(&rslt,'.');                                   // Punkt
                        for (nee=0;;nee++)
                        {
                            if (nee>=prec) break;                               // für jede Stelle die dargestellt wird vor das Komma verschieben
                            r = r * 10;
                        }
                        u = r;                                                  // Nachkommastellen löschen
                        l = r-u;                                                // l hat jetzt Stellen hinter
                        if (l>=0.5) u++;                                        // möglicherweisen runden

                        if (lenfrom_star) len = length-(rslt.pntr-base);          // von der aktuellen Stelle die Startposition abziehen
                        else              len=0;                                // oder länge 0
                        if (ladjust) y_numadd(&rslt,u,10,false,false,len,prec,'0',ladjust,0);
                        else         y_numadd(&rslt,u,10,false,false,0  ,prec,'0',ladjust,0);
                    }

                    break;
                }

            case '\0':                                                          // Ende ???
                fmt--; // für fmt++ negierenden kann das null byte erneut c zugewiesen werden
                break;

            default:
                y_charadd(&rslt,c);
        }
        fmt++;
    }
    return rslt.buffer;
}

///@}
///@}

/**
 @addtogroup c_tempfile
 @{
 @brief Tempfiles und primitive Random Numbers

 Da MS und Linux sich über die Umsetzung nicht ganz oder auch sehr unschön
 zusammenkommen ist hier alles auf ein simples System zusammengestrichen worden.

 tempuniqnumber liefert nur Zahlen bis 32767 (RAND_MAX). Lieg auch auch rand().

 Die charkette tempfilename muss mit free freigegeben werden.
*/

/**
 @brief Liefert eine Zeichenkette auf ein TempVerzeichnis
        in Abhängigkeit vom Betriebssystem zurück
 @return char*

___[ Revision ]______________________________________________________________

 ** 25.06.20 HS ReCreate
___________________________________________________________________________*/

char *tempdir(void)
{
#ifdef OS_LINUX
    return "/tmp";
#endif
#ifdef OS_WINDOWS
    return getenv("TMP");
#endif // OS_WINDOWS
}

/**
 @brief Liefert eine Zahl im Bereich von 0-9223372036854775807LL
 Kann durch maxrand eingegrenzt werden.
 @return int
 @param maxrand Größtmögliche Zahl, die aber maximal LONGLONGRAND_MAX (0x7ffffffffffffffffLL) sein darf ....

___[ Revision ]______________________________________________________________

 ** 25.06.20 HS ReCreate
___________________________________________________________________________*/

long long randomnumber(long long maxrand)
{
    long long bigsize;
    static bool randomnumberInit=false;

    if (!randomnumberInit)
    {
        randomnumberInit=true;
        srand((unsigned)time(NULL));
        //printf ("srand\n");
    }

    bigsize =  (rand() % 255)                            + //  8
               (rand() % 256) * 0x100LL                  + // 16
               (rand() % 256) * 0x10000LL                + // 24
               (rand() % 256) * 0x1000000LL              + // 32

               (rand() % 256) * 0x100000000LL            + // 40
               (rand() % 256) * 0x10000000000LL          + // 48
               (rand() % 256) * 0x1000000000000LL        + // 56
               (rand() % 128) * 0x100000000000000LL;//   + // 64
               //0;
    return (bigsize % maxrand);
}

/**
 @brief Liefert einen Filenamen ... wobei ins auch NULL sein kann

 Die Zeichenkette von tempfilename muss mit free freigegeben werden.

 Das File existiert zu diesem Zeitpunkt noch nicht. Wenn es angelegt wird, sollte es also auch gelöscht werden.
 Das passiert nämlich sonst nicht. Sollten alle 32... Files angelegt sein, dann kann das dauern bis noch ein
 freies File gefunden wird.

 @return char*
 @param ins eine mögliche Beschreibung, wenn NULL dann "hs"

___[ Revision ]______________________________________________________________

 ** 25.06.20 HS ReCreate
___________________________________________________________________________*/

char *tempfilename(char *ins)
{
    char *s;
    long long rnd;
    if (!ins) ins = m_PRGNAME;

    for (;;)
    {
        rnd = randomnumber(LONGLONGRAND_MAX);
        s = strprintf ("%s" DIR_SEP  "tmp.%s.%I64x.$$$", tempdir(), ins, rnd);
        if (!FileOK(s)) break;
        free(s);
    }
    return s;
}

///@}

/**
 @addtogroup c_malloc
 @{
 @brief Die Speicherheilfer

*/

#ifndef malloc0
/**
 @brief Speicher anfordern und NULLEN
 @return void*
 @param size wieviel Speicher

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void *malloc0(size_t size)
{
    void *mem;
    mem = malloc (size);
    if (!mem) return NULL;
    memset_ex(mem, 0, size);
    return mem;
}
#endif

/**
 @brief Speicher freigeben und den Pointer NULLEN
 @return NULL
 @param Kette pointer auf den freizugebenden Speicher

 @code
 myString = free0(myString);
 @endcode

___[ Revision ]______________________________________________________________

 ** 26.12.06 HS Create
 ** 02.04.24 HS Kette=NULL geht nicht wenn kette schon NULL
___________________________________________________________________________*/

void* free0(void *Kette)
{
    if (Kette)
    {
        free(Kette);
        Kette=NULL;
    }
    return Kette;
}


//extern void *malloc (size_t __size) __THROW __attribute_malloc__ __attribute_alloc_size__ ((1)) __wur;
/// interner Zähler: 0=MALLOC_ROTATE_SIZE Zeiger auf buffer -1=uninitialisiert
int malloc_tid=-1;
/// interner Buffer fuer malloc_temp
void *malloc_rotate_buffer[MALLOC_ROTATE_SIZE];

/**
 @brief malloc_tmp - Speicher initialisieren

___[ Revision ]______________________________________________________________

 ** 02.04.24 HS Erste Revision
___________________________________________________________________________*/

void malloc_temp_init(void)
{
    if (malloc_tid>=0) return;
    for (malloc_tid=0;malloc_tid<_countof(malloc_rotate_buffer);malloc_tid++)
    {
        malloc_rotate_buffer[malloc_tid]=NULL;
    }
    malloc_tid=0;
}


/**
 @brief malloc_tmp - Speicher freigeben

___[ Revision ]______________________________________________________________

 ** 02.04.24 HS Erste Revision
___________________________________________________________________________*/

void malloc_temp_free(void)
{
    int freeID;
    malloc_temp_init();
    for (freeID=0;freeID<_countof(malloc_rotate_buffer);freeID++)
    {
        if (malloc_rotate_buffer[freeID]) malloc_rotate_buffer[freeID]=free0(malloc_rotate_buffer[freeID]);
    }
    malloc_tid=0;
}


/**
 @brief malloc_tmp - Speicher reservieren ( rotieren )
 @return Zeiger auf den Speicher
 @param sz Größe die benötigt wird


___[ Revision ]______________________________________________________________

 ** 02.04.24 HS Erste Revision
___________________________________________________________________________*/

void *malloc_temp(size_t sz)
{
    if (malloc_tid<0) malloc_temp_init();
    malloc_tid++;                                                               // Wenn Init dann bei 1 anfangen
    if (malloc_tid>=_countof(malloc_rotate_buffer))                             // bei überlauf mit 0 anfangen
    {
        //for (int soi=0; soi<MALLOC_ROTATE_SIZE; soi++) printf ("%i:%s\n", soi, strNotNULL(malloc_rotate_buffer[soi]));
        malloc_tid=0;
    }
    //printf ("new memory %i: sz=%i\n",malloc_tid,sz);
    if (malloc_rotate_buffer[malloc_tid])
    {
        malloc_rotate_buffer[malloc_tid] = free0(malloc_rotate_buffer[malloc_tid]);
    }
    if (sz>0) malloc_rotate_buffer[malloc_tid] = malloc0(sz+1);
    return malloc_rotate_buffer[malloc_tid];
}

/**
 @brief malloc_tmp - Speicher reservieren für Kette
 @return Zeiger auf den neuen Speicher mit Kette
 @param Kette String der dupliziert erzeugt wird

___[ Revision ]______________________________________________________________

 ** 02.04.24 HS Erste Revision
___________________________________________________________________________*/

char *malloc_temp_strcpy(char *Kette)
{
    char *malloc_rslt;
    if (!Kette) return Kette;
    malloc_rslt=malloc_temp(strlen(Kette)+2);
    strcpy_ex(malloc_rslt,Kette);
    return malloc_rslt;
}

/**
 @brief malloc_tmp - Speicher zuordnen
 @return Zeiger auf auf Kette
 @param Kette String der im Speicher fertig ist

___[ Revision ]______________________________________________________________

 ** 02.04.24 HS Erste Revision
___________________________________________________________________________*/

char *malloc_temp_string(char *Kette)
{
    if (!Kette) return Kette;
    malloc_temp(0);                             // Zähler addieren; alten Speicher freigeben
    malloc_rotate_buffer[malloc_tid] = Kette;   // der Buffer muß NULL sein
    return malloc_rotate_buffer[malloc_tid];    // zurück mit Kette
}

/**
 @brief Speicher vorbelegen mit einem bestimmten Wert
 @param dest Ab hier fuellen
 @param val  womit fuellen
 @param len  wie oft soll da Zeichen wiederholt werden
 @return dest

 macht das Gleiche wie memset nur dass nicht gemeckert wird

 @code
 myString = memset_ex(myString,'*',20);
 @endcode

___[ Revision ]______________________________________________________________

 ** 16.07.22 HS Workaround für C11
_____________________________________________________________________________*/

void *memset_ex(void *dest, int val, size_t len)
{
    unsigned char *ptr = dest;
    while (len-- > 0)
        *ptr++ = val;
    return dest;
}

#ifndef OS_WINDOWS
void ZeroMemory(void *Destination, size_t Length)
{
    memset_ex(Destination,0,Length);
}
#endif // OS_WINDOWS

/**
 @brief Speicher kopieren von src nach dest
 @param dst    Destination Pointer
 @param src    Source Pointer
 @param len    Anzahl der zu kopierenden Zeichen (chars)
 @return dst

 macht das Gleiche wie memcpy nur dass nicht gemeckert wird

___[ Revision ]______________________________________________________________

 ** 24.07.22 HS wg. GCC 11.2 umgehung der Fehlermeldung
___________________________________________________________________________*/

void *memcpy_ex(void *dst, const char *src, size_t len)
{
    assert(src!=NULL);
    unsigned char *dest = dst;
    while (len-- > 0)
      *dest++ = *src++;
    return dst;
}

///@}

/**
 @addtogroup c_timerfunc
 @{
 @brief Verarbeitung von Datum und Uhrzeit auch mit Strings

*/ /**
 @brief Aus der time_t einen String in der Form YYYY-MM-DD HH:MM:SS machen
 @return String in der Form YYYY-MM-DD HH:MM:SS
 @param TIME Zeit im Unix Format

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *timeinfostr(time_t TIME)
{
    char *rslt;
    struct tm *ti;
    ti=localtime(&TIME);
    rslt = strprintf ("%4.4i-%2.2i-%2.2i %2.2i:%2.2i:%2.2i",
            ti->tm_year+1900,ti->tm_mon+1,ti->tm_mday,
            ti->tm_hour,     ti->tm_min,ti->tm_sec);
    return malloc_temp_string(rslt);
}

/**
 @brief Aus der time_t einen String in der Form YYYY-MM-DD machen
 @return String in der Form YYYY-MM-DD
 @param TIME Zeit im Unix Format

 Hier könnte eine Beschreibung stehen

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *datestr(time_t TIME)
{
    char *rslt;
    struct tm *ti;
    ti=localtime(&TIME);
    rslt = strprintf ("%4.4i-%2.2i-%2.2i",
             ti->tm_year+1900,
             ti->tm_mon+1,
             ti->tm_mday
            );
    return malloc_temp_string(rslt);
}

/**
 @brief kurzen timestamp generieren
 @return String in der Form DDMMYYHHMMSS
 @param TIME Zeit im Unix Format

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *timestamp(time_t TIME)
{
    char *rslt;
    struct tm *ti;
    ti=localtime(&TIME);
    rslt = strprintf ("%2.2i%2.2i%2.2i%2.2i%2.2i%2.2i",
             ti->tm_mday,
             ti->tm_mon+1,
             (ti->tm_year+1900) % 100,
             ti->tm_hour,
             ti->tm_min,
             ti->tm_sec);
    return malloc_temp_string(rslt);
}

/**
 @brief kurzen timestamp generieren
 @return String in der Form YYYYMMDDhhmmss
 @param TIME Zeit im Unix Format

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *shorttimestr(time_t TIME)
{
    char *rslt;
    struct tm *ti;
    ti=localtime(&TIME);
    rslt = strprintf ( "%4.4i%2.2i%2.2i%2.2i%2.2i%2.2i",
            ti->tm_year+1900,ti->tm_mon+1,ti->tm_mday,
            ti->tm_hour,     ti->tm_min,ti->tm_sec);
    return malloc_temp_string(rslt);
}

/**
 @brief Unix Time Sekunden seit dem 1.1.1970 00:00 Uhr
 @return time_t mit sekunden seit 1970

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

time_t unixtime(void)
{
   return (time(NULL));
}

/**
 @brief gibt Zeit in sekunden seit 1.1.1970 zurück. Nutzt mktime()
 @return time_t mit sekunden seit 1970
 @param  year Jahr
 @param  mon  Monat
 @param  day  Tag
 @param  hour Stunde
 @param  min  Minute
 @param  sec  Sekunden
 @param  isday DayLightSave wenn -1, dann wird es berechnet

 gibt Zeit in sekunden seit 1.1.1970 zurück. Nutzt mktime()
 isday wird mit übergeben oder bei -1 berechnet

___[ Revision ]______________________________________________________________

 ** 13.11.18 HS Create
___________________________________________________________________________*/

time_t mktime_t(int year, int mon, int day, int hour, int min, int sec, int isday)
{
    struct tm tm;

    tm.tm_mday      = 0;
    tm.tm_yday      = 0;

    tm.tm_sec       = sec;
    tm.tm_min       = min;
    tm.tm_hour      = hour;
    tm.tm_mday      = day;
    tm.tm_mon       = mon-1;
    tm.tm_year      = year-1900;
    if (isday>=0)
    {
        tm.tm_isdst     = isday;
    }else{
        tm.tm_isdst     = Date_Is_DST(year,mon,day,hour);
    }
    return (mktime (&tm));

/* Altenativ ?? da variable Monate eher nicht
        given = sec;
        given = given + min * 60;
        given = given + hour * 3600;
        given = given + day  * 3600 * 24;
        given = given + mon  * 3600 * 24 * 30;
        given = given + yrs  * 3600 * 24 * 30 * 12;
*/
}

#ifndef TIME_T_MIN
/// Minimale Zeit 1970 @see mktime_s <- wird hier verwendet
#define TIME_T_MIN  ((time_t)0 < (time_t)-1 ? (time_t)0 : (time_t)1 << (sizeof(time_t) * CHAR_BIT - 1))
#endif
#ifndef TIME_T_MAX
// #define TIME_T_MAX_O	(time_t)((1UL << ((sizeof(time_t) << 3) - 1)) - 1)
/// Maximale Zeit 2038 @see mktime_s <- wird hier verwendet
#define TIME_T_MAX      (~(time_t)0 - TIME_T_MIN)
#endif

/**
 @brief Die Zeit in Sekunden seit 1.1.1970 wird in Integervariablen aufgeteilt.
 @return EXIT_FAILURE / EXIT_SUCCESS und die ganzen integer
 @param [in]  unxtme    Zeit, die aufgeteilt werden soll
 @param [out] isYear    Jahr
 @param [out] isMon     Monat
 @param [out] isDay     Tag
 @param [out] isHrs     Stunde
 @param [out] isMin     Minute
 @param [out] isSec     Sekunde

 Die Zeit in Sekunden seit 1.1.1970 wird in Integervariaablen aufgeteilt.
 Aufruf gewöhnlich über ...
   mktime_s(given, &yrs, &mon, &day, &hrs, &min, &res);

 Bei erfolgreicher Konvertierung wird EXIT_SUCCESS zurückgegeben.
 Ansonsten EXIT_FAILURE. Ist aber eher experimentel, Spätestens wenn
 das 2038 Jahr Problem sich dramatisiert muß hier nachgearbeitet werden.

___[ Revision ]______________________________________________________________

 ** 14.11.18 HS Create
 ** 12.01.19 HS Unix produziert einen Warning bei "unxtme <= -2147483648",
                mit LL wird das umgangen
 ** 13.02.19 HS Nochmal umgebaut und stattdessen TIME_T_MAX ... _MIN verwendet
___________________________________________________________________________*/


int mktime_s ( time_t unxtme, int *isYear, int *isMon, int *isDay, int *isHrs, int *isMin, int *isSec)
{
    struct tm *ti;
    if (unxtme >   TIME_T_MAX)   return EXIT_FAILURE; //0x7fffffff
    if (unxtme <=  TIME_T_MIN)   return EXIT_FAILURE;

    ti = localtime(&unxtme);

    *isYear  = ti->tm_year;
    *isMon   = ti->tm_mon+1;
    *isDay   = ti->tm_mday;

    *isHrs   = ti->tm_hour;
    *isMin   = ti->tm_min;
    *isSec   = ti->tm_sec;

    return EXIT_SUCCESS;
}

/**
 @brief Wochentag des Datums sonntag=0 ... samstag=6
 @return Sonntag=0 ... samstag=6
 @param year Jahr
 @param month Monat
 @param day TAG

___[ Revision ]______________________________________________________________

 ** 02.11.18 HS Create
___________________________________________________________________________*/

int weekday(int year, int month, int day)
{
	int adj;
	int mm;
	int yy;
	adj = (14 - month) / 12;
	mm = month + 12 * adj - 2;
	yy = year - adj;
	return (day + (13 * mm - 1) / 5 +
                         yy         +
                         yy / 4     -
                         yy / 100   +
                         yy / 400
           ) % 7;
}

/**
 @brief Feststellen on Schaltjahr ist
 @return Rückgabe 1, wenn Schaltjahr ansonsten 0
 @param Year Jahr

 Die Regel lautet: Alles, was durch 4 teilbar ist, ist ein Schaltjahr.
 Es sei denn, das Jahr ist durch 100 teilbar, dann ist es keins.
 Aber wenn es durch 400 teilbar ist, ist es doch wieder eins.

 Rückgabe 1, wenn Schaltjahr ansonsten 0
  damit man mit dem Ergebnis direkt rechnen kann, ansonsten waere es true/false

___[ Revision ]______________________________________________________________

 ** 14.11.18 HS Create
___________________________________________________________________________*/

int isLeapYear(const int Year)
{
    if ((Year % 4)!=0)      return 0;
    if ((Year % 400)==0)    return 1;
    if ((Year % 100)==0)    return 0;
//    return (!(year % 4) && year % 100 || !(year % 400)) ? 1 : 0;
    return 1;
}

/**
 @brief Feststellen wieviele Tage der aktuelle Monat hat
 @return letzter Tag ....[bei falschen Werten gibts es Chaos] nicht -1 wenn Datum fehlerhaft ist
 @param Year    Jahr
 @param month   Monat

___[ Revision ]______________________________________________________________

 ** 25.10.20 HS Create
___________________________________________________________________________*/

int DaysOfMonth(int Year, int month)
{
    int DaysOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month!=2) return DaysOfMonth[month];
    if (isLeapYear(Year)) return DaysOfMonth[month]+1;
    return DaysOfMonth[month];
}

/**
 @brief Prüfung, ob angegebenes Datum in der Sommerzeit liegt
 @return true / false
 @param Year    Jahr
 @param month   Monat
 @param day     Tag
 @param hour    Stunde

 <a href="https://de.wikipedia.org/wiki/Sommerzeit">Sommerzeit auf wikipedia</a>

___[ Revision ]______________________________________________________________

 ** 02.11.18 HS Create
 ** 06.11.18 HS Sicher gestellt das nur true oder false übergeben wird
                Struktur besser debugbar aufgebessert
 ** 31.03.20 HS Mit Stunde 3 Uhr wird die Zeit umgestellt.
___________________________________________________________________________*/

int Date_Is_DST (int Year, int month, int day, int hour)
{
    int previousSunday;
    int wday;

    if (Year < 1980) return false;
    //if (Year > 2018) return false; // Abgeschafte Sommerzeit

    if (month < 3 || month > 10)  return false;
    if (month > 3 && month < 10)  return true;

    wday = weekday(Year, month, day);
    previousSunday = day - wday;

    if (month == 3)
    {
        if (previousSunday < 25)  return false;
        if (wday>0)               return true;
        if (hour<3)               return false;
        return true;
    }

    if (month == 10)
    {
        if (previousSunday < 25)  return true;
        if (wday>0)               return false;
        if (hour<3)               return true;
        return false;
    }
    return false; // this line never gonna happend
}

/**
 @brief Prüfung, ob angegebenes Datum (im time_t format) in der Sommerzeit liegt
 @return true / false
 @param TIME Zeit im Unix Format

 @see Date_Is_DST

___[ Revision ]______________________________________________________________

 ** 02.11.18 HS Create
 ** 06.11.18 HS tm_mon muss +1 sein sonst wären Monate nicht von 1-12
___________________________________________________________________________*/

int time_tIsDST(time_t TIME)
{
    struct tm *ti;
    if (TIME==-1)
    {
        lprintf ("--debug-- TIME = -1 meand date out of range or else");
        return false;
    }
    ti=localtime(&TIME);
    return Date_Is_DST(ti->tm_year+1900,ti->tm_mon+1, ti->tm_mday, ti->tm_hour);
}

static char *Daynames_short[]   = {	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", };
static char *Daynames_long[]    = {	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", };
static char *Monthnames_short[] = {	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", };
static char *Monthnames_long[]  = {	"January", "February", "March", "April", "May", "June", "July",	"August", "September", "October", "November", "December",};

/**
 @brief strftime <b>R</b>eplace
 @return -1 im Fehlerfall oder oder Größe von s
 @param s           wohin soll das String
 @param maxsize     Maximale länge
 @param format      @ref strftimeR_formatbeschreibung Format Beschreibung
 @param t           Zeitbeschreibung

 @anchor strftimeR_formatbeschreibung

 Formatangaben für <b>strftimeR</b>

 fmt       | Bezeichnung                                                       | Beispiel
-----------|-------------------------------------------------------------------|-----
 \%A       | Voller Name des Wochentags                                        | Tuesday
 \%a 	   | Abgekürzter Name des Wochentags                                   | Tue
 \%B 	   | Voller Name des Monats                                            | June
 \%b / \%h | Abgekürzter Name des Monats                                       | Jun
 \%C 	   | Darstellung von Datum und Zeit "%a %b %e %H:%M:%S %Y"             | Tue May  1 07:02:42 2018
 \%c 	   | Amerikanische Darstellung von Datum und Zeit "%m/%d/%y %H:%M:%S"  | 05/01/18 07:02:42
 \%D / \%x | Amerikanische Darstellung von Datum "%m/%d/%y"                    | 05/01/18
 \%d 	   | Tag im Monat (01-31)                                              | 01
 \%e 	   | Tag im Monat ( 1-31) jedoch mit Leerzeichen gefüllt               |  1
 \%H 	   | Stunde (00-23)                                                    | 07
 \%I 	   | Stunde (00-11)                                                    | 07
 \%j 	   | Tag im Jahr (001-366)                                             | 085
 \%k 	   | Stunde ( 0-23) jedoch mit Leerzeichen gefüllt                     |  7
 \%l 	   | Stunde ( 0-11) jedoch mit Leerzeichen gefüllt                     |  7
 \%M 	   | Minute (00-59)                                                    | 42
 \%m 	   | Monat (01-12)                                                     | 05
 \%n 	   | \\n                                                               | \\n
 \%p 	   | lokale Form von AM oder PM                                        | AM
 \%S 	   | Sekunde (00-61)                                                   | 42
 \%s 	   | Sekunden seit 1.1.1970                                            | 1525150962
 \%T / \%X | Lokale Form der Zeit                                              | 07:02:42
 \%t 	   | \\t                                                               | \\t
 \%U 	   | Woche im Jahr (Sonntag erster Wochentag, 00-53)                   | 17
 \%W 	   | Woche im Jahr (Montag erster Wochentag, 00-53)                    | 18
 \%w 	   | Wochentag (0-6, Sonntag=0)                                        | 2
 \%y 	   | Jahr zweistellig (00-99)                                          | 18
 \%Y 	   | Jahr vierstellig (1900-)                                          | 2018
 \%\% 	   | Steht für \%                                                      | \%

___[ Revision ]______________________________________________________________

 ** 03.03.19 HS Create
 ** 25.03.20 HS Dokumentation vervollständigt
___________________________________________________________________________*/

size_t strftimeR(char *s,int maxsize, const char *format, const struct tm *t)
{
    int max;
	max = maxsize;
	if (max < 1) return -1;
	if (strftime_fmt(format, t, &s, &max)<0) return -1;
    return (maxsize - max);
}

/**
 @brief String aus der Zeit machen
 @return Gibt einen String zurück mit der UnixZeit in Verbindung mit format
 @param ltime   DatumZeit in Sekunden seit 1970
 @param format  Ausgabeformat der Zeitbeschreibung @ref strftimeR_formatbeschreibung "Format Beschreibung"

___[ Revision ]______________________________________________________________

 ** 08.08.16 HS Create
 ** 03.03.19 HS auf strftimeR umgestellt
 ** 02.04.24 HS malloc_temp return, TSTR kann nicht mit malloc geholt werden
___________________________________________________________________________*/

char *strstime(time_t ltime, char *format)
{
    static char TSTR[64];                                   // muss ein static char sein !!
    struct tm *tt;
    if (format==NULL)
    {
        strcpy (TSTR, "nix");
        return TSTR;
    }
    tt = localtime(&ltime);
    tt->tm_isdst=0;
    strftimeR (TSTR, 64, format, tt);
    return malloc_temp_strcpy(TSTR);
}

/**
 @brief Schreibt in einen String ( in_out_pt ) die Zeit ( t ) nach den vorgegeben Angaben ( format)
 @return -1 Im Fehlerfall 0 im Erfolgsfall
 @param format      Ausgabeformat der Zeitbeschreibung @ref strftimeR_formatbeschreibung "Format Beschreibung"
 @param t           Zeit
 @param in_out_pt   String der das Ergebnis enthält
 @param max         maximale Stringlänge

 Der eigentliche Worker

 - strftime Replace
 - strftime hatte mal einen "Mrz" statt Mar zurückgegeben
 - da flog die glibc_strftime raus und strftimeR kam rein

 Kann das Gleiche wie strftime, nur Fehlerfrei

___[ Revision ]______________________________________________________________

 ** 03.03.19 HS Create
___________________________________________________________________________*/

int strftime_fmt(const char *format, const struct tm *t, char **in_out_pt, int *max)
{
    char *pt;
    pt = *in_out_pt;

	for (; *format; format++)
	{
		if (*format == '%')
        {
			format++;
			switch(*format)
			{
			case 0:
				break;
			case 'A':
				if (t->tm_wday < 0 || t->tm_wday > 6) 	        return -1;
                if (strstradd(pt,&pt,Daynames_long[t->tm_wday],max)<0)   return -1;
				continue;
			case 'a':
				if (t->tm_wday < 0 || t->tm_wday > 6) 	        return -1;
				if (strstradd(pt,&pt,Daynames_short[t->tm_wday],max)<0)   return -1;
				continue;
			case 'B':
				if (t->tm_mon < 0 || t->tm_mon > 11)	        return -1;
				if (strstradd(pt,&pt,Monthnames_long[t->tm_mon],max)<0)    return -1;
				continue;
			case 'b':
			case 'h':
				if (t->tm_mon < 0 || t->tm_mon > 11)            return -1;
				if (strstradd(pt,&pt,Monthnames_short[t->tm_mon],max)<0)    return -1;
				continue;
			case 'C':
				if (strftime_fmt("%a %b %e %H:%M:%S %Y", t,&pt,max)<0)	return -1;
				continue;
			case 'c':
				if (strftime_fmt("%m/%d/%y %H:%M:%S", t, &pt, max)<0) return -1;
				continue;
			case 'D':
			case 'x':
				if (strftime_fmt("%m/%d/%y", t, &pt, max)<0) return -1;
				continue;
			case 'd':
				 if (strstradd(pt,&pt,strnumformated(t->tm_mday, '0',2), max)<0) return -1;
				continue;
			case 'e':
			    if (strstradd(pt,&pt,strnumformated(t->tm_mday,' ',2),max)<0)    return -1;
				continue;
			case 'H':
				if (strstradd(pt,&pt,strnumformated(t->tm_hour,'0',2), max)<0) return -1;
				continue;
			case 'I':
				 if (strstradd(pt,&pt,strnumformated(t->tm_hour % 12 ? t->tm_hour % 12 : 12, '0', 2), max)<0) return -1;
				continue;
			case 'j':
				 if (strstradd(pt,&pt,strnumformated(t->tm_yday + 1, '0', 3), max)<0) return -1;
				continue;
			case 'k':
				 if (strstradd(pt,&pt,strnumformated(t->tm_hour, ' ', 2), max)<0) return -1;
				continue;
			case 'l':
				 if (strstradd(pt,&pt,strnumformated(t->tm_hour % 12 ? t->tm_hour % 12 : 12,' ',2), max)<0) return -1;
				continue;
			case 'M':
				 if (strstradd(pt,&pt,strnumformated(t->tm_min, '0', 2), max)<0) return -1;
				continue;
			case 'm':
				 if (strstradd(pt,&pt,strnumformated(t->tm_mon + 1,'0',2), max)<0) return -1;
				continue;
			case 'n':
                if (strstradd(pt,&pt,"\n",max)<0)    return -1;
				continue;
			case 'p':
				if (strstradd(pt,&pt,t->tm_hour >= 12 ? "PM" : "AM",max)<0)    return -1;
				continue;
			case 'R':
			    if (strftime_fmt("%H:%M", t, &pt, max)<0) return -1;
				continue;
			case 'r':
			    if (strftime_fmt("%I:%M:%S %p", t, &pt, max)<0) return -1;
				continue;
			case 'S':
				 if (strstradd(pt,&pt,strnumformated(t->tm_sec, '0', 2), max)<0) return -1;
				continue;
			case 's':
			    if (strstradd(pt,&pt, HSLnum2Str(mktime_t( t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, t->tm_isdst),0,0,0),max)<0) return -1;
				continue;
			case 'T':
			case 'X':
			    if (strftime_fmt("%H:%M:%S", t, &pt, max)<0) return -1;
				continue;
			case 't':
                if (strstradd(pt,&pt,"\t",max)<0)    return -1;
				continue;
			case 'U': // week of year
				 if (strstradd(pt,&pt,strnumformated((t->tm_yday + 7 - t->tm_wday) / 7, '0', 2), max)<0) return -1;
				continue;
			case 'W':
				 if (strstradd(pt,&pt,strnumformated((t->tm_yday + 7 - (t->tm_wday ? (t->tm_wday - 1) : 6)) / 7, '0',2), max)<0) return -1;
				continue;
			case 'w':
				 if (strstradd(pt,&pt,strnumformated(t->tm_wday, '0',1), max)<0) return -1;
				continue;
			case 'y':
				 if (strstradd(pt,&pt,strnumformated((t->tm_year + 1900) % 100, '0',2), max)<0) return -1;
				continue;
			case 'Y':
				 if (strstradd(pt,&pt,strnumformated(t->tm_year + 1900, '0', 4), max)<0) return -1;
				continue;
			case '%':
			default:
				break;
			}
		}
		*max = (*max)-1;
		if (*max<=0)
        {
            *pt=0;
            return -1;
        }
		*pt = *format;
		pt++;
	}
	*pt=0;
	*in_out_pt=pt;
	return 0;
}
/**
 @brief String aus der Zeit machen
 @return Gibt einen String zurück mit der UnixZeit in Verbindung mit format
 @param ltime   DatumZeit in Sekunden seit 1970
 @param format  Ausgabeformat der Zeitbeschreibung @ref strtime_formatbeschreibung "Format Beschreibung"

 @anchor strtime_formatbeschreibung

 Wenn Format mit 0x100 geor wird, dann wird die gmt statt der localtime verwendet

 num |  Beispielergebnis                    | Formatierung
 ----|--------------------------------------|----------------
 dfl |  00:00:00                            | hh:mm:ss
   0 |  00:00:00,000001                     | hh:mm:ss,iiiiii
   1 |  00:00:00,001                        | hh:mm:ss,iii
   2 |  06.02.1994 00:00:00                 | dd.mm.yyyy hh:mm:ss
   3 |  000:00:00:00                        | ddd:hh:mm:ss
   4 |  00000:00:00:00                      | ddddd:hh:mm:ss
   5 |  Wednesday, 07-Jun-00 23:12:40 GMT   | strtime
   6 |  2000-06-18                          | yyyy-mm-dd
   7 |  06.02.1994 00:00                    | dd.mm.yyyy hh:mm
   8 |  Tue, 15 Nov 1994 12:45:26 GMT       | strtime
   9 |  06.02.1994                          | dd.mm.yyyy
  10 |  19940206124526000234                | yyyymmddhhmmssiiiiii
  11 |  06.02.94                            | dd.mm.yy
  12 |  94.02.05                            | yy.mm.dd
  13 |  2000-06-18 15:43:23                 | yyyy-mm-dd hh:mm:ss
  14 |  2000_08_08_1600                     | yyyy_mm_dd_hhmm
  15 |  2000                                | yyyy
  16 |  08                                  | MM
  17 |  22                                  | DD
  18 |  23                                  | hh
  19 |  59                                  | mm
  20 |  20000808                            | yyyymmdd
  21 |  02h:14m:10s                         | hhh:mmm:sss 00x: wird nicht ausgegeben

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 08.08.16 HS added 14
 ** 31.12.16 HS added 15-19
 ** 10.04.20 HS added 20
 ** 01.10.22 HS added 21
 ** 02.04.24 HS malloc_temp statt static
__________________________________________________________________________*/

char *strtime(time_t ltime, int format)
{
    char *TSTR;
    TSTR = malloc_temp(64);

    struct tm      *tt;
    time_t         nn;
    struct tm       leer;

    int j;

    nn=ltime;
    if (format>=0x100)
    {
        tt = gmtime(&nn);
    }else{
        tt = localtime(&nn);
    }
    if (tt==NULL)
    {
        leer.tm_hour  = 0;
        leer.tm_isdst = 0;
        leer.tm_mday  = 0;
        leer.tm_min   = 0;
        leer.tm_mon   = 0;
        leer.tm_sec   = 0;
        leer.tm_wday  = 0;
        leer.tm_yday  = 0;
        leer.tm_year  = 0;
        tt = &leer;
    }

/*
       tm_sec  range 0 to 59
       tm_min  range 0 to 59.
       tm_hour range 0 to 23.
       tm_mday range 1 to 31.
       tm_mon  range 0 to 11.
       tm_year The number of years since 1900.
       tm_wday The number of days since Sunday, in the range 0 to 6.
       tm_yday The number of days since January 1, in the range 0 to 365.
       tm_isdst A  flag that indicates whether daylight saving time
              is in effect at the time described.  The  value  is
              positive if daylight saving time is in effect, zero
              if it is not, and negative if  the  information  is
              not available.
*/

    switch (format & 0xff)
    {
    case 0:     //   0  00:00:00,000001         hh:mm:ss,iiiiii
        sprintf_ex (TSTR, "%2.2i:%2.2i:%2.2i",tt->tm_hour,tt->tm_min,tt->tm_sec);
        break;

    case 1:     //   1  00:00:00,001            hh:mm:ss,iii
        sprintf_ex (TSTR, "%2.2i:%2.2i:%2.2i",tt->tm_hour,tt->tm_min,tt->tm_sec);
        break;

    case 2:     //   2  06.02.1994 00:00:00     dd.mm.yy hh:mm:ss
        sprintf_ex (TSTR, "%2.2i.%2.2i.%4.4i %2.2i:%2.2i:%2.2i"
                 ,tt->tm_mday,tt->tm_mon+1,tt->tm_year+1900
                 ,tt->tm_hour,tt->tm_min,tt->tm_sec );
        break;

    case 3:     //   3  000:00:00:00            ddd:hh:mm:ss
        sprintf_ex (TSTR, "%3.3i:%2.2i:%2.2i:%2.2i"
                 ,tt->tm_yday+1
                 ,tt->tm_hour,tt->tm_min,tt->tm_sec );
        break;

    case 4:     //   4  00000:00:00:00          ddddd:hh:mm:ss

        sprintf_ex (TSTR, TIME_STR_5LU ":%2.2i:%2.2i:%2.2i"
                 ,nn / 86400L
                 ,tt->tm_hour,tt->tm_min,tt->tm_sec );
        break;

    case 5:
        strftime(TSTR, 31, "%A, ", tt);
        sprintf_ex (&TSTR[strlen(TSTR)], "%2.2i-%s-%2.2i %2.2i:%2.2i:%2.2i "
                 ,tt->tm_mday,Monthnames_short[tt->tm_mon],tt->tm_year % 100
                 ,tt->tm_hour,tt->tm_min,tt->tm_sec );
        strcat_ex (TSTR, "GMT");
        break;

    case 6:     //   6  2000-06-21              yyyy-mm-dd
        sprintf_ex (TSTR, "%4.4i-%2.2i-%2.2i"
                 ,tt->tm_year+1900
                 ,tt->tm_mon+1
                 ,tt->tm_mday
                );
        break;

    case 7:     //   7  06.02.1994 00:00        dd.mm.yy hh:mm
        sprintf_ex (TSTR, "%2.2i.%2.2i.%4.4i %2.2i:%2.2i"
                 ,tt->tm_mday,tt->tm_mon+1,tt->tm_year+1900
                 ,tt->tm_hour,tt->tm_min );
        break;

    case 8:     //   8  Tue, 15 Nov 1994 12:45:26 GMT
        strftime(TSTR, 31, "%a, ", tt);
        sprintf_ex (&TSTR[strlen(TSTR)], "%i %s %i %2.2i:%2.2i:%2.2i "
                 ,tt->tm_mday,Monthnames_short[tt->tm_mon],tt->tm_year + 1900
                 ,tt->tm_hour,tt->tm_min,tt->tm_sec );
        strcat_ex (TSTR, "GMT");
        break;

    case 9:    //   9 06.02.1994      dd.mm.yy
        sprintf_ex (TSTR, "%2.2i.%2.2i.%4.4i"
                 ,tt->tm_mday,tt->tm_mon+1,tt->tm_year+1900);
        break;

    case 10:   //  10  19940206124526000234                yyyymmddhhmmssiiiiii

        sprintf_ex (TSTR, "%4.4i%2.2i%2.2i%2.2i%2.2i%2.2i"
                 ,tt->tm_year+1900
                 ,tt->tm_mon+1
                 ,tt->tm_mday
                 ,tt->tm_hour
                 ,tt->tm_min
                 ,tt->tm_sec
                 );
        break;

    case 11:    //  11 06.02.94      dd.mm.yy
        j = tt->tm_year % 100;
        sprintf_ex (TSTR, "%2.2i.%2.2i.%2.2i", tt->tm_mday,tt->tm_mon+1,j);
        break;
    case 12:    //  12 06.02.94      dd.mm.yy
        j = tt->tm_year % 100;
        sprintf_ex (TSTR, "%2.2i.%2.2i.%2.2i", j, tt->tm_mon+1 ,tt->tm_mday);
        break;

    case 13:     // 13  2004-02-06 00:00:00     yyyy-mm-dd  hh:mm:ss
        sprintf_ex (TSTR, "%4.4i-%2.2i-%2.2i %2.2i:%2.2i:%2.2i"
                 ,tt->tm_year+1900,tt->tm_mon+1,tt->tm_mday
                 ,tt->tm_hour,tt->tm_min,tt->tm_sec );
        break;

    case 14:     //  14  2000_08_08_1600       yyyy_mm_dd_hhmm
        sprintf_ex (TSTR, "%4.4i_%2.2i_%2.2i_%2.2i%2.2i"
                 ,tt->tm_year+1900,tt->tm_mon+1,tt->tm_mday
                 ,tt->tm_hour,tt->tm_min);
        break;
    case 15:     //  4 Digit Year
        sprintf_ex (TSTR, "%4.4i",tt->tm_year+1900);
        break;
    case 16:     //  2 Digit Mounth
        sprintf_ex (TSTR, "%2.2i",tt->tm_mon+1);
        break;
    case 17:     //  2 Digit Day
        sprintf_ex (TSTR, "%2.2i",tt->tm_mday);
        break;
    case 18:     //  2 Digit Hour
        sprintf_ex (TSTR, "%2.2i",tt->tm_hour);
        break;
    case 19:     //  2 Digit Min
        sprintf_ex (TSTR, "%2.2i",tt->tm_min);
        break;
    case 20:     //  20000621              yyyymmdd
        sprintf_ex (TSTR, "%4.4i%2.2i%2.2i"
                 ,tt->tm_year+1900
                 ,tt->tm_mon+1
                 ,tt->tm_mday
                );
        break;
    case 21:
        TSTR [0]=0;
        time_t elapsed = (tt->tm_hour * 60 * 60) + (tt->tm_min * 60) + tt->tm_sec;
        if (elapsed > (60*60) ) sprintf_ex (TSTR+strlen(TSTR) , "%2.2ih:",tt->tm_hour);
        if (elapsed >  60     ) sprintf_ex (TSTR+strlen(TSTR) , "%2.2im:",tt->tm_min);
        sprintf_ex (TSTR+strlen(TSTR), "%2.2is",tt->tm_sec);
        break;

    default:
        sprintf_ex (TSTR, "%2.2i:%2.2i:%2.2i",tt->tm_hour,tt->tm_min,tt->tm_sec );
        break;
    }
    return TSTR;
}

/**
 @brief Genaue Mitternacht feststellen
 @return Mitternacht in Sekunden seit 1970
 @param t Sekunden seit 1970

 return 00:00:00 für das Datum in time_t t

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

time_t Midnight(time_t t)
{
    struct tm *ti;
    struct tm tm;

    ti=localtime(&t);

    tm.tm_sec       = 0;
    tm.tm_min       = 0;
    tm.tm_hour      = 0;
    tm.tm_mday      = ti->tm_mday;
    tm.tm_mon       = ti->tm_mon;
    tm.tm_year      = ti->tm_year;
    tm.tm_wday      = ti->tm_wday;
    tm.tm_yday      = ti->tm_yday;
    tm.tm_isdst     = ti->tm_isdst;

    return (mktime (&tm));
}

static struct TYPE_MONNAMES MONNAMES[]=
{
    {1,"JAN"},
    {2,"FEB"},
    {3,"MAR"},
    {4,"APR"},
    {5,"MAY"},
    {5,"MAI"},
    {6,"JUN"},
    {7,"JUL"},
    {8,"AUG"},
    {9,"SEP"},
    {10,"OCT"},
    {10,"OKT"},
    {11,"NOV"},
    {12,"DEC"},
    {12,"DEZ"},
    {3,"MRZ"},
    {1,"Januar"},
    {2,"Febuar"},
    {2,"Februar"},
    {3,"Maerz"},
    {3,"März"},
    {4,"April"},
    {5,"Mai"},
    {6,"Juni"},
    {6,"Juno"},
    {7,"Juli"},
    {7,"July"},
    {8,"August"},
    {9,"September"},
    {10,"Oktober"},
    {11,"November"},
    {12,"Dezember"},
/*
  spanisch
  englisch
  italienisch
  französisch
  portugiesisch
  niederländisch
  esperanto
  latein
*/
    {1,"enero"},
    {1,"gennaio"},
    {1,"ianuarius"},
    {1,"janeiro"},
    {1,"januari"},
    {1,"januaro"},
    {1,"january"},
    {1,"janvier"},
    {2,"Fevereiro"},
    {2,"febbraio"},
    {2,"febrero"},
    {2,"februari"},
    {2,"februarius"},
    {2,"februaro"},
    {2,"february"},
    {2,"février"},
    {3,"maart"},
    {3,"march"},
    {3,"mars"},
    {3,"martius"},
    {3,"marto"},
    {3,"marzo"},
    {3,"março"},
    {4,"abril"},
    {4,"aprile"},
    {4,"aprilis"},
    {4,"aprilo"},
    {4,"avril"},
    {5,"maggio"},
    {5,"maio"},
    {5,"maius"},
    {5,"majo"},
    {5,"mayo"},
    {5,"mei"},
    {6,"giugno"},
    {6,"iunius"},
    {6,"juin"},
    {6,"june"},
    {6,"junho"},
    {6,"junio"},
    {7,"iulius"},
    {7,"juillet"},
    {7,"julho"},
    {7,"julio"},
    {7,"july"},
    {7,"luglio"},
    {8,"agosto"},
    {8,"août"},
    {8,"augustus"},
    {8,"augusto"},
    {9,"septembre"},
    {9,"septembro"},
    {9,"septiembre"},
    {9,"setembro"},
    {9,"settembre"},
    {10,"october"},
    {10,"octobre"},
    {10,"octubre"},
    {10,"oktobro"},
    {10,"ottobre"},
    {10,"outubro"},
    {11,"novembre"},
    {11,"novembro"},
    {11,"noviembre"},
    {12,"december"},
    {12,"decembro"},
    {12,"dezembro"},
    {12,"dicembre"},
    {12,"diciembre"},
    {12,"décembre"},
    {0,"NEVER REACHED"}
};

///@brief Wird in @ref ParseAnyDate benötigt
struct TYPE_TZADD
{
    char    *my_tzname; ///< Timezone Name
    long    my_to_gmt;  ///< Abweichung zur GMT in Sekunden
};

static struct TYPE_TZADD TZADD[]=
{
    { "GMT"  ,  0 * 3600},
    { "UT"   ,  0 * 3600},
    { "UTC"  ,  0 * 3600},
    { "WET"  ,  0 * 3600},
    { "WEZ"  ,  0 * 3600},
    { "Z"    ,  0 * 3600},

    { "A"    ,  1 * 3600},
    { "WAT"  ,  1 * 3600},

    { "B"    ,  2 * 3600},
    { "AT"   ,  2 * 3600},

    { "C"    ,  3 * 3600},
    { "ADT"  ,  3 * 3600},

    { "D"    ,  4 * 3600},
    { "AST"  ,  4 * 3600},
    { "EDT"  ,  4 * 3600},

    { "E"    ,  5 * 3600},
    { "CDT"  ,  5 * 3600},
    { "EST"  ,  5 * 3600},

    { "IST"  , (5 * 3600) + 1800},

    { "F"    ,  6 * 3600},
    { "MDT"  ,  6 * 3600},
    { "CST"  ,  6 * 3600},

    { "G"    ,  7 * 3600},
    { "MST"  ,  7 * 3600},
    { "PDT"  ,  7 * 3600},

    { "H"    ,  8 * 3600},
    { "PST"  ,  8 * 3600},
    { "YDT"  ,  8 * 3600},

    { "I"    ,  9 * 3600},
    { "HDT"  ,  9 * 3600},
    { "YST"  ,  9 * 3600},

    { "K"    , 10 * 3600},
    { "AHST" , 10 * 3600},
    { "CAT"  , 10 * 3600},
    { "HST"  , 10 * 3600},

    { "L"    , 11 * 3600},
    { "NT"   , 11 * 3600},

    { "M"    , 12 * 3600},
    { "IDLW" , 12 * 3600},

    { "N"    , -1 * 3600},
    { "BST"  , -1 * 3600},
    { "CET"  , -1 * 3600},
    { "FWT"  , -1 * 3600},
    { "MET"  , -1 * 3600},
    { "MEWT" , -1 * 3600},
    { "SWT"  , -1 * 3600},
    { "ZP1"  , -1 * 3600},

    { "O"    , -2 * 3600},
    { "EET"  , -2 * 3600},
    { "FST"  , -2 * 3600},
    { "MEST" , -2 * 3600},
    { "MESZ" , -2 * 3600},
    { "SST"  , -2 * 3600},
    { "ZP2"  , -2 * 3600},

    { "P"    , -3 * 3600},
    { "BT"   , -3 * 3600},
    { "ZP3"  , -3 * 3600},

    { "Q"    , -4 * 3600},
    { "ZP4"  , -4 * 3600},

    { "R"    , -5 * 3600},
    { "ZP5"  , -5 * 3600},

    { "S"    , -6 * 3600},
    { "ZP6"  , -6 * 3600},

    { "T"    , -7 * 3600},
    { "WAST" , -7 * 3600},

    { "U"    , -8 * 3600},
    { "CCT"  , -8 * 3600},
    { "WADT" , -8 * 3600},
    { "ZP7"  , -8 * 3600},

    { "V"    , -9 * 3600},
    { "JST"  , -9 * 3600},
    { "ZP8"  , -9 * 3600},

    { "W"    ,-10 * 3600},
    { "ZP9"  ,-10 * 3600},
    { "EAST" ,-10 * 3600},
    { "GST"  ,-10 * 3600},

    { "X"    ,-11 * 3600},
    { "EADT" ,-11 * 3600},

    { "Y"    ,-12 * 3600},
    { "IDLE" ,-12 * 3600},
    { "NZST" ,-12 * 3600},
    { "NZT"  ,-12 * 3600},

    { "NZDT" ,-13 * 3600},

    { NULL,     0}
};


/**
 @brief Parst ein RFC 822 Datum nach time_t ( localtime )
 @return -1 (PARSEANYDATE_ERROR) im Fehlerfall sonst die localtime vom Datum
 @param ostr Beschreibung der Zeit in einer fast beliebigen Form

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

time_t ParseAnyDate(char *ostr)
{
    struct tm		tm;
    long		    offset;
    long            tzadd;
    long            tzdif;
    unsigned int	c0, c1, c2, c3;


    char    *cpy;
    char    *str;
    char    mstr[STRING_MAX];
    strcpy_ex (mstr, ostr);
    str=mstr;

    tm.tm_hour  = 0;
    tm.tm_isdst = 0;
    tm.tm_mday  = 0;
    tm.tm_min   = 0;
    tm.tm_mon   = 0;
    tm.tm_sec   = 0;
    tm.tm_wday  = 0;
    tm.tm_yday  = 0;
    tm.tm_year  = 0;

    strCL (str);                                                                // Clean up some space
    //lprintf ("STR6:%s",str);
    if (*str < '0')  return PARSEANYDATE_ERROR;                                 // Fetch first arg from datestring
    if (*str > '9')
    {
	    if ((!isupper ((int)str[0]) && !islower ((int)str[0])) ||               // Weekday names must be 3 chars
            (!isupper ((int)str[1]) && !islower ((int)str[1])) ||
            (!isupper ((int)str[2]) && !islower ((int)str[2])))
            return PARSEANYDATE_ERROR;
        str += 3;                                                               // Pointing after digits
        strCL(str);                                                             // Clean up some space
        if (*str == ',')
        {
            str++;
            strCL(str);                                                         // Clean up some space
    	}
	    if (!isdigit((int)str[0])) return PARSEANYDATE_ERROR;                   // now, we must have an digit
    }
    //lprintf ("STR7:%s",str);
    if ( (strlen(str)==10) && (str[2]=='.') && (str[5]=='.'))                   // 10.04.1994
    {
        str[2]=0;
        str[5]=0;
        str[10]=0;
        tm.tm_mday =atoi(str);
        tm.tm_mon  =atoi(&str[3])-1;
        tm.tm_year =atoi(&str[6])-1900;
        str = "00:00";
        goto parsetime;
    }
    if ( (strlen(str)>11) && (str[2]=='.') && (str[5]=='.') && (str[10]==' ') )// 10.04.1994 12:30:12
    {
        str[2]=0;
        str[5]=0;
        str[10]=0;
        tm.tm_mday =atoi(str);
        tm.tm_mon  =atoi(&str[3])-1;
        tm.tm_year =atoi(&str[6])-1900;
        str +=11;
        goto parsetime;
    }

    if ( (strlen(str)==10) && (str[4]=='-') && (str[7]=='-') )                  // 1994-04-10
    {
        str[4]=0;
        str[7]=0;
        tm.tm_sec  =0;
        tm.tm_min  =0;
        tm.tm_hour =0;
        tm.tm_mday =atoi(&str[8]);
        tm.tm_mon  =atoi(&str[5])-1;
        tm.tm_year =atoi(str)-1900;
        return (mktime (&tm));
    }
    //0123456789012345678
    //2003-04-01 00:00:00
    if ( (strlen(str)==19) && (str[4]=='-') && (str[7]=='-') && (str[10]==' ') && (str[13]==':') && (str[16]==':') )
    {
        str[4]=0;
        str[7]=0;
        str[10]=0;
        str[13]=0;
        str[16]=0;
        tm.tm_sec  =atoi(&str[17]);
        tm.tm_min  =atoi(&str[14]);
        tm.tm_hour =atoi(&str[11]);
        tm.tm_mday =atoi(&str[8]);
        tm.tm_mon  =atoi(&str[5])-1;
        tm.tm_year =atoi(str)-1900;
        return (mktime (&tm));
    }
    //0123456789012345
    //2003-04-01 00:00
    if ( (strlen(str)==16) && (str[4]=='-') && (str[7]=='-') && (str[10]==' ') && (str[13]==':'))
    {
        str[4]=0;
        str[7]=0;
        str[10]=0;
        str[13]=0;
        tm.tm_sec  =0;
        tm.tm_min  =atoi(&str[14]);
        tm.tm_hour =atoi(&str[11]);
        tm.tm_mday =atoi(&str[8]);
        tm.tm_mon  =atoi(&str[5])-1;
        tm.tm_year =atoi(str)-1900;
        return (mktime (&tm));
    }

    //  012345678901234567890
    //  10/Apr/2003:07:33:12 +0200
    if( (strlen(str)>20)   &&
        (str[ 2]=='/')      &&
        (str[ 6]=='/')      &&
        (str[11]==':')      &&
        (str[14]==':')      &&
        (str[17]==':')      &&
        (str[20]==' '))
    {
        str[2]=0;
        str[6]=0;
        str[11]=0;
        str[14]=0;
        str[17]=0;
        str[20]=0;

        tm.tm_sec  =atoi(&str[18]);
        tm.tm_min  =atoi(&str[15]);
        tm.tm_hour =atoi(&str[12]);
        tm.tm_mday =atoi(str);
        tm.tm_year =atoi(&str[7])-1900;

        c0 = toupper(str[3]); if (c0==0) return PARSEANYDATE_ERROR;                 // Name des Monats
        c1 = tolower(str[4]); if (c1==0) return PARSEANYDATE_ERROR;                 // in LowerCase
        c2 = tolower(str[5]); if (c2==0) return PARSEANYDATE_ERROR;

        //lprintf ("STR2:%s",str);
        for (c3=0;;c3++)                                                            // must be fit into the MON_NAME table
        {
            if (c3>=12) return PARSEANYDATE_ERROR;
            if (c0 != (unsigned int)Monthnames_short[c3][0]) continue;
            if (c1 != (unsigned int)Monthnames_short[c3][1]) continue;
            if (c2 != (unsigned int)Monthnames_short[c3][2]) continue;
            tm.tm_mon = c3;
            break;
        }
        return (mktime (&tm));
    }

    //lprintf ("STR4:%s",str);
    tm.tm_mday = *str-'0';                                                          // Holde den Tag von ASC 2 int
    for (str++;;str++)
    {
        if (!isdigit((int)str[0])) break;
	    tm.tm_mday =tm.tm_mday * 10;
        tm.tm_mday =tm.tm_mday + (*str - '0');
    }

    strCL(str);
    if (str[0]=='.')
    {
        str++;
    }
    strCL(str);
    // Maerz 2018

    for (cpy = str;;str++)
    {
        if (str[0]==0) return PARSEANYDATE_ERROR;
        if (str[0]==' ')
        {
            str[0]=0;
            str++;
            break;
        }
    }
    // cpy = 'Maerz'
    // str = '2018'   -> '2018 15:33:24'
    for (c3=0;;c3++)                                                            // must be fit into the
    {
        if (MONNAMES[c3].mon==0) return PARSEANYDATE_ERROR;
        if (!strcasecmp(cpy, MONNAMES[c3].name))
        {
            tm.tm_mon = MONNAMES[c3].mon-1;
            break;
        }
    }

    strCL (str);                                                                // Clean up some space
    //lprintf ("STR8:%s",str);

    c0 = str[0] - '0';                                                          // two digits of year
    c1 = str[1] - '0';
    if ((c0 > 9) || (c1 > 9)) return PARSEANYDATE_ERROR;

    c2 = str[2] - '0';

    if (c2 > 9)                                                                 // two digit year
    {
	    tm.tm_year = (10 * c0) + c1;
    	str += 2;
    }else{                                                                      // four digit year
    	c3 = str[3] - '0';
    	if (c3 > 9) return PARSEANYDATE_ERROR;
	    tm.tm_year = (((1000 * c0) + (100 * c1) + (10 * c2)) + c3) - 1900;
    	str += 4;
    }

parsetime:
    strCL (str);                                                                // Clean up some space
//    tm.tm_isdst=0;
//    tm.tm_wday=0;
    //lprintf ("STR9:%s",str);
    if (*str==0)
    {
//        tm.tm_hour= 0;
//        tm.tm_min = 0;
//        tm.tm_sec = 0;
        return mktime(&tm);
    }

    c0 = str[0] - '0';                                                          // two digits of hour
    c1 = str[1] - '0';
    c2 = str[2];
    if ((c0 > 9) || (c1 > 9) ||	(c2 != ':')) return PARSEANYDATE_ERROR;

    tm.tm_hour = 10 * c0 + c1;
    str += 3;

    c0 = str[0] - '0';                                                          // two digits of min
    c1 = str[1] - '0';
    c2 = str[2];
    if ((c0 > 9) || (c1 > 9))	return PARSEANYDATE_ERROR;

    tm.tm_min = 10 * c0 + c1;
    tm.tm_sec = 0;
    if (c2 == ':')
    {
        str +=3;
        c0 = str[0] - '0';                                                      // two digits of secs
        c1 = str[1] - '0';
        if ((c0 > 9) || (c1 > 9))	return PARSEANYDATE_ERROR;
        tm.tm_sec = 10 * c0 + c1;
    }
    str +=2;

    strCL(str);

    switch (*str)
    {
    case 0:   return mktime(&tm);
              //offset =0;
              //break;

    case '-':
    case '+':
              c0 = str[1] - '0';
              c1 = str[2] - '0';
              c2 = str[3] - '0';
              c3 = str[4] - '0';
              if ((c0 > 9) || (c1 > 9)|| (c2 > 9)|| (c3 > 9)) return PARSEANYDATE_ERROR;
              offset = (3600 * ((10 * c0) + c1)) + (60 * c2) + c3;
              if (*str=='+') offset=-offset;
              break;
    default:
              offset = 0;
              for (c2=0;;c2++)
              {
                  if ( (str[c2]==0) ||
                       (str[c2]=='+') ||
                       (str[c2]=='-')
                     ) break;
              }

              for (c0=0;;c0++)
              {
                  if (TZADD[c0].my_tzname==NULL) break;
                  c1 = strlen(TZADD[c0].my_tzname);
                  if (c1!=c2) continue;
                  if (strncasecmp(TZADD[c0].my_tzname, str, c1)) continue;

                  offset = TZADD[c0].my_to_gmt;
                  str += c1;
                  if ( (*str=='+') || (*str=='-') )
                  {
                        tzdif = atoi(str);
                        tzadd = 3600 * tzdif;
                        offset = offset + tzadd;
                  }
                  break;
              }
              break;
    }

// 29.08.23 HS timezone steht mit UART nicht zur Verfügung


    long TZone = 0;
#ifdef _UCRT
    _get_timezone (&TZone);
#else
#ifdef _MSC_VER
    TZone = _timezone;
#else
    TZone = timezone;
#endif
#endif
    offset = offset - TZone;
    offset = offset + mktime(&tm);
    return offset; //mktime(&tm) + offset - timezone;

#ifdef OLD_STUFF
// timezone is depricated
#ifdef _MSC_VER
    offset = offset - _timezone;
#else
    offset = offset - timezone;
#endif
    offset = offset + mktime(&tm);
    //if (tm.tm_isdst) offset = offset + 3600;;
    return offset; //mktime(&tm) + offset - timezone;
#endif
}

/**
 @brief Zeit von einem String parsen
 @return time_t von str nachdem was in fmt beschrieben ist
 @param fmt beschreibung
 @param str Parameter
 @param len Parameter

 fmt wird geparst und argumente sollten mit leerzeichen bzw. doppelpunkt
 getrennt werden.

 @code
 Beispiel:          012345678901
  t = ParseFmtTime("Mon Day yyyy","Apr 8 1999 Log Done", &date_len );
 @endcode
 t wird mit timt_t aus ParseFmtTime gefüllt außerdem wird date_len
 zurückgegeben und enthält die verarbeiteten Zeichen aus str. In diesem
 wären das 11 ( mit 0 wird begonnen). dh 12 Zeichen insgesamt

 fmt kann folgende Zeichen enthalten:

 Desc | Beschreibung
 -----|---
 hh   |      Stunden seit Mitternacht (0, 23)
 mm   |      Minuten nach der vollen Stunde (0, 59)
 ss   |      Sekunden nach der vollen Minute (0, 59)
 pm   |      kann am oder pm sein die stunde wird ggf. angepasst
   <b> </b>|<b> </b>
 Day oder dd | Tage im Monat (1, 31)
 mo   |     Monate seit Januar (1, 12)
 mon  |     Asc schreibweise des Monats. z.B. Apr kann auch december o.ä. sein
 yy   |     Jahr 2 stelleig seit 2000
 yyyy |    Jahr, wobei erst seit 1970 was sinnvolles rauskommt
 no   |    Eintrag ignorieren

___[ Revision ]______________________________________________________________

 ** 08.04.18 HS Create
___________________________________________________________________________*/


time_t ParseFmtTime(const char *fmt,const char *str, int *len)
{
    struct tm		tm;                                         // zu füllender Zeitstruct
    struct tm		*tm_now;                                    // für die aktuelle Zeit/Datum

    char dup[128];                                              // fmt kann maximal 128 Zeichen umfassen

    char *chk;                                                  // Zeiger auf den aktuellen fmt-parameter
    char *nxt;                                                  // Zeiger auf den nächsten fmt-parameter
    int data;                                                   // zeiger im str
    int mode;                                                   // Zähler

    time_t now;                                                 // aktuelle Zeit

    now = unixtime();                                           // aktuelle Zeit setzen
    tm_now = localtime(&now);                                   // und umwandeln

    tm.tm_hour  = 0;                                            // Feld füllen
    tm.tm_isdst = -1;                                           // dflt, damit keine Sommerzeit berechnet wird
    tm.tm_mday  = 0;
    tm.tm_min   = 0;
    tm.tm_mon   = 0;
    tm.tm_sec   = 0;
    tm.tm_wday  = 0;
    tm.tm_yday  = 0;
    tm.tm_year  = tm_now->tm_year;                              // Jahr ist default


    strncpy_ex (dup,fmt, sizeof(dup)-1);                           // Kopie erstellen , da immer wieder was dadrin geändert wird
    dup[sizeof(dup)-1]=0;                                       // null setzen
    strlwr(dup);                                                // nur kleine Zeichen

    nxt = dup;                                                  // nxt auf den Anfang setzen
    for (data=0;;)
    {
        chk=nxt;                                                // auf den nächsten Eintrag setzen
        if (*chk==0) break;                                     // wenn ende, dann ende
        for (;;nxt++)                                           // nxt setzen
        {
            if (*nxt==0) break;
            if ((*nxt==' ') ||
                (*nxt==':')
               )
            {
                *nxt=0;
                nxt++;
                break;
            }
        }
        if (str[data]==0) break;

        if (!strcmp(chk,"hh"))                                  // Stunden
        {
            tm.tm_hour = atoi(&str[data]);
        }else if (!strcmp(chk,"mm")){                           // Minuten
            tm.tm_min = atoi(&str[data]);
        }else if (!strcmp(chk,"ss")){                           // Sekunden
            tm.tm_sec = atoi(&str[data]);
        }else if (!strcmp(chk,"pm")){                           // am/pm
            if (!strncasecmp(&str[data],"pm",2))
            {
                if (tm.tm_hour<12) tm.tm_hour = tm.tm_hour +12;
            }else if (!strncasecmp(&str[data],"am",2))
            {
                if (tm.tm_hour>12) tm.tm_hour = tm.tm_hour -12;
            }else{
                lprintf ("pm/am need, but found ParseFmtTime(...) \"%s\" not found for \"%s\"",chk,&str[data]);
            }
        }else if ( (!strcmp(chk,"dd")) || (!strcmp(chk,"day"))){// tag
            tm.tm_mday = atoi(&str[data]);
        }else if (!strcmp(chk,"mo")){                           // Monat numerisch
            tm.tm_mon = atoi(&str[data])-1;
        }else if (!strcmp(chk,"mon")){                          // Monat Alphanumerisch
            // special tm.tm_mon = atoi(&str[data]);
            //tm.tm_mon = 3;

            for (mode=0;;mode++)                                // Hilfszähler
            {
                if (MONNAMES[mode].mon==0)
                {
                    lprintf ("Error parsing MON at %s",&str[data]);
                    break;
                }
                if (!strncasecmp(&str[data], MONNAMES[mode].name, strlen(MONNAMES[mode].name)))
                {
                    tm.tm_mon = MONNAMES[mode].mon-1;
                    break;
                }
            }
        }else if (!strcmp(chk,"yy")){                           // Jahr 2 stellig
            tm.tm_year = atoi(&str[data]) + 100;
        }else if (!strcmp(chk,"yyyy")){                         // Jahr 4 stellig
            tm.tm_year = atoi(&str[data]) - 1900;
        }else if (!strcmp(chk,"no")){                           // Ignorieren
            // only if ignored data in time
        }else{
            lprintf ("Wrong format in ParseFmtTime(...) \"%s\" not found for \"%s\"",chk,&str[data]);
            // return 0;
        }

        for ( mode=0;;data++)                                   // Zeiger im str korrigieren
        {
            //printf ("i am here = %s\n", &str[data]);
            if (str[data]==0)
            {
                if (*nxt==0) goto Quit_ParseFmtTime;
                *len=data;
                return 0;
            }
            if ((str[data]==' ')||
                (str[data]==':'))
            {
                if (mode==0) mode=1;
                continue;
            }
            if (mode==1) break;
        }
    }

Quit_ParseFmtTime:
    *len=data;
    return mktime(&tm);
}

/**
 @brief Parse ein Datum von Military in eine Lesbare Form yyyy-mm-dd -> dd.mm.yyyy
 @return String mit den Notation dd.mm.yyyy
 @param String Military Notation des Datums üblich ist yyyy-mm-dd

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *miltaryToHumanDate(char *String)
{                                // 0123456789
                                 // 2001-09-17
    char r[16];
    if (strlen(String)!=10) return "01.01.2000";
    r[0]=String[8];
    r[1]=String[9];
    r[2]='.';
    r[3]=String[5];
    r[4]=String[6];
    r[5]='.';
    r[6]=String[0];
    r[7]=String[1];
    r[8]=String[2];
    r[9]=String[3];
    r[10]=0;
    return malloc_temp_strcpy(r);
}

#ifdef OS_WINDOWS
/**
 @brief time_Info timezone_Info mit aktuellen TICS
 @return immer 0
 @param time_Info wenn nicht NULL, dann wird der struct timeval gefüllt
 @param timezone_Info wenn nicht NULL, dann wird der struct timezone gefüllt

___[ Revision ]______________________________________________________________

 ** 01.01.09
___________________________________________________________________________*/

int gettimeofday(struct timeval *time_Info, struct timezone *timezone_Info)
{
    __uint64 mstimer, freq;
    // Get the time, if they want it
    if (time_Info != NULL)
    {
        time_Info->tv_sec = time(NULL);
                // get ticks-per-second of the performance counter
                // Note the necessary typecast to a LARGE_INTEGER structure

        if (!QueryPerformanceFrequency((LARGE_INTEGER *) & freq))
        {
            time_Info->tv_usec = 0;
        }else{
            QueryPerformanceCounter((LARGE_INTEGER *) & mstimer);
            mstimer = (__uint64) (mstimer * .8);
            time_Info->tv_usec = (long) (mstimer % 0x0FFFFFFF);
        }
    }
    // Get the timezone, if they want it
    if (timezone_Info != NULL)
    {
        _tzset();
        timezone_Info->tz_minuteswest = _timezone;
        timezone_Info->tz_dsttime = _daylight;
    }
    // And return
    return 0;
}
#endif
///@}

/**
 @addtogroup c_dumpfunc
 @{
 @brief Dumps aus allem möglichen erstellen

*/ /**
 @brief Alles auf NULL setzen
 @param DUMPMODE mode
 @anchor DUMPMODES

 Im Header ist folgendes definiert

 @code
#define DUMP_STDOUT  1          // stdout Bildschirm
#define DUMP_STDERR  2          // etderr Bildschirm
#define DUMP_LOGFILE 4          // via lprintf LofFile LOG_LOGFILE
#define DUMP_SYSLLOG 8          // via lprintf LofFile LOG_SYSLLOG
#define DUMP_STRING  16         // wird in eine Verkette Liste ab NODE_HEAD geschrieben
 @endcode

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 16.11.16 HS Neue Listeverwaltung
___________________________________________________________________________*/

void DumpInit( int DUMPMODE )
{
    dumpbyte =0;
    dumpcount=0;
    dumpmode = DUMPMODE;
    //LIST_Clear(&LST_HEAD);
    Node_DelAll(NODE_HEAD);
    NODE_HEAD = NULL;
}

/**
 @brief Ein Byte zum Buffer
 @param byte was soll dazu kommen

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void DumpAddByte ( int byte )
{
    dumpstring[dumpbyte]=byte;
    dumpbyte++;

    if (dumpbyte >= (MAXDUMP))
    {
        DumpPrint();
    }
}

/**
 @brief Einen nullbyte terminierten Stringg zum Buffer
 @param String String der dazu kommt

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void DumpAddString ( char *String )
{
    if (String) DumpAddBuffer(String, strlen(String));
}

/**
 @brief Einen ganzen Buffer zum Buffer
 @param String Buffer dazu kommt
 @param Len mit dieser Länge

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void DumpAddBuffer ( char *String, int Len )
{
    register int i;
    for (i=0;i<Len;i++)
    {
        DumpAddByte ( String[i] );
    }
}

/**
 @brief Gesammelten Buffer ausgeben

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 16.11.16 HS Neue Listeverwaltung
___________________________________________________________________________*/

void DumpPrint(void)
{
    int i;
    int ch;
    char xch[4];

    char ascstring[MAXDUMP + ( MAXDUMP / 8 ) + 2 ];
    //
    // MAXDUMP                  are asc chars
    // MAXDUMP / 8              '-' every 8 chars
    // +2                       zeroybyte

    char outstring[ ( MAXDUMP * 3) + (( MAXDUMP / 8 ) * 2 ) + 8 + sizeof(ascstring)];

    //
    // ( MAXDUMP * 3)           every byte in hex include followd space
    // ( MAXDUMP / 8 ) * 2 )    every 8 hex are follow an '- '
    // 8                        4 digits for count followed by : and after the hexes ' : '
    // sizeof(ascstring)        size from asc chart

    if (dumpbyte==0) return;                                                    // there is nothing to do

    sprintf_ex (outstring, "%4.4x:", dumpcount);
    ascstring[0]=0;                                                             // clean this string

    for (i=0;i<MAXDUMP;i++)
    {
        if (i>=dumpbyte)                                                        // dumpbyte is ranged from 1 to 16
        {
            strcpy_ex (xch,"   ");                                              // build a clean if we are out of range
            ch = 32;
        }else{
            ch = (unsigned char) dumpstring[i];                                 // get the byte from stored info
            sprintf_ex (xch, "%2.2x ", ch);                                     // make it viewable as hex
            if (!isprint(ch)) ch='.';                                           // if is not visable make it as dot
            if (ch == '\t')   ch='.';                                           // dont show tab
        }
        if (i>0)                                                                // not add delimiter if first byte
        {
            if ((i % 8) == 0)                                                   // but every 8 bytes adding the delimiter
            {
                strcat_ex (outstring, "- ");                                       // make it nicer to view
                strcat_ex (ascstring, " ");
            }
        }
        strcat_ex (outstring, xch);                                                // adding the hexvalue
        xch[0]=ch;                                                              // now use xch for the strcat
        xch[1]=0;                                                               // from ch
        strcat_ex (ascstring, xch);                                             // and add this well
    }
    strcat_ex (outstring, ":");                                                 // add to view the asc
    strcat_ex (outstring, ascstring);                                           // add the asc itself
    dumpcount = dumpcount + dumpbyte;                                           // adding bytes to the counter
    dumpbyte = 0;                                                               // reset the counter

    if (dumpmode & DUMP_STDOUT)  printf  ("%s\n", outstring);                   // view it to stdout
    if (dumpmode & DUMP_STDERR)  fprintf (stderr, "%s\n", outstring);           // view it to stderr
    if (dumpmode & DUMP_STRING)
    {
        char *myS;
        myS = malloc0(strlen(outstring)+16);
        NODE_HEAD = Node_Add(NODE_HEAD,myS,true);                               // write to String
        //LIST_Add(&LST_HEAD,outstring);
    }
    if ((dumpmode & DUMP_LOGFILE) || (dumpmode & DUMP_SYSLLOG))
    {
        int tmp;
        tmp = LogType;
        LogType = 0;
        if (dumpmode & DUMP_LOGFILE) if (tmp & LOG_LOGFILE) LogType |= LOG_LOGFILE;
        if (dumpmode & DUMP_SYSLLOG) if (tmp & LOG_SYSLLOG) LogType |= LOG_SYSLLOG;
        if (LogType) lprintf ("%s", outstring);                                 // write to Logfile / Syslog
        LogType = tmp;
    }
}

/**
 @brief Ausgabe eines einzelnen Buffers
 @param DUMPMODE    mode siehe @ref DUMPMODES
 @param String      Eigentlich ein Pointer
 @param Len         Größe des Buffers

 @note Schnelle Lösung. Der Buffer wird überschrieben

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

void DumpSingleBuffer(int DUMPMODE, char *String, int Len )
{
    DumpInit(DUMPMODE);
    DumpAddBuffer ( String, Len );
    DumpPrint();
}

/**
 @brief Holt eine Zeile aus dem Stringbuffer
 @return String; wenn nichs mehr da ist NULL

 Der nächste String wird aus dem Buffer geholt
 Der String wird intern freigegeben; dh. kann nicht nochmal geholt werden.

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 16.11.16 HS Neue Listeverwaltung
___________________________________________________________________________*/

char *DumpString (void)
{
    void *d;
    char *s;
//    char rslt[( MAXDUMP * 3) + (( MAXDUMP / 8 ) * 2 ) + 8 + (MAXDUMP + ( MAXDUMP / 8 ) + 2 ) + 1];
    if ((dumpmode & DUMP_STRING)==0) return NULL;
    DumpPrint();
    // s = Node_GetFirst(NODE_HEAD);
    if (NODE_HEAD==NULL) return NULL;
    d = NODE_HEAD;
    s = Node_GetData(NODE_HEAD);
    NODE_HEAD = Node_GetNext(NODE_HEAD);
    free (d);
    if (!s) return NULL;
    return malloc_temp_string(s);
}

/**
 @brief String aus allen Zeilen erstellen
 @return NULL oder mit free freizugebender Speicher

 Alle Zeilen aus dem Stringbuffer holen.
 Jede Zeile wird mit einem LF aubgeschlossen.

___[ Revision ]______________________________________________________________

 ** 19.07.16 HS Create
___________________________________________________________________________*/

char *DumpFullString(void)
{
    char *s;
    char *e;

    e = NULL;
    while (1)
    {
        s = DumpString();
        if (!s) break;
        stradd(e,s);
        stradd(e,"\n");
    }
    return e;
}
///@}

/**
 @addtogroup c_iofunc
 @{
 @brief Diese Funktionen sind oftmals je nach Betriebssystemen völlig unterschiedlich. Das Ergebnis sollte jedoch identisch sein.

 /////////////////////////////// I/O -Functions ///////////////////////////////

*/ /**
 @brief Ein Zeichen von stdin (normal Tastatur) holen
 @return int bei 0x100 war kein Zeichen vorhanden. Ansonsten ein Zeichen

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

int getach(void)
{
#ifdef OS_LINUX
    fd_set      rfds;
    int         fd;
    int         n;
    struct      timeval tv;
    int         retval;
    char        c[2];

    /* Watch stdin (fd 0) to see when it has input. */

    fd = fileno(stdin);
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    /* Wait up to x seconds. */
    tv.tv_sec  = 0;
    tv.tv_usec = 5; // Slice

    retval = select(1, &rfds, NULL, NULL, &tv); // Don't realy on the value of tv now!

    if (retval==-1) return 0x100;
    if (retval==0) return 0;
    n=read(fd,&c,1);
    if (n<=0) return 0x100;
    if (n==0) return 0;
    // c[0]=getc (stdin);
    return c[0];
#endif

#ifdef OS_WINDOWS
    if (_kbhit()==0) return 0x100;
    return (_getch());
#endif
	return 0;
}

/**
 @brief Eine Zeile aus einer Datei lesen
 @return 0 OK -1 bei Fehlern
 @param Stream      Filestream
 @param Dest        Buffer wohin geshrieben werden soll
 @param MaxLen      maximale Länge

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 05.01.18 HS Remove CR from String
             NEW: Windows-Files im Binary-Mode wenn Sie als Text gelesen
                  werden werden CR/LF im TextMode LF/LF returnen
___________________________________________________________________________*/

int mgetline ( FILE *Stream, char *Dest, int MaxLen )
{
    int i,j;
    Dest[0]=0;

    if (fgets( Dest, MaxLen-1, Stream )==NULL) return(-1);
    for (i=0;i<MaxLen;i++)                                                      // Check the received Chars
    {
		switch ( Dest[i])
        {
          case 13: for (j=i;;j++)                                               // Remove CR from String
                   {                                                            // *NEW Code since 05.01.18
                       Dest[j]=Dest[j+1];
                       if (Dest[j]==0) break;
                   }
                   i--;
                   break;                                                       // Ignore Windows CR
          case 10: Dest[i]=0;                                                   // if Terminatet with LF
                   i=MaxLen;                                                    // Break for all
                   break;
          case 0:  i=MaxLen;                                                    // if zero then also terminate the loop
                   break;
        }
    }
	return (0);
}

// Alte Version
#if 0 == 1
int mgetline ( FILE *Stream, char *Dest, int MaxLen )
{
    int i,j;
    char c;
    Dest[0]=0;
    for (i=0;;)
    {
        if (i>=(MaxLen-2))              // maximum Size
        {
            Dest[i]=0;
            return (0);
        }
        if (feof ( Stream ))            // Fileende
        {
            Dest[i]=0;
            return (0);
        }
        c = fgetc(Stream);              // EIN Zeichen lesen
        if ( (c==0) || (c==10) )        // null oder LF sind das Zeilenende
        {
            Dest[i]=0;
            return (0);
        }
        if (Dest[i]==13) continue;      // Special für Window CR/LF
        Dest[i]=c;
        i++;
    }
    return 0;
}
#endif // 0

/**
 @brief Prüfe, ob eine Datei exestiert
 @return TRUE/FALSE (False kann auch kommen, wenn keine Zugriffberechtigung herrscht)
 @param name Filename der geprüft werden soll

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 17.01.17 HS FileOK ohne aka's
___________________________________________________________________________*/

int FileOK (char *name)
{
    struct stat buf;

    if (stat (name ,&buf )==-1) return (FALSE);
    if (!S_ISREG( buf.st_mode )) return (FALSE);
    return (TRUE);
}

/**
 @brief Prüfe, ob ein Verzeichnis exestiert
 @return TRUE/FALSE (False kann auch kommen, wenn keine Zugriffberechtigung herrscht)
 @param name Dirname der geprüft werden soll

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 17.01.17 HS DirOK ohne aka's
___________________________________________________________________________*/

int DirOK(char *name)
{
    struct stat buf;
    if (stat (name ,&buf )==-1)  return (FALSE);
    if (!S_ISDIR( buf.st_mode )) return (FALSE);
    return (TRUE);
}

/**
 @addtogroup c_links
 @{
 @brief Diese Funktionen sind sehr Betriebssystemabhängig

 Prüfe, ob eine Datei ein Link ist. Dabei werden aus unabhängiger Sicht
 nicht klar ob Soft- oder Hardlink. Auf Datei- und Filesystemschicht ist
 eine klare Trennung vorhanden.

 Hardlinks sind unter Windows, wie unter Linux, nicht vorhanden.
 Unter Linux werden die Nodes gezählt. Und eine zu löschende
 Datei wird bei 0 auch die anhängenden Daten löschen.
 Bei Windows gibt es immer die Orginaldaten auf die verwiesen wird.
 Es wird auch nur dort ein Flag gesetzt, das die Datei als Link ausweist.

 @anchor FILE_ATTRIBUTES

 Windows GetFileAttributes von MSN Description

 const   | const      | define                                | Description
 -------:|-----------:|---------------------------------------|----------------
       1 |      (0x1) | FILE_ATTRIBUTE_READONLY               | A file that is read-only. Applications can read the file, but cannot write to it or delete it. This attribute is not honored on directories. For more information, see You cannot view or change the Read-only or the System attributes of folders in Windows Server 2003, in Windows XP, in Windows Vista or in Windows 7.
       2 |      (0x2) | FILE_ATTRIBUTE_HIDDEN                 | The file or directory is hidden. It is not included in an ordinary directory listing.
       4 |      (0x4) | FILE_ATTRIBUTE_SYSTEM                 | A file or directory that the operating system uses a part of, or uses exclusively.
      16 |     (0x10) | FILE_ATTRIBUTE_DIRECTORY              | The handle that identifies a directory.
      32 |     (0x20) | FILE_ATTRIBUTE_ARCHIVE                | A file or directory that is an archive file or directory. Applications typically use this attribute to mark files for backup or removal.
      64 |     (0x40) | FILE_ATTRIBUTE_DEVICE                 | This value is reserved for system use.
     128 |     (0x80) | FILE_ATTRIBUTE_NORMAL                 | A file that does not have other attributes set. This attribute is valid only when used alone.
     256 |    (0x100) | FILE_ATTRIBUTE_TEMPORARY              | A file that is being used for temporary storage. File systems avoid writing data back to mass storage if sufficient cache memory is available, because typically, an application deletes a temporary file after the handle is closed. In that scenario, the system can entirely avoid writing the data. Otherwise, the data is written after the handle is closed.
     512 |    (0x200) | FILE_ATTRIBUTE_SPARSE_FILE            | A file that is a sparse file.
    1024 |    (0x400) | FILE_ATTRIBUTE_REPARSE_POINT          | A file or directory that has an associated reparse point, or a file that is a symbolic link.
    2048 |   ( 0x800) | FILE_ATTRIBUTE_COMPRESSED             | A file or directory that is compressed. For a file, all of the data in the file is compressed. For a directory, compression is the default for newly created files and subdirectories.
    4096 |   (0x1000) | FILE_ATTRIBUTE_OFFLINE                | The data of a file is not available immediately. This attribute indicates that the file data
    8192 |   (0x2000) | FILE_ATTRIBUTE_NOT_CONTENT_INDEXED    | The file or directory is not to be indexed by the content indexing service.
   16384 |   (0x4000) | FILE_ATTRIBUTE_ENCRYPTED              | A file or directory that is encrypted. For a file, all data streams in the file are encrypted. For a directory, encryption is the default for newly created files and subdirectories.
   32768 |   (0x8000) | FILE_ATTRIBUTE_INTEGRITY_STREAM       | The directory or user data stream is configured with integrity (only supported on ReFS volumes). It is not included in an ordinary directory listing. The integrity setting persists with the file if it's renamed. If a file is copied the destination file will have integrity set if either the source file or destination directory have integrity set.Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:  This flag is not supported until Windows Server 2012.
   65536 |  (0x10000) | FILE_ATTRIBUTE_VIRTUAL                | This value is reserved for system
  131072 |  (0x20000) | FILE_ATTRIBUTE_NO_SCRUB_DATA          | The user data stream not to be read by the background data integrity scanner (AKA scrubber). When set on a directory it only provides inheritance. This flag is only supported on Storage Spaces and ReFS volumes. It is not included in an ordinary directory listing. Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:  This flag is not supported until Windows 8 and Windows Server 2012.
  262144 |  (0x40000) | FILE_ATTRIBUTE_RECALL_ON_OPEN         | This attribute only appears in directory enumeration classes (FILE_DIRECTORY_INFORMATION, FILE_BOTH_DIR_INFORMATION, etc.). When this attribute is set, it means that the file or directory has no physical representation on the local system; the item is virtual. Opening the item will be more expensive than normal, e.g. it will cause at least some of it to be fetched from a remote store.
 4194304 | (0x400000) | FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS  | When this attribute is set, it means that the file or directory is not fully present locally. For a file that means that not all of its data is on local storage (e.g. it may be sparse with some data still in remote storage). For a directory it means that some of the directory contents are being virtualized from another location. Reading the file / enumerating the directory will be more expensive than normal, e.g. it will cause at least some of the file/directory content to be fetched from a remote store. Only kernel-mode callers can set this bit.

___[ Revision ]______________________________________________________________

 ** 02.06.18 HS Create ( Basis war SysDir aus HSsync )
 ** 04.06.18 HS Add IsRoot
___________________________________________________________________________*/


/**
 @brief Prüfe ob es ein Link ist
 @return -1 if Error 0 normal 1 IsLinkFlag
 @param name Filename oder Verzechnisname

___________________________________________________________________________*/

#ifdef OS_WINDOWS
int IsLink(char *name)
{
    //if (IsSymbolicLink(name)) return 1;
    //if (IsSoftLink(name)) return 1;
    return IsHardLink(name);
}
#endif
#ifdef OS_LINUX
int IsLink(char *name)
{
    //if (IsSymbolicLink(name)) return 1;
    return
       ( IsSoftLink(name) ||
         IsHardLink(name)
       );
}
#endif

/**
 @brief Check System Flag
 @return -1 if Error 0 normal 1 IsSystemFlag
 @param name Filename oder Verzechnisname

 Check System Flag; Dabei wird NUR das Systemflag augeklammert
 Linux kennt keine Systemfiles .... dh. ist von mir das Rootverzeichnis
 als System deklariert worden.

___________________________________________________________________________*/

int IsSystem (char *name)
{
#ifdef OS_LINUX
    if (IsRoot(name)==1)
    {
        if (!strcmp(name,"/")) return 1;
    }
    return 0;
#endif // OS_LINUX
#ifdef OS_WINDOWS
    unsigned long fatt;
    fatt = GetFileAttributesA(name);
    if (fatt==INVALID_FILE_ATTRIBUTES) return -1;
    if (fatt & FILE_ATTRIBUTE_SYSTEM) return 1;
    return 0;
#endif // OS_WINDOWS
}

/**
 @brief Ob es das Hauptverzeichnos ist
 @return 1 wenn wahr 0 wenn falsch
 @param name Zu prüfendes Verzeichnis / File

___________________________________________________________________________*/

#ifdef OS_FSYS_DRIVE
int IsRoot (char *name)
{
    if (name[0]=='\\')
    {
        if (name[1]==0) return 1;
        return 0;
    }
    if (strlen(name)<3) return 0;
    if (name[1]!=':')   return 0;
    if (!isalpha(name[0])) return 0;
    if (name[2]!='\\') return 0;
    if (name[3]==0) return 1;
    return 0;
}
#endif
#ifdef OS_FSYS_PATH
int IsRoot (char *name)
{
    if (name[0]!='/')      return 0;
    if (strcmp(name,"/"))  return 0;
    return 1;
}
#endif

/**
 @brief Ob es ein Softlink ist
 @return 1 wenn wahr 0 wenn falsch -1 wenn Fehler
 @details name Ein zu pruefendes Verzeichnis / File

___________________________________________________________________________*/

#ifdef OS_WINDOWS
int IsSoftLink(char *name)
{
    if (name) return 0;
    return 0;
}
#endif

#ifdef OS_LINUX
int IsSoftLink(char *name)
{
    struct stat buf;

    if (lstat(name,&buf)==-1) return -1;
    //lprintf ("S:name=%s  buf.st_mode=%i", name, buf.st_mode);
    if (S_ISLNK( buf.st_mode )) return 1;
    return 0;
}
#endif

/**
 @brief Ob es ein Hardlink ist
 @return 1 wenn wahr 0 wenn falsch -1 wenn Fehler
 @param name Zu prüfendes Verzeichnis / File

___________________________________________________________________________*/
#ifdef OS_WINDOWS
int IsHardLink(char *name)
{
    unsigned long fatt;
    fatt = GetFileAttributesA(name);
    //printf (">%s 0x%08x %s\n",binstr(fatt),(int)fatt,name);
    if (fatt == INVALID_FILE_ATTRIBUTES) return -1;
    if (fatt & FILE_ATTRIBUTE_REPARSE_POINT) return 1;
    return 0;
}

/*
int IsSymbolicLink(char*name)
{
    unsigned long fatt;
    fatt = GetFileAttributes(name);
    printf (">%s 0x%08x %s\n",binstr(fatt),(int)fatt,name);
    if (fatt == INVALID_FILE_ATTRIBUTES) return -1;
    //if (fatt & FILE_ATTRIBUTE_REPARSE_POINT) return 1;
    if (fatt & FILE_ATTRIBUTE_REPARSE_POINT) return 1;
    return 0;
}*/
#endif
#ifdef OS_LINUX
int IsHardLink(char *name)
{
    struct stat buf;
    if (lstat(name,&buf)==-1) return -1;
    //lprintf ("H:name=%s  buf.st_mode=%i", name, buf.st_mode);
    if (!S_ISREG( buf.st_mode )) return 0;
    return (buf.st_nlink>1);
}
//int IsSymbolicLink(char*name)
//{
//    return 0;
//}
#endif // OS_LINUX
///@}

/**
 @brief Filegröße abfragen bei möglichen sehr großen Dateien
 @return Größe des Files oder -1 bei Fehler
 @param name Filename

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 10.05.20 HS st_size ist auf int64 long
___________________________________________________________________________*/

long long filesize64(char *name)
{
    struct stat64 buf;
    if (stat64(name,&buf)==-1) return -1LL;
    if (!S_ISREG( buf.st_mode )) return -1LL;
    return buf.st_size;
}

/**
 @brief Filegröße abfragen
 @return Größe des Files oder -1 bei Fehler
 @param name Filename

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 10.05.20 HS st_size ist long/int
___________________________________________________________________________*/

long filesize(char *name)
{
    struct stat buf;
    if (stat(name,&buf)==-1) return -1;
    if (!S_ISREG( buf.st_mode )) return -1;
    return buf.st_size;
}

#ifdef OS_WINDOWS_NOT_USED

/**
 @brief Unixtime zu Windows Filetime korriegieren
 @return true / false ( aktuell immer true )
 @param tt [in]       zu konvertierende Zeit
 @param ft [out]      FILETIME die zu füllen ist
 @param cor_DST [in]  ob ggf. eine Anpasssung an Sommerzeit nötig ist

___[ Revision ]______________________________________________________________

 ** 01.01.18 HS Create
 ** 31.03.20 HS Offenbar muss die Windowszeit angepasst werden, je nachdem
                ob man in Sommerzeit ist oder nicht und das File sich in
                einer anderen Zeitzone befindet
___________________________________________________________________________*/

BOOL time_t2FileTime (time_t tt, FILETIME *ft, int cor_DST)
{
    long long ll;
    ll = tt;

    time_t  now;

    if (cor_DST)
    {
        now = unixtime();
        if (time_tIsDST(now)==true)
        {
            if ( time_tIsDST(tt)!=true ) ll = tt - 3600;
        }else{
            if ( time_tIsDST(tt)==true ) ll = tt + 3600;
        }
    }
    ll = (ll * 10000000) + 116444736000000000;
    ft->dwLowDateTime  = (DWORD) ll;
    ft->dwHighDateTime = ll >> 32;
    return TRUE;
}

int LogPrintLastError(char* ExtraString1, char* ExtraString2)
{
    char* lpMsgBuf;
    DWORD dw = GetLastError();
    FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                    NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&lpMsgBuf, 0, NULL);
    lprintf("%s %d: %s -> %s", ExtraString1, dw, lpMsgBuf, ExtraString2);
    LocalFree(lpMsgBuf);
    return (int)dw;
}

/**
 @brief Filedatum setzen / ist unter Windows der Worker für copyfiletime
 @return NOERROR(0) oder die mit GetLastError geholte errno
 @param F_name      zu änderndes File
 @param F_create    0 oder Create meint nicht die Erstellungszeit, kann man aber modifizieren
 @param F_access    0 oder letzter Zugriff
 @param F_modif)    0 oder letzte Änderung

___[ Revision ]______________________________________________________________

 ** 02.11.18 HS Implementierung auch für Windows
___________________________________________________________________________*/


//int filedate_set (char *F_name, time_t F_create, time_t F_access, time_t F_modif, bool isDir false, int retrys = -1)
int filedate_set (char *F_name, time_t F_create, time_t F_access, time_t F_modif)
{
    int rc;
    HANDLE hFile;

    FILETIME *T1;
    FILETIME *T2;
    FILETIME *T3;

    FILETIME Time1;
    FILETIME Time2;
    FILETIME Time3;

    rc = NOERROR;

    int count;
    for (count=0;count<40;count++)
    {                                                                   //FILE_ATTRIBUTE_DIRECTORY
        hFile = CreateFileA( F_name, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile!=INVALID_HANDLE_VALUE) break;
        rc = GetLastError();
        if ( rc==ERROR_SHARING_VIOLATION )
        {
// ERROR_SHARING_VIOLATION 	0x20
// The process cannot access the file because
// it is being used by another process.
            lprintf ("retry %i while ERROR_SHARING_VIOLATION; in %s", count+1, F_name);
            Sleep(count * 25);
            continue;
        }
        return LogPrintLastError("INVALID_HANDLE_VALUE:", F_name);
    }

    T1=NULL;
    T2=NULL;
    T3=NULL;

    if (F_create!=0) {time_t2FileTime(F_create,&Time1, 1); T1=&Time1;}
    if (F_access!=0) {time_t2FileTime(F_access,&Time2, 0); T2=&Time2;}
    if (F_modif !=0) {time_t2FileTime(F_modif ,&Time3, 1); T3=&Time3;}

    if (SetFileTime(hFile, T1, T2, T3)==0)
    {
        rc = LogPrintLastError("SetFileTime:", F_name);
    }
    CloseHandle(hFile);
    return rc;
}

#endif // OS_WINDOWS

/**
 @brief Kopieren der Zeiteinstellung eines File auf ein anderes File
 @return EXIT_FAILURE / EXIT_SUCCESS
 @param from Quell Datei
 @param dest Ziel Datei

 Alte Beschreibung:
 copy date of a file ( can also used for DIR ) DIR funktioniert nicht unter Windows

 SetFileTime() unter Windows
 GetFileTime() unet Windows ???

 utime Rückgabewert
 Diese Funktionen gibt 0 zurück, wenn die Datei-Modifikationszeit geändert wurde. Ein Rückgabewert von -1
 zeigt einen Fehler an. Wird ein ungültiger Parameter übergeben, wird der invalid Parameter-Handler aufgerufen,
 wie in der Parametervalidierung beschrieben. Wenn die Ausführung fortgesetzt werden darf, geben diese
 Funktionen -1 zurück und errno ist auf einen der folgenden Werte gesetzt:

 Wert   | Zustand
 -------|-----------------------------------------------------------
 EACCES | Path gibt Verzeichnis oder Nur-Lese-Datei an
 EINVAL | Invalid timesArgument
 EMFILE | Zu viele offene Dateien (die Datei muss geöffnet werden, um ihre Änderungszeit zu ändern)
 ENOENT | Pfad oder Dateiname nicht gefunden

 Weitere Informationen zu Rückgabecodes finden Sie unter errno, _doserrno, _sys_errlist, und _sys_nerr.

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 02.11.18 HS Implementierung auch für Windows@date
 ** 27.09.20 HS Rückgabewert zeigt Erfolg an
 ** 04.10.23 HS copyfiletime jetzt mit utime für Windows (auf Probe)
___________________________________________________________________________*/

int copyfiletime (char *from, char *dest)
{
    struct stat buf;
    if (stat (from , &buf )==-1) return EXIT_FAILURE;
#if (defined OS_LINUX) || (defined OS_WINDOWS)
    //if (S_ISDIR( buf.st_mode )) return EXIT_SUCCESS; // noch nicht getestet
    struct utimbuf ut ;
    ut.actime   = buf.st_atime;
    ut.modtime  = buf.st_mtime;
    return utime (dest, &ut) ? EXIT_FAILURE : EXIT_SUCCESS;
#endif
    //return utimbuf32
    //return utimbuf

//lprintf ("X-Source Time: %s", timeinfostr(buf.st_mtime));
#ifdef OS_WINDOWS_NOT_USED
    if (S_ISDIR( buf.st_mode )) return EXIT_SUCCESS; // noch nicht getestet
    //if (buf.st_mtime==-1) return EXIT_FAILURE;

    if (filedate_set(dest, buf.st_ctime, buf.st_atime, buf.st_mtime ))
    {
        return EXIT_FAILURE;
    }
#endif // OS_WINDOWS
    return EXIT_SUCCESS;
}

/**
 @brief Kopieren des Users & Gruppe eines File auf ein anderes File
 @return EXIT_SUCCESS oder EXIT_FAILURE
 @param from Quell Datei
 @param dest Ziel Datei

 Nur unter Linux

___[ Revision ]______________________________________________________________

 ** 27.09.20 HS Create
___________________________________________________________________________*/

//int a __attribute__ ((unused)) ;

int copyFileOwner(char *from __attribute__ ((unused)), char *dest __attribute__ ((unused)))
{
#ifdef OS_WINDOWS
    return EXIT_SUCCESS;
#endif // OS_WINDOWS

#ifdef OS_LINUX
    struct stat buf;
    if (stat (from , &buf )==-1) return EXIT_FAILURE;
    return chown(dest, buf.st_uid, buf.st_gid) ? EXIT_FAILURE : EXIT_SUCCESS;
#endif // OS_LINUX

}

/**
 @brief Kopieren der Zugriffsrechte
 @return EXIT_SUCCESS oder EXIT_FAILURE
 @param from Quell Datei
 @param dest Ziel Datei

 Nur unter Linux

___[ Revision ]______________________________________________________________

 ** 27.09.20 HS Create
___________________________________________________________________________*/

int copyFileMod  (char *from __attribute__ ((unused)), char *dest __attribute__ ((unused)))
{
#ifdef OS_WINDOWS
    return EXIT_SUCCESS;
#endif // OS_WINDOWS

#ifdef OS_LINUX
    struct stat buf;
    if (stat (from , &buf )==-1) return EXIT_FAILURE;
    return chmod(dest, buf.st_mode & ( S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH )) ? EXIT_FAILURE : EXIT_SUCCESS;
#endif // OS_LINUX
}


/**
 @brief Filetime
 @return Gibt Filetime time_t in Unixtime oder 0 zurück
 @param name Zu prüfendes File

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

time_t filedate(char *name)
{
    struct stat buf;

    if (stat(name,&buf)==-1) return 0;
    return buf.st_mtime;
}

/**
 @brief Erstelle ein beliebiges Verzeichnis
 @return 0 bei Erfolg -1 bei Fehlern
 @param dirname Name des Verzeichnisses

 @note Unter Unix werden die Rechte auf 0x755 benutzt

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
___________________________________________________________________________*/

int createdir(char *dirname)
{
#if (defined OS_LINUX)
    return (mkdir(dirname, 0755));
#endif
#if (defined OS_WINDOWS)
    return (mkdir(dirname));
#endif
    return -1;
}

//int rc;
//mode_t oldmask=umask(0);
//rc= mkdir(dirname, 0755);
//umask(oldmask);
//return rc;


/**
 @brief Namen von einem Pfad
 @return pointer auf den Namen
 @param Kette Pfad

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 11.11.16 HS für den GDB Debuger muß auch Forslash drin stehen
 ** 21.03.24 HS modified
___________________________________________________________________________*/

char *Cbasename (char *Kette)
{
  char *base;
  for (base=Kette;*Kette;Kette++)
  {
      if ((*Kette == '\\') || (*Kette == '/')) base = Kette + 1;
  }
  return base;
}

/**
 @brief Extension eines Files ermitteln oder leeren String
 @return pointer auf ext oder "" nicht NULL
 @param filename Filename

___[ Revision ]______________________________________________________________

 ** 22.10.18 HS Create
___________________________________________________________________________*/

char *CfilenameExt(char *filename)
{
    char *dot;
    dot = strrchr(filename, '.');
    if((!dot) || (dot == filename)) return "";
    return dot + 1;
}

/**
 @brief Nur der Name
 @return String mit dem Namen
 @param filename Filename

 Nur der Name. Keine Extension oder Pfad eines Files ermitteln,
 wenn nicht vorhanden -> leeren String

___[ Revision ]______________________________________________________________

 ** 22.10.18 HS Create
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *CfilenameName(char *filename)
{
    char *dot;
    char *rslt;
    rslt=malloc_temp_strcpy(Cbasename(filename));
    dot = strrchr(rslt, '.');
    if((!dot) || (dot == rslt)) return rslt;
    *dot = '\0';
    return rslt;
}

/**
 @brief Environment-Variablen auflösen
 @return mit malloc geholter String
 @param path String der aufgelöst werden soll

 @code
 Beispiel:
 char *fn = univault ("%HSDIR%");
 fn = "C:\\HS"
 @endcode

 Cdirname wird am Ende aufgerufen

___[ Revision ]______________________________________________________________

 ** 07.07.20 HS War vorher nur in Cdirvault. Aber bereinigt für cfilevault
 ** 02.04.24 HS malloc_temp statt static
___________________________________________________________________________*/

char *univault(char *path)
{
    char *buffer;
    int i,o,p;
    char *env;
    char findname[PATH_MAX];

    //lprintf ("char *univault(char *path=%s)", path);
    buffer = malloc_temp(PATH_MAX);

    i=0;
    o=0;

#ifdef OS_LINUX
    if (path[0]=='~')
    {
        i=1;
        env = getenv("HOME");
        if (env)
        {
            strcpy (buffer, env);
            o=strlen(buffer);
        }
    }
#endif // OS_LINUX

    // in out ptr
    for (p=-1;;i++)
    {
        if (path[i]==0)
        {
            buffer[o]=0;
            break;                          // wenn p-1, dann ??? muss das abgefangen werden ?
        }
        if (path[i]==OTHER_OS_cDIR_SEP)
        {
            buffer[o]=cDIR_SEP;
            o++;
            continue;
        }
        if (path[i]=='%')
        {
            if (p==-1)                      // env start gefunden
            {
                p=0;
                continue;
            }
            findname[p]=0;
            env = getenv(findname);
            if (env)
            {
                for (p=0;;p++,o++)
                {
                    buffer[o]=env[p];
                    if (buffer[o]==0) break;
                }
            }
            p=-1;
            continue;
        }
        if (p>=0)
        {
            findname[p]=path[i];
            p++;
            continue;
        }
        buffer[o]=path[i];
        o++;
    }
    //lprintf ("return: univault %i %i %i %s",i,o,p, buffer);
    //printf ("%i %i %i %s\n",i,o,p, buffer);
    return buffer;
}

/**
 @brief Directory ohne Filenamen
 @return String mit dem Verzeichnisnamen
 @param path pfad

 @code{.cpp}
 Beispiel:
 char *fn = Cdirvault ("%HSDIR%");
 fn = "C:\\HS";
 char *fn = Cdirvault ("%HSDIR%\\etc\prg.cfg");
 fn = "C:\\HS\\etc";
 @endcode

 Wenn im Root, dann wird auf "Z:\\" aufgeloest. Ansonsten ist der letzte
 Buchstabe kein Slash. Cdirvault bereinigt Betriebssystemabhaengig
 Slash und loest Varablennamen in x Zeichen auf.

 @note Cdirname wird am Ende aufgerufen

___[ Revision ]______________________________________________________________

 ** 08.05.18 HS Erweitertes Cdirname zu Cdirvault bereinigt Betriebssystemabhängig
                Slash und löst Varablennamen in % Zeichen auf. cdirname wird
                am Ende aufgerufen
 ** 07.07.20 HS Herzroutine in eigene Routine verschoben
___________________________________________________________________________*/


char *Cdirvault(char *path)
{
    return Cdirname(univault(path));
}

/**
 @brief Directory ohne Filenamen
 @return String mit dem Verzeichnisnamen
 @param path pfad

 Wenn im Root, dann wird auf "Z:\\" aufgelöst. Ansonsten ist der letzte
 Buchstabe kein Slash. Cdirvault bereinigt Betriebssystemabhängig
 Slash

 @see Cdirvault

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 10.07.16 HS ReWritten
 ** 04.01.18 HS Reimplemented stoneage LinuxCode for Linux OS
 ** 16.12.20 HS Windowsteil weitgehend neu
 ** 02.04.24 HS malloc_temp statt static
 ___________________________________________________________________________*/

char *Cdirname (char *path)
{
    char newpath[PATH_MAX];
    char *slash;
    int length;

#ifdef OS_WINDOWS
    char tmppath[PATH_MAX];
    char *curpath;
    int  curdrive;
    char chgRootDir[]="A:\\";
    char chgDrive[]="A:";
    char chgBack[]="A:";
#endif // OS_WINDOWS
	if (path == NULL || *path == '\0')           // Sicherheitsabfrage
    {
		return malloc_temp_strcpy(".");
	}

#ifdef OS_LINUX
//    if (DirOK(path))                            // Wenn es den Pfad wirklich so gibt, dann nicht hinterfragen
//    {
//        strcpy(newpath,path);
//        return newpath; // return not allowed here
//    }
    strcpy_ex(newpath, path);
    strReplace(newpath, OTHER_OS_cDIR_SEP,cDIR_SEP);// Windows 2 Linux
    strstrreplace(newpath,"//","/");            // Doppelte korrigieren
    slash = strrchr (newpath, '/');             // Rechts suchen
    if (!slash) return malloc_temp_strcpy("."); // File ist im aktuellen Verzeichnis
    while (slash > newpath && *slash == cDIR_SEP) --slash;// Führende slashes löschen
    length = slash - newpath + 1;               // Laenge ermitteln
    newpath[length] = 0;                        // und kürzen
    return malloc_temp_strcpy(newpath);
#endif // OS_LINUX

#ifdef OS_WINDOWS
    strcpy_ex (newpath, path);                     // path dann kopieren

    strReplace(newpath,'/','\\');               // Linux 2 Windows
    strstrreplace(newpath,"\\\\","\\");         // Doppelte korrigieren
    GetCWD(tmppath);
    curpath = tmppath;                          // aktuellen Pfad merken
    if (newpath[0]==0)                          // bei leerem Pfad aktuellen Pfad nehmen
    {
        strcpy_ex (newpath, curpath);
        strcat_ex (newpath,"\\");
    }
    curdrive = toupper(curpath[0]);             // aktuelles Laufwerk merken
    if ((newpath[0]!=0) && (newpath[1]==':'))   // Laufwerk angegeben ?
    {
        curdrive = toupper(newpath[0]);         // dann merke LW
        if ((curdrive<'A') || (curdrive>'Z') ) curdrive = toupper(curpath[0]);
        strdel (newpath,0,2);                   // danach kann das mal weg
        if (curdrive != toupper(curpath[0]) )   // angegebenes LW nich aktuelles, dann muss auch der Pfad angepasst werden
        {
            chgBack[0]  = toupper(curpath[0]);
            chgDrive[0] = curdrive;
            chgRootDir[0] = curdrive;
            if (chdir(chgDrive)==EXIT_SUCCESS)
            {
                GetCWD(tmppath);
                curpath = tmppath;
            }
            else curpath = chgRootDir;
            chdir (chgBack);
        }
    }
    length = strlen(newpath);
    if (newpath[length-1]=='\\')                // ist das letzte Zeichen ein Slash
    {
        if (length>1) newpath[length-1]=0;
    }else{                                      // Wenn nicht
        slash = strrchr (newpath, '\\');        // Letztes Slash suchen
        if (slash)
        {
            //lprintf ("DEL in: \"%s\"", newpath);
            slash[0]=0;                         // und dahinter nullen
        }else{
            newpath[0]=0;                       // ansonsten ist es kein Pfad vorhanden, wie C:auto.txt
        }
    }

    if ((newpath[0]!=0) && (newpath[0]!='.') && (newpath[0]!='\\')) strins(newpath,".\\",0);
    if (newpath[0]==0) strcpy (newpath,".");
    if (newpath[0]=='.')
    {
        for (;newpath[0]=='.';strdel(newpath,0,1));
        if (newpath[0]=='\\') strdel(newpath,0,1);
        if (strlen(curpath)>3) if (newpath[0]!=0) strins (newpath, "\\", 0);
        strins (newpath, &curpath[2], 0);
    }else{
        if ( (newpath[0]!=0) && (newpath[0]!='\\') ) strins (newpath, "\\", 0);
    }
    strins (newpath, "*:", 0);
    newpath[0]=curdrive;
    return malloc_temp_strcpy(newpath);
#endif // OS_WINDOWS
}

/**
 @brief Directory mit Filenamen
 @return String mit dem Verzeichnisnamen bereinigt
 @param path pfad

 @see Cdirvault
 @see univault

___[ Revision ]______________________________________________________________

 ** 07.07.20 HS Create ( das meiste gab es schon in CDirvault
 ___________________________________________________________________________*/

char *CFilevault (char *path)
{
    char *p;
    char *buffer;
    buffer = malloc_temp(PATH_MAX);
    p = univault(path);
    strcpy_ex (buffer, Cdirname(p));
    strcat_ex (buffer, DIR_SEP);
    strcat_ex (buffer, Cbasename(p));
    return buffer;
}

/**
 @brief Angegebenes Verzeichnis auf das aktuelle Betriebssystem anwenden
 @param path Zu ändernder Pfad - übergebener path wird geändert

 @note Ursprünglich nur im Source von HSsync

___[ Revision ]______________________________________________________________

 ** 08.06.18 HS Nach Tools verschoben
 ** 16.06.18 HS Laufwerksbuchstaben korrigieren
___________________________________________________________________________*/

void CorrectPath(char *path)
{
#ifdef OS_WINDOWS
    int i;
    char *alphabet="@ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    strReplace(path,'/','\\');                                  // Linux 2 Windows
    strstrreplace(path,"\\\\","\\");                            // Doppelte korrigieren
    for(;;)
    {
        i = strright( path, '\\');
        if (i<=0) break;
        path[i]=0;
    }

    if (path[1]!=':') return;
    i = path[0] & 0x1f;
    path[0] = alphabet[i];                                      //<-- HIER

    if (strlen(path)>2) return;
    path[2]='\\';
    path[3]=0;
    return;
#endif

#ifdef OS_LINUX
    int i;
    strReplace(path,'\\','/');
    strstrreplace(path,"//","/");
    for(;;)
    {
        i = strright( path, '/');
        if (i<=0) break; //?? i<=0 für root ????
        path[i]=0;
    }
#endif
}

/**
 @brief Aktuelles Verzeichnis in übergebenen Pfad speichern
 @param Kette gibt das aktuelle Verzeichnis oder Leerzeichen zurück
 @return EXIT_SUCCESS wenn Erfolg

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 10.11.22 HS return added Code changed
___________________________________________________________________________*/

int GetCWD ( char *Kette )
{
/*
    char *buffer;
    buffer = (char *) malloc ( PATH_MAX );
    if ( getcwd( buffer, PATH_MAX ) != NULL)
    {
        strcpy_ex ( Kette, buffer);
    }else{
        Kette[0]=0;
    }
    free (buffer);
*/
	if (getcwd(Kette, PATH_MAX) == NULL )
	{
		Kette[0]=0;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/**
 @brief Aktuelles Verzeichnis zurückgeben
 @return String  mit dem aktuellen Verzeichnis ( muss mit free freigegeben werden )

___[ Revision ]______________________________________________________________

 ** 10.07.16 HS ReCreate
 ** 10.11.22 HS GetCWD statt getcwd buffer nicht mehr intern, sondern malloc
___________________________________________________________________________*/

char *strGetCWD(void)
{
    char *buffer;
    buffer = (char *) malloc ( PATH_MAX );
    if (GetCWD( buffer)) buffer[0]=0;
    //if (getcwd( buffer, PATH_MAX ) == NULL) buffer[0]=0;
    return buffer;
}

/**
 @brief chdir mit Prüfung
 @return 0 wenn Erfolg, ansonsten Fehler
 @param path Pfad zu dem gewechselt wird

 chdir mit Abfrage obs stattgefunden hat
 rslt = 0 alles OK, Ansonsten Fehler

___[ Revision ]______________________________________________________________

 ** 15.11.16 HS Create
___________________________________________________________________________*/

int save_chdir(char *path)
{
    int rc;
    char *a;
    rc = chdir (path);
    if (rc) return (rc);
    rc=0;
//    lprintf ("PAX = \"%s\"", path);
//    lprintf ("PWX = \"%s\"", _getCWD());
    a=strGetCWD();
    if(strcmp(path,a)) rc=99;
    free(a);
    return rc;
}

/// Die Größe für den FileCopy :: jetzt dynamisch HS 28.09.20
// #define filecopybufferlen 16384
/// Maximale Anzahl der Sterne in einer Reihe kann z.B. mit -DFILECOPY_MAX_PCT=40 überschrieben werden
#ifndef FILECOPY_MAX_PCT
#define FILECOPY_MAX_PCT 90
#endif

/**
 @brief Simple Anzeige für ein Filecopy
 @return diese display_filecopy kommt immer mit EXIT_SUCCESS zurück, wenn mit EXIT_FAILURE beendet wird bricht FileCopy ab
 @param dummy   Dummy, wird nicht verwendet, zeigt auf den aktuellen Filenamen
 @param pct     zeigt wieviel Prozent insgesamt angezeigt wird.

___[ Revision ]______________________________________________________________

 ** 31.03.20 HS Create
 ** 01.04.20 HS Dokumentation
 ** 11.04.20 HS verschoben nach tools.c
___________________________________________________________________________*/

int display_filecopy (char *dummy __attribute__ ((unused)), int pct)
{
    int i;
    char show[FILECOPY_MAX_PCT+16];                         // String zum Anzeigen der Sterne
    if (pct>100) {
            //lprintf ("\rerror pct=%i\n", pct);
            pct=100;
    }
    if (pct==0)                                             // bei 0 soll die Zeile gelöscht werden. Kann man machen, muss man aber nicht
    {
        strsetto(show,' ',FILECOPY_MAX_PCT+15);             // Alle mit Leerzeichen
        printf ("\r%s\r", show);                            // Ausgeben und Cursor auf den Zeilenanfang positionieren
        return EXIT_SUCCESS;                                // Zurück mit Erfolg
    }
    i = (pct*FILECOPY_MAX_PCT)/100;                         // Berechne Anzahl der Sterne
    strsetto(show,'*',i);                                   // Soviele Sterne wie nötig
    strsetto(&show[i],' ',FILECOPY_MAX_PCT-i+1);            // den Rest mit Leerzeichen
    show[i]='|';                                            // Erster Abstandsbalken
    show[FILECOPY_MAX_PCT]='|';                             // Zeiter Abstandsbalken
    show[FILECOPY_MAX_PCT+1]=0;                             // Stringende
    // printf ("%i %i %i %s\n",pct,i, strlen(show),show);   // DEBUG
    printf ("\r%s %i%%", show, pct); //(pct*100)/MAX_PCT);  // String ausgeben
#ifdef OS_LINUX
    fflush(stdout);
#endif // OS_LINUX
    return EXIT_SUCCESS;                                    // Zurück mit Erfolg
}
//Function: int isatty (int filedes)
//    This function returns 1 if filedes is a file descriptor associated with an open terminal device

/**
 @brief filecopy = filecopy
 @return EXIT_SUCCESS / EXIT_FAILURE
 @param Source  Quelldatei
 @param Dest    Zieldatei

 das ganz simple filecopy ruft das filecopy mit Prozent auf, da wird dann
 festgestellt, das nichts angezeigt werden soll.

 @see filecopy_pct
 @see copyfiletime

___[ Revision ]______________________________________________________________

 ** 15.11.16 HS ReCreate für HSsync
___________________________________________________________________________*/


int filecopy(char *Source, char *Dest)
{
    return filecopy_pct (Source, Dest, NULL, 0, 0);
}

/**
 @brief filecopy = filecopy
 @return EXIT_SUCCESS / EXIT_FAILURE
 @param Source      Quelldatei
 @param Dest        Zieldatei
 @param func        Funktion zum Ausgeben der Prozentanzeige bei NULL erfolgt keine Anzeige
 @param pct_start   prozent bei start
 @param pct_end     prozent ende

 Immer wenn eine Prozentänderung auftritt, dann wird die externe Routine (*func)
 aufgerufen.

 @see filecopy
 @see copyfiletime

___[ Revision ]______________________________________________________________

 ** 05.03.20 HS FileCopy mit möglichlicher Prozentanzeige
 ** 28.09.20 HS filecopybufferlen jetzt durch dynamische fblen ersetzt
___________________________________________________________________________*/

int filecopy_pct (char *Source, char *Dest, int (*func) (char *, int), int pct_start, int pct_end)
{
    FILE    *S,*D;
    char    *buffer;
    size_t   BufLen;
    int abort;
    int start;

    long file_steps;

    double pct_sz;
    double pct_doit;
    double pct_count;
    double pct_steps;
    double pct_next;

    long long fsize, fblen;

    if (!FileOK(Source)) return 1;
    if ((D=fopen(Dest, "wb"))==NULL)
    {
        // workaround since 28.12.19 HS
        remove (Dest);
        if ((D=fopen(Dest, "wb"))==NULL) return 3;
    }

    fsize       = filesize64(Source);

//    fblen = ( fsize / 1638400LL ) * 16384LL
//    fblen = 16384;
//    if (fsize >   9400000LL ) fblen = 81920;
//    if (fsize > 120000000LL ) fblen = 1048576;
    fblen = fsize / 1638400;                            // 100 Durchläufe minimum
    fblen *= 16384LL;                                   // Vielfaches von 16384
    if (fblen<16384LL) fblen = 16384LL;                 // Minimumsize
    if (fblen>1048576LL) fblen = 1048576LL;             // Maximumsize

    if ((buffer=(char *) malloc(fblen))==NULL) return 2;

    pct_sz      = pct_end - pct_start;
    file_steps  = (fsize/fblen) + 1;
    pct_doit    = pct_sz / file_steps;
    if (pct_sz>0) pct_steps = file_steps / pct_sz;
    else          pct_steps = file_steps + 1;

    //printf ("fblen = " LLD_STR " %s\n", fblen, Source);
    //lprintf ("fblen = " LLD_STR "\npct_sz = %f\nfile_steps = %ld \npct_doit = %f\npct_steps = %f\n", fblen,pct_sz,file_steps,pct_doit,pct_steps);

    pct_count   = pct_start;
    pct_next    = -1;
    S=fopen(Source,"rb");
    for(start=0,abort=EXIT_SUCCESS;;start++)
    {
        BufLen=fread(buffer, 1, fblen, S);
        if (BufLen==0) break;
        fwrite(buffer, 1, BufLen, D);
        if (*func)
        {
            if (pct_doit>=1)
            {
                pct_count = pct_count + pct_doit;
                abort = (*func)(Source, (int) pct_count);
            }else{

                if ( ((double)start) > pct_next )
                {
                    //printf ("\rstart=%i\npct_next=%f\npct_count=%f\n", start, pct_next, pct_count);
                    abort = (*func)(Source, (int) ((double)start/pct_steps));
                    pct_next=(double)start+pct_steps;
                }
                /*
                if ( (start % (int)pct_steps) == 0 )
                {
                    abort = (*func)(Source, (int) pct_count);
                    pct_count++;
                }
                */
            }
        }
        if (abort) break;   // ist abort == EXIT_FAILURE
    }
    fclose (S);
    fclose (D);
    free (buffer);
    //if (!abort) if (*func) (*func)(Source, pct_end);
    if (!abort) if (*func) (*func)(Source, 0);
    return abort;
}

/**
 @brief Freier Speicher vom aktuellen Pfad (unter Windows Laufwerksbuchstabe)
 @return Freien Speicher als unsigned long long
 @param Kette Pfad

___[ Revision ]______________________________________________________________

 ** 23.07.16 Wrapper
___________________________________________________________________________*/

unsigned long long diskfree (char *Kette)
{
    if (diskstate(Kette)==false) return 0LL;
    return hs_diskinfo.Free;
}

/**
 @brief Gesamten Speicher vom aktuellen Pfad (unter Windows Laufwerksbuchstabe)
 @return Gesamten Speicher als unsigned long long
 @param Kette Pfad

___[ Revision ]______________________________________________________________

 ** 23.07.16 Wrapper
___________________________________________________________________________*/

unsigned long long disktotal (char *Kette)
{
    if (diskstate(Kette)==false) return 0LL;
    return hs_diskinfo.Total;
}

/**
 @brief Benutzten Speicher vom aktuellen Pfad (unter Windows Laufwerksbuchstabe)
 @return Benutzten Speicher als unsigned long long
 @param Kette Pfad

___[ Revision ]______________________________________________________________

 ** 23.07.16 Wrapper
___________________________________________________________________________*/

unsigned long long diskused  (char *Kette)
{
    if (diskstate(Kette)==false) return 0LL;
    return hs_diskinfo.Used;
}

/**
 @brief Der Worker für @ref diskfree @ ref disktotal @ref disktotal
 @return true / false
 @param Kette Pfad

___[ Revision ]______________________________________________________________

 ** 02.04.06 HS ReCreate
 ** 23.07.16 HS Diskstate spiegelt jetzt alle Informationen wieder
                dazu sind 2 wrapper gekommen diskstate liefert(file) 0 (false)
                im Fehlerfall, ansonsten ist hs_diskinfo gefüllt
 ** 05.07.20 HS Für Windows GetDiskFreeSpaceExA statt der dos funktion
___________________________________________________________________________*/

int diskstate(char *Kette)
{
#ifdef OS_LINUX
    struct statfs fsstat;
    unsigned long long int a,b,c,d;
	//unsigned long long MaxFStat;
    if (statfs ( Kette, &fsstat)) return false;

    // ULONG_MAX is 0xffffffffL
    //MaxFStat = (ULONG_MAX / fsstat.f_bsize);
    //if ( fsstat.f_bavail>= MaxFStat) return false;
    //d = ( fsstat.f_bsize * fsstat.f_bfree ) / 1024;

	a = fsstat.f_bavail;	//f_bfree;
	b = fsstat.f_blocks;
	c = fsstat.f_bsize;
	d = fsstat.f_bfree;
	//t = b*c;

	//hs_diskinfo.t=d;
	//hs_diskinfo.a=a;
	//hs_diskinfo.b=b;
	//hs_diskinfo.c=c;

    hs_diskinfo.Free    = a * c;
    hs_diskinfo.Total   = b * c;
	hs_diskinfo.Used 	= (b - d) * c;
    //hs_diskinfo.Used = hs_diskinfo.Total - hs_diskinfo.Free;

	return true;
#endif // __linux

#ifdef OS_WINDOWS

    ULARGE_INTEGER Lcfree,Ltotal,Lfree;
    if ( !GetDiskFreeSpaceExA( Kette , &Lcfree , &Ltotal , &Lfree ) ) return false;
    hs_diskinfo.Free    = Lfree.QuadPart;
    hs_diskinfo.Total   = Ltotal.QuadPart;
	//hs_diskinfo.Used 	= Ltotal - Lfree;
    hs_diskinfo.Used    = hs_diskinfo.Total - hs_diskinfo.Free;

	return true;
#endif // OS_WINDOWS

#ifdef OS_WINDOWS_OLD
    struct _diskfree_t df;
    int                drive;
    unsigned long long a,b,c,t;

    drive = toupper(Kette[0])-'A';
    if ( (drive<=0) || (drive>26)) return false;           // wrong driveletter
    if (_getdiskfree(drive+1, &df) != 0) return false;     // any else wrong

    t = df.total_clusters;
    a = df.avail_clusters;
    b = df.sectors_per_cluster;
    c = df.bytes_per_sector;

    hs_diskinfo.Free    = a * b * c;
    hs_diskinfo.Total   = t * b * c;
    hs_diskinfo.Used = hs_diskinfo.Total - hs_diskinfo.Free;
    return true;
#endif

	return false;
}

/// Verzeichnisse in den @ref RCdir_ENUM opt_RCdir zu finden sind
typedef struct {
    int  optValue;
    char *dest;
}t_opt;
/// Verzeichnisse2 in den @ref RCdir_ENUM opt_RCdir zu finden sind
#if 0
t_opt db_opt[]={
    { opt_RCdir_PathFile , "" },
#ifdef OS_WINDOWS
    { opt_RCdir_PRG      , "%ARG0%" },
    { opt_RCdir_CFGDIR   , "%CFGDIR%" },
    { opt_RCdir_root_etc , "%APPDATA%/hs" },
    { opt_RCdir_root_etcd, "%APPDATA%/hs/%prgname%" },
    { opt_RCdir_HSDIR_etc, "%HSDIR%/etc" },
    { opt_RCdir_user_cfg , "%APPDATA%/hs" },

    { opt_RCdir_HSDIR_var, "%HSDIR%/var" },
    { opt_RCdir_root_var , "%APPDATA%/hs" },
#else //OS_LINUX
    { opt_RCdir_PRG      , NULL },
    { opt_RCdir_CFGDIR   , "%CFGDIR%" },
    { opt_RCdir_root_etc , "/etc" },
    { opt_RCdir_root_etcd, "/etc/%prgname%.d" },
    { opt_RCdir_HSDIR_etc, "%HSDIR%/etc" },
    { opt_RCdir_user_cfg , "%HOME%" },
//    { opt_RCdir_userc_cfg, "%HOME%/.config" },

    { opt_RCdir_root_var , "/var/%prgname%" },
    { opt_RCdir_HSDIR_var, "%HSDIR%/var" },
#endif
    { 0, NULL }
};
#endif

t_opt db_opt[]={
    { opt_RCdir_PathFile , "" },
#ifdef OS_WINDOWS
    { opt_RCdir_PRG      , "%ARG0%" },
    { opt_RCdir_CFGDIR   , "%CFGDIR%" },
    { opt_RCdir_root_etc , "%APPDATA%/hs" },
    { opt_RCdir_root_etcd, "%APPDATA%/hs/%prgname%" },
    { opt_RCdir_HSDIR_etc, "%HSDIR%/etc" },
    { opt_RCdir_user_cfg , "%APPDATA%/hs" },
    { opt_RCdir_uconfig_cfg, "%APPDATA%/hs" },

    { opt_RCdir_HSDIR_var, "%HSDIR%/var" },
    { opt_RCdir_root_var , "%APPDATA%/hs" },
#else //OS_LINUX
    { opt_RCdir_PRG      , "" },
    { opt_RCdir_CFGDIR   , "%CFGDIR%" },
    { opt_RCdir_root_etc , "/etc" },
    { opt_RCdir_root_etcd, "/etc/%prgname%.d" },
    { opt_RCdir_HSDIR_etc, "%HSDIR%/etc" },
    { opt_RCdir_user_cfg , "%HOME%" },
    { opt_RCdir_uconfig_cfg, "%HOME%/.config" },

    { opt_RCdir_HSDIR_var, "%HSDIR%/var" },
    { opt_RCdir_root_var , "/var/%prgname%" },
#endif
    { 0, NULL }
};


/**
 @brief eine RC-Datei lesen und den Inhalt im Speicher ablegen
 @return pointer auf tabelle mit den werten ( kann NULL sein )
 @param opt Optionen sind weiter unten gelistet
 @param rcreadfile NULL oder zeigt auf einen buffer, wohin der aktuelle ConfigFilename kopiert wird
 @param filename datei die gelesen werden soll

 - *opt* besteht aus optionen, wie den nodefault, siehe @ref RCdir_ENUM opt_RCdir
 - *readfile* KANN NULL sein. Wenn nicht zeigt readfile auf einen  Speicher, der den
    Filenamen mit Pfad aufnehmen kann. Ist reafile nicht NULL und es trat
    ein Fehler auf, dann ist readfile ein LeerString "".
 - *filename* Im Normalfall ein Filename. Dieser kann nartürlich auch Macros (SYSTEMVARIABLEN)
   enthalten. Auch NULL ist nachtbar, dann wird _programmname_.rc angenommen. Auch Teilpfade
   oder komplette Pfade sein moeglich. Ein Parameter opt_RCdir_PathFile ist dafuer vorgesehen.

 Ist eine RC-Datei gefunden, werden alle Daten in eine einfach verkettete Liste bereitgestellt.

 Sectionen wie [Privat] werden nur bei entsprechenden Flag mitgelesen.


| flags/optionen       | Beschreibung Linux/Windows                ||
| -------------------- | ----------------------------|-------------|
| opt_RCdir_silence    | silence ist ohne LogOutput                ||
| opt_RCdir_Sections   | Beim Lesen sind [Section] erlaubt         ||
| opt_RCdir_nodflt     | keine defaults                            ||
| opt_RCdir_must_exist | File muss beim Suchen existieren          ||
| <b> </b>             | **Linux**             | **Windows**       |
| opt_RCdir_PathFile   | Pfad und Filename in filename uebergeben  ||
| opt_RCdir_PRG        | not Allowed           | ./.**             |
| opt_RCdir_CFGDIR     | from /etc/hsrc        | \%HSDIR%/etc/hsrc or \%APPDATA%/hs/hsrc |
| opt_RCdir_root_etc   | /etc/.**              | \%APPDATA%/hs/.** |
| opt_RCdir_root_etcd  | /etc/\%prgname%.d/.** | \%APPDATA%/hs/%prgname%/.** |
| opt_RCdir_HSDIR_etc  | <b>beide:</b> \%HSDIR%/etc/.**            ||
| opt_RCdir_user_cfg   | \%HOME%/.**           | \%APPDATA%/hs/.** |
| opt_RCdir_HSDIR_var  | <b>beide:</b> \%HSDIR%/var/.**            ||
| opt_RCdir_root_var   | /var/\%prgname%/.**   | \%APPDATA%/hs/.** |

___[ Revision ]______________________________________________________________

 ** 20.10.20 HS Start
 ** 29.11.20 HS Das finden des Dateinamens, wenn er fehlt überarbeitet
 ** 11.11.22 HS opt und rcreadfile übertragen, wenn angegeben
 ** 15.11.22 HS Pfade nicht mehr einzeln auswerten, sonden ueber die Tabelle
 ** 18.11.22 HS Nochmal komplett Ueberarbeitet. PCreadPath
___________________________________________________________________________*/

void *RCread(int opt, char *rcreadfile, char *filename)
{
    void *tab;
    char Line[PATH_MAX];
    char Section[PATH_MAX];
    char *rc_Filename;
//    char rc_Fullname[PATH_MAX];
    FILE *cfg;
    int  d,s;

    if (rcreadfile!=NULL) rcreadfile[0]=0;
    rc_Filename = RCFileNameCreate(filename);                                   // Filename in "uebersetzter Form"
    if (RCreadPath (opt|opt_RCdir_must_exist, RCFullName, NULL, rc_Filename))
    {
        d=1<<31;
        if (!(opt & opt_RCdir_nodflt))
        {
#ifdef OS_WINDOWS
            sprintf ( RCFullName, "%s\\%s", RCunivault("%ARG0%"), rc_Filename);
#else
            sprintf ( RCFullName, "%s/%s", RCunivault("%HOME%"), rc_Filename);
#endif
			if (FileOK(RCFullName)) d=0;
        }
        if (d)
        {
            if (!(opt & opt_RCdir_silence))  lprintf ("RCread can't load: %s", rc_Filename);
            free(rc_Filename);
            return NULL; //(void *)
        }
    }
    free(rc_Filename);                                                       // kann schon mal free'ed werden

    if(( cfg = fopen(RCFullName,"rt")) == NULL ) return NULL;                   // Datei oeffnen
    if (rcreadfile!=NULL) strcpy_ex (rcreadfile, RCFullName);                   // fall noetig, Fullname kopieren
    tab = NULL;                                                                 // Start festlegen
    Section[0]=0;
    while ( 1 )
    {
        if (mgetline(cfg,Line,sizeof(Line)-3)!=0) break;                        // Zeile einlesen
        CL(Line);                                                               // bereinigen
        if (Line[0]==0) continue;
        if (Line[0]=='#') continue;                                             // Kommentarzeilen
        if (Line[0]=='[')
        {
            Section[0]=0;
            if ( (opt & opt_RCdir_Sections) || (opt & opt_RCdir_imSections) )
            {
                for (d=0,s=1;;s++)
                {
                    Section[d]=0;
                    if (Line[s]==0) break;
                    if (Line[s]==']')
                    {
                        Line[s+1]=0;
                        if (!(opt & opt_RCdir_imSections)) tab = Node_Add(tab,strdup(Line),Node_Add_Append);
                        break; // -> nextline
                    }
                    if (!isprint(Line[s])) break;
                    Section[d]=Line[s];
                    d++;
                }
            }
            continue;
        }

        //var finden vor dem = wird nur 0-9;a-z;A-Z gelesen äö und jeder Spacer wird überlesen
        for (d=0,s=0;;s++)
        {
            if (Line[s]==0) break;
            //Line[d]=tolower(Line[s]);
            Line[d]=Line[s];
            if (Line[s]=='=') break;
            if ((isalpha(Line[d])) || (isdigit(Line[d])))
            {
                d++;
            }else{ // 17.03.24 HS auch unterstriche und minus erlauben
                if (opt&opt_RCdir_isExpVars)
                {
                    if ( (Line[d]=='@') ||
                         (Line[d]=='_') ||
                         (Line[d]=='.') ||
                         (Line[d]=='-')
                        ) d++;
                }
            }
        }

        if (Line[s]==0)
        {
            break;
//            if (!(opt & opt_RCdir_ignoEqual)) break;
//            s=-1;
        }

        // Leerzeichen und Tabs nach dem = entfernen
        for (s++;;s++)
        {
            if (!isspace(Line[s])) break;
        }
        // Alles hinterher übernehmen
        for (d++;;s++)
        {
            if (isspace(Line[s])) Line[s]=' ';
            Line[d]=Line[s];
            if (Line[s]==0) break;
            if (isprint(Line[d])) d++;
        }
        if ( (opt & opt_RCdir_imSections) && (Section[0]) )
        {
            strins(Line,".",0);
            strins(Line,Section,0);
        }

        tab = Node_Add(tab,strdup(Line),1);
    }
    fclose (cfg);
    return tab;
}

/**
 @brief Einzelnen Pfad herausarbeiten
 @return EXIT_FAILURE / EXIT_SUCCESS
 @param opt opt_RC.. siehe @ref RCread
 @param rc_Fullname Zeiger auf einen Speicher fuer eine erfolgreiche Rueckgabe
 @param subpath  Verzeichnis statt programmnamen verwenden
 @param filename Filename wird nur gebraucht, wenn opt_RCdir_must_exists gesetzt ist

 Filenamen aus der Tabelle suchen und ggef. auf vorhandensein suchen

___[ Revision ]______________________________________________________________

 ** 18.11.22 HS Ausgekoppelt bei RCread
 ** 17.03.24 HS opt_RCdir_isrc deutlicher
___________________________________________________________________________*/

int RCreadPath(int opt, char *rc_Fullname, char *subpath, char *filename)
{
    char *rc_Pathname;
    int i;
    int rc_opt;

    //TODO: abfangen? vielleicht in HS_DEBUG?, waere dann ein "interner Assert"
    // if ((opt&opt_RCdir_must_exist) && (!filename)) then ERROR

    if (!rc_Fullname) return EXIT_FAILURE;                                      // if (!rc_Fullname) then ERROR
    rc_Fullname[0]=0;
    rc_opt = (opt | (opt_RCdir_start-1)) - (opt_RCdir_start-1);                 // bits unterhalb von start loeschen
//    if (!rc_opt) rc_opt=(1<<31);                                              // opt nicht angegeben ? muss aber nicht sein
    for (i=0;;i++)                                                              // rc_opt ist auf jedenfall wertig im Notfall 1<<31
    {
        if (db_opt[i].optValue==0) break;                                       // Ende der tabelle
        if (rc_opt & db_opt[i].optValue)                                        // opt und tabelle stimmen ueberein
        {
            rc_Pathname = RCdirvault(db_opt[i].dest, subpath);                  // Uebersetze den Teil damit keine Variablen mehr vorhanden sind
            if (!rc_Pathname) break;                                            // kann nur _nicht_ sein, wenn ...dest schon NULL war. Also eher nicht!
            if (filename)
            {
                if ( (opt & opt_RCdir_PathFile) && (subpath) && (filename))
                {
                    sprintf ( rc_Fullname, "%s" DIR_SEP "%s" DIR_SEP "%s", rc_Pathname, subpath, filename); // Keine Leerstrings
                }else{
                    if (rc_Pathname[0]) sprintf ( rc_Fullname, "%s" DIR_SEP "%s", rc_Pathname, filename);
                    else                strcpy  ( rc_Fullname, filename);       // Ansonsten ist ja kein Pfad drin oder sogar gewollt
                }
                strstrreplace(rc_Fullname, DIR_SEP DIR_SEP, DIR_SEP);

                if (opt & opt_RCdir_isrc) strcat ( rc_Fullname, ".rc");
                if (opt & opt_RCdir_must_exist)
                {
                    if (!FileOK(rc_Fullname)) continue;                         // Wenn nicht Datei existiert, dann weiter suchen
                }
            }else{
                strcpy(rc_Fullname, rc_Pathname);
                if ((opt & opt_RCdir_must_exist) && (!DirOK(rc_Fullname))) return EXIT_FAILURE;               // Wenn nicht Datei existiert, dann weiter suchen
            }
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}


/**
 @brief eine im Speicher befindene RC-Datei lesen und den Inhalt einer Variablen zurückgeben
 @return pointer auf variable ( kann NULL sein )
 @param RCNodes Nodes, die durchsucht werden sollen
 @param var Variable die gefunden werden soll
 @param num die wievielte Variablenfundstelle gefunden werden soll

 im Speicher nach RC-Wert suchen und die Value zurückgeben; wenn nicht vorhanden, dann NULL

___[ Revision ]______________________________________________________________

 ** 20.10.20 HS Start
___________________________________________________________________________*/

char *RCfindNum(void *RCNodes, char *var, int num)
{
    void *RCtab;
    char *z;
    int  p;
    int  found;
    found = -1;
    for (RCtab = RCNodes;;RCtab=Node_GetNext(RCtab))
    {
        if (!RCtab) break;
        z = (char*)Node_GetData(RCtab);
        p = strchrpos(z,'=',0);
        if (p<0) continue;
        if (strncmp(z,var,p)) continue;
        found ++;
        if (found != num) continue;
        return &z[p+1];
    }
    return NULL;
}

/**
 @brief eine im Speicher befindene RC-Datei lesen und den Inhalt einer Bezeichners und Variablen zurückgeben
 @return EXIT_FAILURE / EXIT_SUCCESS, dann mean und value gesetzt
 @param RCNodes Nodes, die durchsucht werden sollen
 @param mean ziel für den Inhalt _vor_ dem '='
 @param value ziel für den Inhalt _nach_ dem '='
 @param num die wievielte Variable gefunden werden soll

 im Speicher nach einem RC-Wert suchen (Nummer) und die Bezeichner und Value zurückgeben
 im Fehlerfall oder wenn num zu gross, dann EXIT_FAILURE

___[ Revision ]______________________________________________________________

 ** 21.02.24 HS Start
___________________________________________________________________________*/

int RCValuesNum(void *RCNodes, char *mean, char *value, int num)
{
    void *RCtab;
    char *z;
    int  p;
    int  found;
    found = -1;
    for (RCtab = RCNodes;;RCtab=Node_GetNext(RCtab))
    {
        if (!RCtab) break;
        z = (char*)Node_GetData(RCtab);
        p = strchrpos(z,'=',0);
        if (p<0) continue;
        found ++;
        if (found != num) continue;
        memset_ex(mean,0,p+1);
        memcpy(mean,z,p);
        strcpy(value, &z[p+1]);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

/**
 @brief Es wurd RCFindNum aufgerufen mit num=0
 @param RCNodes Nodes, die durchsucht werden sollen
 @param var Variable die gefunden werden soll
 @return pointer auf variable ( kann NULL sein )

 @code
    return RCfindNum(RCNodes, var, 0);
 @endcode

___[ Revision ]______________________________________________________________

 ** 20.10.20 HS Start
 ** 21.02.24 HS erweitert auf num und verschoben
___________________________________________________________________________*/

char *RCfind(void *RCNodes, char *var)
{
    return RCfindNum(RCNodes, var, 0);
}



/**
@brief              Tauscht zusaetzlich zum zu den Systemvariablen
@param filename     Filename welcher auch SystemVariablen enthalten kann
@return             String mit dem einem Filenamen

Tauscht zusaetzlich zu den Systemvariablen auch

 - %%prgname%    in den aktuellen Programmnamen
 - %%ARG0%       in den Pfad des aktuellen Programmes
 - %%CFGDIR%     "CFGDIR=" aus der hsrc, sofern vorhanden

___[ Revision ]______________________________________________________________

 ** 14.11.22 HS Implementiert
___________________________________________________________________________*/

char *RCunivault(const char *filename)
{
    char *Kette;                                                                // dummy
    char fnn[PATH_MAX];                                                         // Buffer für manipolierbare Pfad
    if (!filename) return NULL;
    strcpy (fnn, filename);                                                     // Pfad in den Buffer laden
               strstrreplace(fnn,"%prgname%",m_PRGNAME);                        // da ist auch Platz...ist PATH_MAX lang
    Kette = Cdirname(m_PRG_arguv[0]);                                           // ProgrammPfad ?
    if (Kette) strstrreplace(fnn,"%ARG0%",Kette);
    Kette = RCfind(RConfig, "CFGDIR");                                          // Pfad vorgegeben ?
    if (Kette) strstrreplace(fnn,"%CFGDIR%",Kette);
    return univault(fnn);                                                       // zeigt auf einen malloctierten Bereich von univault
}

/**
@brief              Tauscht zusaetzlich zum zu den Systemvariablen
@param mask         Mit dieser Maske einen neuen Verzeicnisnamen bilden
@param prgname      kann NULL sein, dann argv0 ansonsten Verzeichnisergaenzung
@return             String mit dem einem Dirnamen

Tauscht zusaetzlich zum zu den Systemvariablen auch

 - %%prgname%    in den aktuellen Programmnamen oder prgnamen
 - %%ARG0%       in den Pfad des aktuellen Programmes
 - %%CFGDIR%     config aus dem jeweiligen Hostsystem

___[ Revision ]______________________________________________________________

 ** 14.11.22 HS Implementiert
___________________________________________________________________________*/

char *RCdirvault(char *mask, char *prgname)
{
    char *Kette;                                                                // dummy
    char fnn[PATH_MAX];                                                         // Buffer für manipolierbare Pfad
    if (!mask) return NULL;

    if (prgname!=NULL)  Kette = prgname;
    else                Kette = Cdirname(m_PRG_arguv[0]);                       // ProgrammPfad !
    strcpy (fnn, mask);                                                         // Pfad in den Buffer laden
    if (Kette) strstrreplace(fnn,"%ARG0%",Kette);
    if (Kette) strstrreplace(fnn,"%prgname%",Kette);                        // da ist auch Platz...ist PATH_MAX lang
    if (strstr(fnn,"%CFGDIR%"))
    {
#ifdef OS_WINDOWS
    //Kette = strdup_ex("/Users/%USERNAME%/.config/");
        Kette = strdup("%APPDATA%");
        stradd( Kette, DIR_SEP );
#else
        Kette = strdup("%HOME%/.config/");
#endif // OS_WINDOWS
        if (prgname==NULL) stradd( Kette, m_PRGNAME );
        else               stradd( Kette, prgname );
        strstrreplace(fnn,"%CFGDIR%", Kette);
        free(Kette);
    }
    return univault(fnn);                                                       // zeigt auf einen malloctierten Bereich von univault
}
//
//->"%APPDATA%/hs/%prgname%"
//
//
//
//
//    Kette = Cdirname(m_PRG_arguv[0]);                                           // ProgrammPfad ?
//    Kette = RCfind(RConfig, "CFGDIR");                                          // Pfad vorgegeben ?
//    if (Kette) strstrreplace(fnn,"%CFGDIR%",Kette);


/**
@brief  Einen Filenamen fuer RCread aufloesen
@param  filename     Filename als String oder NULL
@return              malloctierten Speicher mit dem aufgeloesten filenamen

filename kann Variablen oder auch Unterverzeichnisse enthalten kann
Speicher _muss_ freigegeben werden

___[ Revision ]______________________________________________________________

 ** 13.11.22 HS Implementiert
___________________________________________________________________________*/

char *RCFileNameCreate(const char *filename)
{
    if (filename)
    {
        return strdup(RCunivault(filename));                          			// mit einer Kopie des Speicher zurueckkommen
    }
    return strdup(RCunivault("%prgname%.rc"));                    				// default
}

/**
 @brief Speicher für einen fread_all breitstellen
 @return NULL bei Fehlern oder Pointer auf gelesenen fread_all
 @param filename zu öffnendes File

 Das File wird komplett in den Speicher geladen "rb". Derzeit getestet mit
 einem 19 GB langen Textfile.



 frall_t       | Bezeichnung
 --------------|------------
 rs->line      | Aktuelle Zeile
 rs->sz        | größe des Streams
 rs->flags     | fra_isEOF zeigt ende des Streams
 rs->file      | das gesammte File, wie mit fopen gelesen
 rs->pointer   | aktueller pointer für getline ( nicht aktuelle Zeile )
 rs->nextline  | aktuelle Zeile

___[ Revision ]______________________________________________________________

 ** 27.01.24 HS Create
 ** 27.01.24 HS fopen_readall gibt *char bei erfolg oder NULL fopen_getline
___________________________________________________________________________*/

frall_t *fread_all(const char* filename)
{
    FILE *F;
    frall_t *rs;
    long int rsz;
    if((F = fopen (filename,"rb"))==NULL) return NULL;                          // File muss vorhanden sein, sonst Fehler
    rs = malloc0(sizeof (frall_t));                                             // Speicher für Funktion
    if (!rs) { fclose (F); return NULL; }                                       // Sollte vorhanden sein 2 x int + 2 x *char irgendwas bei unter 32 Byte
    rs->line = 0;                                                               // Wir haben noch nichts gelesen
    rs->flags = 0;                                                              // Default
    if (fseek(F, 0, SEEK_END) < 0) { free (rs); fclose (F); return NULL; }      // Ans Ende Positionieren
    rs->sz  =ftell(F);                                                          // Filelänge speichern
    rs->file=malloc0(rs->sz+1);                                                 // Das ist mind. 1 Byte, selbst bei Filelänge 0
    if (!rs->file) { free (rs); fclose (F); return NULL; }                      // Auch dieser Speicher muss gehen, hier kann das mal fehlschlagen, weil File zu gross ist
    fseek(F, 0, SEEK_SET);
    rsz = fread(rs->file, 1, rs->sz, F);                                        // Alles in einem Rutsch einlesen ... geht das oder kann das mal ein Teilpaket werden ?
    fclose (F);                                                                 // Dateihandle wieder schliessen
    rs->nextline=NULL;                                                          // Zur Zeit kein Zeile im Speicher
    rs->pointer=rs->file;                                                       // nächste Zeile=start
    if (rsz!=rs->sz)                                                            // Das muss immer passen oder nacharbeiten
    {
        lprintf("Error: fread_all sz not rsz %lld != %lld", rs->sz, rsz);       // Anzahl der gelesenen muss mit der Filelänge übereinstimmen ( bis 19GB getestet )
        fread_all_close(rs);                                                    // beenden
        return NULL;                                                            // Nix gelesen
    }
    if (rs->sz==0) rs->flags=rs->flags|fra_isEOF;
    return rs;                                                                  // rs und rs->file wurden mit malloc geholt
}

/**
 @brief Speicher eine fread_all wieder freigeben
 @param rs Pointer zu einem fread_all struct

___[ Revision ]______________________________________________________________

 ** 27.01.24 HS Create
___________________________________________________________________________*/

void fread_all_close(frall_t *rs)
{
    if (rs->nextline) free(rs->nextline);
    if (rs->file) free (rs->file);
    free (rs);
}

/**
 @brief Eine Zeile nach rs->nextline sichern. CR werden überlesen
 @return EXIT_FAILURE / EXIT_SUCCESS
 @param rs Pointer zu einem fread_all struct

___[ Revision ]______________________________________________________________

 ** 27.01.24 HS Create
___________________________________________________________________________*/

#define FRA_SIZE 256                                                            /// Defaultgröße einer Zeile
int fread_all_getline(frall_t *rs)
{
    unsigned char c;                                                            // Zeichenbuffer
    int lz;                                                                     // aktueller Zeiger in der neuen Zeile
    int sz=FRA_SIZE;                                                            // Größe des Buffer

    if (rs->nextline) free(rs->nextline);                                       // Alte Zeile ggf. Freigeben
    rs->nextline=malloc0(FRA_SIZE+16);                                          // und neuen Speicher reservieren
    if (rs->flags&fra_isEOF) return EXIT_FAILURE;                               // Wenn Ende bereits markiert, dann ende
    if (!rs->pointer) return EXIT_FAILURE;                                      // Sicherheitsabfrage, damit kein segfault kommen kann

    for (lz=0;;lz++)                                                            // Neue Zeile starten
    {
        if (lz>=sz)                                                             // Buffer Vergrößerung nötig
        {
            rs->nextline=realloc(rs->nextline,sz+FRA_SIZE+16);                  // Speicher erweitern
            memset(rs->nextline+sz,0,FRA_SIZE);                                 // Speicher mit 0 vollschreiben
            sz=sz+FRA_SIZE;                                                     // Neue größe merken
        }
fra_no_read_cr:
        c = (unsigned char) rs->pointer[0];                                     // Zeichen aus dem SpeicherStream
        rs->pointer++;                                                          // pointer aufaddieren
        if (c==13) goto fra_no_read_cr; // ignore CR's                          // CR aus Windows wird simple ignoriert
        if (c==0) rs->flags=rs->flags|fra_isEOF;                                // Ende, Wenn Stream endet ohne LF
        if (c=='\n')                                                            // wenn LF, dann Zeilenende
        {
            if (rs->pointer[0]==0) rs->flags=rs->flags|fra_isEOF;               // Wenn nach den LF StreamEnde, dann EOF setzen
            c=0;                                                                // EOL ist 0
        }
        rs->nextline[lz]=c;                                                     // Zeichen oder Zeilenende merken
//        if (c>127)
//            if ((rs->flags&fra_noTranslate) == 0)
//                fread_all_getline_translate
        if (c!=0) continue;                                                     // Nächstes Zeichen wenn nicht Zeilenden
        rs->line++;                                                             // Zeilencounter erhöhen
        return EXIT_SUCCESS;
    }
}

///@}


/*
//
// Listenverwaltung einer einfach verketteten Liste
//_____________________________________________________________________________
//
// 11.07.16 HS ReCreate
//_____________________________________________________________________________
//
// Ganze Liste löschen
//_____________________________________________________________________________

void LIST_Clear(struct LST_NODE *NODE)
{
    struct LST_NODE *nxt;

    while (1)
    {
        nxt = NODE->NEXT;
        if (!nxt) break;                        // Kopf ist jetzt leer; ende
        NODE->NEXT = nxt->NEXT;                 // nächsten zeiger holen
        if (nxt->TEXT) free (nxt->TEXT);        // aktuellen freigeben
        free (nxt);
    }
}
//
// Neuen Text anhängen
//_____________________________________________________________________________

void LIST_Add   (struct LST_NODE *NODE, char *txt)
{
    struct LST_NODE *nxt;
    struct LST_NODE *newNode;

    nxt = NODE;
    while (1)                                   // Ende der Liste suchen
    {
        if (!nxt->NEXT) break;
        nxt = nxt->NEXT;                        // durchhangeln
    }
    newNode = malloc (sizeof(struct LST_NODE)); // Speicher holen für Node
    if (!newNode) return;                       // uups out of mem

    newNode->NEXT = NULL;                       // neuen struct füllen
    newNode->TEXT = malloc(strlen(txt)+1);      // Speicher holen Text
    if (!newNode->TEXT)                         // uups out of mem
    {                                           // Sollte besser nicht passieren
        free (newNode);
        return;
    }
    strcpy (newNode->TEXT,txt);
    nxt->NEXT=newNode;
}

8//
// ersten Text lesen und löschen
// Der zurückgegeben String muß mit free() freigegeben werden !!!
// im fehlerfall gibts NULL
//_____________________________________________________________________________

char *LIST_Get(struct LST_NODE *NODE)
{
    char *rslt;
    struct LST_NODE *nxt;

    if (!NODE->NEXT) return (NULL);             // Im Head sollte ein Node stehen
    nxt = NODE->NEXT;                           // ansonsten haben wir einen gültigen Record
    NODE->NEXT = nxt->NEXT;                     // Head korrigieren

    rslt = nxt->TEXT;                           // Rückgabewert merken
    free (nxt);                                 // Node freigeben
    return rslt;                                // Text zurückgeben (free() nicht vergessen !!)
}
*/

/**
 @addtogroup c_chainlist
 @{
 @brief Listenverwaltung Verkette Liste mit voids

 Listenverwaltung einer einfach verketteten Liste

___[ Revision ]______________________________________________________________

 ** 11.07.16 HS ReCreate
 ** 15.11.16 HS Create Void Pointer
 ** 16.11.16 HS Alles auf Void Pointer umgestellt und universeller gemacht
 ** 24.11.16 HS neu Node_DelFirstNode und Node_Count
 ** 11.10.18 HS neu Node_DelOne
___________________________________________________________________________*/

/**
 @brief Neuen Text anhängen
 @return Neuen ListenStartNode
 @param StartNode   ListenStartNode
 @param Data        Buffer der die Daten enthält
 @param direction   Legt fest ob die Daten vorgehängt werden (false) - schneller oder ans Ende der Liste angehängt werden

___[ Revision ]______________________________________________________________

 ** 16.11.16 HS
___________________________________________________________________________*/

void *Node_Add (void* StartNode, void *Data, int direction)
{
    struct n_Node *my_IDX;
    struct n_Node *Last_IDX;

    if (Data==NULL) return StartNode;

    my_IDX = malloc (sizeof (struct n_Node));
    my_IDX->n_DATA=Data;

    if (direction==false) // TODO (HS): Node_Add_Insert (false und true loesung?)
    {
        my_IDX->n_NEXT = StartNode;
        return my_IDX;
    }

    // sorted (insert) Datendsatz
    my_IDX->n_NEXT=NULL;
    if (StartNode==NULL)  // Erster Datensatz
    {
        return my_IDX;
    }
    Last_IDX=StartNode;
    for (;;)
    {
        if (Last_IDX->n_NEXT==NULL)
        {
            Last_IDX->n_NEXT=my_IDX;
            return StartNode;
        }
        Last_IDX=Last_IDX->n_NEXT;
    }
    // never reached Code
    return NULL;
}

/**
 @brief Ersten Datensatz löschen ohne Daten !!!
 @return Neuen ListenStartNode
 @param StartNode   ListenStartNode

___[ Revision ]______________________________________________________________

 ** 16.11.16 HS
___________________________________________________________________________*/

void *Node_DelFirstNode(void *StartNode)
{
    struct n_Node *my_IDX;
    void *RootPnt;

    if (StartNode==NULL) return NULL;
    my_IDX = StartNode;
    RootPnt = my_IDX->n_NEXT;
    //free (my_IDX->n_DATA);
    free (my_IDX);
    return (RootPnt);
}

/**
 @brief Einen bestimmten Datenknoten löschen ohne Daten !!!
 @return Neuen ListenStartNode
 @param StartNode   ListenStartNode
 @param NodeToDel   Datenknoten der gelöscht werden soll

___[ Revision ]______________________________________________________________

 ** 16.11.16 HS
___________________________________________________________________________*/

void *Node_DelOne(void *StartNode, void *NodeToDel)
{
    struct n_Node *my_IDX;
    struct n_Node *Prev_IDX;
    //void *RootPnt;
    //void *PrevPnt;

    if (StartNode==NULL) return NULL;
    if (StartNode==NodeToDel) return Node_DelFirstNode(StartNode);

    my_IDX = StartNode;
    //RootPnt = my_IDX->n_NEXT;

    while (1)
    {
        Prev_IDX = my_IDX;
        my_IDX = Prev_IDX->n_NEXT;
        if (my_IDX==NULL) return (StartNode);
        if (my_IDX==NodeToDel) break;
    }
    Prev_IDX->n_NEXT=my_IDX->n_NEXT;
    free(my_IDX);
    return (StartNode);
}

/**
 @brief Einen Node nach einem anderen einfügen
 @return Neuen ListenStartNode
 @param StartNode   ListenStartNode
 @param After       Hinter welchen Node soll eingefügt werden
 @param Data        Daten

 ___[ Revision ]______________________________________________________________

 ** 31.10.22 HS
___________________________________________________________________________*/

//node_insert_after (head,before?after,node)
//head = node_insert_after (head, node);
void *Node_Add_After(void *StartNode, void *After, void *Data)
{
    struct n_Node *my_IDX;
    struct n_Node *after_IDX;

    if (Data==NULL) return StartNode;

    my_IDX = malloc (sizeof (struct n_Node));
    my_IDX->n_DATA=Data;

    if (After==NULL) // insert TOP
    {
        my_IDX->n_NEXT=StartNode;
        return (my_IDX) ;
    }
    after_IDX = After;
    my_IDX->n_NEXT = after_IDX->n_NEXT;
    after_IDX->n_NEXT=my_IDX;
    return StartNode;
}

/**
 @brief Ganze Liste löschen
 @return Neuen ListenStartNode, der ist NULL
 @param StartNode   ListenStartNode

 Ganze Liste löschen incl. Daten

___[ Revision ]______________________________________________________________

 ** 16.11.16 HS
___________________________________________________________________________*/

void *Node_DelAll(void *StartNode)
{
    struct n_Node *my_IDX;
    void *RootPnt;

    RootPnt = StartNode;
    for (;;)
    {
        if (RootPnt==NULL) break;
        my_IDX = RootPnt;
        RootPnt = my_IDX->n_NEXT;
        if (my_IDX->n_DATA) free (my_IDX->n_DATA);
        free (my_IDX);
    }
    return NULL;
}

/**
 @brief Nächsten Pointer holen
 @return Nächsten ListenNode; kann NULL sein !!
 @param StartNode   ListenNode

___[ Revision ]______________________________________________________________

 ** 16.11.16 HS
___________________________________________________________________________*/

void *Node_GetNext(void *StartNode)
{
    struct n_Node *my_IDX;
    my_IDX = StartNode;
    return my_IDX->n_NEXT;
}

/**
 @brief Datensatz zurückgegeben
 @return Daten vom ListenNode
 @param StartNode   ListenNode

___[ Revision ]______________________________________________________________

 ** 16.11.16 HS
___________________________________________________________________________*/

void *Node_GetData(void *StartNode)
{
    struct n_Node *my_IDX;
    if (StartNode==NULL) return NULL;
    my_IDX = StartNode;
    return my_IDX->n_DATA;
}

/**
 @brief Daten neu setzen; wenn Daten vorhanden, dann verwerfen
 @param Node   zu bearbeitender Knoten
 @param Data   neu zu setzende Daten ) alte Daten werden freigegeben
 @param freeOldData Default war die alten Daten freizugeben

___[ Revision ]______________________________________________________________

 ** 30.11.22 HS
 ** 18.03.24 HS new: freeOldData was default im Prinzip 1 ist
___________________________________________________________________________*/

void Node_SetData(void *Node, void *Data, int freeOldData)
{
    struct n_Node *my_IDX;
    if (Node==NULL) return;
    my_IDX = Node;
    if (freeOldData)
    {
        if (my_IDX->n_DATA) free(my_IDX->n_DATA);
    }
    my_IDX->n_DATA = Data;
}

/**
 @brief Anzahl Datensaetze zurückgegeben
 @return Anzahl der Knoten
 @param StartNode   ListenStartNode

___[ Revision ]______________________________________________________________

 ** 16.11.16 HS
___________________________________________________________________________*/

int Node_Count(void *StartNode)
{
    int nodes;
    struct n_Node *my_IDX;
    void *RootPnt;

    nodes=0;
    RootPnt = StartNode;
    for (;;)
    {
        if (RootPnt==NULL) break;
        nodes++;
        my_IDX = RootPnt;
        RootPnt = my_IDX->n_NEXT;
    }
    return (nodes);
}

/**
 @brief Sortieren der einzelnen Nodes via einfachen ShellSort
 @return Neuen ListenStartNode
 @param Stck        ListenStartNode
 @param Compare     Funktion die die Daten vergleicht


 Sortieren der einzelnen Nodes via einfachen ShellSort

 Es wird vom Anfang der Liste zum Ende immer eine Exhange-Variable zum
 Tauschen genommen, dann die kleinste Variable genommen und mittels
 "Tausch" an den Anfang gestellt. Dann wird die Liste am Anfang um eines
 "gekürzt" und dann der nächste "Kleinere" gesucht, bis nichts mehr da ist.

 Um die Liste zu sortieren muss es eine Vergleichsfunktion geben, die
 ist fogendermassen definiert.

 @code
    typedef int (*Nodecompfn)(const void*, const void*);
 @endcode

 Es werden die beiden Daten der Knoten übergeben. Im einfachsten Fall <em>strcmp</em>

___[ Revision ]______________________________________________________________

 ** 05.07.18 HS Create
___________________________________________________________________________*/

void *Node_Sort(void *Stck, Nodecompfn Compare)
{
    int  szIdx;                             // Anzahl aller Nodes
    int  cmprslt;                           // Ergebnis vom Vergleich

    void *tmpData;                          // zum Tauschen von Dateninhalten

    struct n_Node *exchg;                   // steht auf den ersten Datensatz in der Liste
    struct n_Node *smallest;                // steht auf den Kleinsten
    struct n_Node *chain;                   // Zeiger auf den "aktuellen" Datensatz

    szIdx = Node_Count(Stck);               // Anzahl Nodes
    if (szIdx<2) return (Stck);             // muß 2 oder größer sein

    exchg = Stck;                           // Beim ersten Mal auch den Anfnag der Liste
#ifdef HS_DEBUG
    NodesSortChanges = 0;                   // Wird nur im Debug definiert undn gezählt
#endif // HS_DEBUG
    for (;;)
    {
        smallest = exchg;                   // Auf den ersten
        chain    = exchg;                   // Auch den auf Anfang
        for (;;)
        {                                   // Compare wird übergeben, kann also auch negativ sortiert sein
            cmprslt = Compare(smallest->n_DATA, chain->n_DATA);
            if (cmprslt>0) smallest = chain;// ggfls. ist das das kleinste SET
            if (chain->n_NEXT==NULL) break; // und das solange bis wir am Ende sind
            chain = chain->n_NEXT;
        }
        if (smallest!=exchg)                // Wenn nicht ohnehin am Anfang ...
        {
            tmpData = smallest->n_DATA;     // Datenzeiger tauschen, nicht die Zeiger
            smallest->n_DATA=exchg->n_DATA;
            exchg->n_DATA = tmpData;
#ifdef HS_DEBUG
            NodesSortChanges++;             // Nur bei HS_DEBUG
#endif
        }
        exchg = exchg->n_NEXT;              // Und das bis der Zeiger der letzte ist
        if (exchg==NULL) break;
    }
    return Stck;
}
///@}


#ifdef  __cplusplus
}
#endif
//echo | gcc -dM -E -| sort | grep 64
//int a __attribute__ ((unused)) ;
//printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
//void *data   -> Node_Delete ( *First, *Node ) null if not deleted !!!
//void* StartNode = Node_DelOne (void* StartNode, void* DelNode);
//windres.exe -IC:\HS\wxWidgets\include -IC:\HS\wxWidgets\lib\gcc_dll\mswud  -J rc -O coff -i C:\HS\src\selfmade\HSWEAT~1\resource.rc -o .\selfmade\HSweather\resource.res
/*EOF*/
/*
#if defined(__GNUC__) && __GNUC__ >= 7
 #define FALL_THROUGH __attribute__ ((fallthrough))
#else
 #define FALL_THROUGH ((void)0)
#endif // __GNUC__ >= 7
and then I use FALL_THROUGH; in code
*/
