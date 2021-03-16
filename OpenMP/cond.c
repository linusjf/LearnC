#include <omp.h>
#include <stdio.h>

int main(void) {
  // true value
  __attribute__((unused)) int t = 0 == 0;
  // false value
  __attribute__((unused)) int f = 1 == 0;

#pragma omp parallel if (f)
  { printf("FALSE: I am thread %d\n", omp_get_thread_num()); }

#pragma omp parallel if (t)
  { printf("TRUE : I am thread %d\n", omp_get_thread_num()); }

  return 0;
}
