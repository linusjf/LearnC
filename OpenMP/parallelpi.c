#include <omp.h>
#include <unistd.h>

static long num_steps = 100000;
double step;

int main(int argc, char *argv[]) {
  int i;
  int nthrds = sysconf(_SC_NPROCESSORS_ONLN);
  printf("Number of cores online: %d\n", nthrds);
  double pi = 0.0, sum[nthrds];
  step = 1.0 / (double)num_steps;
  omp_set_num_threads(nthrds);
#pragma omp parallel
  {
    int i, id;
    double x;
    id = omp_get_thread_num();
    for (i = id, sum[id] = 0.0; i < num_steps; i += nthrds) {
      x = (i + 0.5) * step;
      sum[id] += 4.0 / (1.0 + x * x);
    }
  }
  for (i = 0; i < nthrds; i++)
    pi += sum[i] * step;
  printf("PI = %f\n", pi);
}
