#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
void display_prompt();
void read_input(char* input);
void parse_input(char* input, char** args);
void execute_command(char** args);

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_ARGS];

    while (1) {
        display_prompt();
        read_input(input);
        parse_input(input, args);
        execute_command(args);
    }

    return 0;
}

#include <unistd.h>
#include <limits.h>

void display_prompt() {
    char hostname[HOST_NAME_MAX + 1];
    char username[LOGIN_NAME_MAX + 1];

    
    gethostname(hostname, HOST_NAME_MAX + 1);
    getlogin_r(username, LOGIN_NAME_MAX + 1);

    
    printf("%s@%s:~$ ", hostname, username);
    fflush(stdout); 
}


void read_input(char* input) {
    fgets(input, MAX_INPUT_LENGTH, stdin);
   
    input[strcspn(input, "\n")] = '\0';
}

void parse_input(char* input, char** args) {
    char* token;
    int i = 0;

   
    token = strtok(input, " ");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; 
}

void execute_command(char** args) {
    pid_t pid = fork(); 
    int status;

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        
        if (execvp(args[0], args) == -1) {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        
        do {
            waitpid(pid, &status, WUNTRACED); 
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
