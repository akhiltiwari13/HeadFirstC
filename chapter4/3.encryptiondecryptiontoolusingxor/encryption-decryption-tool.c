//author: akhil
//This program is used to encrypt and decrypt the code read from a source.

#include<stdio.h>
#include"encrypt.h"

void main()
{
	char message[80];
	while(fgets(message, 80, stdin))
	{
		encrypt(message);
		fputs(message,stdout);
	}
}
