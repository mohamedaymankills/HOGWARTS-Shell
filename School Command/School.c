/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : School.c         ************************/
/************************ Date   : 23-7-2024        ************************/
/************************ Version: 0.0.1            ************************/

#include <stdio.h>    // Include the standard input/output library for printf.
#include <stdlib.h>   // Include the standard library for general functions such as getenv and strdup.
#include <string.h>   // Include the string handling library for functions like strcmp and strtok.
#include <unistd.h>   // Include the POSIX API for system calls like access.
#include "School.h"   // Include the header file for the School command.

// List of internal commands
const char *internal_commands[] = {
    "lineage", "mirror", "apparition", "mobiliarbus", "geminio", "school", "revelio", "voldemort", "diary", NULL
    // Array of known internal commands, ending with a NULL pointer.
};

// Function to check if a command is internal
int internal_command(const char *command) {
    for (int i = 0; internal_commands[i] != NULL; i++) {
        // Compare each internal command with the given command.
        if (strcmp(command, internal_commands[i]) == 0) {
            return 1;  // Return 1 if the command is found in the internal commands list.
        }
    }
    return 0;  // Return 0 if the command is not found in the internal commands list.
}

void execute_school(char *args) {
    if (args == NULL) {
        // If no arguments are provided, print usage information.
        printf("Usage: type <command>\n");
        return;
    }

    if (internal_command(args)) {
        // If the command is internal, print that it is an internal command.
        printf("%s is an internal command\n", args);
    } else {
        // If the command is not internal, check if it is an external command.
        char *path = getenv("PATH");  // Get the PATH environment variable.
        if (path == NULL) {
            // Print an error message if PATH is not set.
            printf("PATH environment variable not set\n");
            return;
        }

        // Duplicate the PATH environment variable to modify it.
        char *path_copy = strdup(path);
        char *dir = strtok(path_copy, ":");  // Tokenize PATH into directories.
        char command_path[1024];  // Buffer to hold the full path to the command.

        while (dir != NULL) {
            // Construct the full path to the command.
            snprintf(command_path, sizeof(command_path), "%s/%s", dir, args);
            if (access(command_path, X_OK) == 0) {
                // If the command is found and executable, print that it is an external command.
                printf("%s is an external command\n", args);
                free(path_copy);  // Free the allocated memory for path_copy.
                return;
            }
            dir = strtok(NULL, ":");  // Move to the next directory in PATH.
        }

        // If the command is not found in any PATH directory, print that it is unsupported.
        free(path_copy);  // Free the allocated memory for path_copy.
        printf("%s is an unsupported command\n", args);
    }
}

