#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    void *shared_memory;
    char buff[100];
    int shmid;

    // Create shared memory segment
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *) -1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    printf("Key of shared memory is %d\n", shmid);
    printf("Process attached at %p\n", shared_memory);

    // Read data from user
    printf("Enter some data to write to shared memory:\n");
    ssize_t bytes_read = read(0, buff, sizeof(buff) - 1);
    if (bytes_read == -1) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    buff[bytes_read] = '\0'; // Null-terminate the string

    // Copy data to shared memory
    strncpy((char *)shared_memory, buff, 1024);
    printf("You wrote: %s\n", (char *)shared_memory);

    // Detach shared memory
    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
