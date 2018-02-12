#include<stdio.h>
#include<stdlib.h>

int compare_ints(void * num_1, void * num_2);
int compare_strings(void * str1, void * str2);

int main()
{
  int numbers[]={22, 343, 564, 3, 345, 234};
  qsort(numbers, 6, sizeof(int), &compare_ints);

  puts("------------------------");
  puts("Sorted Values are as:-");
  puts("------------------------");

  for(int i=0; i<6; i++)
  printf("%d\n",numbers[i] );

  char * str_arr[]={"akhil", "alok", "aditya", "ayush", "don", "merideth", "catlyn"};
  qsort(str_arr, 7, sizeof(char *), &compare_strings);

  puts("------------------------");
  puts("Sorted Values are as:-");
  puts("------------------------");

  for(int i=0; i<7; i++)
  printf("%s\n",str_arr[i] );



  return 0;
}
