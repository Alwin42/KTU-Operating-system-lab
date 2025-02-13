#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
struct dirent *dptr;
	int main(int arge, char * argv[])
	{
	char buff[256];
	DIR *dirp;
	printf("\n Enter directory name ");
	scanf("%s", buff);
	dirp=opendir(buff);
	if(dirp == NULL)
	{
		printf("Error \n");
		exit(0);
	}
	while(dptr = readdir(dirp))
	{
		printf("%s \n", dptr->d_name);
	}
	closedir(dirp);
	printf("Parent process successfully created \n");
	printf(" child_pid= %d \n parent_pid = %d \n", getpid() , getppid());
	}

