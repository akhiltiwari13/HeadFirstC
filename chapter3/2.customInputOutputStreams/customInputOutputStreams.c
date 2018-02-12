//author akhil
//Program to build custom input and output streams for the programs which reads the data from a specified input stream and categorizes them
//Syntax: ./<program-name> <i/p stream> <pattern 1> <o/p stream1> < pattern2> <o/p stream2> <pattern3> <o/p stream3>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argumentcount, char *arguments[])
{
	FILE *in, *opstrm1, *opstrm2, *opstrm3;
	char characterarray[80];

	if(argumentcount != 6)	
	{
		printf("incorrect number of arguments passed: %d", argumentcount);
		return 1;
	}
	if(!(in= fopen("inputfile.txt","r")))	
	{
		printf("The data stream could not be opened-1\n");
		return 1;
	}
	if(!(opstrm1= fopen(arguments[2],"w")))	
	{
		printf("The data stream could not be opened-2\n");
		return 1;
	}
	if(!(opstrm2= fopen(arguments[4],"w")))	
	{
		printf("The data stream could not be opened-3\n");
		return 1;
	}
	if(!(opstrm3= fopen(arguments[5],"w")))	
	{
		printf("The data stream could not be opened-4\n");
		return 1;
	}
	while(fscanf(in,"%79[^\n]\n", characterarray) == 1){
		if(strcasestr(characterarray, arguments[1]))		
		{
			fprintf(opstrm1,"%s", characterarray);
		}
		else
		{
			if(strcasestr(characterarray, arguments[3]))		
			{	
				fprintf(opstrm2,"%s", characterarray);
			}
			else
			{	
				fprintf(opstrm3, "%s",characterarray);
			}

		}
	}
fclose(in);
fclose(opstrm1);
fclose(opstrm2);
fclose(opstrm3);
	return 0;
}					




