#include <omp.h>
#include <stdio.h>

void get_float(float *tmp) { *tmp = 100; }

float read_next() {
  float *tmp;
  float return_val;

#pragma omp single copyprivate(tmp)
  { tmp = (float *)malloc(sizeof(float)); }

#pragma omp master
  { get_float(tmp); }

#pragma omp barrier
  return_val = *tmp;
#pragma omp barrier

#pragma omp single
  { free(tmp); }

  return return_val;
}

int main(int argc, char **argv) { printf("%f\n", read_next()); }
