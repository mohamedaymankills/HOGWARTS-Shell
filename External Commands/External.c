/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : External.c       ************************/
/************************ Date   : 23-7-2024        ************************/
/************************ Version: 0.0.1            ************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "External.h"

/**
 * Executes an external command.
 * 
 * @param command The command to execute.
 * @param args The arguments to pass to the command.
 * 
 * @return The exit status of the command if successful, -1 if an error occurs.
 */
int execute_external(char *command, char *args) {
    // Create a child process
    pid_t pid = fork();

    if (pid == 0) {
        // This block is executed in the child process
        char *argv[100];  // Array to hold command and its arguments
        int argc = 0;     // Argument count

        argv[argc++] = command;  // Set the first argument as the command itself

        // Tokenize the arguments
        char *arg = strtok(args, " ");
        while (arg != NULL) {
            argv[argc++] = arg;  // Add each argument to the argv array
            arg = strtok(NULL, " ");  // Get the next argument
        }
        argv[argc] = NULL;  // Null-terminate the argv array for execvp

        // Execute the command with arguments
        execvp(command, argv);
        // If execvp returns, it means there was an error
        perror("execvp failed");
        exit(1);  // Exit with an error code
    } 
    else if (pid < 0) {
        // If fork fails, print an error message
        perror("fork failed");
        return -1;  // Return -1 to indicate an error
    } 
    else 
    {
        // This block is executed in the parent process
        int status;
        // Wait for the child process to finish
        waitpid(pid, &status, 0);
        // Check if the child process exited normally
        if (WIFEXITED(status)) {
            // Return the exit status of the child process
            return WEXITSTATUS(status);
        } 
        else {
            // If the child process did not exit normally
            return -1;  // Return -1 to indicate an error
        }
    }
}

