#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>// holds the definition of exec functions.


// for printing the error during a system call
void error(char * message)
{
	printf("Error Occurred:%s-%s",message,strerror(errno));
	exit(1);//this system call terminates the program with the specified exit status. It saves us from returning a value to main.
}

//opens the url
void open_url(char* url)
{
	if(execlp("firefox", "firefox", url, NULL )==-1)
	{
		error("can't open the URL in the browser");
	}
}
int main( void )
{
	open_url("http://www.youtube.com");
	return 0;
}
