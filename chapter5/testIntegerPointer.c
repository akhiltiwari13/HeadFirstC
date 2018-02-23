#include<stdio.h>
void  main()
{
	int *point;
	int x= 44;
	point= &x;
	printf("the value the pointer holds is %d\n", point);
	printf("the value at the address in the pointer is %d\n", *point);
}
