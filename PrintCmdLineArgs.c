#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  printf("Display Command Line Arguments\n");
  for (i = 0; i < argc; ++i) {
    printf("Argument %d = \"%s\"\n", i, argv[i]);
  }
  return 0;
}
