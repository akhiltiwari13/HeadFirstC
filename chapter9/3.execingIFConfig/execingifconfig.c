#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h> //this has the definition of the exec() function.

int main()
{
  if(execlp("ip","ip","a", "s", NULL) == -1);
  printf("Error invoking the execlp system call:->%s\n",strerror(errno) );
  return 0;
}
