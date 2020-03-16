#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static const char *BASE_62_CHARS =
    "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

/**
 * Reverse string.
 * Exemple:
 *
 * base_62_strrev(h, key, &stc_one);
 *
 * @param[in] str string to reverse
 * @param[out] str reversed string
 */

char *base_62_strrev(char *str) {
    char *p1, *p2;

    if (!str || !*str) return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

/**
 * Convert a integer to base 62 string
 * Exemple:
 *
 *  char k[11];
 *  uint64_t n = 0x16B5C9428C1B05;
 *
 *  base_62_encode(n, k);
 *  0x16B5C9428C1B05 -> thatscool
 *
 * @param[in] n interger to parse
 * @param[in] ponter to base 62 string
 */

void base_62_encode(uint64_t n, char *s) {
    int i;
    uint64_t r;
    char c;

    if (n == 0) {
        s[0] = '0';
        s[1] = 0x0;
        return;
    }

    i = 0;
    while (n > 0) {
        r = n % 62;
        s[i] = BASE_62_CHARS[r];
        i++;
        n /= 62;
    }

    s[i] = 0x0;

    base_62_strrev(s);
}
