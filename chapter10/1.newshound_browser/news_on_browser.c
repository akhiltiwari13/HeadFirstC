#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> //holds the signature of the exec() function.

//prints error message during faliure of a system call.
void error(char * message)
{
	printf("Error Occurred:%s-%s",message,strerror(errno));
	exit(1);
}


//opens the url
void open_url(char* url)
{
	if(execlp("firefox", "firefox", url, NULL )==-1)
	{
		error("can't open the URL in the browser");
	}
}


/*The main function */
int main(void)
{
	char* feed= "http://rss.cnn.com/rss/edition_world.rss";
	char* phrase="The";
	char argument_string[200]; // for passing NULL as the last value, otherwise the "sentinel argument missing error occus" in execle

	// sets up a pipe for inter-process communication.
	int file_des_pipe[2];
	pipe(file_des_pipe);

	sprintf(argument_string, "RSS_FEED=%s", feed); // This may internally be getting exported when passed as an environment variable in execle
	char* arg_with_null[]={argument_string,NULL};
	pid_t pid=fork();

	if(pid==-1){
		error("Can't fork the Program");
	}

	//execution of child process
	if(!pid)
	{
		//close the read pipe for the child and map the stdout wiht the write end of the pipe.
		close(file_des_pipe[0]);
		dup2(file_des_pipe[1],1);

		if(execle("/usr/bin/python2","/usr/bin/python2", "./rssgossip/rssgossip.py","-u", phrase,NULL,arg_with_null)==-1)
		{
			error("Can't run the python script");
		}
	}

	/*Code for the parent process*/
	/*Close the write end of pipe and copy the read end to the stdin*/
	close(file_des_pipe[1]);
	dup2(file_des_pipe[0],0);
	char read[255];
	while(fgets(read,255,stdin))
	{

		if(read[0]=='\t') //checks if the starting character is a tab.
			pid=fork();
		if(!pid)
		{
			//puts(read+1);
			open_url(read + 1);
		}

	}
	return 0;
}
