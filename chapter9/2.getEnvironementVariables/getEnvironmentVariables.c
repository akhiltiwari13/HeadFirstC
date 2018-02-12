#include<stdio.h>
#include<stdlib.h>

int main ()
{
  printf("The value of the PATH environment variable is%s", getenv("PATH"));
  return 0;
}
