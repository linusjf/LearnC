#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *src = "This Is A Line";
  char *lower, *upper, *chr;
  int len;
  len = strlen(src);
 lower = (char *)malloc(sizeof(char)*len);
  strncpy(lower, src, len+1);

  upper = (char *)malloc(sizeof(char)*len);
  strncpy(upper, src, len+1);

 for (int i = 0; i < len; ++i) {
    *(lower + i) = tolower(src[i]);
    *(upper + i) = toupper(src[i]);
  }
  printf("Original: %s\n", src);
  printf("Upper:%s\n", upper);
  printf("Lower:%s\n", lower);
}
