# BungOS

Made for watermelon_sir's bungus contest, and forked from a private project

## Building

Download and install watcom c, and modify makefiles to your install dir

Run make and fix errors until it works

## Running

### Debian Linux / Debian WSL
`sudo apt install qemu-system`

`cd Build; qemu-system-x86_64 -fda main_floppy.img`

### Windows
`winget qemu`

`cd Build; qemu-system-x86_64 -fda main_floppy.img`
