#include <omp.h>

#define NUM_THREADS 6

static long num_steps = 100000;
double step;

int main(int argc, char *argv[]) {
  int i;
  double pi = 0.0, sum[NUM_THREADS];
  step = 1.0 / (double)num_steps;
  omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
  {
    int i, id, nthrds;
    double x;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    for (i = id, sum[id] = 0.0; i < num_steps; i = i + nthrds) {
      x = (i + 0.5) * step;
      sum[id] += 4.0 / (1.0 + x * x);
    }
  }
  for (i = 0; i < NUM_THREADS; i++)
    pi += sum[i] * step;
  printf("PI = %f\n", pi);
}
