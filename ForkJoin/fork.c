#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* A global variable */
int globvar;

int main() {
  int pid, status, retval;
  /* A stack variable */
  int stackvar;

  globvar = 1;
  stackvar = 1;
  printf("Main - calling fork globvar=%d stackvar=%d\n", globvar, stackvar);
  pid = fork();
  printf("Main - fork returned pid=%d\n", pid);
  if (pid == 0) {
    printf("Child - globvar=%d stackvar=%d\n", globvar, stackvar);
    sleep(1);
    printf("Child - woke up globvar=%d stackvar=%d\n", globvar, stackvar);
    globvar = 100;
    stackvar = 100;
    printf("Child - modified globvar=%d stackvar=%d\n", globvar, stackvar);
    retval = execl("/data/data/com.termux/files/usr/bin", (char *)NULL,
                   (char *)NULL);
    printf("Child - WHY ARE WE HERE retval=%d\n", retval);
  } else {
    printf("Parent - globvar=%d stackvar=%d\n", globvar, stackvar);
    globvar = 5;
    stackvar = 5;
    printf("Parent - sleeping globvar=%d stackvar=%d\n", globvar, stackvar);
    sleep(2);
    printf("Parent - woke up globvar=%d stackvar=%d\n", globvar, stackvar);
    printf("Parent - waiting for pid=%d\n", pid);
    /* Return code in bits 15-8 */
    retval = wait(&status);
    status = status >> 8;
    printf("Parent - status=%d retval=%d\n", status, retval);
  }
}
