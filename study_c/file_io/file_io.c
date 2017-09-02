/*
 * file_io.c
 *
 *  Created on: Sep 2, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1000

int main() {
  char str[MAX_LINE_SIZE];
  FILE *fp1;
  FILE *fp2;
  const char* file1_name = "/tmp/file1.txt";
  const char* file2_name = "/tmp/file2.txt";

  // check if file1 exists
  fp1 = fopen(file1_name, "r");
  if (fp1 == NULL) {
    fprintf(stderr, "Error opening %s\n", file1_name);
    return(-1);
  }

  // open file2 for writing
  fp2 = fopen(file2_name, "w");
  if (fp1 == NULL) {
    fprintf(stderr, "Error opening %s for writing\n", file1_name);
    return(-1);
  }

  // read file1 line by line and write to file2
  printf("Copying %s to %s ...\n", file1_name, file2_name);
  printf("File content:\n");
  while(fgets(str, MAX_LINE_SIZE, fp1) != NULL) {
    printf("%s", str);
    fprintf(fp2, "%s", str);
  }

  printf("\nCopy operation finished successfully.\n");
  return(0);
}
