#include <omp.h>
#include <stdio.h>

void work(int i, int j, int id) { printf("%d %d for thread: %d\n", i, j, id); }

int main(int argc, char *argv[]) {
  int i, j;
  int n = 10;
  omp_set_num_threads(6);
#pragma omp parallel default(shared)
  {
#pragma omp for collapse(2)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        work(i, j, omp_get_thread_num());
  }
}
