#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]){
char input[100];
int fd;
for (int i = 1; i < argc; i++) {
        strcat(input, argv[i]);
        strcat(input, " ");
    }
fd=open("assignment3.txt", O_WRONLY | O_CREAT,0666);
if(fd==-1){
perror("error opening  file");
exit(1);
}
 if (write(fd, input, strlen(input)) == -1) {
perror("error writing to file");
exit(1);
}
close(fd);
printf("writing was succesful");
return 0;
}
