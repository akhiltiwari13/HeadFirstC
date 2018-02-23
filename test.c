#include<stdio.h>
#include<string.h>

int teststrdup(char * str)
{
  int len = strdup(str);
  return len;
}
void main()
{
  char * str="AKHIL";
printf("%d\n",teststrdup(str));

}
