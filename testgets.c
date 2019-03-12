#include <stdio.h>
#define MAX 10
int main() {
  char buf[MAX];
  gets(buf);
  printf("string is: %s\n", buf);
  return 0;
}
