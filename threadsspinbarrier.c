/* basic lines for threads */
#define REENTRANT

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define THREAD_COUNT 5
void *SpinFunc(void *);
/* A global variable */
int globvar;
/* Local zero-based thread index */
long idx[THREAD_COUNT];
/* POSIX Thread IDs */
pthread_t thread_id[THREAD_COUNT];
/* MUTEX data structure */
pthread_mutex_t my_mutex;
// the barrier synchronization object
pthread_barrier_t barrier; 

int main() {
  int i, retval;
  pthread_t tid;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_mutex_init(&my_mutex, NULL);
  // create a barrier object with a count
  pthread_barrier_init (&barrier, NULL,THREAD_COUNT);
  srand(time(NULL));
  globvar = 0;
  printf("Main - globvar=%d\n", globvar);
  for (i = 0; i < THREAD_COUNT; i++) {
    idx[i] = i;
    retval = pthread_create(&tid, NULL, SpinFunc, (void *)idx[i]);
    printf("Main - creating i=%d tid=%ld retval=%d\n", i, (long)tid, retval);
    thread_id[i] = tid;
  }
  printf("Main thread - threads started globvar=%d\n", globvar);
  for (i = 0; i < THREAD_COUNT; i++) {
    printf("Main - waiting for join %ld\n", thread_id[i]);
    retval = pthread_join(thread_id[i], NULL);
    printf("Main - back from join %d retval=%d\n", i, retval);
  }
  printf("Main thread - threads completed globvar=%d\n", globvar);
}

void *SpinFunc(void *parm) {
  long me = (long)parm;
  printf("SpinFunc me=%ld - sleeping %ld seconds ...\n", me, me + 1);
  sleep(me + 1);
  printf("SpinFunc me=%ld  wake globvar=%d...\n", me, globvar);
  pthread_mutex_lock(&my_mutex);
  globvar++;
  pthread_mutex_unlock(&my_mutex);
  printf("SpinFunc me=%ld - spinning globvar=%d...\n", me, globvar);
  pthread_barrier_wait(&barrier);
  printf("SpinFunc me=%ld  done globvar=%d...\n", me, globvar);
  sleep(THREAD_COUNT + 1);
  return (void *)me;
}
