#include <omp.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int *g, b = 0, i;
  g = (int *)calloc(10000, sizeof(int));
  for (i = 0; i < 10000; i++)
    g[i] = 1;
omp_set_num_threads(6);
#pragma omp parallel for shared(b)
  for (i = 0; i < 10000; i++) 
    b += g[i];
  printf("%d\n", b);
  b = 0;
#pragma omp parallel for shared(b)
  for (i = 0; i < 10000; i++) {
#pragma omp atomic
    b += g[i];
  }
  printf("%d\n", b);
  return 0;
}
