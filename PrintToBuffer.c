#include <stdio.h>

char buffer[200];
char *p = buffer;
char cpBuffer[200]="This is a test atring";
int i, j;
double fp;
char *s = "baltimore";
char c;
int main() {
  c = 'l';
  i = 35;
  fp = 1.7320508;
  // Format and print various data
  j = sprintf(buffer, "%s\n", s);
  j += sprintf(buffer + j, "%c\n", c);
  j += sprintf(buffer + j, "%d\n", i);
  j += sprintf(buffer + j, "%f\n", fp);
  printf("string:\n%s\ncharacter count =%d\n", buffer, j);
  memcpy(buffer,cpBuffer,j);
  printf("memcpy:\n%s\n", buffer);

  int cmp = memcmp(buffer,cpBuffer,j);
   printf("memcmp:\n%s\n%d\n", buffer,cmp);

  p = memchr(buffer, 'a',  j/2);
  printf("memchr:\n%s\n%s\n", buffer,p);

  memset(p,'D',j/2);
  printf("memset:\n%s\n%s\n", buffer,p);

  memmove(p, cpBuffer, j/2);
  printf("memmove:\n%s\n%s\n", buffer,p);

  return (0);
}
