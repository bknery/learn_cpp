/*
 * contact.h
 *
 *  Created on: Sep 1, 2017
 *      Author: bknery
 */

#ifndef CONTACT_H_
#define CONTACT_H_

#define CONTACT_MAX_NAME_SIZE 50
#define CONTACT_MAX_PHONE_SIZE 30
#define CONTACT_MAX_ADDR_SIZE 100

typedef struct contact {
  char name[CONTACT_MAX_NAME_SIZE];
  char address[CONTACT_MAX_ADDR_SIZE];
  char phone[CONTACT_MAX_PHONE_SIZE];
} contact_t;

int contact_print(contact_t *contact);

#endif /* CONTACT_H_ */
