#include <stdio.h>
#define MAX 10

int main() {
  char buf[MAX];
  // will pop warning since gets is deprecated in
  // C11. Function definition no longer present in // stdio.h. Use fgets instead.
  gets(buf);
  printf("string is: %s\n", buf);
  return 0;
}
