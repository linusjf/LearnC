#include <stdio.h>
#include <stdlib.h>

int main() {
  int rowLengths[] = {6, 4, 3, 5};
  int *jagged[4];
  for (int i = 0; i < 4; ++i) {
    jagged[i] = (int *)malloc(sizeof(int) * rowLengths[i]);
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < rowLengths[i]; ++j) {
      jagged[i][j] = i + j + i * j;
      printf("(%d,%d) = %d    ", i, j, jagged[i][j]);
    }
    printf("\n\n");
  }
    for (int i = 0; i < 4; ++i) {
        printf("Row %d: { ",i+1);
    for (int j = 0; j < rowLengths[i]; ++j) {
      jagged[i][j] = i + j + i * j;
      printf("%d ", jagged[i][j]);
    }
    printf("}\n");
  }return 0;
}
