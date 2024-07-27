/************************ Author : Mohamed Ayman ************************/
/************************ Name   : Geminio.c     ************************/
/************************ Date   : 23-7-2024     ************************/
/************************ Version: 0.0.1         ************************/


/********************* [ Geminio ------------> CP ] *******************/

// Include the standard I/O library for input and output functions
#include <stdio.h>

// Include the standard library for memory allocation and process control
#include <stdlib.h>

// Include the string library for string manipulation functions
#include <string.h>

// Include the file control library for file operations (e.g., open, read, write)
#include <fcntl.h>

// Include the POSIX operating system API for system calls (e.g., close, read, write)
#include <unistd.h>

// Function to execute the copy (cp) command
// The 'args' parameter is a pointer to a string that contains the source and destination paths
void execute_geminio(char *args) {
    // Check if 'args' is NULL; if so, print usage information and return
    if (args == NULL) {
        printf("Usage: geminio <source> <destination>\n");
        return;
    }

    // Tokenize the 'args' string to extract source and destination file paths
    // char *strtok(char *str, const char *delim);
    // strtok() : functions return a pointer to the next  token, or NULL if there are no more tokens.
    char *source = strtok(args, " ");
    char *destination = strtok(NULL, " ");

    // Check if source or destination paths are missing; if so, print usage information and return
    if (source == NULL || destination == NULL) {
        printf("Usage: geminio <source> <destination>\n");
        return;
    }

    // Open the source file for reading only
    // int open(const char *pathname, int flags);
    int src_fd = open(source, O_RDONLY);
    // Check if the source file was successfully opened
    // failed when src_fd = -1
    if (src_fd < 0) {
        perror("Error opening source file"); // print a system error message
        return;
    }

    // Open the destination file for writing only; create it if it does not exist, truncate it if it does
    // Set file permissions to 0644 (owner can read/write, others can read)
    // O_TRUNC: If the file already exists and is a regular file and the  access mode  allows  writing it will be truncated to length 0.
    int dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // Check if the destination file was successfully opened
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);  // Close the source file descriptor before returning
        return;
    }

    // Buffer to hold data read from the source file
    char buffer[1024];
    ssize_t bytesRead;

    // Read from the source file and write to the destination file in chunks
    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        // Write the read data to the destination file
        if (write(dest_fd, buffer, bytesRead) != bytesRead) {
            // If the number of bytes written does not match the number read, print an error message
            perror("Error writing to destination file");
            close(src_fd);  // Close file descriptors before returning
            close(dest_fd);
            return;
        }
    }

    // If reading from the source file failed, print an error message
    if (bytesRead < 0) {
        perror("Error reading from source file");
    }

    // Close both file descriptors
    close(src_fd);
    close(dest_fd);
}

