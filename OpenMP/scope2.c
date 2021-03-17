#include <omp.h>
int main(int argc, char *argv[]) {
  int g[100];
  int r = 0, a = 1, b = 0, i;
#pragma omp parallel for firstprivate(a) private(i) reduction(+ : b) reduction (* : r)
  for (i = 0; i < 100; i++) {
    g[i] = a;
    b = g[i];
    r = g[i];
    (void)r;
  }
  a = b;
  (void)a;
  return 0;
}
