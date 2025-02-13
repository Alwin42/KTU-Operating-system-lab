#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char file[100];
    struct stat sfile;

    printf("Enter the file path: \n");
    scanf("%s", file);

    
    if (stat(file, &sfile) == -1) {
        perror("Error retrieving file information");
        return EXIT_FAILURE;
    }

    
    printf("st_mode = %o \n", sfile.st_mode & 07777);

    printf("size_id = %ld \n", sfile.st_blksize);

    
    printf("file last accessed in: %s", ctime(&sfile.st_atime));
    
    printf("file last modified in: %s", ctime(&sfile.st_mtime)); 

  
    printf("user_id is: %d \n", sfile.st_uid);

  
    printf("No. of links is: %ld \n", sfile.st_nlink); 

    return EXIT_SUCCESS;
}
