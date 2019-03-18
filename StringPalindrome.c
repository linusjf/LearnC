#include <stdio.h>
#include <string.h>

int scanString(char str[]) {
  int len = strlen(str);
  int i = 0;
  while ( i < len/2 && str[i] == str[len - i - 1])
  {
      i++;
    continue;
}
  return (int)(i == len/2);

}
int main() {
  int result = 0;
  char line1[] = "radar";
  char line2[] = "motion";
  char *results[] = { "NO","YES"};
  result = scanString(line1);
  printf("Current Word: %s\n", line1);
  printf("Palindrome: %s\n", results[result]);
  result = scanString(line2);
  printf("Current Word: %s\n", line2);
  printf("Palindrome: %s\n", results[result]);
  return 0;
}
