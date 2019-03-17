#include <stdbool.h>
#include <stdio.h>

void bubbleSort(int arr[], int n) {
  // Base case
  if (n == 1)
    return;
  bool swapped;
  int temp;
  // One pass of bubble sort. After
  // this pass, the largest element
  // is moved (or bubbled) to end.
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        if (arr[i] > arr[i + 1]) {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
    }
  }
  // Largest element is fixed,
  // recur for remaining array
  if (swapped)
    bubbleSort(arr, n - 1);
}

void bubblesort(int numbers[], int count) {
  bool swapped;
  int temp;
  for (int i = 0; i < count - 1; i++) {
    swapped = false;
    for (int j = i; j < count; j++) {
      if (numbers[i] > numbers[j]) {
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

int main() {
  int numbers[] = {5, 1, 2, 4, 3};
  int nums[] = {5, 1, 2, 4, 3};
  int count = sizeof(numbers)/sizeof(numbers[0]);
  int temp;
  printf("Original: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  bubblesort(numbers, count);
  printf("Sorted: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  bubbleSort(nums, count);
  printf("Sorted: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
