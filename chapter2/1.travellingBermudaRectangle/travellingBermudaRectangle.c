#include<stdio.h>

void goSoutEast(int *latitude, int *longitude)
{
	*latitude = *latitude -1;
	*longitude= *longitude +1;
}
int main()
{
	int latitude = 32;
	int longitude= 6;
	goSoutEast(&latitude, &longitude);
	printf( "The new coordinates of the ship after the movement are as follows:\n latitude= %i \n longitude= %i \n", latitude, longitude);
	return 0;
}
