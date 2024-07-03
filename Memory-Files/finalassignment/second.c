#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
mode_t mode=S_IRUSR|S_IWUSR;
int fd=creat("sechello.txt",mode);
if (fd < 0) {
        perror("open");
        return 1;
    }
}
