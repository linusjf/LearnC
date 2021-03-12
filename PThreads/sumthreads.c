#define _REENTRANT
/* basic 3-lines for threads */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREAD 5
void *SumFunc(void *);
/* Threads on this try */
int ThreadCount;
/* A global variable */
double GlobSum;
/* Local zero-based thread index */
long idx[MAX_THREAD];
/* POSIX Thread IDs */
pthread_t thread_id[MAX_THREAD];
/* Thread attributes NULL=use default */
pthread_attr_t attr;
/* MUTEX data structure */
pthread_mutex_t my_mutex;

#define MAX_SIZE 10000000
/* What we are summing... */
double array[MAX_SIZE];

int main() {
  int i;
  pthread_t tid;
  double single, multi;
  struct timespec start, end;

  /* Initialize things */
  for (i = 0; i < MAX_SIZE; i++)
    array[i] = drand48();
  /* Initialize attr with defaults */
  pthread_attr_init(&attr);
  pthread_mutex_init(&my_mutex, NULL);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

  /* Single threaded sum */
  GlobSum = 0;

  clock_gettime(CLOCK_REALTIME, &start);
  for (i = 0; i < MAX_SIZE; i++)
    GlobSum = GlobSum + array[i];
  clock_gettime(CLOCK_REALTIME, &end);
  long seconds = end.tv_sec - start.tv_sec;
  long nanos = seconds * 1000000000 + end.tv_nsec - start.tv_nsec;
  single = (double)(seconds * 1000000000 + nanos) / 1000000000;
  printf("Single sum=%lf time=%lf seconds \n", GlobSum, single);

  /* Use different numbers of threads to accomplish the same thing */
  for (ThreadCount = 2; ThreadCount <= MAX_THREAD; ThreadCount++) {
    printf("Threads=%d\n", ThreadCount);
    GlobSum = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    for (i = 0; i < ThreadCount; i++) {
      idx[i] = i;
      pthread_create(&tid, &attr, SumFunc, (void *)idx[i]);
      thread_id[i] = tid;
    }
    for (i = 0; i < ThreadCount; i++)
      pthread_join(thread_id[i], NULL);
    clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - start.tv_sec;
    long nanos = seconds * 1000000000 + end.tv_nsec - start.tv_nsec;
    multi = (double)(seconds * 1000000000 + nanos) / 1000000000;
    printf("Multi sum=%lf time=%lf seconds\n", GlobSum, multi);
    printf("Efficiency = %lf\n", single / (multi * ThreadCount));
    /* End of the ThreadCount loop */
  }
}

void *SumFunc(void *parm) {
  int i, chunk, start, end;
  double LocSum;

  /* Decide which iterations belong to me */
  long me = (long)parm;
  chunk = MAX_SIZE / ThreadCount;
  start = me * chunk;
  /* C-Style - actual element + 1 */
  end = start + chunk;
  if (me == (ThreadCount - 1))
    end = MAX_SIZE;
  printf("SumFunc me=%ld start=%d end=%d\n", me, start, end);

  /* Compute sum of our subset*/
  LocSum = 0;
  for (i = start; i < end; i++)
    LocSum = LocSum + array[i];

  /* Update the global sum and return to the waiting join */
  pthread_mutex_lock(&my_mutex);
  GlobSum = GlobSum + LocSum;
  pthread_mutex_unlock(&my_mutex);
  return (void *)me;
}
