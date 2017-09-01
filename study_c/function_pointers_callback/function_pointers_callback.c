/*
 * function_pointers_callback.c
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

void print_compare(fp_compare_t compare_function, int x, int y);

int main() {
  int x = 2;
  int y = 4;

  printf("Function pointers with callback:\n");

  // first compare greater
  printf("Compare greater:\n");
  print_compare(&compare_greater, x, y);

  // now compare less
  printf("Compare less:\n");
  print_compare(&compare_less, x, y);

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

void print_compare(fp_compare_t compare_function, int x, int y) {
  int result = 0;

  result = (*compare_function)(x, y);
  printf("Compare result = %d\n", result);
}
