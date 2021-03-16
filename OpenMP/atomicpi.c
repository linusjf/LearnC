#include <omp.h>
#include <stdio.h>
#include <unistd.h>

static long num_steps = 100000;
double step;

int main(int argc, char *argv[]) {
  double pi = 0;
  int cores = sysconf(_SC_NPROCESSORS_ONLN);
  omp_set_num_threads(cores);
  double step = 1.0 / (double)num_steps;
#pragma omp parallel
  {
    int i;
    double sum = 0;
    double aux;
    double x;
    int id = omp_get_thread_num();
    for (i = id; i < num_steps; i += cores) {
      x = (i + 0.5) * step;
      aux = 4.0 / (1.0 + x * x);
      sum += aux;
    }
    sum = sum * step;
#pragma omp atomic
    pi += sum;
  }
  printf("pi = %f\n", pi);
}
