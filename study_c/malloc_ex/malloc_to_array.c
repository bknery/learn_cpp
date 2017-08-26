/*
 * malloc_to_array.c
 *
 *  Created on: Aug 25, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t array_size = 0;
  int get_size = 0;
  int i;
  int element = 0;
  int *array;

  printf("Enter the number of array elements: ");
  scanf("%d", &get_size);

  array_size = get_size;

  array = (int *) calloc(array_size, sizeof(int));
  if(array == NULL) {
    printf("Error allocating memory for the array.\n");
    exit(1);
  }

  printf("Enter the integer elements:\n");
  for(i = 0; i < array_size; i++) {
    printf("array[%d]: ", i);
    scanf("%d", &element);
    array[i] = element;
  }

  printf("\nArray:\n");
  for(i = 0; i < array_size; i++) {
    printf("array[%d] = %d\n", i, array[i]);
  }

  free(array);
}
