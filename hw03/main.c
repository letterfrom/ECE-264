// Do NOT modify this file

#include "count_words.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }

    char* line = malloc(sizeof *line * LINE_LEN);
    printf("%d", countWord(argv[1], argv[2], line, LINE_LEN));
    free(line);
    return EXIT_SUCCESS;
}