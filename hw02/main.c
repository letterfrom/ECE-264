// ***
// *** DO NOT modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <stdbool.h>
#define NUMCHAR 256

bool countChar(char * filename, int * counts, int size);
void printCounts(int * counts, int size);
bool addFile(char * filename, int * sum);
bool writeSum(char * filename, int sum);

int main(int argc, char * * argv) {
    if (argc < 3) {
        printf("Usage: %s <char filename> <int filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int charCounts[NUMCHAR] = {0}; // initialize all elements to zero
    if (!countChar(argv[1], charCounts, 256)) {
        printf("Failed to open file for character counting.\n");
        return EXIT_FAILURE;
    }

    printCounts(charCounts, 256);

    int sum = 0;
    if (!addFile(argv[2], &sum)) {
        printf("Failed to open file for integer addition.\n");
        return EXIT_FAILURE;
    }

    if (!writeSum("sum_output.txt", sum)) {
        printf("Failed to write sum to output file.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}