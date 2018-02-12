//author: akhil
//This program is used to encrypt and decrypt the code read from a source.

#include<stdio.h>
#include"encrypt.h"
#include"./checksum.h"

void main()
{
	char message[80];
	while(fgets(message, 80, stdin))
	{
		encrypt(message);
		fprintf(stdout,"Encrypted value is: %s\n",message);
		printf("checksum is: %d\n", checksum(message));
		encrypt(message);
		printf("The message has been decrypted back to: %s\n", message);
		printf("Checksum for decrypted message is: %d\n", checksum(message));
	}
}
