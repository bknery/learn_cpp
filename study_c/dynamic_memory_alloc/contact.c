/*
 * contact.c
 *
 *  Created on: Sep 1, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>

#include "contact.h"

int contact_print(contact_t *contact) {
  if(contact == NULL) {
    printf("ERROR: invalid contact\n");
    return -1;
  }
  printf("Name: %s\n", contact->name);
  printf("Phone: %s\n", contact->phone);
  printf("Address: %s\n", contact->address);

  return 0;
}
