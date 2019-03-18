#include <stdio.h>

//Swap function definition
void swap(int *a, int *b)
{
   int t;

   t  = *b;
   *b = *a;
   *a = t;
}



// Converts A[][] to its transpose

int transpose(int A[4][4],int n)
{
    int swapCount = 0;
    for (int i = 0; i < n; i++)

        for (int j = i+1; j < n; j++)
        {
            swap(&A[i][j],&A[j][i]);
            swapCount++;
        }
    return swapCount;
}

int main() {
  int row = 4, col = 4;
  int arr1[4][4] = {{1, 2, 3,4}, { 5, 6,7,8}, {9,10, 11, 12},{13,14,15,16}};
  // display original matrix
  printf("Original\n");
  for (int i = 0; i < row; i++) {
    printf("Row %d: ", i);
    for (int j = 0; j < col; j++) {
      printf("%d ", arr1[i][j]);
    }
    printf("\n");
  }
  // since diagonal elements not to be swapped,
  // only swaps three pairs of elements.
  // works for square matrices only.
  int swapCount =0;
  for (int i = 1; i < row; i++) {
    for (int j = 0; j < i; j++) {
      swap(&arr1[i][j],&arr1[j][i]);
      swapCount++;
    }
  } // display
  // transposed matrix
  printf("Transpose\n");
  for (int i = 0; i < row; i++) {
    printf("Row %d: ", i);
    for (int j = 0; j < col; j++) {
      printf("%d ", arr1[i][j]);
    }
    printf("\n");
  }
  printf("Swap count : %d\n",swapCount);

  swapCount = transpose(arr1,4);

// original  matrix
  printf("Original matrix from Transpose\n");
  for (int i = 0; i < row; i++) {
    printf("Row %d: ", i);
    for (int j = 0; j < col; j++) {
      printf("%d ", arr1[i][j]);
    }
    printf("\n");
  }
  printf("Swap count : %d\n",swapCount);


  return 0;
}
