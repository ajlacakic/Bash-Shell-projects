
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

void ls(int hidden, FILE *output_file) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if ((!hidden && entry->d_name[0] == '.')|| 
            strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue; 
        }
        fprintf(output_file, "%s\n", entry->d_name);
    }

    closedir(dir);
}

void mkdircommand(const char *dir_name, int create_parents) {
    if (create_parents) {
        mkdir(dir_name, 0777); 
    } else {
        mkdir(dir_name, 0777); 
    }
}
void uptime(FILE *output_file) {
    struct timespec uptime;
    if (clock_gettime(CLOCK_BOOTTIME, &uptime) == -1) {
        perror("clock_gettime");
        return;
    }
    fprintf(output_file, "System uptime: %ld seconds\n", uptime.tv_sec);
}

void sl(FILE *output_file) {
    fprintf(output_file, "Choo choo! (Steam locomotive animation)\n");
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [options]\n", argv[0]);
        return 1;
    }
    FILE *output_file = stdout;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], ">") == 0 && i + 1 < argc) {
            output_file = fopen(argv[i + 1], "w");
            if (!output_file) {
                perror("fopen");
                return 1;
            }
            break;
        }
    }

    if (strcmp(argv[1], "ls") == 0) {
        int show_hidden = 0;
        if (argc > 2 && strcmp(argv[2], "-a") == 0) {
            show_hidden = 1;
        }
        ls(show_hidden,output_file);
    } else if (strcmp(argv[1], "mkdir") == 0) {
        if (argc < 3) {
            printf("Usage: %s mkdir directory_name [-p]\n", argv[0]);
            return 1;
        }
        int create_parents = 0;
        if (argc > 3 && strcmp(argv[3], "-p") == 0) {
            create_parents = 1;
        }
        mkdircommand(argv[2], create_parents);
    } else if (strcmp(argv[1], "uptime") == 0) {
        uptime(output_file);
    } else if (strcmp(argv[1], "sl") == 0) {
        sl(output_file);
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }
    if (output_file != stdout) {
        fclose(output_file);  
    }

    return 0;
}
