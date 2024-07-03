#include <stdio.h>

#define COLOR_GREEN "\033[92m"
#define COLOR_RESET "\033[0m"

void print_prompt() {
    char *user = "user";
    char *cwd = "/home/user";
    printf("%s%s%s:", COLOR_GREEN, user, COLOR_RESET);
    printf("%s%s%s$ ", COLOR_GREEN, cwd, COLOR_RESET);
}

void execute_command(char *command) {
    printf("Executing: %s\n", command);
}

int main() {
    char user_input[100];
    while (1) {
        print_prompt();
        fgets(user_input, sizeof(user_input), stdin);
        if (strcmp(user_input, "exit\n") == 0) {
            printf("Exiting shell.\n");
            break;
        }
        execute_command(user_input);
    }
    return 0;
}
