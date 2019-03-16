#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *src = "This is one line of text";
  char *dest;
  int len;
  len = strlen(src);
  dest = (char *)malloc(sizeof(src));
  // fill up 'dest'
  strncpy(dest, src, len);
  free(dest);
  // strdup does the same as malloc and strncpy
  dest = strdup(src);
  // not required because 'strncpy' adds a null terminator:
  // dest[len-1] = '\0';
  printf("len:%d\n", len);
  printf("src:%s\n", src);
  printf("dest: %s\n", dest);
  free(dest);
}
