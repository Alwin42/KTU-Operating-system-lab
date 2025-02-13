#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
	{
	int pid;
	pid=fork();
	if(pid==0){
		printf("exec start \n");
		execl("/bin/ls", "ls" "-1", NULL);
		printf("exec didn't work \n");
		}
		else 
		{
		wait(0);
		printf("parent = ls is completed in child \n");
		}
		return 0;
		}
