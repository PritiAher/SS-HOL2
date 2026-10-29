#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Program 1 started.\n");
    printf("PID of Program 1: %d\n", getpid());
    printf("Waiting for SIGSTOP signal...\n");

    while (1) {
        pause();
    }

    return 0;
}

/*
Output:
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ gcc question_64.c -o question64
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question64
Program 1 started.
PID of Program 1: 5200
Waiting for SIGSTOP signal...
*/

