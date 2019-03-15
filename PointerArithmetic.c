#include <stdio.h>

int arr[] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
 int main() {
   int *arr_ptr = arr;
    while ((*arr_ptr) != 3)++ arr_ptr;
  printf("Number of elements before 3: %ld\n", arr_ptr - arr);
    return (0);
}
