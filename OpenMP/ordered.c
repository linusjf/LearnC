#include <omp.h>
#include <stdio.h>

void work(int k) {
#pragma omp ordered
  printf(" %d", k);
}

int main(int argc, char **argv) {
  omp_set_num_threads(8);
  omp_set_dynamic(0);
  int lb = 0;
  int ub = 10;
  int i;
#pragma omp parallel
  {
#pragma omp for ordered schedule(dynamic)
    for (i = lb; i < ub; i++)
      work(i);
  }
  printf("\n");
}
