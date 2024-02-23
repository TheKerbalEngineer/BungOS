INTRO

BungOS is a Bungus themed operating system, for use on x86 computers.
Currently this project is in alpha, at best.

USAGE

BungOS works in phases, each page has instructions for it, and it's own seperate use.
Pages will be covered at the end of this file.

BUILDING

To build BungOS, you need to have a handful of things

1. Debian Linux, this can be wsl, a vm, or a linux computer
2. Git, to clone the repo
3. Watcom C, to compile the program
4. GCC, same(?) as 3.
4. Make, for auto compiling
5. Mtools, for FAT formating
6. Qemu, for emulation

First, download and install Watcom C 2 (3.), Then, edit the makefiles to point to your watcom c directory.
Next, run make to compile the program. Make sure to fix any errors you might have, until it compiles.
Finally, use Run.sh to start BungOS.

86 BOX

It's worth note that since BungOS is built for x86_64, 86Box could be used to emulate it on windows.
This has not been tested yet, but could very well work with the right config.

PAGES

1. Start Page, contains file listing and main logo
2. Type Page, allows user to type with some features, and quit with `
3. Login Test Page, Simple login test for cursor manipulation
4. Test Page, Test Page
