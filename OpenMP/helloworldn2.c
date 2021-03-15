#include <omp.h>

int main(int argc, char *argv[]) {

  int nthreads;
  omp_set_num_threads(4);
  /* Fork a team of threads with each thread having a private tid variable */
#pragma omp parallel
  {
    /* Obtain and print thread id */
    int tid = omp_get_thread_num();
    printf("Hello World from thread = %d\n", tid);

    /* Only master thread does this */
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      printf("Number of threads = %d\n", nthreads);
    }
    /* All threads join master thread and terminate */
  }
}
