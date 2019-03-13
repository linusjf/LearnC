#include <stdio.h>

int main() {
  int max = 5;
  for (int i = 0; i < max; i++) {
    printf("(i,j) : ");
    for (int j = 0; j < max; j++) {
      printf("(%d %d) ", i, j);
    }
    printf("\n");
  }
  return 0;
}
