#include <stdbool.h>
#include <stdio.h>

struct foo1 {
  char *p;
  char c;
  long x;
};
#pragma pack(push, 1)
struct foo1packed {
  char *p;
  char c;
  long x;
};
#pragma pack(pop)


struct foo2 {
  char c;      /* 1 byte */
  char pad[7]; /* 7 bytes */
  char *p;     /* 8 bytes */
  long x;      /* 8 bytes */
};
#pragma pack(push, 1)
struct foo2packed {
  char c;      /* 1 byte */
  char pad[7]; /* 7 bytes */
  char *p;     /* 8 bytes */
  long x;      /* 8 bytes */
};
#pragma pack(pop)


struct foo3 {
  char *p; /* 8 bytes */
  char c;  /* 1 byte */
};
#pragma pack(push, 1)
struct foo3packed {
  char *p; /* 8 bytes */
  char c;  /* 1 byte */
};
#pragma pack(pop)


struct foo4 {
  short s; /* 2 bytes */
  char c;  /* 1 byte */
};
#pragma pack(push, 1)
struct foo4packed  {
  short s; /* 2 bytes */
  char c;  /* 1 byte */
};
#pragma pack(pop)

struct foo5 {
  char c;
  struct foo5_inner {
    char *p;
    short x;

  } inner;
};

#pragma pack(push, 1)
struct foo5packed  {
  char c;
  struct foo5packed_inner {
    char *p;
    short x;

  } inner;
};
#pragma pack(pop)
struct foo6 {
  short s;
  char c;
  int flip : 1;
  int nybble : 4;
  int septet : 7;
};
#pragma pack(push, 1)
struct foo6packed{
  short s;
  char c;
  int flip : 1;
  int nybble : 4;
  int septet : 7;
};
#pragma pack(pop)


struct foo7 {
  int bigfield : 31;
  int littlefield : 1;
};
#pragma pack(push, 1)
struct foo7packed {
  int bigfield : 31;
  int littlefield : 1;
};
#pragma pack(pop)


struct foo8 {
  int bigfield1 : 31;
  int littlefield1 : 1;
  int bigfield2 : 31;
  int littlefield2 : 1;
};
#pragma pack(push, 1)
struct foo8packed {
  int bigfield1 : 31;
  int littlefield1 : 1;
  int bigfield2 : 31;
  int littlefield2 : 1;
};
#pragma pack(pop)

struct foo9 {
  int bigfield1 : 31;
  int bigfield2 : 31;
  int littlefield1 : 1;
  int littlefield2 : 1;
};
#pragma pack(push, 1)
struct foo9packed {
  int bigfield1 : 31;
  int bigfield2 : 31;
  int littlefield1 : 1;
  int littlefield2 : 1;
};
#pragma pack(pop)

struct foo10 {
  char c;
  struct foo10 *p;
  short x;
};
#pragma pack(push, 1)
struct foo10packed {
  char c;
  struct foo10packed *p;
  short x;
};
#pragma pack(pop)

struct foo11 {
  struct foo11 *p;
  short x;
  char c;
};
#pragma pack(push, 1)
struct foo11packed {
  struct foo11packed *p;
  short x;
  char c;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct foo12packed {
  struct foo12packed_inner {
    char *p;
    short x;

  } inner;
  char c;
};
#pragma pack(pop)


struct foo12 {
  struct foo12_inner {
    char *p;
    short x;

  } inner;
  char c;
};

int main(int argc, char *argv[]) {
  printf("sizeof(char *)        = %zu\n", sizeof(char *));
  printf("sizeof(long)          = %zu\n", sizeof(long));
  printf("sizeof(int)           = %zu\n", sizeof(int));
  printf("sizeof(short)         = %zu\n", sizeof(short));
  printf("sizeof(char)          = %zu\n", sizeof(char));
  printf("sizeof(float)         = %zu\n", sizeof(float));
  printf("sizeof(double)        = %zu\n", sizeof(double));
  printf("sizeof(struct foo1)   = %zu\n", sizeof(struct foo1));
  printf("sizeof(struct foo1packed)   = %zu\n", sizeof(struct foo1packed));
  printf("sizeof(struct foo2)   = %zu\n", sizeof(struct foo2));
  printf("sizeof(struct foo2packed)   = %zu\n", sizeof(struct foo2packed));
  printf("sizeof(struct foo3)   = %zu\n", sizeof(struct foo3));
  printf("sizeof(struct foo3packed)   = %zu\n", sizeof(struct foo3packed));
  printf("sizeof(struct foo4)   = %zu\n", sizeof(struct foo4));
  printf("sizeof(struct foo4packed)   = %zu\n", sizeof(struct foo4packed));
  printf("sizeof(struct foo5)   = %zu\n", sizeof(struct foo5));
  printf("sizeof(struct foo5packed)   = %zu\n", sizeof(struct foo5packed));
  printf("sizeof(struct foo6)   = %zu\n", sizeof(struct foo6));
  printf("sizeof(struct foo6packed)   = %zu\n", sizeof(struct foo6packed));
  printf("sizeof(struct foo7)   = %zu\n", sizeof(struct foo7));
  printf("sizeof(struct foo7packed)   = %zu\n", sizeof(struct foo7packed));
  printf("sizeof(struct foo8)   = %zu\n", sizeof(struct foo8));
  printf("sizeof(struct foo8packed)   = %zu\n", sizeof(struct foo8packed));
  printf("sizeof(struct foo9)   = %zu\n", sizeof(struct foo9));
  printf("sizeof(struct foo9packed)   = %zu\n", sizeof(struct foo9packed));
  printf("sizeof(struct foo10)   = %zu\n", sizeof(struct foo10));
  printf("sizeof(struct foo10packed)   = %zu\n", sizeof(struct foo10packed));
  printf("sizeof(struct foo11)   = %zu\n", sizeof(struct foo11));
  printf("sizeof(struct foo11packed)   = %zu\n", sizeof(struct foo11packed));
  printf("sizeof(struct foo12)   = %zu\n", sizeof(struct foo12));
  printf("sizeof(struct foo12packed)   = %zu\n", sizeof(struct foo12packed));
return 0;
}
