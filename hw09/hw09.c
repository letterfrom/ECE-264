#include "hw09.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>

// Helper function to skip whitespace
static const char *skip_whitespace(const char *ptr) {
    while (isspace(*ptr)) {
        ptr++;
    }
    return ptr;
}

// Helper function to convert char to int
static int char_to_int(char c) {
    if (isdigit(c)) return c - '0';
    if (islower(c)) c = toupper(c);
    if (isupper(c)) return c - 'A' + 10;
    return 36;
}

// IMPLEMENT string_to_long BELOW THIS COMMENT
long string_to_long(const char *string, const char **endptr, int base) {
    #define INV_SYMBOL 36
    assert(string != NULL);
    errno = 0;

    long ret_value = 0;

    if ((base < 0) || (base == 1) || (base > 36)) {
        errno = EINVAL;
        if (endptr) *endptr = string;
        return 0;
    }

    const char *ptr = skip_whitespace(string);

    int negative = 0;
    if (*ptr == '-') {
        negative = 1;
        ptr++;
    } else if (*ptr == '+') {
        ptr++;
    }

    if (base == 0) {
        if (*ptr == '0') {
            if (ptr[1] == 'x' || ptr[1] == 'X') {
                base = 16;
                ptr += 2;
            } else {
                base = 8;
                ptr++;
            }
        } else {
            base = 10;
        }
    } else if (base == 16) {
        if (*ptr == '0' && (ptr[1] == 'x' || ptr[1] == 'X')) {
            ptr += 2;
        }
    }

    int any_digits = 0;
    while (*ptr) {
        int digit = char_to_int(*ptr);
        if (digit == INV_SYMBOL || digit >= base) break;

        any_digits = 1;

        // Overflow/underflow check
        if (!negative) {
            if (ret_value > (LONG_MAX - digit) / base) {
                errno = ERANGE;
                ret_value = LONG_MAX;
                while (1) {
                    ptr++;
                    int d = char_to_int(*ptr);
                    if (d == INV_SYMBOL || d >= base) break;
                }
                break;
            }
        } else {
            if (ret_value < (LONG_MIN + digit) / base) {
                errno = ERANGE;
                ret_value = LONG_MIN;
                while (1) {
                    ptr++;
                    int d = char_to_int(*ptr);
                    if (d == INV_SYMBOL || d >= base) break;
                }
                break;
            }
        }

        ret_value = ret_value * base + (negative ? -digit : digit);
        ptr++;
    }

    if (!any_digits) {
        if (endptr) *endptr = string;
        return 0;
    }

    if (endptr) *endptr = ptr;
    return ret_value;
}
