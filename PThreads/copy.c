#include "pthread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* state > 0, multiple readers; state = 0, free */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
int start = 0;
int count = 0;

void *display(int *max_iterations) {
  struct timespec now;
  int iterations = 0;

  now.tv_nsec = 0;
  now.tv_sec = time(NULL) + 1;
  pthread_mutex_lock(&mutex);
  pthread_cond_timedwait(&cond2, &mutex, &now);

  pthread_cond_signal(&cond1);

  count = 0;
  do {
    start++;
    now.tv_nsec += 100000000;
    if (now.tv_nsec == 1000000000) {
      now.tv_nsec = 0;
      now.tv_sec++;
    }
    pthread_cond_timedwait(&cond2, &mutex, &now);
    printf("Copied 4096B %d times during the last .1 second\n", count);
  } while (iterations++ < *max_iterations);
  pthread_mutex_unlock(&mutex);

  exit(0);
}

int main(int argc, char *argv[]) {
  struct sched_param sparam;
  int max_iterations = 10;
  pthread_t thread;
  char from[4096];
  char to[4096];

  pthread_setschedparam(pthread_self(), SCHED_FIFO, NULL);

  pthread_create(&thread, NULL, (void *)display, &max_iterations);
  sparam.sched_priority = sched_get_priority_max(SCHED_FIFO);
  pthread_setschedparam(thread, SCHED_FIFO, &sparam);

  pthread_mutex_lock(&mutex);
  while (start == 0)
    pthread_cond_wait(&cond1, &mutex);
  pthread_mutex_unlock(&mutex);

  while (1) {
    memcpy(to, from, 4096);
    pthread_mutex_lock(&mutex);
    count++;
    pthread_mutex_unlock(&mutex);
  }
}
