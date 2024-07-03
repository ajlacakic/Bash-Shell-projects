#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>  
#include <unistd.h>
#include <stdlib.h>

int main() {
    int p = fork();
    
    if (p < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (p == 0) {
        printf("Hello from the child process\n");

        char *args[] = {"date", NULL};
        execvp(args[0], args);

        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
       
        if (wait(NULL) == (pid_t)-1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        printf("Goodbye from parent\n");
    }

    return 0;
}

