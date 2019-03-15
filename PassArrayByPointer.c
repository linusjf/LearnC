#include <stdio.h>

void multiplyArray2(int factor, int a[],int len, int *result) {
    for (int i = 0; i < len; i++) {
    *(result + i) = factor * a[i];
  }
}
int main() {
  int arr1[] = {1, 2, 3, 4, 5}, factor = 3, *result = arr1;
  printf("Initial Values:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  multiplyArray2(factor, arr1, 5,result);
  printf("Updated Values:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  return 0;
}
