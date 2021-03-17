#include <omp.h>
#include <stdio.h>

#define THRESHOLD 5

int fib(int n) {
  int i, j;

  if (n < 2)
    return n;

#pragma omp task shared(i) firstprivate(n) final(n <= THRESHOLD)
  i = fib(n - 1);

#pragma omp task shared(j) firstprivate(n) final(n <= THRESHOLD)
  j = fib(n - 2);

#pragma omp taskwait
  return i + j;
}

int main(int argc, char *argv[]) {
  int n = 30;
  omp_set_dynamic(0);
  omp_set_num_threads(4);

#pragma omp parallel shared(n)
  {
#pragma omp single
    printf("fib(%d) = %d\n", n, fib(n));
  }
}
