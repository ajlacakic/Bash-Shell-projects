#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid = vfork();  

    printf("Parent process PID before if...else block: %d\n", getpid());

    if (pid == 0) {  
        printf("This is the child process and PID is: %d\n", getpid());

      
        execl("/bin/echo", "echo", "Hello from the child process", NULL);

        
        perror("execl");
        _exit(EXIT_FAILURE); 
    } else if (pid > 0) {  
        printf("This is the parent process and PID is: %d\n", getpid());
    } else {
        printf("Error while forking\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

