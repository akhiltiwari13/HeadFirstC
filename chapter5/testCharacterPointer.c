#include<stdio.h>
void main()
{
char *testCharacterPointerArray;
testCharacterPointerArray= "Sestarray";
printf("The value testCharacterPointerArray holds is %d\n", testCharacterPointerArray);
int * t= testCharacterPointerArray;
printf("the substituted value is %d\n", t);

printf("the value at the address that our t pointer holds is %c \n", *t);
//now change the character pointer to point to something else

testCharacterPointerArray= "thisisthenewstringthispointsto";
printf("the new value of the character pointer is%s\n", testCharacterPointerArray);

}
