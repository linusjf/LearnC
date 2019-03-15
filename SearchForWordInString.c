#include <stdio.h>
#include <string.h>

int main() {
  char *str = "One two Three four";
  char *word1 = "our";
  char *word2 = "Three";
  if ((strstr(str, word1)) != NULL) {
    printf("Current Line: %s\n", str);
    printf("Exact Match:%s\n", word1);
  }
  if ((strstr(str, word2)) != NULL) {
    printf("Current Line: %s\n", str);
    printf("Exact Match:%s\n", word2);
  }

  return 0;
}
