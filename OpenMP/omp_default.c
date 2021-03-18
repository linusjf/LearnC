// openmp_using_clausedefault.c
// compile with: /openmp
#include <omp.h>
#include <stdio.h>

int x, y, z[1000];
#pragma omp threadprivate(x)

int main(int argc, char **argv) {
  const int c = 1;
  int i = 0;
  int a;

#pragma omp parallel default(none) private(a) firstprivate(i) shared(z, c, y)
  {
    int j = omp_get_thread_num();
    // O.K.  - j is declared within parallel region
    a = z[j];
    (void)a;
    // O.K.  - a is listed in private clause
    //      - z is listed in shared clause
    x = c;
    // O.K.  - x is threadprivate
    // - c has const-qualified type
    z[i] = y;
    // C3052 error - cannot reference i or y here

#pragma omp for
    for (i = 0; i < 10; i++) {
      z[i] = y;
      // O.K. - i is the loop control variable
      // - y is listed in firstprivate clause
    }
    z[i] = y;
    // Error - cannot reference i or y here
  }
}
