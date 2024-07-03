#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

void ls() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

void mkdircommand(const char *dir_name) {
    if (mkdir(dir_name, 0777) == -1) {
        perror("mkdir");
    } else {
        printf("Directory '%s' created successfully.\n", dir_name);
    }
}

void uptime() {
    struct timespec uptime;
    if (clock_gettime(CLOCK_BOOTTIME, &uptime) == -1) {
        perror("clock_gettime");
        return;
    }
    printf("System uptime: %ld seconds\n", uptime.tv_sec);
}

void sl() {
    printf("Displaying steam locomotive animation...\n");
    system("sl");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "ls") == 0) {
        ls();
    } else if (strcmp(argv[1], "mkdir") == 0) {
        if (argc < 3) {
            printf("Usage: %s mkdir directory_name\n", argv[0]);
            return 1;
        }
        mkdircommand(argv[2]);
    } else if (strcmp(argv[1], "uptime") == 0) {
        uptime();
    } else if (strcmp(argv[1], "sl") == 0) {
        sl();
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}

