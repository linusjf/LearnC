#include <stdio.h>
#include <string.h>
#pragma pack(push,1)
typedef struct date
{
    short day: 5;
    short month: 4;
    short year: 14;
} DATE;
typedef union 
{
    DATE date;
    unsigned int intDt:24;
} UNION_DATE;
#pragma pack(pop)
int main() {
  printf("Memory size occupied by UNION_DATE: %ld\n", sizeof(UNION_DATE));
  printf("Memory size occupied by DATE: %ld\n", sizeof(DATE));
  return 0;
}
