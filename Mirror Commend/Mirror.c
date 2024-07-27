/************************ Author : Mohamed Ayman ************************/
/************************ Name   : Mirror.c      ************************/
/************************ Date   : 23-7-2024     ************************/
/************************ Version: 0.0.1         ************************/



/****************** [ MIRROR -------> ECHO ] ***************/

// Include the standard I/O library for input and output functions
#include <stdio.h>

// Include the string library for string manipulation functions
#include <string.h>

// Function to execute and print the input arguments
// The 'args' parameter is a pointer to a string (character array) that contains the text to be printed
void execute_mirror(char *args) {

    // Check if the 'args' pointer is not NULL
    if (args != NULL) 
    {
        // Print the string pointed to by 'args' followed by a newline
        printf("%s\n", args);
    } 
    else 
    {
        // If 'args' is NULL, print a newline character
        printf("\n");
    }
}

