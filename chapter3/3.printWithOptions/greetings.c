#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char main(int argumentcount, char* arguments[])
{
	char *salamperson;
	char option;

	while((option = getopt(argumentcount, arguments, "hns:"))!= EOF)
	{		printf("the value of option is= %c\n",option);
		switch (option)
		{
			case 'h':
				printf("hello\t ");
				break;

			case 'n':
				printf("namaste\t");
				break;

			case 's':
				salamperson= optarg;
				printf("salam\t%s",salamperson);
				break;

			default:
				fprintf(stderr,"SYNTAX: ./greetings [hns:] <your name>");
				return 'f';

		}
		argumentcount -= optind;
		arguments+= optind;
		printf("optind value %d", optind);
	}	
	if(argumentcount != 1)
	{printf("incorrect number of arguments passed to the program, expected argument count = 1 found argument count = %d", argumentcount);
		return 'f';}
	printf("%s",arguments[0]);
	return 's';}
