#include <stdio.h>

int main() {
   char *list[] = {"add", "bear", "cask", "doting", NULL};
    for (char **ptr = list; *ptr != NULL; ptr++) {
    printf("array item: %s\n", ptr[0]);

  }
  return 0;
}
