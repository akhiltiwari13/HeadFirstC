#include<stdio.h>
#include<stdarg.h>

void print_ints(int count, ...)
{
  va_list list_of_arguments;
  va_start(list_of_arguments, count);
  for(int i=0; i<count; i++)
  printf("%d\n",va_arg(list_of_arguments, int) );
  va_end(list_of_arguments);
}

int main()
{
  print_ints(6, 122, 44, 413443, 0, 601, 345);
  return 0;
}
