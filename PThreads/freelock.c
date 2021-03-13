#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define P_M_L(x) pthread_mutex_lock(x)
#define P_M_U(x) pthread_mutex_unlock(x)

int num_pthreads = 2;
pthread_mutex_t foo_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t bar_mutex = PTHREAD_MUTEX_INITIALIZER;
int foo = 0, bar = 0;

void foo_bar_inc() {
  P_M_L(&foo_mutex);
  sleep(1);
  P_M_L(&bar_mutex);
  bar = foo++;
  P_M_U(&bar_mutex);
  P_M_U(&foo_mutex);
}

void bar_foo_dec() {
  P_M_L(&bar_mutex);
  while (pthread_mutex_trylock(&foo_mutex)) {
    P_M_U(&bar_mutex);
    sleep(1);
    P_M_L(&bar_mutex);
  }
  foo = bar--;
  P_M_U(&bar_mutex);
  P_M_U(&foo_mutex);
}

void *threadone() {
  bar_foo_dec();
  return NULL;
}

void *threadtwo() {
  foo_bar_inc();
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t thread1;
  pthread_t thread2;

  printf("Freelock example\n");
  pthread_create(&thread1, NULL, threadone, NULL);
  pthread_create(&thread2, NULL, threadtwo, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  printf("Normal exit.\n");
  pthread_exit(NULL);
}
