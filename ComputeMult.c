#include <stdio.h>

long computeMult(int b, int mult, int r) {
if (mult)
    return computeMult(b, mult - 1, r + b);
return r;
}

int main() {
  int base = 4, mult = 5;
  long int result;
  result = computeMult(base, mult, 0);
  printf("%d multiplied by  %d = %ld\n", base, mult, result);
  return 0;
}
