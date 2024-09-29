/**	***********************************************************************************************

 @file   cbp2cmake
 @author Sir Hesti (hstools@t-online.de)
 @brief  convertet codeblocks.cbp files into cmake
 @date   04.04.2024
 @copyright GNU Public License. http://www.gnu.org/licenses/gpl-3.0.html

 Da ich nicht wirklich ein Programm dafuer gefunden habe ... Eigene nicht 100% Loesung, aber für
 mich das Richtige

--[ HS: Devoloper Notes ]--------------------------------------------------------------------------

** FindCairo.cmake
-m  ../../gui/userdb/CMakeLists.txt -c ../../gui/userdb/userdb.cbp -r -t Release -p /tmp
-m ../cb_console_runner/CMakeLists.txt -c ../cb_console_runner/cb_console_runner.cbp -r -t Release -p /tmp
-m ../hsim/CMakeLists.txt -c ../hsim/hsim.cbp -r -t Release  -p /tmp
-m ../../gui/hsvc/CMakeLists.txt -c ../../gui/hsvc/hsvc.cbp -r -t Release -p /tmp
-m ../hswatchd/CMakeLists.txt -c ../hswatchd/hswatchd.cbp -r -t Release  -p /tmp

--[ Revision ]-------------------------------------------------------------------------------------

 ** 04.04.24 HS First Version
 ** 05.04.24 HS readCBP
 ** 06.04.24 HS WriteCmakeFile
 ** 07.04.24 HS Library's (wxWidgets, cairo, sqlite3) cairo .. FindCairo.cmake siehe WriteCmakeFile
 ** 08.04.24 HS Version geht nicht reibungsfrei ist aber auch nicht notwendig, niceToHave
 ** 09.04.24 HS tcc geht derzeit nicht.
 ** 10.04.24 HS directory's aus hsinstall interpretieren
 ** 14.04.24 HS git -g und -f mit app.ini statt .git
 ** 25.04.24 HS add cfgThreadsLib option

************************************************************************************************ */

#include "tools.h"
#include "VERSION.h"

int v_major=0;
int v_minor=0;
int v_patch=0;
char *v_beta=NULL;

char *cfgCodeBlocksProjectFile=NULL;                        // Name ist auch Programm
char *cfgTarget=NULL;                                       // Release Debug o.ä.
char *cfgOutputName=NULL;                                   // im Prinzip die EXE
char *cfgCMakeFile=NULL;                                    // CMakeFile
bool cfgReplaceOutPut=false;                                // CMakeFile.txt überschreiben, falls vorhanden
char *cfgDestOpt=NULL;                                      // wohin soll das File nach der Fertigstellung (hsinstall)
char *cfgDestPath=NULL;                                     // Verzeichnis wohin das File geschrieben wird.
char *cfgGitFilelist=NULL;                                  // möglicher app.ini oder aber wie angegeben
bool cfgCMake4Git=false;                                    // Standard schreiben ... bei true "GitVersion"

bool cfgWXlib=false;                                        // gefunden: <Add option="`wx-config`"
bool cfgCairoLib=false;                                     // gefunden: <Add library="cairo"
bool cfgSqlite3Lib=false;                                   // gefunden: <Add library="sqlite3"
bool cfgThreadsLib=false;                                   // gefunden: <Add option=-pthread"
bool cfgCTCC=false;                                         // tcc statt gcc - geht leider so nicht

char **Defines=NULL;                                        // -DBigBossCode gefunden
char **Files=NULL;                                          // welche Files werden für das binary benötigt
char **Dirs=NULL;                                           // Include Verzeichnisse
//char **Libs=NULL;                                         // einzeln gemacht, nicht global


int HELP(void){    // ab  e   ijklmn  q s uvwxyz
    printf (" -o <filename>   \"CMakeLists.txt\" default\n");
    printf (" -c <filename>   *.cbp-FileName to use\n");
    printf (" -p /save/to/dir dflt: use from projectfile from hsinstall\n");
    printf (" -t <target>     Target to Build [dft: Release]\n");
    printf (" -r              Replace OutputFile\n");
    printf (" -f <gitfile>    filelist writeout. if ARG missing, then \"git/filelist\" used\n");
    printf (" -g              GitVersion without inlcudes\n");
    printf (" -h/-?/--help    Help\n");
    return 0;
}

// 10.04.24 HS Speicher aufräumen
int cleanup(void)
{
    cfgCodeBlocksProjectFile  = free0(cfgCodeBlocksProjectFile);
    cfgTarget                 = free0(cfgTarget);
    cfgOutputName             = free0(cfgOutputName);
    cfgDestOpt                = free0(cfgDestOpt);
    cfgCMakeFile              = free0(cfgCMakeFile);
    cfgDestPath               = free0(cfgDestPath);
    cfgGitFilelist            = free0(cfgGitFilelist);
    v_beta                    = free0(v_beta);
    Files=strlstfree(Files);
    Defines=strlstfree(Defines);
    Dirs=strlstfree(Dirs);
    return 0;
}

// Das erste File im Verzeichnis suchen, das auf "findfile" passt
char *findfirstfile(char *directory, char *findfile)
{
    DIR *dir;
    struct dirent *entry;
    char *r;
    if ((dir = opendir(directory)) == NULL) return NULL;
    r = NULL;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] == '.') continue;
        if (!strmtch(findfile, entry->d_name,0)) continue;
        r = strdup_ex(entry->d_name);
        break;
    }
    closedir(dir);
    return r;
}

// nach dem letzen " suchen. und dann isolieren
int RemoveUsedStuffFromString(char *str)
{
    char *p;
    p = strrchr(str,'\"');
    if (p)
    {
        p++;
        *p='\0';
    }
    strunquote(str);
    return EXIT_SUCCESS;
}

// Name ohne Include
int IncludedNameToBase(char *shadow)
{
    int f,k,sz;
    for (;;)
    {
        f=0;
        if (!Dirs) return EXIT_FAILURE;
        for (k=0;Dirs[k];k++)
        {
            sz = strlen(Dirs[k]);
            if (!sz) break;
            if (!strncmp(Dirs[k],shadow,sz))
            {
                strdel(shadow,0,sz);
                if (shadow[0]==cDIR_SEP) strdel(shadow,0,1);
                f++;
            }
        }
        if (!f) return EXIT_SUCCESS;
    }
}

// cbp lesen und interpretieren
int readCBP(void)
{
    frall_t *rs;
    int rc;

    bool opt_project   = false;
    bool opt_build     = false;
    int  opt_target    = 0;

    rs = fread_all(cfgCodeBlocksProjectFile);
    if (!cfgTarget) cfgTarget=strdup_ex("Release");

    rc=True;
    for (;!fread_all_getline(rs);)
    {
        strCL(rs->nextline);
        if (!strncmp(rs->nextline,"<?xml",5)) continue;
        if (!strcmp(rs->nextline,"<CodeBlocks_project_file>")) continue;
        if (!strcmp(rs->nextline,"</CodeBlocks_project_file>")) continue;

        if (!strcmp(rs->nextline,"<Option compiler=\"tcc\" />")) { cfgCTCC = true  ; continue; }

        if (strncmp(rs->nextline,"<Option output=",15))
            if (!strncmp(rs->nextline,"<Option ",8)) continue;
        if (!strcmp(rs->nextline,"<Project>")) { opt_project = true  ; continue; }
        if (!strcmp(rs->nextline,"</Project>")){ opt_project = false ; continue; }
        if (!strcmp(rs->nextline,"<Build>"))   { opt_build   = true  ; continue; }
        if (!strcmp(rs->nextline,"</Build>"))  { opt_build   = false ; opt_target  = 0 ; continue; }
        if (!strcmp(rs->nextline,"</Target>")) { opt_target  = 0     ; continue; }
        if (!strncmp(rs->nextline,"<FileVersion",12)) continue;

        if (!strcmp(rs->nextline,"<Compiler>")) continue;
        if (!strcmp(rs->nextline,"</Compiler>")) continue;

        if (!strcmp(rs->nextline,"</Unit>")) continue;
        if (!strcmp(rs->nextline,"<Linker>")) continue;
        if (!strcmp(rs->nextline,"</Linker>")) continue;
        if (!strcmp(rs->nextline,"<Extensions />")) continue;
        if (!strcmp(rs->nextline,"<Extensions>")) continue;
        if (!strcmp(rs->nextline,"</Extensions>")) continue;
        if (!strcmp(rs->nextline,"<resources>")) continue;
        if (!strcmp(rs->nextline,"</resources>")) continue;
        if (!strncmp(rs->nextline,"<wxsmith version=",17)) continue;
        if (!strcmp(rs->nextline,"</wxsmith>")) continue;
        if (!strncmp(rs->nextline,"<gui name=",10)) continue;
        if (!strncmp(rs->nextline,"<wxFrame ",9)) continue;
        if (!strncmp(rs->nextline,"<wxDialog ",10)) continue;
        if (!strcmp(rs->nextline,"<lib_finder disable_auto=\"1\" />")) continue;
        if (!strcmp(rs->nextline,"<ResourceCompiler>")) continue;
        if (!strcmp(rs->nextline,"</ResourceCompiler>")) continue;


        if (!strcmp(rs->nextline,"<ExtraCommands>")) continue;
        if (!strcmp(rs->nextline,"</ExtraCommands>")) continue;
#ifdef xHS_DEBUG
            printf ("*: pass : %s\n", rs->nextline);
#endif
        if ((opt_build)&&(!strncmp(rs->nextline,"<Target title=", 14)))
        {
            opt_target = 1;
            strdel (rs->nextline,0, 14);
            RemoveUsedStuffFromString(rs->nextline);
#ifdef xHS_DEBUG
            printf ("\n***%s***\n\n", rs->nextline);
#endif
            if (!strcasecmp(rs->nextline,cfgTarget)) opt_target = 2;
            continue;
        }
        if ( (!opt_project) || (opt_target==1) ) continue;
        if (!strncasecmp(rs->nextline,"<Add after=\"hsinstall",21))
        {
            char *x;
            strdel (rs->nextline,0, 21);
            cfgDestOpt=free0(cfgDestOpt);
            x = stridx(rs->nextline,0);
            RemoveUsedStuffFromString(x);
#ifdef xHS_DEBUG
            printf ("*: DST : %s\n", x);
#endif
            cfgDestOpt = strdup_ex(x);
            continue;
        }

        if (!strncasecmp(rs->nextline,"<Unit filename=",15))
        {
            strdel (rs->nextline,0, 15);
            RemoveUsedStuffFromString(rs->nextline);

#ifdef xHS_DEBUG
            printf ("*: add : %s\n", rs->nextline);
#endif
            Files=strlstadd(Files,strdup_ex(rs->nextline));
            continue;
        }

        if (!strncasecmp(rs->nextline,"<Add directory=",15))
        {
            strdel (rs->nextline,0, 15);
            RemoveUsedStuffFromString(rs->nextline);
#ifdef xHS_DEBUG
            printf ("*: dir : %s\n", rs->nextline);
#endif
            Dirs=strlstadd(Dirs,strdup_ex(rs->nextline));
            continue;
        }

        if (!strncasecmp(rs->nextline,"<Add option=\"-pthread",21))
        {
#ifdef HS_DEBUG
            printf ("*: opt : %s\n", rs->nextline);
#endif
            cfgThreadsLib=true;
        }

        if (!strncasecmp(rs->nextline,"<Add option=\"-D",15))
        {
            strdel (rs->nextline,0, 15);
            strins (rs->nextline,"\"",0);
            RemoveUsedStuffFromString(rs->nextline);
#ifdef xHS_DEBUG
            printf ("*: opt : %s\n", rs->nextline);
#endif
            Defines=strlstadd(Defines,strdup_ex(rs->nextline));
            continue;
        }

        if ( (!opt_project) || (opt_target==2) )
        {
            if (!strncasecmp(rs->nextline,"<Option output=",15))
            {
                char *x;
                if (cfgOutputName) continue;
                strdel (rs->nextline,0, 15);
                x = stridx(rs->nextline,0);
                RemoveUsedStuffFromString(x);
#ifdef xHS_DEBUG
                printf ("*: OUT : %s\n", x);
#endif
                cfgOutputName = strdup_ex(x);
                continue;
            }
        }
        if (!strncasecmp(rs->nextline,"<Add library=\"cairo\"",20))
        {
#ifdef xHS_DEBUG
            printf ("*: CAIRO-Found\n");
#endif
            cfgCairoLib=true;
            continue;
        }

        if (!strncasecmp(rs->nextline,"<Add library=\"sqlite3\"",22))
        {
#ifdef xHS_DEBUG
            printf ("*: SQlite3-Found\n");
#endif
            cfgSqlite3Lib=true;
            continue;
        }

        if (!strncasecmp(rs->nextline,"<Add option=\"`wx-config",23))
        {
#ifdef xHS_DEBUG
            printf ("*: WX-Found\n");
#endif
            cfgWXlib=true;
            continue;
        }

        if (!strncmp(rs->nextline,"<Option ",8)) continue;
        if (!strncmp(rs->nextline,"<Add option=",12)) continue;
        if (!strncmp(rs->nextline,"<Add before=",12)) continue;
        if (!strncmp(rs->nextline,"<Add after=",11)) continue;
        printf ("UNKNOWN todo '%s'\n",rs->nextline);
        rc = False;
    }
    fread_all_close(rs);
    if(rc==False) return rc;

// Diese Code war vorgesehen um auch zu interpretieren.
#if 0
    char *version;
    version=strdup(Cdirname(cfgCodeBlocksProjectFile));
    stradd(version,"/VERSION.h");
//    printf ("%s\n", version);
    if (!FileOK(version))
    {
        free(version);
        return rc;
    }
    rs = fread_all(version);
    if (rs)
    {
        for (;!fread_all_getline(rs);)
        {
            if (strcmp(LeftStr(rs->nextline,8),"#define ")) continue;
            strdel(rs->nextline,0,8);
            if (!strcmp(LeftStr(rs->nextline,2),"I_")) strdel(rs->nextline,0,2);
            if (!strcmp(LeftStr(rs->nextline,6),"MAJOR "))
            {
                strdel(rs->nextline,0,6);
                v_major = atoi(rs->nextline);
            }
            if (!strcmp(LeftStr(rs->nextline,6),"MINOR "))
            {
                strdel(rs->nextline,0,6);
                v_minor = atoi(rs->nextline);
            }
            if (!strcmp(LeftStr(rs->nextline,6),"BUILD "))
            {
                strdel(rs->nextline,0,6);
                v_patch = atoi(rs->nextline);
            }
            if (!strcmp(LeftStr(rs->nextline,5),"BETA "))
            {
                strdel(rs->nextline,0,5);
                strunquote(rs->nextline);
                if (v_beta) free(v_beta);
                v_beta = strdup_ex(rs->nextline);
            }
            //printf ("%s\n", rs->nextline);
        }
    }
    fread_all_close(rs);
    free(version);
#endif
    return rc;
}

// CMakeFiles.txt schreiben
int WriteCmakeFile(void)
{
    FILE *F;

    char *prefix=NULL;
    char *destdir=NULL;
    int flag_c=0;
    int flag_cpp=0;
    int i;

    if (!cfgCMakeFile) return True;
    if ((FileOK(cfgCMakeFile)) && (!cfgReplaceOutPut))
    {
        printf ("%s File exist -- ", cfgCMakeFile);
        return False;
    }

    if ((F = fopen(cfgCMakeFile,"wt"))==NULL)
    {
        printf ("%s File can't write -- ", cfgCMakeFile);
        return False;
    }

    fprintf (F,"# %s Genrated by %s\n", strtime(unixtime(),2), m_PRG_INFO );
//    if ((v_major+v_minor+v_patch)!=0) fprintf (F,"cmake_policy(SET CMP0048 NEW)\n");
    fprintf (F,"project(%s", Cbasename(cfgOutputName));
//    if ((v_major+v_minor+v_patch)!=0) fprintf(F," VERSION %i.%i.%i",v_major,v_minor,v_patch);
    if (Files)
    {
        for (i=0;Files[i];i++)
        {
            if (!strcasecmp(CfilenameExt(Files[i]),"c")) flag_c=1;
            if (!strcasecmp(CfilenameExt(Files[i]),"cpp")) flag_cpp=1;
            if (!strcasecmp(CfilenameExt(Files[i]),"c++")) flag_cpp=1;
        }
        if (flag_c|flag_cpp)
        {
            fprintf(F," LANGUAGES");
            if (flag_cpp) fprintf(F," CXX");
            if (flag_c) fprintf(F," C");
        }
    }
    fprintf (F,")\n");
    if (flag_cpp) fprintf(F,"set(CMAKE_CXX_STANDARD 17)\n");

// tcc scheint nicht zu gehen if ( (flag_c) && (cfgCTCC) && (!flag_cpp) ) fprintf(F,"set(CMAKE_C_COMPILER \"/usr/bin/tcc\")\n");
/* todo: tcc -m64  cfgCTCC
<Option compiler="tcc" />
tcc
version.h
CXXFLAGS=-m64?
project(<PROJECT-NAME>
        [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
        [DESCRIPTION <project-description-string>]
        [HOMEPAGE_URL <url-string>]
        [LANGUAGES <language-name>...])
project(ortools VERSION ${VERSION} LANGUAGES CXX C)
project(fuerte CXX C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
*/

    fprintf (F,"cmake_minimum_required(VERSION 3.0 FATAL_ERROR)\n");
    // where was hsinstall
    if (!cfgDestOpt) cfgDestOpt=strdup("bin");

    if (cfgDestPath)
    {
        destdir = strrchr(cfgDestPath,'/');
        if (destdir)
        {
            *destdir='\0';
            destdir++;
            prefix=cfgDestPath;
        }
    } else if (!strcmp(cfgDestOpt, "usrbin"))
    {
        prefix  = "usr";
        destdir = "bin";
    } else if ( (!strcmp(cfgDestOpt, "usrsbin")) || (!strcmp(cfgDestOpt, "sbin")) )
    {
        prefix  = "usr";
        destdir = "sbin";
    }else if (!strcmp(cfgDestOpt, "cbbin"))
    {
        prefix  = "usr";
        destdir = "bin";
    }else if (!strcmp(cfgDestOpt, "bin"))
    {
        destdir=getenv("HOSTNAME");
        if (destdir)
        {
            if (!strcasecmp(destdir,"PC-Hesti"))
            {
                if (DirOK("/hs")) prefix = "hs";
            }
        }
        if (!prefix) prefix = "usr";
        destdir = "bin";
    }else
    {
        lprintf ("hsinstall with unknown argument");
        fclose (F);
        return False;
    }
    if ((!prefix)||(!destdir))
    {
        lprintf ("prefix or destdir wrong");
        fclose (F);
        return False;
    }
    fprintf (F,"set (CMAKE_INSTALL_PREFIX /%s )\n", prefix);
    if ((Dirs) && (cfgCMake4Git==false))
    {
//        if (Dirs[1])
//        {
            fprintf (F,"include_directories(");
            for (i=0;Dirs[i];i++)
            {
                if (i) fprintf (F," ");
                fprintf (F,Dirs[i]);
            }
            fprintf (F,")\n");
//        }else{
//            fprintf (F,"include_directories(%s)\n", Dirs[0]);
//        }
    }

    if (Defines)
    {
        for (i=0;Defines[i];i++)
        {
            fprintf (F,"add_definitions(-D%s)\n", Defines[i]);
        }
    }

    fprintf (F,"add_executable(%s", Cbasename(cfgOutputName));

    if (Files)
    {
        for (i=0;Files[i];i++)
        {
            prefix = CfilenameExt(Files[i]);
            if (!strcmp(prefix,"h")) continue;
            if (!strcmp(prefix,"hpp")) continue;
            if (!strcmp(prefix,"md")) continue;
            if (!strcmp(prefix,"txt")) continue;
            if (!strcmp(prefix,"wxs")) continue;
            if (cfgCMake4Git==false)
            {
                fprintf (F," %s",Files[i]);
            }else{
                char myshadow[PATH_MAX];
                strcpy_ex(myshadow,Files[i]);
                IncludedNameToBase(myshadow);
                fprintf (F," %s",myshadow);
            }
        }
    }
    fprintf (F,")\n");

    if (cfgThreadsLib)
    {
        //fprintf(F,"set(CMAKE_THREAD_PREFER_PTHREAD TRUE)\n");
        //fprintf(F,"set(THREADS_PREFER_PTHREAD_FLAG TRUE)\n");
        fprintf(F,"find_package(Threads REQUIRED)\n");
        fprintf(F,"target_link_libraries(%s ${CMAKE_THREAD_LIBS_INIT})\n",Cbasename(cfgOutputName));
    }
    if (cfgSqlite3Lib)
    {
        fprintf(F,"find_package(SQLite3)\n");
        fprintf(F,"if (SQLite3_FOUND)\n");
        fprintf(F,"  include_directories(${SQLite3_INCLUDE_DIRS})\n");
        fprintf(F,"  target_link_libraries(%s ${SQLite3_LIBRARIES})\n", Cbasename(cfgOutputName));
        fprintf(F,"else()\n");
        fprintf(F,"     message( FATAL_ERROR \"SQLite3 not found\\n\" )\n");
        fprintf(F,"endif()\n");
    }
    if (cfgCairoLib)
    {
        fprintf(F,"# locate FindCairo.cmake at https://gitlab.freedesktop.org/poppler/poppler/blob/master/cmake/modules/FindCairo.cmake\n");
        fprintf(F,"find_package(Cairo)\n");
        fprintf(F,"if (CAIRO_FOUND)\n");
        fprintf(F,"  include_directories(${CAIRO_INCLUDE_DIRS})\n");
        fprintf(F,"  target_link_libraries(%s ${CAIRO_LIBRARIES})\n", Cbasename(cfgOutputName));
        fprintf(F,"else()\n");
        fprintf(F,"     message( FATAL_ERROR \"Cairo not found\\n\" )\n");
        fprintf(F,"endif()\n");
    }
    if (cfgWXlib)
    {
        fprintf(F,"find_package(wxWidgets COMPONENTS net gl core base)\n");
        fprintf(F,"if(wxWidgets_FOUND)\n");
        fprintf(F,"  include(${wxWidgets_USE_FILE})\n");
        fprintf(F,"  target_link_libraries(%s ${wxWidgets_LIBRARIES})\n", Cbasename(cfgOutputName));
        fprintf(F,"else()\n");
        fprintf(F," message( FATAL_ERROR \"WX-Config not found\\n\" )\n");
        fprintf(F,"endif()\n");
    }
    fprintf (F,"install(TARGETS %s RUNTIME DESTINATION %s)\n", Cbasename(cfgOutputName),destdir);
// todo: koennte man machen ....
//if(UNIX)
//  # actions ...
//  message("Running on Unix-like OS")
//endif()
//if(CMAKE_SIZEOF_VOID_P EQUAL 8)
//   message(" [INFO] 64 bits build.")
//else()
//   message(" [INFO] 32 bits build.")
//endif()
    fclose (F);
    return True;
}

int WriteGitFilelist(void)
{
    int i;
    FILE *F;
    char dirname [PATH_MAX];
    char file    [PATH_MAX];
    char shadow  [PATH_MAX];

    char **oldfile;
    frall_t *rs;

    strcpy(dirname,Cdirvault(cfgGitFilelist));
    if (!DirOK(dirname)) createdir(dirname);
    if (!DirOK(dirname))
    {
        lprintf ("Dir %s not found; need to write %s", dirname, cfgGitFilelist);
        return EXIT_FAILURE;
    }

    oldfile=NULL;
    rs = fread_all(cfgGitFilelist);
    if (rs)
    {
        for (i=0;!fread_all_getline(rs);)
        {
            if (rs->nextline[0]=='[')
            {
                if (!strcmp(rs->nextline,"[filelist]")) i=1;
                else i=0;
            }
            if (!i) oldfile=strlstadd(oldfile,strdup_ex(rs->nextline));
        }
        fread_all_close(rs);
        // remove empty lines at the end of the old file
//#ifdef HS_DEBUG
//        char *dbg __attribute__ ((unused)) ;
//#endif // HS_DEBUG
        if (oldfile)
        {
            for (i=0;oldfile[i];i++);
            for (i--;i>=0;i--)
            {
//    #ifdef HS_DEBUG
//                dbg=oldfile[i];
//    #endif
                if (*oldfile[i]!='\0') break;
                oldfile[i]=free0(oldfile[i]);
            }
        }
    }

// fopen to write
    if ((F = fopen(cfgGitFilelist,"wt"))==NULL)
    {
        printf ("%s File can't write -- ", cfgGitFilelist);
        return EXIT_FAILURE;
    }
    if (oldfile)
    {
        for (i=0;oldfile[i];i++)
        {
//#ifdef HS_DEBUG
//            dbg=oldfile[i];
//#endif
            fprintf (F, "%s\n", oldfile[i]);
        }
    }
    strlstfree(oldfile);
    fprintf (F, "\n[filelist]\n");
// write the new ones
    for (i=0;Files[i];i++)
    {
        strcpy (file, Files[i]);
        strcpy (shadow, Files[i]);
        IncludedNameToBase(shadow);
        strquote(shadow);
        strquote(file);
        fprintf (F, "%s=%s\n", shadow, file);
    }
    fprintf (F, "\n");
//close
    fclose(F);
    return EXIT_SUCCESS;
}

signed int main(int argc, char *argv[])
{
	if (InitTools(argc , argv, "%v%t", I_MAJOR, I_MINOR, I_BUILD, I_BETA, LOG_STDERR)) return -1;

	if ((aChkARG("h"))||(aChkARG("?"))||(aChkARGlong("help"))) return 255|cleanup()|HELP();
    if (aChkARG("c")) if(ARG)cfgCodeBlocksProjectFile = strdup_ex(ARG);
    if (aChkARG("t")) if(ARG)cfgTarget                = strdup_ex(ARG);
    if (aChkARG("p")) if(ARG)cfgDestPath              = strdup_ex(ARG);
    if (aChkARG("o")) if(ARG)cfgCMakeFile             = strdup_ex(ARG);
    if (aChkARG("g")) cfgCMake4Git = true;
    if (aChkARG("f"))
    {
        if(ARG) cfgGitFilelist   = strdup_ex(ARG);
        else    cfgGitFilelist   = strdup_ex("app.ini");
    }

    if (aChkARG("r")) cfgReplaceOutPut = true;
    if (!cfgCMakeFile) cfgCMakeFile = strdup_ex("CMakeLists.txt");
    if (!strcmp(cfgCMakeFile,"-")) cfgCMakeFile=free0(cfgCMakeFile);

    if (!cfgCodeBlocksProjectFile) cfgCodeBlocksProjectFile=findfirstfile(".","*.cbp");
    if (!FileOK(cfgCodeBlocksProjectFile)) return 255|cleanup()|printf("cbp-File not found");
    if (!readCBP()) return 255|cleanup()|printf("read CBP error");
    if (cfgGitFilelist) if (WriteGitFilelist()) return 255|cleanup();
    if (!cfgOutputName) return 255|cleanup()|printf("no OutputFile found - use -o Option");

    //write CMakeFile.txt
    if (!WriteCmakeFile()) return 255|cleanup()|printf("cMakeFile not or wrong");
    printf ("Done\n");
    //printf ("Result=%s\n",cfgCodeBlocksProjectFile);
#ifdef HS_DEBUG
    if (cfgCMakeFile) if (FileOK(cfgCMakeFile))
    {
        char *p;
        p = strprintf("cat %s", cfgCMakeFile);
        system(p);
        free(p);
    }
#endif
    return cleanup();
}
