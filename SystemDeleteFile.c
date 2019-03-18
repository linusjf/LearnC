#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
extern int errno;


int main() {
  char *filename = "text.txt";
  if (unlink("text.txt") == -1 && errno == ENOENT) {
    printf("File %s does not exist-%s\n", filename,strerror(errno));
  } else {
    printf("Successfully removed file %s\n", filename);
  }
  return 0;
}
