#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("SIGSEGV caught! Signal number: %d\n", signum);
}

int main() {
    struct sigaction sa; // creates structure to configure signal handling 

    sa.sa_handler = handler; //specifies the function to call when signal arrives 
    sigemptyset(&sa.sa_mask);  //nitializes the signal mask to an empty set, so no additional signals are blocked by this mask while the handler runs.
    sa.sa_flags = 0; 

    sigaction(SIGSEGV, &sa, NULL);  //registers the handler for SIGSEGV. The last NULL means you don't need to save the previous action.

    printf("Raising SIGSEGV...\n");
    raise(SIGSEGV);

    printf("Program continues after handling SIGSEGV.\n");

    return 0;
}

/*
Output:
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ gcc question_61.c -o question61
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question61
Raising SIGSEGV...
SIGSEGV caught! Signal number: 11
Program continues after handling SIGSEGV.
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("\nSIGINT caught! Signal number: %d\n", signum);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C to generate SIGINT.\n");

    while (1) {
        pause();
    }

    return 0;
}

/*
Output:
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ gcc question_61.c -o question61
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question61
Press Ctrl+C to generate SIGINT.
^C
SIGINT caught! Signal number: 2
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("SIGFPE caught! Signal number: %d\n", signum);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    printf("Raising SIGFPE...\n");
    raise(SIGFPE);

    printf("Program continues after handling SIGFPE.\n");

    return 0;
}

/*
Output:
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ gcc question_61.c -o question61
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$ ./question61
Raising SIGFPE...
SIGFPE caught! Signal number: 8
Program continues after handling SIGFPE.
delladmin@dell:~/Desktop/COURSEWORK/SS/Hands-on-2$
*/