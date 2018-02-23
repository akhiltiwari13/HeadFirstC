#include <stdio.h>
#include <limits.h>
#include <float.h>

void main()
{
	puts("i have included 2 new header files in this program\n");
	puts("these are limits.h and floats.h; \t these give the max and min sizes of various data types in c\n");

	fprintf(stdout, "this is the size of INT_MAX: %i\n", INT_MAX);
	fprintf(stdout, "this is the size of INT_MIN: %i\n", INT_MIN);
	fprintf(stdout, "this is the size of LNG_MAX: %ld\n", LONG_MAX);
	fprintf(stdout, "this is the size of LNG_MIN: %ld\n", LONG_MIN);
	fprintf(stdout, "this is the size of SHRT_MAX: %d\n", SHRT_MAX);
	fprintf(stdout, "this is the size of SHRT_MIN: %d\n", SHRT_MIN);
	fprintf(stdout, "this is the size of CHAR_MIN: %c\n", CHAR_MIN);
	fprintf(stdout, "this is the size of CHAR_MAX: %c\n", CHAR_MAX);
	fprintf(stdout, "this is the size of FLT_MAX: %f\n", FLT_MAX);
	fprintf(stdout, "this is the size of FLT_MIN: %f\n", FLT_MIN);
	fprintf(stdout, "this is the size of DBL_MAX: %f\n", DBL_MAX);
	fprintf(stdout, "this is the size of DBL_MIN: %f\n", DBL_MIN);

	puts("fun fact, both of these header files have macros corressponding to the maximum and minimum sizes that the data types can hold");
}
