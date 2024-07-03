#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int p1, p2, p3, p4;
    int fd;
    char message1[]="CAT\n";
    char message2[] = "DOG\n";
    char message3[] = "BIRD\n";
    char message4[] = "LION\n";
    char message5[] = "CARACAL\n";

    fd = open("processes.txt", O_TRUNC | O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    p1 = fork();
    if (p1 < 0) {
        perror("Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (p1 == 0) {
       write(fd, message1, sizeof(message1) - 1);
        close(fd);
        exit(EXIT_SUCCESS);
    } else {
        waitpid(p1, NULL, 0);
        p2 = fork();
	if(p2<0){
perror("fork failed");
exit(EXIT_FAILURE);

}
else if(p2==0){
write(fd,message2,sizeof(message2)-1);
close(fd);
exit(EXIT_SUCCESS);

        } else {
            waitpid(p2, NULL, 0);
            p3 = fork();
            if (p3 < 0) {
                perror("Fork failed\n");
                exit(EXIT_FAILURE);
            } else if (p3 == 0) {
                 write(fd, message3, sizeof(message3) - 1);
                close(fd);
                exit(EXIT_SUCCESS);
            } else {
                waitpid(p3, NULL, 0);
                p4 = fork();
                if (p4 < 0) {
                    perror("Fork failed\n");
                    exit(EXIT_FAILURE);
                } else if (p4 == 0) {
                     write(fd, message4, sizeof(message4) - 1);
                    close(fd);
                    exit(EXIT_SUCCESS);
                } else {
                    wait(NULL);
                     write(fd, message5, sizeof(message5) - 1);
                    close(fd);
                    printf("File closed by parent\n");
                }
            }
        }
    }

    return 0;
}

