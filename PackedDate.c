#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma pack(push,1)
typedef struct date
{
    unsigned short day: 5;
    unsigned short month: 4;
    unsigned short year: 7;
} DATE;
typedef union 
{
    DATE date;
    unsigned short shortDt;
    unsigned char bytes[2];
} UNION_DATE;
#pragma pack(pop)
int main() {
  printf("Memory size occupied by UNION_DATE: %ld\n", sizeof(UNION_DATE));
  printf("Memory size occupied by DATE: %ld\n", sizeof(DATE));
  /* localtime example */
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  UNION_DATE dt;
  dt.date.day = (short)timeinfo->tm_mday;
  dt.date.month = timeinfo->tm_mon + 1;
  dt.date.year = timeinfo->tm_year - 100;
  printf("Value of date: %hd %hd %hd\n",dt.date.day,dt.date.month,dt.date.year);
  printf("Value of date in hex: %x %x %x\n",dt.date.day,dt.date.month,dt.date.year);
  printf("Value of date in short int format: %hd\n",dt.shortDt);
  printf("Value of date in hexadecimal format: %x\n",dt.shortDt);
  printf("First byte in hexadecimal format: %x\n",dt.bytes[0]);
  printf("Second byte in hexadecimal format: %x\n",dt.bytes[1]);
  return 0;
}
