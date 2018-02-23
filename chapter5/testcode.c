// to test if typedef could be used for aliasing anu datatype and not just structs.
#include<stdio.h>

void main()
{
typedef int aliasint;

aliasint r=33;
r++;
printf("the incremented value is %d", r);
}
