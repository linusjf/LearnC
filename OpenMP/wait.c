#include <omp.h>
#include <stdio.h>

int main(int argc, char **argv) {
  omp_set_num_threads(6);
  omp_set_dynamic(0);
  int j = 100;
#pragma omp parallel shared(j)
  {
#pragma omp sections firstprivate(j)
    {
#pragma omp section
      {
#pragma omp task shared(j)
        {
#pragma omp critical
          printf("In Task, j = %d\n", j);
        }
/* Use TASKWAIT for synchronization. */
#pragma omp taskwait
      }
    }
  }
  printf("After parallel, j = %d\n", j);
}
