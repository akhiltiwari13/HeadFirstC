// author-akhil
// Program to store music tracks and to retrieve them

#include<stdio.h>
#include<string.h>

char playlist[][79] = { "One Love", "The way I am", "Summer of '69", "With or Without You"};

void searchstring( char *searchpattern)
{
	int loop=0;
	for(loop=0; loop<4; loop++)
	{
		if(strcasestr(playlist[loop], searchpattern))
		{			printf("The first match has been found and the track is:--> %s\n",playlist[loop]);}
	}
}

void main()
{
	puts("Enter Track to search");
	char pattern[80];
	scanf("%79s",pattern);
	searchstring(pattern);

	//	puts(playlist[4][0]);
	//	puts(playlist[0][1]);	

	//due to some reason the puts function does not properly work for the 2 dimensional array therefore I had to resort to the printf functions.
	/*	printf("%s", playlist[2]);
		printf("%s", playlist[1][7]);*/

}
