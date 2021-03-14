//
// boss/worker pthreads model
// the boss will create threads to handle incoming requests
//
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void task1() { printf("task 1\n"); }

void task2() { printf("task 2\n"); }

void task3() { printf("task 3\n"); }

int main(int argc, const char *argv[]) {
  srand(time(NULL));
  pthread_t thread1 = 0;
  pthread_t thread2 = 0;
  pthread_t thread3 = 0;
  // the manager/boss main thread
  // the manager will create a pool of threads ahead of time to serve
  // the requests .. in this example they are created when a request comes

  int n = 1;
  while (n) {
    // get a request
    n = rand() % 4;
    switch (n) {
    case 1:
      pthread_create(&thread1, NULL, (void *)task1, NULL);
      break;
    case 2:
      pthread_create(&thread2, NULL, (void *)task2, NULL);
      break;
    case 3:
      pthread_create(&thread3, NULL, (void *)task3, NULL);
      break;
    default:
      break;
    }
  }
  if (thread1 != 0)
    pthread_join(thread1, NULL);
  if (thread2 != 0)
    pthread_join(thread2, NULL);
  if (thread3 != 0)
    pthread_join(thread3, NULL);
  printf("done!\n");
  return 0;
}
