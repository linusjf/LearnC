/***
 * This program creates a date structure in both packed and unpacked formats.While the packed format saves a byte of memory space,the misalignment of bytes causes a delay in executing both write and read instructions.
 * ***/
#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma pack(push, 1)
typedef struct date {
  unsigned short day : 5;
  unsigned short month : 4;
  unsigned short year : 14;
} DATE;
typedef union {
  DATE date;
  unsigned int intDt : 24;
  unsigned char bytes[3];
} UNION_DATE;
#pragma pack(pop)

typedef struct date1 {
  unsigned short day : 5;
  unsigned short month : 4;
  unsigned short year : 14;
} DATE1;
typedef union {
  DATE1 date;
  unsigned int intDt;
  unsigned char bytes[4];
} UNION_DATE1;

struct timespec diff(struct timespec start,struct timespec end) {
  struct timespec temp;
  if ((end.tv_nsec - start.tv_nsec) < 0) {
    temp.tv_sec = end.tv_sec - start.tv_sec - 1;
    temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;

  } else {
    temp.tv_sec = end.tv_sec - start.tv_sec;
    temp.tv_nsec = end.tv_nsec - start.tv_nsec;
  }
  return temp;
}

int main() {
  printf("Memory size occupied by UNION_DATE: %ld\n", sizeof(UNION_DATE));
  printf("Memory size occupied by DATE: %ld\n", sizeof(DATE));
  printf("Memory size occupied by UNION_DATE1: %ld\n", sizeof(UNION_DATE1));
  printf("Memory size occupied by DATE1: %ld\n", sizeof(DATE1));
  /* localtime example */
  time_t rawtime;
  struct tm *timeinfo;
  struct timespec time1, time2, difference;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
  printf("%s", "\n----Packed version UNION_DATE---- \n");

  UNION_DATE dt;
  dt.date.day = timeinfo->tm_mday;
  dt.date.month = timeinfo->tm_mon + 1;
  dt.date.year = timeinfo->tm_year + 1900;
  printf("\nValue of date: %hd %hd %d\n", dt.date.day, dt.date.month,
         dt.date.year);
  printf("Value of date in hex: %x %x %x\n", dt.date.day, dt.date.month,
         dt.date.year);
  printf("\nValue of date in int format: %d\n", dt.intDt);
  printf("Value of date in hexadecimal format: %x\n", dt.intDt);
  printf("First byte in hexadecimal format: %x\n", dt.bytes[0]);
  printf("Second byte in hexadecimal format: %x\n", dt.bytes[1]);
  printf("Third byte in hexadecimal format: %x\n", dt.bytes[2]);

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
  difference = diff(time1, time2);
  printf("Time taken: %ld:%ld\n", difference.tv_sec, difference.tv_nsec);

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
  printf("%s", "\n----UnPacked version UNION_DATE1----\n");
  UNION_DATE1 dt1;
  dt1.date.day = timeinfo->tm_mday;
  dt1.date.month = timeinfo->tm_mon + 1;
  dt1.date.year = timeinfo->tm_year + 1900;
  printf("\nValue of date: %hd %hd %d\n", dt1.date.day, dt1.date.month,
         dt1.date.year);
  printf("Value of date in hex: %x %x %x\n", dt1.date.day, dt1.date.month,
         dt1.date.year);
  printf("Value of date in int format: %d\n", dt1.intDt);
  printf("Value of date in hexadecimal format: %x\n", dt1.intDt);
  printf("First byte in hexadecimal format: %x\n", dt1.bytes[0]);
  printf("Second byte in hexadecimal format: %x\n", dt1.bytes[1]);
  printf("Third byte in hexadecimal format: %x\n", dt1.bytes[2]);
  printf("Fourth byte in hexadecimal format: %x\n", dt1.bytes[3]);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
  difference = diff(time1, time2);
  printf("Time taken: %ld:%ld\n", difference.tv_sec, difference.tv_nsec);
  return 0;
}
