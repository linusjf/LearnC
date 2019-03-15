#include <stdio.h>

int main() {
  char *ptr1 = "Hello World";
  char str1[] = "Hello Earth";
  char *ptr2 = str1;
  printf("%s\n", ptr1);
  printf("%s\n", str1);
  printf("%s\n", ptr2);
  ptr1 = ptr2;
  printf("%s\n", ptr1);
  strcpy(ptr1,str1);
 printf("%s\n", ptr1);

return 0;
}
