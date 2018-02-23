//author: akhil
//program to check how string or other arrays for that matter are passed to functions.

#include <stdio.h>

void passthestring(char string[])
{
	printf("The string passed to this function is %s\n", string);
	printf("The size of the string passed to this function is %li bytes\n", sizeof(string));
}

void main()
{
	char string[]= "astonishing";
	char *pointertoelementone= string;
	passthestring(string);
	printf("if i were to print the value of the variable string of the main function then it would be %d\n",sizeof(string));
	printf("if i were to print the value of the size of the pointer that points to the first element of the strng then it would be %d",sizeof(pointertoelementone));
}
