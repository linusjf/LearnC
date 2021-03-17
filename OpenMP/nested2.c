#include <omp.h>
#include <stdio.h>

#define DEPTH 5

void report_num_threads(int level) {
#pragma omp single
  {
    printf("Level %d: number of threads in the team - %d\n", level,
           omp_get_num_threads());
  }
}

void nested(int depth) {
  if (depth == DEPTH)
    return;
#pragma omp parallel num_threads(2)
  {
    report_num_threads(depth);
    nested(depth + 1);
  }
}

int main(int argc, char *argv[]) {
  omp_set_dynamic(0);
  omp_set_nested(1);
  nested(1);
  return (0);
}
