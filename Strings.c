#include <stdio.h>
#include <string.h>

int main() {
  char *str = "This is a humongous string. Like it or not.";

  char dest[100];

  char *result = strcpy(dest, str);

  printf("%s\n", result);

  result = strncpy(dest, str, 25);

  printf("%s\n", result);

  int cmp = strcmp(dest, str);

  printf("%d\n", cmp);

  cmp = strncmp(dest, str, 25);
  printf("%d\n", cmp);

  int length = strlen(str);

  printf("%d\n", length);

  result = strcat(dest, str);

  printf("%s\n", result);

  result = strncat(dest, str, 10);

  printf("%s\n", result);

  char *occurence = strchr(dest, 'h');

  printf("%s\n", occurence);

  occurence = strrchr(dest, 'h');

  printf("%s\n", occurence);
  occurence = strstr(dest, "humongous");

  printf("%s\n", occurence);

  char *tokens = strtok(dest, ".");

  while (tokens != NULL) {

    printf("%s\n", tokens);

    tokens = strtok(NULL, ".");
  }

  return 0;
}
