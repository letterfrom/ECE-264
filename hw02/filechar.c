#include <stdio.h>
#include <stdbool.h>


bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  //
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //

  FILE *fp = fopen(filename, "r");
  
  if (fp == NULL) {
      return false;
  }

  int onechar;
  while ((onechar = fgetc(fp)) != EOF) {
      if (onechar >= 0 && onechar < size) {
          counts[onechar]++;
      }
  }

  fclose(fp);
  return true;
}


void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print

  for (int ind = 0; ind < size; ind++) {
      if (counts[ind] == 0) {
          continue;
      }

      char onechar = ' ';
      if ((ind >= 'a' && ind <= 'z') || (ind >= 'A' && ind <= 'Z')) {
          onechar = (char)ind;
      }

      printf("%d, %c, %d\n", ind, onechar, counts[ind]);
    }
}
