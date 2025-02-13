#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
void main()
	{
	pid_t cpid;
	if(fork() == 0)
	{
	exit(0);
	}
	else {
	cpid= wait(NULL);
	printf("Parent id = %d \n", getpid());
	printf("Child id = %d \n" , cpid);
	}
	}
