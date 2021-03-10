/* basic lines for threads */
#define REENTRANT

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define THREAD_COUNT 5
void *TestFunc(void *);
/* A global variable */
int globvar;
/* Local zero-based thread index */
long idx[THREAD_COUNT];
pthread_t thread_id[THREAD_COUNT]; /* POSIX Thread IDs */

int main() {
  int i, retval;
  pthread_t tid;

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
  globvar = me + 15;
  printf("TestFunc me=%ld - sleeping globvar=%d\n", me, globvar);
  sleep(2);
  printf("TestFunc me=%ld - done param=%ld globvar=%d\n", me, self, globvar);
  return (void *)me;
}
