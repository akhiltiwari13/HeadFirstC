//author: akhil
//program to check pointer arithmatic and to identify the difference between array variables and pointers.

#include<stdio.h>

void main()
{
	char *pointer= "The String Literal";
	printf("the value of the second letter of the string literal is %c\n", 2[pointer]);
	printf("now if I try to change the value of the string literal I will get a run-time error\n");
//	5[pointer]= 6;
	puts("check if the execution terminates\n");
	puts("getting an input string from the standard input which is the keyboard, using fgets");
	char pointercopy[5] ;
	fgets(pointercopy, 5, stdin);
	puts(pointercopy);
	puts("enter the value to overwrite the existing value of the variable pointercopy");
	scanf("%4s",pointercopy);
	puts("The new value of the pointer is");
	puts( pointercopy);

}
