/************************ Author : Mohamed Ayman ************************/
//************************ Name   : grep.c       ************************/
//************************ Date   : 4-8-2024    ************************/
//************************ Version: 0.0.1    ************************/
//****************** [ GREP ---------> grep ] ******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void execute_grep(char *args) {
    char *pattern = strtok(args, " ");
    char *file = strtok(NULL, " ");

    if (pattern == NULL || file == NULL) {
        printf("Usage: grep <pattern> <file>\n");
        return;
    }

    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        char *line = strtok(buffer, "\n");
        while (line != NULL) {
            if (strstr(line, pattern) != NULL) {
                printf("%s\n", line);
            }
            line = strtok(NULL, "\n");
        }
    }

    if (bytesRead < 0) {
        perror("Error reading file");
    }

    close(fd);
}

