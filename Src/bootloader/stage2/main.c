#include "stdint.h"
#include "stdio.h"
#include "disk.h"
#include "fat.h"
#include "keyboard.h"

void far* g_data = (void far*)0x00500200;

void _cdecl cstart_(uint16_t bootDrive)
{
    DISK disk;
    if (!DISK_Initialize(&disk, bootDrive))
    {
        printf("Disk init error\r\n");
        goto end;
    }

    DISK_ReadSectors(&disk, 19, 1, g_data);

    if (!FAT_Initialize(&disk))
    {
        printf("FAT init error\r\n");
        goto end;
    }

    // browse files in root
    printf("CONTENTS OF C:/\r\n");
    FAT_File far* fd = FAT_Open(&disk, "/");
    FAT_DirectoryEntry entry;
    int i = 0;
    while (FAT_ReadEntry(&disk, fd, &entry) && i++ < 5)
    {
        printf("  ");
        for (int i = 0; i < 11; i++)
            putc(entry.Name[i]);
        printf("\r\n");
    }
    FAT_Close(fd);

    // browse files in /usr
    printf("\r\nCONTENTS OF C:/USR");
    fd = FAT_Open(&disk, "/USR");
    //FAT_DirectoryEntry entry;
    i = 0;
    while (FAT_ReadEntry(&disk, fd, &entry) && i++ < 5)
    {
        printf("  ");
        for (int i = 0; i < 11; i++)
            putc(entry.Name[i]);
        printf("\r\n");
    }
    FAT_Close(fd);

    // read usr/logo.txt
    printf("\r\nWelcome to\r\n");
    char buffer[100];
    uint32_t read;
    fd = FAT_Open(&disk, "USR/LOGO.TXT");
    while ((read = FAT_Read(&disk, fd, sizeof(buffer), buffer)))
    {
        for (uint32_t i = 0; i < read; i++)
        {
            if (buffer[i] == '\n')
                putc('\r');
            putc(buffer[i]);
        }
    }
    FAT_Close(fd);

    printf("\r\nPress Any Key...\r\n");
    getch();
    printf("Entering Type Mode...\r\n");
    uint8_t a;
    getch();
    x86_clear();
    while (a != '`') {
	    getch();
	    __asm mov a, al; // Get Keyboard Char
        if (a == 13) {
            printf("\r\n");
        } else if (a == 8){
            printf("%c", 8);
            printf(" ");
            printf("%c", 8);
        } else {
            printf("%c", a);
        }
    }

    x86_clear();
    __asm mov a, al;
    printf("User: ");
    while (a != 13) { // Add Username Buffer!
	    getch();
	    __asm mov a, al;
        if (a == 8) {
            printf("%c", 8);
            printf(" ");
            printf("%c", 8);
        } else {
	    printf("%c", a);
        }
    }
    printf("\r\n");

    __asm mov a, al;
    printf("Password: ");
    while (a != 13) { // Add Password Buffer!
	    getch();
	    __asm mov a, al;
        if (a == 8) {
            printf("%c", 8);
            printf(" ");
            printf("%c", 8);
        } else {
	    printf("%c", a);
        }
    }
    printf("\r\n");
    printf("Acoount Logged");

end:
    for (;;);
}
