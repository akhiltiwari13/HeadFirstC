// Program to print the memory location of a variable
// author: akhil

#include<stdio.h>

int main ()
{
	int testVariable;
	printf("Please enter a value to store in the testVariable so that it can be defined\n");
	scanf("%d", &testVariable);
	printf("The value of the memory address that has been allocated to the testVariable is %p\n", &testVariable);
	return 0;
}
