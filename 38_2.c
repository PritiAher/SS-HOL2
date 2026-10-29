
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char msg[100];
    int fd1, fd2;

    // Receive message from Program 1
    fd1 = open("fifo1", O_RDONLY);
    read(fd1, msg, sizeof(msg));
    printf("Program 2 received: %s", msg);
    close(fd1);

    // Send reply to Program 1
    fd2 = open("fifo2", O_WRONLY);

    printf("Program 2: Enter reply: ");
    fgets(msg, sizeof(msg), stdin);
    write(fd2, msg, strlen(msg) + 1);
    close(fd2);

    return 0;
}

/*
Output :
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question38_2
Program 2 received: priti aher
Program 2: Enter reply: Hello Priti
*/