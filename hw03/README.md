[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/h1J1P4SO)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19848223&assignment_repo_type=AssignmentRepo)
# Count Words in File

Deadline: 2/7/2025

Late: 2/12/2025

Learning Goals 
==============

This assignment asks you to write a program that reads lines from a file,
counts the frequency of a given word, and reports the result.

You will learn to
* Read and store lines as strings
* Check if one string is inside another

Read Lines from File and Count Words
===================================

This assignment uses `fgets` to read strings from a file and
`strstr` to find whether a word is inside the string.
This assignment is a simplified version of the `grep` command in
Linux.

What To Do
==========

You need to write a function called `int countWord(char* filename, char* word, char* line, int size)` 
that opens a file named `filename`, counts the frequency of a given word in the file,
and returns it. If `fopen()` fails, return -1 and **DO NOT** call `fclose()`.
Further instructions are in the comments in `count_words.c`.

WHAT TO SUBMIT
==============

Please submit **ONLY** the `count_words.c` file to Gradescope by 2/7/2025.

Test Inputs
===========

Nine test cases have been provided. You can test individual testcases using `make test#` or the entire suite using `make testall`.