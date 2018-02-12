// author akhil
//program to convert the format of the geolocation data to json format.

#include<stdio.h>

int main()
{
	int applycomma = 0;
	float latitude;
	float longitude;
	char info[80];

	puts("data= [");
	while(scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3)
	{
		if(applycomma)
			puts(",\n");
		else
		applycomma = 1;
		if(latitude<-90 ||latitude > 90)
		{
			fprintf(stderr,"latitude has an incorrect value: %f", latitude);
			return 2;
		}
		if(longitude<-180 || longitude > 180)
		{
			fprintf(stderr, "longitude has an incorrect value: %f", longitude);
			return 2;
		}
		printf("{latitude: %f, longitude: %f,info: %s}", latitude, longitude, info);
	
	}
	puts("\n]");
	return 0;
}
