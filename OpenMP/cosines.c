#include <math.h>
#include <omp.h>
#include <stdio.h>

#define N 1000000

int main(int argc, char *argv[]) {
  int nthreads = omp_get_max_threads();
  for (int j = 1; j <= nthreads; j++) {
    omp_set_num_threads(j);
    double sum = 0;
    double tbegin = omp_get_wtime();
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < N; i++)
      sum += cos(i);
    double wtime = omp_get_wtime() - tbegin;
    printf("Computing %d cosines and summing them with %d threads took %fs\n",
           N, j, wtime);
  }
  return 0;
}
