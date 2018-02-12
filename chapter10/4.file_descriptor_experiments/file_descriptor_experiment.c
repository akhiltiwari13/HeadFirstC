#include<stdio.h>
#include<stdlib.h>

void main() //gcc supports the void return type of the main function however it may give a warning.
{
	printf("The file descriptor of STDIN macro is\t%d\n", fileno(stdin));
	printf("The file descriptor of STDOUT macro is\t%d\n", fileno(stdout));
	printf("The file descriptor of STDERR macro is\t%d\n", fileno(stderr));
}
