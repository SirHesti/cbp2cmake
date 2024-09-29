# CodeBlocksProject2Cmake - cbp2cmake
<a name="anker-English"></a>
[German Translation](#anker-German)<br>

cbp2cmake generates a CMakeLists.txt without CodeBlocks having to be installed.

Only a [project].cbp is required. A few switches can be used to change the behavior
and appearance. Unfortunately, libraries are not always clearly located in the
[project].cbp under cmake, so for the time being only the libraries I use
are implemented.

cbp2cmake HELP Final

| | | |
|:--|:--|:--|
| -o|<filename>    |"CMakeLists.txt" default
| -c|  <filename>  |\*.cbp-FileName to use
| -p| /save/to/dir |dflt: use from projectfile from hsinstall; like _/usr/bin_
| -t| <target>     |Target to Build [dft: Release]
| -r|              |Replace OutputFile
| -f| <gitfile>    |filelist writeout. if ARG missing, then "git/filelist" used
| -g|              |GitVersion without inlcudes
| -h| -? &dash;&dash;help |Help

typically a call __WITHOUT__ parameters.

supported libraries:

- wxWidgets
- Cairo
- Sqlite3
- Threads


<a name="anker-German"></a>

cbp2cmake generiert eine CMakeLists.txt ohne das CodeBlocks installiert sein muss.
Einzig eine [project].cbp ist nötig. Durch einige Schalter können
Verhalten und Aussehen geändert werden. Bibliotheken sind unter cmake leider nicht
immer eindeutig in der [project].cbp zu finden, so dass vorläufig nur die bei mir
verwendeten Bibliotheken implemetiert sind.

cbp2cmake HELP Finale

| | | |
|:--|:--|:--|
| -o|<filename>    |"CMakeLists.txt" default
| -c|  <filename>  |\*.cbp-FileName to use
| -p| /save/to/dir |dflt: use from projectfile from hsinstall; like _/usr/bin_
| -t| <target>     |Target to Build [dft: Release]
| -r|              |Replace OutputFile
| -f| <gitfile>    |filelist writeout. if ARG missing, then "git/filelist" used
| -g|              |GitVersion without inlcudes
| -h| -? &dash;&dash;help |Help

typischischer Weise ein ist Aufruf __OHNE__ Parameter.

unterstütze Libraries:

- wxWidgets
- Cairo
- Sqlite3
- Threads
