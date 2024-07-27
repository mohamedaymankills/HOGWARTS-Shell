# Hogwarts Shell
![1](https://github.com/mohamedaymankills/HOGWARTS-Shell/blob/main/Readme_Images/Hogwarts.png)
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
![2](https://github.com/mohamedaymankills/HOGWARTS-Shell/blob/main/Readme_Images/lineage.png)
 - Displays the current working directory.
 - Outputs the absolute path of the current working directory .
 - lineage = pwd
   ## Usage :
   ```lineage ```

## "mirror" :
![3](https://github.com/mohamedaymankills/HOGWARTS-Shell/blob/main/Readme_Images/mirror.png)
 - Echoes the provided arguments.
 - Prints the given text to the terminal. If no text is provided, it prints an empty line.
 - mirror = echo
   ## Usage :
   ```mirror <string>```

 ## "geminio" :
 ![4](https://github.com/mohamedaymankills/HOGWARTS-Shell/blob/main/Readme_Images/geminio.png)
  - Copies a file from the source to the destination.
  - Copies the file specified by <source> to the path specified by <destination>. If any errors occur (e.g., file not found), they are reported.
  - geminio = cp
    ## Usage :
    ```geminio <Source> <Destination>```

 ## "mobiliarbus" :
 ![5](https://github.com/mohamedaymankills/HOGWARTS-Shell/blob/main/Readme_Images/mobiliarbus.png)
  - Moves a file from the source to the destination.
  - Moves the file specified by <source> to the path specified by <destination>. If any errors occur, they are reported.
  - mobiliarbus = mv
    ## Usage :
    ```mobiliarbus <Source> <Destination>```

 ## "voldemort" :
 ![6](https://github.com/mohamedaymankills/HOGWARTS-Shell/blob/main/Readme_Images/voldemort.png)
  - Exits the shell with a custom message.
  - Prints a special exit message and terminates the shell.
  - voldemort = exit
    ## Usage :
    ```voldemort```

  ## "diary" :
  ![7](https://github.com/mohamedaymankills/HOGWARTS-Shell/blob/main/Readme_Images/diary.png)
   - Displays help information for each command.
   - Provides a brief overview and usage instructions for each available command.
   - diary = help
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

# Customization
You can customize the shell by modifying the source code. Here are some points where you might want to make changes:

   Welcome Message: Modify the print_welcome_message function in main.c to change the shell's startup message.
   Exit Message: Customize the execute_voldemort function to change the exit message.
   Command Implementations: Update or add new commands by editing or adding new .c and .h files.

# Troubleshooting 
The SPELL not recognized ( Command Not Recognized ) : Ensure the command is correctly typed and listed in the commands array in main.c.
File Errors: Check file paths and permissions when using geminio and mobiliarbus.
Compilation Issues: Ensure all required files are included and that you are using a compatible compiler.

# License
[Linkedin](https://www.linkedin.com/in/mohamed-ayman-78361a251/)



   
    

