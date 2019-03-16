#include <stdio.h>

int main() { // int array with 6 elements
  int arr1[6] = {1, 2, 3, 4, 5, 6};
  int  count = 6;
  printf("Initial:");
  for (int i = 0; i < count; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  for (int i = 0; i < count / 2; i++) {

    arr1[i] = arr1[i]+arr1[count - i - 1];
        arr1[count -i -1]=arr1[i]-arr1[count -i -1];
    arr1[i]=arr1[i]-arr1[count -i -1];

  }
  printf("Reversed: ");
  for (int    i = 0; i < count; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  for (int i = 0; i < count / 2; i++) {

    arr1[i] = arr1[i]^arr1[count - i - 1];
    printf("%d",arr1[i]);
        arr1[count -i -1]=arr1[i]^arr1[count -i -1];
        printf("%d",arr1[count-i-1]);
    arr1[i]=arr1[i]^arr1[count -i -1];
    printf("%d",arr1[i]);

  }
  printf("Original after reversing again: ");
  for (int    i = 0; i < count; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");
  return 0;
}
