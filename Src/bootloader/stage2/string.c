#include "string.h"
#include "stdint.h"
#include "memory.h"

const char* strchr(const char* str, char chr)
{
    if (str == NULL)
        return NULL;

    while (*str)
    {
        if (*str == chr)
            return str;

        ++str;
    }

    return NULL;
}

char* strcpy(char* dst, const char* src)
{
    char* origDst = dst;

    if (dst == NULL)
        return NULL;

    if (src == NULL)
    {
        *dst = '\0';
        return dst;
    }

    while (*src)
    {
        *dst = *src;
        ++src;
        ++dst;
    }
    
    *dst = '\0';
    return origDst;
}

unsigned strlen(const char* str)
{
    unsigned len = 0;
    while (*str)
    {
        ++len;
        ++str;
    }

    return len;
}

char *stpcpy(char *restrict dst, const char *restrict src)
{
    char  *p;
    p = memcpy(dst, src, strlen(src));
    *p = '\0';
    return p;
}

/*
char* strcat(char *restrict dst, const char *restrict src)
{
    stpcpy(dst + strlen(dst), src);
    return dst;
}
*/
