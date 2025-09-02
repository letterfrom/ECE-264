// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  // You may initialize the elements to a number of your choice (e.g., 0)
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }

  int remain = n;
  int index = 0;
  int count = 0;

  
  // counting to k,
  // mark the eliminated element; you choose the mark (e.g., 1)
  // print the index of the marked element
  // repeat until only one element is unmarked
  while (remain > 1)
  {
    if (arr[index] == 0)
    {
      count++;

      if (count == k)
      {
        arr[index] = 1;
        printf("%d\n", index);
        remain--;
        count = 0; // reset count
      }
    }
    
    index = (index + 1) % n;
  }



  // print the last remaining index

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      printf("%d\n", i);
    }
  }


  // release the memory of the array
  free (arr);
}

