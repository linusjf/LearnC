/* basic lines for threads */
#define REENTRANT

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <time.h> 

#define THREAD_COUNT 5
void *TestFunc(void *);
/* A global variable */
int globvar;
/* Local zero-based thread index */
long idx[THREAD_COUNT];
/* POSIX Thread IDs */
pthread_t thread_id[THREAD_COUNT]; 

int main() {
  int i, retval;
  pthread_t tid;

  srand(time(NULL));
  globvar = 0;
  printf("Main - globvar=%d\n", globvar);
  for (i = 0; i < THREAD_COUNT; i++) {
    idx[i] = i;
    retval = pthread_create(&tid, NULL, TestFunc, (void *)idx[i]);
    printf("Main - creating i=%d tid=%ld retval=%d\n", i, (long)tid, retval);
    thread_id[i] = tid;
  }
  printf("Main thread - threads started globvar=%d\n", globvar);
  for (i = 0; i < THREAD_COUNT; i++) {
    printf("Main - waiting for join %ld\n", 
        thread_id[i]);
    retval = pthread_join(thread_id[i], NULL);
    printf("Main - back from join %d retval=%d\n", i, retval);
  }
  printf("Main thread - threads completed globvar=%d\n", globvar);
}

void *TestFunc(void *parm) {
  long me, self;

  /* My own assigned thread ordinal */
  me = (long)parm;        
  /* The POSIX Thread library thread number */
  self = pthread_self(); 
  printf("TestFunc me=%ld - self=%ld globvar=%d\n", me, self, globvar);
  int sleep_time = rand() % 11;
  globvar += me + sleep_time;
  printf("TestFunc me=%ld - sleeping globvar=%d\n", me, globvar);
  printf("Sleeping for : %d\n", sleep_time);
  sleep(sleep_time);
  printf("TestFunc me=%ld - done param=%ld globvar=%d\n", me, self, globvar);
  return (void *)me;
}
