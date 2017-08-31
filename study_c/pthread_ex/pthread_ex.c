/*
 * pthread_ex.c
 *
 *  Created on: Aug 26, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_hello(void *thread_id);

int main(){
  pthread_t thread1, thread2;
  long thread_id1 = 1;
  long thread_id2 = 2;
  long *thread_id1_p = &thread_id1;
  long *thread_id2_p = &thread_id2;
  int rc;

  rc = pthread_create(&thread1, NULL, print_hello, (void *)thread_id1_p);
  if(rc) {
    printf("Error creating thread 1");
    return(-1);
  }
  rc = pthread_create(&thread2, NULL, print_hello, (void *)thread_id2_p);
  if(rc) {
    printf("Error creating thread 2");
    return(-1);
  }

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
}

void *print_hello(void *thread_id) {
  long thread_id_l;

  thread_id_l = *(long *)thread_id;
  printf("Hello from thread %ld\n", thread_id_l);

  pthread_exit(NULL);
}
