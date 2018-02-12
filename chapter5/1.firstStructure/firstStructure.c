#include<stdio.h>

typedef struct testStructure
{
char *name;
long rollnumber;
short age;
}testStructure;
void main()
{

testStructure test= {.name= "test name",.age=2 };
printf("printing the first structure that i have programmed apparently\n");
printf("name:%s\n", test.name);
printf("roll-number:%li\n", test.rollnumber);
printf("age:%i\n", test.age);

}
