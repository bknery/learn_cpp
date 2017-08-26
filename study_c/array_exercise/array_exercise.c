/*
 * array_exercise.c
 *
 *  Created on: Aug 25, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>

static void print_array(int* array, size_t size) {
  int i = 0;
  for(i = 0; i < size; i++) {
    printf("array[%d] = %d\n", i, array[i]);
  }
}

int main() {
  int array[7] = {0, 1, 20, 50, -2, -100, 60};
  int i;

  printf("Array before:\n");
  print_array(array, sizeof(array)/sizeof(array[0]));

  for(i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
    if(array[i] < 0) {
      array[i] = 100;
    }
  }

  printf("Array after:\n");
  print_array(array, sizeof(array)/sizeof(array[0]));

  return 0;

}
