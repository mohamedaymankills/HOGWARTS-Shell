/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : Revelio.c        ************************/
/************************ Date   : 23-7-2024        ************************/
/************************ Version: 0.0.1            ************************/

#include <stdio.h>   // Include the standard input/output library for printf.
#include <stdlib.h>  // Include the standard library for general functions such as getenv.
#include <string.h>  // Include the string handling library for string manipulation functions.
#include "Revelio.h" // Include the header file for the Revelio command.

extern char **environ;  // Declare the extern variable 'environ' to access environment variables.

void execute_revelio(char *args) {
    if (args == NULL) {
        // If no arguments are provided, print all environment variables
        char **env = environ;  // Start with the environment variables array
        while (*env) {
            printf("%s\n", *env);  // Print each environment variable
            env++;  // Move to the next environment variable
        }
    } 
    else 
        {
        // If an argument is provided, print the value of the specified environment variable
        char *value = getenv(args);  // Retrieve the value of the environment variable
        if (value != NULL) {
            // If the environment variable exists, print its name and value
            printf("%s=%s\n", args, value);
        } 
        else 
        {
            // If the environment variable does not exist, print a not found message
            printf("Environment variable %s not found\n", args);
        }
    }
}

