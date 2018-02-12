// author: akhil
// this source file has a method definition which can be used to encrypt characters by xoring them wiht  a number.

#include"encrypt.h"

void encrypt(char message[])
{
 	while(*message !='\0')
	{
		*message= *message ^ 31;
		message++;
	}	
	
}
