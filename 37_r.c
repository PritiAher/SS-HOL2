
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char *fifo = "myfifo";
    char message[100];

    // Open FIFO for reading
    int fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read message from FIFO
    read(fd, message, sizeof(message));

    printf("Received message: %s\n", message);

    close(fd);
    return 0;
}

/*
Output :
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./receiver
Received message: priti aher
*/