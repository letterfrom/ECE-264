#include "hw09.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Helper function for easier assertions
void run_test(const char *input, int base, long expected, int expected_errno, const char *expected_endptr_desc) {
    const char *endptr = NULL;
    errno = 0;
    long result = string_to_long(input, &endptr, base);
    int pass = 1;

    // Check result
    if (result != expected) {
        fprintf(stderr, "FAIL: input='%s', base=%d, expected value %ld, got %ld\n", input, base, expected, result);
        pass = 0;
    }
    // Check errno
    if (errno != expected_errno) {
        fprintf(stderr, "FAIL: input='%s', base=%d, expected errno %d, got %d\n", input, base, expected_errno, errno);
        pass = 0;
    }
    // Check endptr
    if ((expected_endptr_desc && *expected_endptr_desc)
        && (!endptr || strcmp(endptr, expected_endptr_desc) != 0)) {
        fprintf(stderr, "FAIL: input='%s', base=%d, expected endptr \"%s\", got \"%s\"\n", input, base, expected_endptr_desc, endptr ? endptr : "NULL");
        pass = 0;
    } else if ((!expected_endptr_desc || !*expected_endptr_desc) && endptr && *endptr) {
        fprintf(stderr, "FAIL: input='%s', base=%d, expected endptr at end, got \"%s\"\n", input, base, endptr);
        pass = 0;
    }

    if (pass) {
        fprintf(stderr, "PASS: input='%s', base=%d, value=%ld, errno=%d, endptr=\"%s\"\n",
            input, base, result, errno, endptr ? endptr : "NULL");
    }
}

int main(int argc, char **argv) {
    errno = 0;
    fprintf(stderr, "Welcome to ECE264, we are working on HW09!\n\n");

    // Invalid base
    run_test("123", 1, 0, EINVAL, "123");
    run_test("123", -1, 0, EINVAL, "123");
    run_test("123", 37, 0, EINVAL, "123");

    // Whitespace skip, valid base
    run_test("   42", 10, 42, 0, "");

    // Positive/negative signs
    run_test("-1234", 10, -1234, 0, "");
    run_test("+5678", 10, 5678, 0, "");

    // Multiple signs (invalid)
    run_test("+-234", 10, 0, 0, "+-234");
    run_test("-+234", 10, 0, 0, "-+234");

    // Base=0, hex and octal detection
    run_test("0xFF", 0, 255, 0, "");
    run_test("077", 0, 63, 0, "");

    // Base=16 with explicit 0x prefix
    run_test("0x1A", 16, 26, 0, "");

    // Base=8
    run_test("012", 8, 10, 0, "");

    // Base=10
    run_test("99", 10, 99, 0, "");

    // Overflow
    char str_overflow[32];
    sprintf(str_overflow, "%ld9", LONG_MAX);
    run_test(str_overflow, 10, LONG_MAX, ERANGE, "");

    // Underflow
    char str_underflow[32];
    sprintf(str_underflow, "%ld9", LONG_MIN);
    run_test(str_underflow, 10, LONG_MIN, ERANGE, "");

    // No digits, junk input
    run_test("!@^#%!&#@%", 10, 0, 0, "!@^#%!&#@%");
    run_test("AAF", 10, 0, 0, "AAF");
    run_test(",,", 10, 0, 0, ",,");
    run_test("asdl3234!!!94", 10, 0, 0, "asdl3234!!!94");
    run_test("", 10, 0, 0, "");
    run_test("    ", 10, 0, 0, "    ");

    // Endptr at first invalid char
    run_test("123abc", 10, 123, 0, "abc");

    // Hex with invalid digits
    run_test("0xzzzzzzzzzzzzzz", 0, 0, 0, "0xzzzzzzzzzzzzzz");

    // Negative octal with invalid digit
    run_test("-0000000008     ", 0, 0, 0, "-0000000008     ");

    // Leading whitespace only
    run_test("   ", 10, 0, 0, "   ");

    // Leading sign only
    run_test("+", 10, 0, 0, "+");
    run_test("-", 10, 0, 0, "-");

    // Valid base 36
    run_test("Z", 36, 35, 0, "");

    // Valid base 2
    run_test("1010", 2, 10, 0, "");

    // Leading zeros
    run_test("00000123", 10, 123, 0, "");

    // Valid input with spaces after number
    run_test("123   ", 10, 123, 0, "   ");

    

    fprintf(stderr, "\nAll tests completed!\n");
    return EXIT_SUCCESS;
}
