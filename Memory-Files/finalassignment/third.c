#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int fd;

    // Create a file named "permission.txt" with read and write permissions for the user
    fd = open("permission.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

   
    close(fd);

    return 0;
}
