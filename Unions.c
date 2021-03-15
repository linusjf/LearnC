#include <stdio.h>
#include <string.h>
#pragma pack(push, 1)
typedef union  {
  int i;
  float f;
  char str[10];
} MYDATA;
#pragma pack(pop)

int main() {
  //MYDATA mydata;
  printf("%ld %ld %ld ",sizeof(int),sizeof(float),sizeof(char[10]));
  printf("Memory allocated to mydata: %ld\n", sizeof(MYDATA));
  return 0;
}
