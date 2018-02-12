#include<stdio.h>
#include<stdlib.h>


void main()
{
  puts("enter data");
  char*  data= (char*)malloc(sizeof(char)*20);
  //passing the file descriptor instead of the data stream does not seem to be working for the fsacanf() and fprintf() functions.
  //this is because file descriptor is a number(a regular integer) and data streams are file pointers (FILE *).
  fscanf(stdin,"%19s",data);
  fprintf(stdout, "The data enterd is: %s\n",data );
}
