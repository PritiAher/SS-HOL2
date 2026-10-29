#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    if (kill(pid, SIGSTOP) == -1) {
        perror("kill failed");
        return 1;
    }

    printf("SIGSTOP sent to process %d successfully.\n", pid);

    return 0;
}

/*
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ gcc question_73.c -o question73
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question73 5200
SIGSTOP sent to process 5200 successfully.
*/