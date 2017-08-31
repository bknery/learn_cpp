/*
 * pthread_struct.c
 *
 *  Created on: Aug 26, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 2

typedef struct thread_info_t {
  int id;
  char *name;
  int n_execs;
} thread_info_t;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_hello(void *thread_info) {
  thread_info_t *thread_info_p = (thread_info_t *) thread_info;
  int i = 0;

  pthread_mutex_lock(&mutex);
  for(i = 0; i < thread_info_p->n_execs; i++) {
    printf("\nThread info:\n");
    printf("id: %d\n", thread_info_p->id);
    printf("name: %s\n", thread_info_p->name);
    printf("system id: %d", (int)pthread_self());
  }
  pthread_mutex_unlock(&mutex);

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[N_THREADS];
  thread_info_t threads_info[N_THREADS] = {
      {1, "First Thread", 1},
      {2, "Second Thread", 2}
  };
  int i = 0;

  // create threads
  for(i = 0; i < N_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_hello, (void *)&threads_info[i]);
  }

  // join threads
  for(i = 0; i < N_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

}
