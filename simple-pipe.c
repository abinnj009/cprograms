#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd[2], nbytes;
	pid_t childpid;
	char string[] = "Hellow world\n";
	char readbuffer[80];

	pipe(fd);

	if((childpid = fork()) == -1)
	{
		perror("Forking failure");
		exit(1);
	}

	if(childpid == 0)
	{	/* child process here */
		/*child closing input side of pipe (read) */
		close(fd[0]);
		
		/*send string through the output (write) side of pipe */
		write(fd[1], string, strlen(string));
		exit(0);
	}
	else
	{
		/* parent here */
		/*closing the output (write)  side of the pipe */
		close(fd[1]);
		
		/* read string from the pipe */
		read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Received the string: %s ", readbuffer);
	}
	return 0;
}
