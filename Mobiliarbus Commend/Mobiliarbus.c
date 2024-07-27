/************************ Author : Mohamed Ayman ************************/
/************************ Name   : Mobiliarbus.c ************************/
/************************ Date   : 23-7-2024     ************************/
/************************ Version: 0.0.1         ************************/


/******************** [ MOBILIARBUS ---------> MV ] **********************/

#include <stdio.h>    // Include the standard input/output library for printf and perror.
#include <stdlib.h>   // Include the standard library for general functions (e.g., exit).
#include <unistd.h>   // Include the POSIX API for system calls (e.g., rename).
#include <string.h>   // Include the string handling library for string manipulation functions.

void execute_mobiliarbus(char *args) {
    // Function to move (rename) a file from source to destination.

    if (args == NULL) {
        // If no arguments are provided, print usage message and return.
        printf("Usage: mv <source> <destination>\n");
        return;
    }

    // Tokenize the input arguments to separate the source and destination paths.
    char *source = strtok(args, " ");       // Get the first token as the source file path.
    char *destination = strtok(NULL, " ");  // Get the second token as the destination file path.

    if (source == NULL || destination == NULL) {
        // If either source or destination is not provided, print usage message and return.
        printf("Usage: mv <source> <destination>\n");
        return;
    }

    // Attempt to rename (move) the source file to the destination path.
    if (rename(source, destination) != 0) {
        // If rename fails, print an error message with the reason.
        perror("Error moving file");
    }
}

