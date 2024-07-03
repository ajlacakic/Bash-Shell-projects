#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int fd = open("hello.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    
    close(fd);

    return 0;
}

