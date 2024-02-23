//#include "io.h"
//#include "stdint.h"
//
//static inline void outb(unsigned short port, unsigned char val) {
//    __asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
//}
//
//// Input a byte from a port
//static inline unsigned char inb(unsigned short port) {
//    unsigned char ret;
//    __asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
//    return ret;
//}
//