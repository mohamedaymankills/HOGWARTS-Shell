/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : HOGWARTS_Sheel.c ************************/
/************************ Date   : 23-7-2024        ************************/
/************************ Version: 0.4.3            ************************/

/*************************** Includes ***************************/
#include <stdio.h>       // Include the standard input/output library for printf, perror, etc.
#include <string.h>      // Include the string handling library for string manipulation functions.
#include <unistd.h>      // Include the POSIX API for system calls such as read and write.
#include <stdlib.h>      // Include the standard library for general functions such as exit.
#include <sys/types.h>   // Include definitions for data types used in system calls.
#include <sys/wait.h>    // Include the header for wait functions.
#include <sys/stat.h>    // Include the header for file status and mode constants.
#include <fcntl.h>       // Include the header for file control options.
#include "Lineage.h"     // Include the header file for the Lineage command.
#include "Mirror.h"      // Include the header file for the Mirror command.
#include "Geminio.h"     // Include the header file for the Geminio command.
#include "Mobiliarbus.h" // Include the header file for the Mobiliarbus command.
#include "Diary.h"       // Include the header file for the Diary command.
#include "Apparition.h"  // Include the header file for the Apparition command.
#include "Revelio.h"     // Include the header file for the Revelio command.
#include "School.h"      // Include the header file for the School command.
#include "External.h"    // Include the header file for the External command.
#include "Showme.h"      // Include the header file for the Showme command.
#include "Tempus.h"      // Include the header file for the Tempus command.
//#include "Grep.h"       // Header file for the Grep command (commented out).

/*************************** Definitions ***************************/
#define STDIN  0      // Define the file descriptor for standard input.
#define STDOUT 1      // Define the file descriptor for standard output.
#define STDERR 2      // Define the file descriptor for standard error.

typedef void (*command_func)(char *);   // Define a type for command functions that take a string argument.

typedef struct {
    char *name;           // Command name.
    command_func func;   // Function pointer for the command.
} command_entry;          // Structure to map command names to their functions.

void execute_unknown(char *args) {
    // Function to handle unknown commands.
    printf("The SPELL not recognized\n");   // Print a message indicating the command is not recognized.
}

void execute_voldemort(char *args) {
    // Function to execute the 'voldemort' command.
    const char *exit_message = 
        "███████╗██╗  ██╗██╗   ██╗████████╗    ██╗   ██╗██████╗     \n"
        "██╔════╝██║  ██║██║   ██║╚══██╔══╝    ██║   ██║██╔══██╗    \n"
        "███████╗███████║██║   ██║   ██║       ██║   ██║██████╔╝    \n"
        "╚════██║██╔══██║██║   ██║   ██║       ██║   ██║██╔═══╝     \n"
        "███████║██║  ██║╚██████╔╝   ██║       ╚██████╔╝██║         \n"
        "╚══════╝╚═╝  ╚═╝ ╚═════╝    ╚═╝        ╚═════╝ ╚═╝         \n"
        "\n";
    
    printf("%s", exit_message);  // Print the exit message.
    exit(0);                    // Terminate the program with success status.
}

void print_welcome_message() {
    // Function to print the welcome message when the shell starts.
    const char *welcome_message = 
        "██╗  ██╗ ██████╗  ██████╗ ██╗    ██╗ █████╗ ██████╗ ████████╗███████╗    ███████╗██╗  ██╗███████╗██╗     ██╗     \n"
        "██║  ██║██╔═══██╗██╔════╝ ██║    ██║██╔══██╗██╔══██╗╚══██╔══╝██╔════╝    ██╔════╝██║  ██║██╔════╝██║     ██║     \n"
        "███████║██║   ██║██║  ███╗██║ █╗ ██║███████║██████╔╝   ██║   ███████╗    ███████╗███████║█████╗  ██║     ██║     \n"
        "██╔══██║██║   ██║██║   ██║██║███╗██║██╔══██║██╔══██╗   ██║   ╚════██║    ╚════██║██╔══██║██╔══╝  ██║     ██║     \n"
        "██║  ██║╚██████╔╝╚██████╔╝╚███╔███╔╝██║  ██║██║  ██║   ██║   ███████║    ███████║██║  ██║███████╗███████╗███████╗\n"
        "╚═╝  ╚═╝ ╚═════╝  ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝    ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n";

    printf("%s\n", welcome_message);  // Print the welcome message.
}

void execute_command(char *cmd) {
    // Function to execute a command using execvp.
    char *args[10];      // Array to hold command arguments.
    int i = 0;
    char *token = strtok(cmd, " \t");  // Tokenize the command string by space or tab.
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \t");
    }
    args[i] = NULL;  // Null-terminate the arguments array.
    execvp(args[0], args);  // Execute the command.
    perror("execvp failed"); // Print error if execvp fails.
    exit(1);                // Exit the program with an error status.
}

void handle_pipe(char *cmd) {
    // Function to handle piping between two commands.
    int pipefd[2];    // File descriptors for the pipe.
    pid_t pid1, pid2; // Process IDs for the two child processes.
    char *cmd1 = strtok(cmd, "|"); // First command in the pipe.
    char *cmd2 = strtok(NULL, "|"); // Second command in the pipe.

    if (pipe(pipefd) == -1) {  // Create the pipe.
        perror("pipe");       // Print error if pipe creation fails.
        exit(1);              // Exit the program with an error status.
    }

    if ((pid1 = fork()) == -1) { // Fork the first child process.
        perror("fork");         // Print error if fork fails.
        exit(1);                // Exit the program with an error status.
    }

    if (pid1 == 0) { // Child 1
        close(pipefd[0]); // Close unused read end of the pipe.
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe write end.
        close(pipefd[1]); // Close the write end of the pipe.
        execute_command(cmd1); // Execute the first command.
    } else {
        if ((pid2 = fork()) == -1) { // Fork the second child process.
            perror("fork");         // Print error if fork fails.
            exit(1);                // Exit the program with an error status.
        }

        if (pid2 == 0) { // Child 2
            close(pipefd[1]); // Close unused write end of the pipe.
            dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end.
            close(pipefd[0]); // Close the read end of the pipe.
            execute_command(cmd2); // Execute the second command.
        } else {
            close(pipefd[0]); // Close both ends of the pipe in the parent.
            close(pipefd[1]);
            waitpid(pid1, NULL, 0); // Wait for the first child to finish.
            waitpid(pid2, NULL, 0); // Wait for the second child to finish.
        }
    }
}

#define MAX_CMD_SIZE 1024 // Define the maximum size of the command buffer.

void execute_redirection(char *cmd) {
    // Function to handle input and output redirection.
    char *args[MAX_CMD_SIZE / 2 + 1]; // Array to hold command arguments.
    char *input_file = NULL; // File for input redirection.
    char *output_file = NULL; // File for output redirection.
    int i = 0;

    // Tokenize the command string.
    char *token = strtok(cmd, " \t\n");
    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            input_file = strtok(NULL, " \t\n"); // Get the input file name.
        } else if (strcmp(token, ">") == 0) {
            output_file = strtok(NULL, " \t\n"); // Get the output file name.
        } else {
            args[i++] = token; // Add argument to the array.
        }
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL; // Null-terminate the arguments array.

    // Handle input redirection.
    if (input_file) {
        int fd_in = open(input_file, O_RDONLY); // Open the input file.
        if (fd_in < 0) {
            perror("open"); // Print error if file cannot be opened.
            exit(EXIT_FAILURE); // Exit the program with failure status.
        }
        dup2(fd_in, STDIN_FILENO); // Redirect stdin to the input file.
        close(fd_in); // Close the file descriptor.
    }

    // Handle output redirection.
    if (output_file) {
        int fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // Open the output file.
        if (fd_out < 0) {
            perror("open"); // Print error if file cannot be opened.
            exit(EXIT_FAILURE); // Exit the program with failure status.
        }
        dup2(fd_out, STDOUT_FILENO); // Redirect stdout to the output file.
        close(fd_out); // Close the file descriptor.
    }

    // Execute the command.
    if (execvp(args[0], args) == -1) {
        perror("execvp"); // Print error if execvp fails.
        exit(EXIT_FAILURE); // Exit the program with failure status.
    }
}

int main(void) {
    char cmd[MAX_CMD_SIZE]; // Buffer to store the command input.
    char command[100];      // Buffer to store the input command from the user.
    char *token;            // Pointer to hold the tokenized command.
    ssize_t readsize = 0;   // Variable to store the number of bytes read.
    const char *shellmsg = "HOGWARTS---> "; // Shell prompt message.

    print_welcome_message(); // Print the welcome message when the shell starts.

    // Define the command dispatch table with command names and their corresponding functions.
    command_entry commands[] = {
        {"lineage", execute_lineage},         // Mapping for 'lineage' command.
        {"mirror", execute_mirror},           // Mapping for 'mirror' command.
        {"geminio", execute_geminio},         // Mapping for 'geminio' command.
        {"mobiliarbus", execute_mobiliarbus}, // Mapping for 'mobiliarbus' command.
        {"voldemort", execute_voldemort},     // Mapping for 'voldemort' command.
        {"diary", execute_diary},             // Mapping for 'diary' command.
        {"apparition", execute_apparition},   // Mapping for 'apparition' command.
        {"revelio", execute_revelio},         // Mapping for 'revelio' command.
        {"school", execute_school},           // Mapping for 'school' command.   
        {"showme", execute_showme},           // Mapping for 'showme' command.
        {"tempus", execute_tempus},           // Mapping for 'tempus' command.
        //{"mygrep", execute_grep},           // Mapping for 'mygrep' command (commented out).
        {NULL, execute_unknown}               // Default handler for unknown commands. This must be the last entry.
    };

    while (1) {    
        write(STDOUT, shellmsg, strlen(shellmsg)); // Print the shell prompt message.
        readsize = read(STDIN, command, sizeof(command) - 1); // Read input from the user.

        if (readsize <= 0) {
            perror("read"); // Print error if read fails.
            continue; // Continue the loop to prompt for a new command.
        }

        // Null-terminate the string read by read() function.
        command[readsize] = '\0';

        // Remove the newline character read by read() function if present.
        if (command[readsize - 1] == '\n') {
            command[readsize - 1] = '\0';
        }
        
        // Check if the command contains a pipe.
        if (strchr(command, '|')) {
            handle_pipe(command); // Handle piping between commands.
        } else {
            // Tokenize the command input to separate the command name from the arguments.
            token = strtok(command, " ");
            char *args = strtok(NULL, "");  // Remaining part after the command name as arguments.

            if (token != NULL) {
                int i = 0;
                int found = 0;
                while (commands[i].name != NULL) {
                    if (strcmp(token, commands[i].name) == 0) {
                        commands[i].func(args);  // Call the function associated with the command.
                        found = 1;
                        break;
                    }
                    i++;
                }

                // If no command matches, execute the unknown command handler.
                if (!found) {
                     if (execute_external(token, args) == -1) {
                        execute_unknown(args); // Execute unknown command handler.
                        execute_redirection(cmd); // Handle redirection if specified.
                    }           
                }
            }
        }
    }
    return 0; // Return 0 indicating successful completion (though the loop is infinite).
}
