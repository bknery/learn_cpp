/*
 * contact_list.c
 *
 *  Created on: Sep 1, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"

int main() {
  // array of pointers to struct
  contact_t **contact_array = NULL;
  int i = 0;
  int j = 0;
  contact_t temp_contact;

  printf("Usage: follow the instructions. When done, write: exit\n");

  while(1) {

    printf("\nEnter the contact name: ");
    fgets(temp_contact.name, CONTACT_MAX_NAME_SIZE, stdin);
    // Remove trailing newline
    temp_contact.name[strlen(temp_contact.name) - 1] = '\0';
    if (strcmp(temp_contact.name, "exit") == 0) {
      break;
    }

    printf("Enter the contact phone: ");
    fgets(temp_contact.phone, CONTACT_MAX_PHONE_SIZE, stdin);
    // Remove trailing newline
    temp_contact.phone[strlen(temp_contact.phone) - 1] = '\0';
    if (strcmp(temp_contact.phone, "exit") == 0) {
      break;
    }

    printf("Enter the contact address: ");
    fgets(temp_contact.address, CONTACT_MAX_ADDR_SIZE, stdin);
    // Remove trailing newline
    temp_contact.address[strlen(temp_contact.address) - 1] = '\0';
    if(strcmp(temp_contact.address, "exit") == 0) {
      break;
    }

    if(contact_array == NULL) {
      // first contact
      contact_array = malloc(sizeof(contact_t *));
      if(contact_array == NULL) {
        printf("ERROR allocating memory\n");
        return(-1);
      }
    } else {
      // not the first contact: realloc
      contact_array = realloc(contact_array, (i + 1) * sizeof(contact_t *));
      if(contact_array == NULL) {
        printf("ERROR reallocating memory\n");
        return(-1);
      }
    }

    contact_array[i] = malloc(sizeof(contact_t));
    if(contact_array[i] == NULL) {
      printf("ERROR allocating memory array[i]\n");
      return(-1);
    }

    // fill the array
    strcpy(contact_array[i]->name, temp_contact.name);
    strcpy(contact_array[i]->phone, temp_contact.phone);
    strcpy(contact_array[i]->address, temp_contact.address);

    i++;
  }

  if (contact_array == NULL) {
    printf("Empty contact list\n");
    return(0);
  }

  // print the array
  printf("\n\nContacts:\n\n");

  for (j = 0; j < i; j++) {
    contact_print(contact_array[j]);
    printf("\n");
  }

  // free memory
  for (j = 0; j < i; j++) {
    free(contact_array[j]);
  }
  free(contact_array);

  return(0);
}
