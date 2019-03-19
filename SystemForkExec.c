#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *ls_args[] = {"/bin/ls", "-l",NULL};
  int pid = fork();
  if (pid == 0) // the child
  {
    execv(ls_args[0], ls_args);
  } else if (pid > 0) // the parent
  { // wait for the child to complete
    wait(NULL);
  } else {
    printf("Error: negative process ID\n");
  }
  exit(EXIT_SUCCESS);
}
