#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <string.h>
char first[100];
int
main ()
{
#if defined __STDC_LIB_EXT1__
    strcpy_s (first, "John");
    printf("%s",first);
#endif
  return 0;
}
