#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> //holds the signature of the exec() function.

//fork basically clones the current process.

int main(int argc, char* argv[])
{
  char* feeds[]= {"http://rss.cnn.com/rss/edition_world.rss","http://rss.cnn.com/rss/edition_technology.rss"};
  char* phrase[]={"The", "a"};


  char argument_string[200];


  for(int i=0; i<=1; i++)
  {
    sprintf(argument_string, "RSS_FEED=%s", feeds[i]); // This may internally be getting exported when passed as an environment variable in execle
    char* arg_with_null[]={argument_string,NULL};
    pid_t pid=fork();
    if(pid==-1){
      fprintf(stderr, "can fork the program: %s", strerror(errno));
      return 1;
    }

    //execution of child process
    if(!pid)
    {
      if(execle("/usr/bin/python2","/usr/bin/python2", "./rssgossip/rssgossip.py", phrase[i],NULL,arg_with_null)==-1)
      {fprintf(stderr,"can't run script : %s \n",strerror(errno));
      return 1;}
    }

  }
  return 0;
}
