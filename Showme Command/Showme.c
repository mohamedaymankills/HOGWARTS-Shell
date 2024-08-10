/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : showme.c         ************************/
/************************ Date   : 4-8-2024         ************************/
/************************ Version: 0.0.1            ************************/

#include <stdio.h>    // Include standard input/output functions
#include <stdlib.h>   // Include standard library functions
#include <sys/sysinfo.h> // Include for sysinfo() function

void execute_showme(char *args) {
    struct sysinfo info;

    // Retrieve system information
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return;
    }

    // Print RAM information
    printf("RAM Information:\n");
    printf("Total RAM: %ld MB\n", info.totalram * info.mem_unit / (1024 * 1024));
    printf("Free RAM: %ld MB\n", info.freeram * info.mem_unit / (1024 * 1024));
    printf("Used RAM: %ld MB\n", (info.totalram - info.freeram) * info.mem_unit / (1024 * 1024));

    // Print Swap area information
    printf("\nSwap Information:\n");
    printf("Total Swap: %ld MB\n", info.totalswap * info.mem_unit / (1024 * 1024));
    printf("Free Swap: %ld MB\n", info.freeswap * info.mem_unit / (1024 * 1024));
    printf("Used Swap: %ld MB\n", (info.totalswap - info.freeswap) * info.mem_unit / (1024 * 1024));
}

