#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x;
  omp_lock_t lck;
  omp_init_lock(&lck);
  x = 0;
#pragma omp parallel shared(x)
  {
#pragma omp master
    {
      omp_set_lock(&lck);
      x = x + 1;
      (void)x;
      omp_unset_lock(&lck);
    }
#pragma omp single
    {
      omp_set_lock(&lck);
      x = x + 1;
      (void)x;
      omp_unset_lock(&lck);
    }
  }
  printf("%d\n", x);
  omp_destroy_lock(&lck);
}
