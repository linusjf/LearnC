#include <stdio.h>

static long num_steps = 100000;
double step;
double sum = 0;
double aux;

int main(int argc, char *argv[]) {
  int i;
  double x, pi, sum = 0.0;
  step = 1.0 / (double)num_steps;
#pragma omp parallel private(i, aux, x) shared(sum)
  {
#pragma omp for reduction(+ : sum) schedule(static)
    for (i = 0; i < num_steps; i++) {
      x = (i + 0.5) * step;
      aux = 4.0 / (1.0 + x * x);
      sum += aux;
    }
  }
  pi = step * sum;
  printf("pi = %f\n", pi);
}
