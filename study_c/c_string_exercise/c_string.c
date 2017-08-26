/*
 * c_string.c
 *
 *  Created on: Aug 25, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>

static void print_string(char *str) {
  printf("string = %s\n", str);
}

int main() {
  char *str = "Test string";

  // pass string to function
  print_string(str);
}
