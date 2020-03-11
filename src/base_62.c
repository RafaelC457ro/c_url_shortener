#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static const char *BASE_62_CHARS = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *base_62_strrev(char *str) {
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}


void base_62_encode(uint64_t n, char *s) {
    int i;
    uint64_t r;
    char c;
    
    if (n == 0) {
        s[0]='0';
        s[1] = 0x0;
        return;
    }

    i=0 ;
    while (n > 0) {
        r = n % 62 ;
        s[i] = BASE_62_CHARS[r];
        i++ ;
        n /= 62 ;
    }

    s[i] = 0x0;

    base_62_strrev(s);
}

uint64_t base_62_decode(char *s) {
    return 0;
}
