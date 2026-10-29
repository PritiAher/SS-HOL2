
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate the key used to create the queue
    key = ftok(".", 'A');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    // Access the existing message queue
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Message Queue ID: %d\n", msgid);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

/*
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ gcc question_46.c -o question46
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question46
Message Queue ID: 0
Message queue removed successfully.
*/