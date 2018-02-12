// intro to IPC using waitpid() and dup2().
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h> //holds the signature of the exec() function.
#include <sys/wait.h> // has to be included to used the waitpid() system call.   

void error(char * message)
{
	printf("Error Occurred:%s-%s\n",message,strerror(errno));
	exit(1);
}
//fork basically clones the current process.
int main(void)
{
	char* feeds="http://rss.cnn.com/rss/edition_world.rss";
	char* phrase="The";
	int child_process_status;
	pid_t pid;
	char argument_string[200];
	FILE *file;


	sprintf(argument_string, "RSS_FEED=%s", feeds); // This may internally be getting exported when passed as an environment variable in execle
	char* arg_with_null[]={argument_string,NULL};

	// fork() a child process to execute the rssgossip.py program.
	pid=fork();
	if(pid==-1){
		error("can't fork the program.");
	}

	//execution of child process
	// this piece of code gets executed in the child process only.
	if(!pid)
	{
		// child process opens the news file in the write mode.
		file= fopen("news.txt", "w");  // file option w is of type string and not a char.
		if(!file)
		{
			error("could not open the file news.txt for writing.");
		}

		// this makes stdout point to the data-stream corressponding to the file descriptor of FILE *file.
		if(dup2(fileno(file), 1)==-1)
		{
			error("can't redirect stdout to FILE *file");
		}
		if(execle("/usr/bin/python2","/usr/bin/python2", "./rssgossip/rssgossip.py", phrase,NULL,arg_with_null)==-1)
		{
			error("can't execute rssgossip.py");
		}
	}


	// only the parent needs to wait for the child's execution.
	if(pid)
	{
		if(waitpid(pid, &child_process_status, 0)==-1)
		{
			error("Unable to wait for the child process");
		}
		printf("child process's status: %d\n", WEXITSTATUS(child_process_status));
		printf("child process's signal: %d\n", WIFSIGNALED(child_process_status));
	}
	return 0;
}
