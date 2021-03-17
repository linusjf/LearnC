#include <omp.h>
#include <stdio.h>
void work() {
  int i;
  i = 10;
#pragma omp task shared(i)
  {
#pragma omp critical
    printf("In Task, i = %d\n", i);
  }
  /* Use TASKWAIT for synchronization. */
#pragma omp taskwait
}

int main(int argc, char **argv) {
  omp_set_num_threads(8);
  omp_set_dynamic(0);
#pragma omp parallel
  { work(); }
}
