#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv,char**envp)  {
for (char **env = envp; *env != 0; env++)
  {
    char *thisEnv = *env;
   char *envVar =  getenv(thisEnv);
  printf("%s=%s\n",thisEnv, envVar);
  }
  return 0;
}
