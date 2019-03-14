#include <stdio.h>

int countDigits(int num, int result) {
  if (num == 0)
    return result;
  return countDigits(num / 10, result + 1);
}

int computeSum(int num, int result) {
  printf("(%d,%d)",num,result);
    if (num == 0)
    {
        if (result!=0 && countDigits(result,0) == 1)
        {
            return result;
        }
        else
            return computeSum(result, 0);
    }
  return computeSum(num / 10, result + num % 10);
}
int main() {
  int number = 98765, result = 0;
  result = computeSum(number, 0);
  printf("\nFinal Sum of digits in %d = %d\n", number, result);
  return 0;
}
