[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19960930&assignment_repo_type=AssignmentRepo)
# Homework 9: Strings to Long Integers

## Introduction

In this assignment, you will implement a function similar to the C standard library function `strtol`, named `string_to_long`. Your implementation must follow the same specification as `strtol`, and correctly convert a string representation of a number to a `long` integer value. We expect you to handle various bases and edge cases appropriately.

It is important that you read the manpage of `strtol`, which you can find by typing `man strtol` in a Linux terminal, or at [this](https://man7.org/linux/man-pages/man3/strtol.3.html) link.

## Function Spec

You will implement the following function

`long string_to_long(const char* string, const char** endptr, int base);`

### Parameter Details

+ `string`: a pointer to the input string. Assume this is not null.
+ `endptr`: a pointer to a `char` pointer storing the address of the first invalid character encountered.
+ `base`: the numerical base of the string representation. Note that if `base` is `0`, the conversion can be performed in base 8, base 16, or base 10. It depends on the first two characters of the input string after the optional +/- sign.
  + If the first character is `'0'` and the next character is not `'x'` or `'X'`, conversion should be done in base 8.
  + If the first two characters are `'0x'` or `'0X'`, conversion should be done in base 16.
  + Otherwise, base is 10.

### Return Value

+ Returns the converted `long` when conversion is successful (even partially).
+ If the conversion fails totally, return 0 and set `endptr` correctly.

Note that in the case that conversion is only completed partially, we still expect `endptr` to be updated appropriately. If conversion is completely successful, `endptr` should point to the null character at the end of `string`.

#### Error Handling

If the base is invalid, the variable `errno` should be set to `EINVAL`. It should be set to `ERANGE` if the conversion of the input string results in underflow/overflow.

### Important Notes

+ Do *NOT* use `strtol` or `atoi` or `stdlib` in your `hw09.c` file.
+ Properly handle leading whitespace, signs ('+' or '-'), and prefixes ('0x' for hex, '0' for octal etc.).
+ `endptr` should point to the first invalid character encountered. We expect you to properly investigate `endptr` behavior exhibited by `strtol` and implement a similar spec.
+ Ensure that your implementation adheres to the behavior of `strtol`, wherever possible.

## Testing Guidelines

We will not be providing test cases to verify your program, but consider the following types of test cases.

- Trivial Cases:
  + Converting simple numbers: e.g. `"42"` in base 10 should return `42`
  + Test with incremental complexity, i.e. single-digit -> double-digit -> ...
- Edge Cases:
  + Smallest and largest possible values (i.e. `LONG_MIN` and `LONG_MAX`)
  + Lowest and highest bases (i.e. `base = 2` and `base = 36`)
- Boundary Cases:
  + Transition between numeric and alphabetic characters
  + Overflow and underflow conditions
- Special Cases & Invalid Input:
  + Base 0: infer base from prefix (`"0x"` for hex, `"0"` for octal)
  + Strings without a valid number
  + Invalid bases
  + Overflow/underflow

### Helper Function

You are encouraged to use a simple test helper function to run your function, and check it against `strtol`.

`void check_string_to_long(const char* string)`

### Coverage

Code coverage testing can help you find bugs in your code by discovering aspects of the functionality that you are not testing. We have included a rule called `coverage` in the Makefile which will help you check how thoroughly you are testing your function.

The method we use is called _line coverage_. It runs the executable `hw09_cov` and monitors which statements in your implementation were executed. It indicates what percentage of your lines were being run, showing you the effectiveness of your testing.

Ideally, you should get output similar to this:
`
Function 'string_to_long':
Lines executed: 100.00% of ..
`

In this assignment, 10% of your credit is dependent on achieving 100% test coverage of the function `string_to_long`. To achieve full credit, you must submit your own `main.c` file with test cases that test each line of code in the function `string_to_long`.

## Provided Files

+ `hw09.h`
+ `hw09.c` 
+ `main.c`
+ `Makefile`

## Submission

*ONLY* submit `hw09.c` and `main.c` to Gradescope.

## Appendix

A few things to keep in mind while writing and testing this assignment:
+ `long` can have different sizes on Windows, Mac, and Linux. Make sure to test your implementation on `eceprog`, so that test cases do not fail because of overflow/underflow discrepancies.
+ You may use `strtol` to verify expected outputs, but *NOT* in your implementation, i.e. `hw09.c`.
+ [Here](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) is a link to learn more about line coverage testing.
