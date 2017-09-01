/*
 * function_pointers_typedef.c
 *
 *  Created on: 1 de set de 2017
 *      Author: bruno.nery
 */

#include <stdio.h>
#include <stdlib.h>

// function pointer type
typedef int (*fp_compare_t)(int x, int y);

// function prototypes, same signature as function pointer
int compare_greater(int x, int y);

int compare_less(int x, int y);

int main() {
  int x = 2;
  int y = 4;
  int result = 0;

  fp_compare_t fp_compare = &compare_greater;

  printf("Function pointers with typedef\n");

  // first compare greater

  result = (*fp_compare)(x, y);
  printf("Compare greater result = %d\n", result);

  // now change the pointer to compare less
  fp_compare = &compare_less;
  result = (*fp_compare)(x, y);
  printf("Compare greater result = %d\n", result);
}

int compare_greater(int x, int y) {
  if (x > y) {
    return 1;
  } else if (x < y) {
    return -1;
  } else {
    return 0;
  }
}

int compare_less(int x, int y) {
  if (x > y) {
    return -1;
  } else if (x < y) {
    return 1;
  } else {
    return 0;
  }
}
