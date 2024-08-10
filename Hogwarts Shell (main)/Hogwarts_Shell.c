/************************ Author : Mohamed Ayman    ************************/
/************************ Name   : HOGWARTS_Sheel.c ************************/
/************************ Date   : 23-7-2024        ************************/
/************************ Version: 0.2.3            ************************/

/*************************** Includes ***************************/
#include <stdio.h>       // Include the standard input/output library for printf, perror, etc.
#include <string.h>      // Include the string handling library for string manipulation functions.
#include <unistd.h>      // Include the POSIX API for system calls such as read and write.
#include <stdlib.h>      // Include the standard library for general functions such as exit.
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>    // Include the header for wait functions.
#include "Lineage.h"     // Include the header file for the Lineage command.
#include "Mirror.h"      // Include the header file for the Mirror command.
#include "Geminio.h"     // Include the header file for the Geminio command.
#include "Mobiliarbus.h" // Include the header file for the Mobiliarbus command.
#include "Diary.h"       // Include the header file for the Diary command.
#include "Apparition.h"  // Include the header file for the Apparition command.
#include "Revelio.h"     // Include the header file for the Revelio command.
#include "School.h"      // Include the header file for the School command.
#include "External.h"    // Include the header file for the Exterlnal command.
#include "Showme.h"
#include "Tempus.h"
//#include "Grep.h"

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
    const char *exit_message = 
        "███████╗██╗  ██╗██╗   ██╗████████╗    ██╗   ██╗██████╗     \n"
        "██╔════╝██║  ██║██║   ██║╚══██╔══╝    ██║   ██║██╔══██╗    \n"
        "███████╗███████║██║   ██║   ██║       ██║   ██║██████╔╝    \n"
        "╚════██║██╔══██║██║   ██║   ██║       ██║   ██║██╔═══╝     \n"
        "███████║██║  ██║╚██████╔╝   ██║       ╚██████╔╝██║         \n"
        "╚══════╝╚═╝  ╚═╝ ╚═════╝    ╚═╝        ╚═════╝ ╚═╝         \n"
        "\n";
    
    printf("%s", exit_message);
    exit(0);
}

void print_welcome_message() {
    const char *welcome_message = 
        "██╗  ██╗ ██████╗  ██████╗ ██╗    ██╗ █████╗ ██████╗ ████████╗███████╗    ███████╗██╗  ██╗███████╗██╗     ██╗     \n"
        "██║  ██║██╔═══██╗██╔════╝ ██║    ██║██╔══██╗██╔══██╗╚══██╔══╝██╔════╝    ██╔════╝██║  ██║██╔════╝██║     ██║     \n"
        "███████║██║   ██║██║  ███╗██║ █╗ ██║███████║██████╔╝   ██║   ███████╗    ███████╗███████║█████╗  ██║     ██║     \n"
        "██╔══██║██║   ██║██║   ██║██║███╗██║██╔══██║██╔══██╗   ██║   ╚════██║    ╚════██║██╔══██║██╔══╝  ██║     ██║     \n"
        "██║  ██║╚██████╔╝╚██████╔╝╚███╔███╔╝██║  ██║██║  ██║   ██║   ███████║    ███████║██║  ██║███████╗███████╗███████╗\n"
        "╚═╝  ╚═╝ ╚═════╝  ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝    ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n";

    printf("%s\n", welcome_message);
}

void execute_command(char *cmd) {
    char *args[10];
    int i = 0;
    char *token = strtok(cmd, " \t");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \t");
    }
    args[i] = NULL;
    execvp(args[0], args);
    perror("execvp failed");
    exit(1);
}

void handle_pipe(char *cmd) {
    int pipefd[2];
    pid_t pid1, pid2;
    char *cmd1 = strtok(cmd, "|");
    char *cmd2 = strtok(NULL, "|");

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (pid1 == 0) { // Child 1
        close(pipefd[0]); // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(pipefd[1]);
        execute_command(cmd1);
    } else {
        if ((pid2 = fork()) == -1) {
            perror("fork");
            exit(1);
        }

        if (pid2 == 0) { // Child 2
            close(pipefd[1]); // Close unused write end
            dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end
            close(pipefd[0]);
            execute_command(cmd2);
        } else {
            close(pipefd[0]);
            close(pipefd[1]);
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
        }
    }
}





#define MAX_CMD_SIZE 1024

void execute_redirection(char *cmd) {
    char *args[MAX_CMD_SIZE / 2 + 1];
    char *input_file = NULL;
    char *output_file = NULL;
    int i = 0;

    // Tokenize the command
    char *token = strtok(cmd, " \t\n");
    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            input_file = strtok(NULL, " \t\n");
        } else if (strcmp(token, ">") == 0) {
            output_file = strtok(NULL, " \t\n");
        } else {
            args[i++] = token;
        }
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    // Handle redirection
    if (input_file) {
        int fd_in = open(input_file, O_RDONLY);
        if (fd_in < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
    }

    if (output_file) {
        int fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd_out < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(fd_out, STDOUT_FILENO);
        close(fd_out);
    }

    // Execute the command
    if (execvp(args[0], args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}








int main(void) {
    char cmd[MAX_CMD_SIZE];
    char command[100];   // Buffer to store the input command from the user.
    char *token;         // Pointer to hold the tokenized command.
    ssize_t readsize = 0; // Variable to store the number of bytes read.
    const char *shellmsg = "HOGWARTS---> ";  // Shell prompt message.

    print_welcome_message();  // Print the welcome message when the shell starts.

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
        {"showme", execute_showme}, 
        {"tempus", execute_tempus},
        //{"mygrep", execute_grep},
        {NULL, execute_unknown}               // Default handler for unknown commands. This must be the last entry.
    };

    while (1) {    
        write(STDOUT, shellmsg, strlen(shellmsg)); // Print the shell prompt message.
        readsize = read(STDIN, command, sizeof(command) - 1); // Read input from the user.

        if (readsize <= 0) {
            perror("read");
            continue;
        }

        // Null-terminate the string read by read() function.
        command[readsize] = '\0';

        // Remove the newline character read by read() function if present.
        if (command[readsize - 1] == '\n') {
            command[readsize - 1] = '\0';
        }
        
        // Check if the command contains a pipe
        if (strchr(command, '|')) {
            handle_pipe(command);
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
                        execute_unknown(args);
                        execute_redirection(cmd);
                    }           
                }
            }
        }
    }
    return 0; // Return 0 indicating successful completion (though the loop is infinite).
}
