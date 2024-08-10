/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : tempus.c         ************************/
/************************ Date   : 4-8-2024         ************************/
/************************ Version: 0.0.1            ************************/

#include <stdio.h>     // Include standard I/O functions
#include <stdlib.h>    // Include standard library functions
#include <unistd.h>    // Include POSIX API functions
#include <sys/sysinfo.h> // Include sysinfo() for uptime
#include <fcntl.h>     // Include file control options
#include <string.h>    // Include string manipulation functions

#define STAT_FILE "/proc/stat" // Path to the file containing CPU statistics

void execute_tempus(char *args) {
    struct sysinfo info;
    FILE *stat_file;
    char buffer[256];
    long idle_time = 0;
    long total_time = 0;

    // Retrieve system information
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return;
    }

    // Print system uptime
    printf("System Uptime: %ld days, %ld hours, %ld minutes, %ld seconds\n",
           info.uptime / (24 * 3600),
           (info.uptime % (24 * 3600)) / 3600,
           (info.uptime % 3600) / 60,
           info.uptime % 60);

    // Open /proc/stat to read CPU times
    stat_file = fopen(STAT_FILE, "r");
    if (stat_file == NULL) {
        perror("fopen");
        return;
    }

    // Read the first line of /proc/stat
    if (fgets(buffer, sizeof(buffer), stat_file) != NULL) {
        char *token = strtok(buffer, " ");
        // Skip the "cpu" token
        token = strtok(NULL, " ");
        while (token != NULL) {
            total_time += strtol(token, NULL, 10);
            if (strtok(NULL, " ") == NULL) {
                idle_time = strtol(token, NULL, 10);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(stat_file);

    // Print idle time and total CPU time
    printf("Idle Time: %ld seconds\n", idle_time / sysconf(_SC_CLK_TCK));
}

