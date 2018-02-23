#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


char* get_time()
{
  time_t t; // this could be like pid_t, an alias which could be of different data types depending on the environment.
  time(&t);
  return asctime(localtime(&t));
}
int main()
{
  char* comment;
  char* cmd;
  char * env= getenv("LD_LIBRARY_PATH");
  printf("LD_LIBRARY_PATH %s\n",env );

  puts("comment:");
  comment=(char*)malloc(sizeof(char)*80);
  fgets(comment, 80, stdin);

  cmd=(char*)malloc(sizeof(char)*120);
  sprintf(cmd, "echo '%s %s'>>logs.log", get_time(), comment);

  //puts(env);
  system(cmd);
  puts("checks if the parent process still exits after the \"system\" system-call");
  return 0;
}
