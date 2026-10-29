
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok(".", 'A');

    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue
    msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Message Queue Key: %d\n", (int)key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ gcc question_41.c -o question41
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question41
Message Queue Key: 1090862868
Message Queue ID: 0
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2

*/