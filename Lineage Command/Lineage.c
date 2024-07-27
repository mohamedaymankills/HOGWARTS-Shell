/************************ Author : Mohamed Ayman ************************/
/************************ Name   : Lineage.c     ************************/
/************************ Date   : 23-7-2024     ************************/
/************************ Version: 0.0.1         ************************/


/***************** [ Lineage ---------> PWD ]  *****************/

// Include standard I/O library for input and output functions
#include <stdio.h>

// Include unistd.h for POSIX operating system API, including getcwd function
#include <unistd.h>

// Function to execute and display the current working directory
void execute_lineage() {

    // Define a buffer to store the current working directory path
    char cwd[1024];

    // Get the current working directory and store it in the buffer
    // char *getcwd(char *buf, size_t size);
    // getcwd() returns a pointer to the buffer if successful, or NULL if an error occurs
    
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        // Print the current working directory to standard output
        printf("%s\n", cwd);
    } else {
        // Print an error message to standard error if getcwd() fails
        perror("getcwd() error");
    }
}

