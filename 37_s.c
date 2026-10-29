
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char *fifo = "myfifo";
    char message[100];
    
    // Create FIFO
    mkfifo(fifo, 0666);

    // Open FIFO for writing
    int fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    // Write message to FIFO
    write(fd, message, strlen(message) + 1);

    printf("Message sent successfully.\n");

    close(fd);
    return 0;
}

/*
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./sender
priti aher
Enter message: Message sent successfully.
*/