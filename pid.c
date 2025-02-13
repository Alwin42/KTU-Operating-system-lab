#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
	{
	pid_t child_pid;
	child_pid = fork();
	if(child_pid == 0)
	{
		printf("Child created \n");
		printf("Child pid = %d \n parent_pid = %d\n", getpid(),getppid());
		}
	else if(child_pid<0)
	{
		printf("Fork failed");
		return 0;
	}
	else
	{
	wait(NULL);
	printf("Parent created \n");
	printf("Child pid = %d \n parent_pid = %d\n", getpid(),getppid());
	}
}
		
