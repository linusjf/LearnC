#include <stdio.h>

long computePower(int b, int e, int r) {
if (e)
    return computePower(b, e - 1, r * b);
return r;
}

int main() {
  int base = 4, exp = 5;
  long int result;
  result = computePower(base, exp, 1);
  printf("%d to the power of %d = %ld\n", base, exp, result);
  return 0;
}
