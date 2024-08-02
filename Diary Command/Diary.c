/************************ Author : Mohamed Ayman ************************/
/************************ Name   : Diary.c       ************************/
/************************ Date   : 23-7-2024     ************************/
/************************ Version: 0.0.2         ************************/


/************************ [ DIARY ----------> HELP ] **********************/

#include <stdio.h>
#include <string.h>

void execute_diary(char *args) {
    if (args == NULL || strcmp(args, "") == 0) {
        printf("Available commands:\n");
        printf("  lineage        - Print the current working directory\n");
        printf("  mirror         - Display a line of text\n");
        printf("  geminio        - Copy files\n");
        printf("  mobiliarbus    - Move or rename files\n");
        printf("  voldemort      - Exit the shell\n");
        printf("  diary          - Display this help message\n");
        printf("  apparition     - Moving in directories \n");
        printf("  school         - Find the Type of commands if Internal or External\n");
        printf("  revelio        - print all the environment variables \n");
        printf("  Use 'diary <command>' for detailed information on a command.\n");
        return;
    }

    if (strcmp(args, "lineage") == 0) {
	printf(        "██╗     ██╗███╗   ██╗███████╗ █████╗  ██████╗ ███████╗ \n"
		       "██║     ██║████╗  ██║██╔════╝██╔══██╗██╔════╝ ██╔════╝ \n"
	               "██║     ██║██╔██╗ ██║█████╗  ███████║██║  ███╗█████╗   \n"
		       "██║     ██║██║╚██╗██║██╔══╝  ██╔══██║██║   ██║██╔══╝   \n"
                       "███████╗██║██║ ╚████║███████╗██║  ██║╚██████╔╝███████  \n"
                       "╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝ \n"
                       "                                                       \n"	);    
        printf("lineage: Print the current working directory\n");
        printf("lineage ------------------> pwd\n");
        printf("Usage: lineage\n");


    } else if (strcmp(args, "mirror") == 0) {
        printf(        "███╗   ███╗██╗██████╗ ██████╗  ██████╗ ██████╗  \n"
                       "████╗ ████║██║██╔══██╗██╔══██╗██╔═══██╗██╔══██╗ \n"
                       "██╔████╔██║██║██████╔╝██████╔╝██║   ██║██████╔╝ \n"
                       "██║╚██╔╝██║██║██╔══██╗██╔══██╗██║   ██║██╔══██╗ \n"
                       "██║ ╚═╝ ██║██║██║  ██║██║  ██║╚██████╔╝██║  ██║ \n"
                       "╚═╝     ╚═╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝ \n"
                       "                                                \n"      );
       
        printf("mirror: Display a line of text\n");
        printf("mirror ------------------> echo\n");
        printf("Usage: mirror [string...]\n");


    } else if (strcmp(args, "geminio") == 0) {
        printf(        " ██████╗ ███████╗███╗   ███╗██╗███╗   ██╗██╗ ██████╗  \n"
                       "██╔════╝ ██╔════╝████╗ ████║██║████╗  ██║██║██╔═══██╗ \n"
                       "██║  ███╗█████╗  ██╔████╔██║██║██╔██╗ ██║██║██║   ██║ \n"
                       "██║   ██║██╔══╝  ██║╚██╔╝██║██║██║╚██╗██║██║██║   ██║ \n"
                       "╚██████╔╝███████╗██║ ╚═╝ ██║██║██║ ╚████║██║╚██████╔╝ \n"
                       " ╚═════╝ ╚══════╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝ ╚═════╝  \n"
                       "                                                      \n"      );
       
        printf("geminio: Copy files\n");
        printf("geminio ------------------> cp\n");
        printf("Usage: geminio <source> <destination>\n");



    } else if (strcmp(args, "mobiliarbus") == 0) {
        printf(        "███╗   ███╗ ██████╗ ██████╗ ██╗██╗     ██╗ █████╗ ██████╗ ██████╗ ██╗   ██╗███████╗ \n"
                       "████╗ ████║██╔═══██╗██╔══██╗██║██║     ██║██╔══██╗██╔══██╗██╔══██╗██║   ██║██╔════╝ \n"
                       "██╔████╔██║██║   ██║██████╔╝██║██║     ██║███████║██████╔╝██████╔╝██║   ██║███████╗ \n"
                       "██║╚██╔╝██║██║   ██║██╔══██╗██║██║     ██║██╔══██║██╔══██╗██╔══██╗██║   ██║╚════██║ \n"
                       "██║ ╚═╝ ██║╚██████╔╝██████╔╝██║███████╗██║██║  ██║██║  ██║██████╔╝╚██████╔╝███████║ \n"
                       "╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚═╝╚══════╝╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚══════╝ \n"
                       "                                                                                    \n"      );
      
        printf("mobiliarbus: Move or rename files\n");
        printf("mobiliarbus ------------------> mv\n");
        printf("Usage: mobiliarbus <source> <destination>\n");


    } else if (strcmp(args, "voldemort") == 0) {
        printf(        "██╗   ██╗ ██████╗ ██╗     ██████╗ ██████╗ ███╗   ███╗ ██████╗ ██████╗ ████████╗ \n"
                       "██║   ██║██╔═══██╗██║     ██╔══██╗██╔══██╗████╗ ████║██╔═══██╗██╔══██╗╚══██╔══╝ \n"
                       "██║   ██║██║   ██║██║     ██║  ██║██████╔╝██╔████╔██║██║   ██║██████╔╝   ██║    \n"
                       "╚██╗ ██╔╝██║   ██║██║     ██║  ██║██╔══██╗██║╚██╔╝██║██║   ██║██╔══██╗   ██║    \n"
                       " ╚████╔╝ ╚██████╔╝███████╗██████╔╝██║  ██║██║ ╚═╝ ██║╚██████╔╝██║  ██║   ██║    \n"
                       "  ╚═══╝   ╚═════╝ ╚══════╝╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝    \n"
                       "                                                                                \n"      );
       
        printf("voldemort: Exit the shell\n");
        printf("voldemort ------------------> exit\n");
        printf("Usage: voldemort\n");



    } else if (strcmp(args, "diary") == 0) {
        printf(        "██████╗ ██╗ █████╗ ██████╗ ██╗   ██╗    \n"
                       "██╔══██╗██║██╔══██╗██╔══██╗╚██╗ ██╔╝    \n"
                       "██║  ██║██║███████║██████╔╝ ╚████╔╝     \n"
                       "██║  ██║██║██╔══██║██╔══██╗  ╚██╔╝      \n"
                       "██████╔╝██║██║  ██║██║  ██║   ██║       \n"
                       "╚═════╝ ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       \n"
                       "                                        \n"      );
      
        printf("diary: Display this help message\n");
        printf("diary ------------------> help\n");
        printf("Usage: diary\n");
        
        

    } else if (strcmp(args, "apparition") == 0) {
        printf(        " █████╗ ██████╗ ██████╗  █████╗ ██████╗ ██╗████████╗██╗ ██████╗ ███╗   ██╗\n"
                       "██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║╚══██╔══╝██║██╔═══██╗████╗  ██║ \n"
                       "███████║██████╔╝██████╔╝███████║██████╔╝██║   ██║   ██║██║   ██║██╔██╗ ██║\n"
                       "██╔══██║██╔═══╝ ██╔═══╝ ██╔══██║██╔══██╗██║   ██║   ██║██║   ██║██║╚██╗██║ \n"
                       "██║  ██║██║     ██║     ██║  ██║██║  ██║██║   ██║   ██║╚██████╔╝██║ ╚████║ \n"
                       "╚═╝  ╚═╝╚═╝     ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝   \n"
                       "                                                                             \n"      );
      
        printf("apparition: Moving in directories \n");
        printf("apparition ------------------> cd\n");
        printf("Usage: apparition </path/>\n");
        
        

    } else if (strcmp(args, "school") == 0) {
        printf(        "███████╗ ██████╗██╗  ██╗ ██████╗  ██████╗ ██╗      \n"
                       "██╔════╝██╔════╝██║  ██║██╔═══██╗██╔═══██╗██║     \n"
                       "███████╗██║     ███████║██║   ██║██║   ██║██║     \n"
                       "╚════██║██║     ██╔══██║██║   ██║██║   ██║██║     \n"
                       "███████║╚██████╗██║  ██║╚██████╔╝╚██████╔╝███████╗\n"
                       "╚══════╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝\n"
                       "                                                                             \n"      );
      
        printf("school: Find the Type of commands if Internal or External\n");
        printf("school ------------------> type\n");
        printf("Usage: school <command>\n");
        
        

    } else if (strcmp(args, "revelio") == 0) {
        printf(        "██████╗ ███████╗██╗   ██╗███████╗██╗     ██╗ ██████╗   \n"
                       "██╔══██╗██╔════╝██║   ██║██╔════╝██║     ██║██╔═══██╗ \n"
                       "██████╔╝█████╗  ██║   ██║█████╗  ██║     ██║██║   ██║  \n"
                       "██╔══██╗██╔══╝  ╚██╗ ██╔╝██╔══╝  ██║     ██║██║   ██║  \n"
                       "██║  ██║███████╗ ╚████╔╝ ███████╗███████╗██║╚██████╔╝ \n"
                       "╚═╝  ╚═╝╚══════╝  ╚═══╝  ╚══════╝╚══════╝╚═╝ ╚═════╝ \n"
                       "                                                                             \n"      );
      
        printf("revelio: print all the environment variables \n");
        printf("revelio ------------------> env\n");
        printf("Usage: revelio \n");
        
        

    }
    else 
    {
        printf("Unknown command: %s\n", args);
    }
}
