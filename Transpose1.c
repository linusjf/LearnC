#include <stdio.h>
//Swap function definition
void swap(int *a, int *b)
{
   int t;
   t  = *b;
   *b = *a;
   *a = t;
}
int transpose(int *a,int n)
{
    int swapCount = 0;
    for (int i = 0; i < n; i++)

        for (int j = i+1; j < n; j++)
        {
            swap(a+i*n+j,a+j*n+i);
            swapCount++;
        }
    return swapCount;
}
void ptrArray(int *arr, int row, int col) {
   for (int i = 0; i < row; i++)  {
    printf("Row %d: ", i);
    for (int j = 0; j < col; j++){
       printf("%d ", *(arr + i * row + j));

    }
    printf("\n");

  }
}

 int main() {
   int row = 3, col = 3;
   int arr1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // display original matrix
       printf("Original\n");
   ptrArray(&arr1[0][0], row, col);
    for (int i = 1; i < row; i++)  {
    for (int j = 0; j < i; j++)
       swap(&arr1[i][j],&arr1[j][i]);

  }
    // display transposed matrix
       printf("Transpose\n");
   ptrArray(&arr1[0][0], col, row);

   transpose(&arr1[0][0],row);
   printf("Transposed original\n");
   ptrArray(&arr1[0][0], col, row);

    return 0;
}
