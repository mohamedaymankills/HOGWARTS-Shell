/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : Apparition.c     ************************/
/************************ Date   : 23-7-2024        ************************/
/************************ Version: 0.0.1            ************************/

#include <stdio.h>    // Include the standard input/output library for functions like printf and perror.
#include <string.h>   // Include the string handling library for functions like strlen (not used here but often included for string operations).
#include <stddef.h>   // Include for definitions of size_t and NULL.
#include <unistd.h>   // Include the POSIX API for system calls like chdir.
#include <stdlib.h>   // Include the standard library for general functions such as exit (not used here but often included for memory management).

// Function to change the current working directory.
void execute_apparition(char *path) {
    // Attempt to change the current working directory to the specified path.
    if (chdir(path) != 0) {
        // If chdir fails, print an error message using perror.
        perror("Apparition");
    }
}

