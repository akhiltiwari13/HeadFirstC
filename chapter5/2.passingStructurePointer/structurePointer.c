// program to pass a pointer to a structure to a function and modify the structure.
#include<stdio.h>

typedef struct structname{
	char *name;
	int age;
} animal;

void alterStructure( animal *argument);

void main()
{
	animal hippo= {"alan", 33};
	printf("the name of our hippo is %s\n", hippo.name);
	printf("the age of our hippo is %d\n", hippo.age);
	alterStructure(&hippo);
	printf("the altered age of the animal is %d", hippo.age);


} 

void alterStructure (animal *argument){
printf("the name of the argument structure passed to this function is %s\n", (*argument).name);
(*argument).age++;
}

