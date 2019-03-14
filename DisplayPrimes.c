#include <stdio.h>
#include <math.h>

int isPrime(int idx) {
  int flag = 0, div = 2;
  int limit = floor(sqrt(idx))+1;
  while (div <= limit) {
    if (idx % div == 0)
    // composite
    {
      flag = 1;
      break;
    }
    div++;
  }
  return flag;
}
int main() {
  int maxVal = 1000, idx = 0, result = 0;
  for (idx = 1; idx <= maxVal; idx++) {
    result = isPrime(idx);
    if (result == 0) // prime
    {
      printf("%d ", idx);
    }
  }
  printf("\n");
  return 0;
}
