# Hogwarts Shell
![]()
Welcome to the Hogwarts Shell, a simple command-line interface inspired by the magical world of Harry Potter. This shell supports various commands to mimic a basic Unix shell environment with a touch of wizardry. Below is a guide to help you get started with the Hogwarts Shell, including its commands, functionalities, and how to use it.

# Table of Contents
    Features
    Commands
        - lineage
        - mirror
        - geminio
        - mobiliarbus
        - voldemort
        - diary
        - help

     Installation
     Usage
     Customization
# Features

    Custom Command Set: Execute magical commands to interact with files and directories.
    Help System: Access command usage information.
    Friendly Messages: Enjoy welcoming and exit messages with a magical touch.   
# Commands    
## "lineage" :
 - Displays the current working directory.
 - Outputs the absolute path of the current working directory .
   ## Usage :
   ```lineage ```

## "mirror" :
 - Echoes the provided arguments.
 - Prints the given text to the terminal. If no text is provided, it prints an empty line.
   ## Usage :
   ```mirror <string>```

 ## "geminio" :
  - Copies a file from the source to the destination.
  - Copies the file specified by <source> to the path specified by <destination>. If any errors occur (e.g., file not found), they are reported.
    ## Usage :
    ```geminio <Source> <Destination>```

 ## "mobiliarbus" :
  - Moves a file from the source to the destination.
  - Moves the file specified by <source> to the path specified by <destination>. If any errors occur, they are reported.
    ## Usage :
    ```mobiliarbus <Source> <Destination>```

 ## "voldemort" :
  - Exits the shell with a custom message.
  - Prints a special exit message and terminates the shell.
    ## Usage :
    ```voldemort```

  ## "diary" :
   - Displays help information for each command.
   - Provides a brief overview and usage instructions for each available command.
     ## Usage :
     ```diary```
     ```diary <Commend Name>```

   # Installation
   1. Clone the Repository:
   ```git clone https://github.com/mohamedaymankills/HOGWARTS-Shell```
   ```cd HOGWARTS-Shell```
   2. Compile the Shell:
   ```gcc -o Hogwarts_Shell Hogwarts_Shell.c Lineage.c Mirror.c Geminio.c Mobiliarbus.c Diary.c```
   3. Run the Shell:
   ```./Hogwarts_Shell```

# Usage 
Once you have the shell running, you can start typing commands at the HOGWARTS---> prompt. Use the commands listed above to interact with the shell. For example, you can use lineage to see your current directory, mirror to print text, and geminio to copy files.


   
    

