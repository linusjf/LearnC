#include <stdio.h>
void bin(unsigned n) {

  unsigned i;

  for (i = 1 << 31; i > 0; i = i / 2)

    (n & i) ? printf("1") : printf("0");
}

// Function for multiplication

int multiply(int n, int m) {

  int ans = 0, count = 0;

  while (m)

  {

    // check for set bit and left

    // shift n, count times

    if ((m & 1) == 1) {
//      printf("(%d %d % d %d)", ans, m, n, count);
      //            ans += n << count;
      if (m == 1)// no need to add n to ans now
        ans = ans | (n << count);
      else
        ans = n | ans | (n << count);
   }

    // increment of place value (count)

    count++;

    m = m >> 1;
  }

  return ans;
}

// Driver code

int main() {

  int n = 20, m = 32;
  int ans = multiply(n, m);
  printf("%d\n", ans);
  //bin(n);
 // printf("\n");
//  bin(ans);
  //printf("\n");
  return 0;
}
