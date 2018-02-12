#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare_ints(const void * num_1,const void * num_2)
{
  int n1= *(int *)num_1;
  int n2= *(int *)num_2;

  return n1-n2;
};

int compare_strings(void * str1, void * str2)
{
  char ** s1= (char **)str1;
  char ** s2= (char **)str2;

  return strcmp(*s1,*s2);
}
