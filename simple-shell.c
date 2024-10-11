#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LEN 100

void printTime()
{
    time_t rawtime;
    struct tm *timeStruct;
    char buffer[80];

    time(&rawtime);
    timeStruct = localtime(&rawtime);
    strftime(buffer, 80, "%H:%M", timeStruct);
    printf("%s ", buffer);
}

int main()
{
    char command[MAX_LEN];

    // Create array of pointers
    // Each element is a pointer that points to memory containing start of word
    char *arrayOfPointers[MAX_LEN];

    while (1)
    {
        printTime();

        // Get command from stdin and put in command variable - fgets includes \n
        fgets(command, MAX_LEN, stdin);

        // Get index of \n in command
        char newLineI = strcspn(command, "\n");

        // Set end of command to 0
        command[newLineI] = 0;

        // Pointer to start of word
        char *wordPointer = strtok(command, " ");

        int counter = 0;
        while (wordPointer != NULL)
        {
            // Store word pointer to array of pointers
            arrayOfPointers[counter] = wordPointer;
            // When 1st arg is NULL, continues where it left off in the memory
            // Then start searching for the next occurence of " "
            // Then everything before " " is the token
            wordPointer = strtok(NULL, " ");

            counter++;
        }
        // Add NULL at the end so that execvp knows where the array of arguments end
        // https://stackoverflow.com/questions/42540991/bad-address-error-with-execvp
        arrayOfPointers[counter] = NULL;

        // Get pointer to first word of user command
        char *commandWord = arrayOfPointers[0];

        // Compare 2 words, strcmp compares if words are equal
        if (strcmp(commandWord, "exit") == 0)
        {
            printf("...exiting");
            exit(0);
        }

        // Create child process and get pid
        // returns 0 if child pid is created
        pid_t pid = fork();

        // child process not created
        if (pid == -1)
        {
            perror("Could not create process. Fork() error - command probably does not exist.");
            exit(1);
        }
        // enter here if child process is created
        // execvp returns -1 if there is an error
        else if (pid == 0 && execvp(commandWord, arrayOfPointers) == -1)
        {
            perror("Execution error");
            exit(1);
        }
        else
        {
            waitpid(pid, NULL, 0);
        }
    }
}

// Some links that helped me a lot - forgot to add some of the other stuff but I lost the links
// https://www.geeksforgeeks.org/array-of-strings-in-c/
// https://stackoverflow.com/questions/15472299/split-string-into-tokens-and-save-them-in-an-array
// https://stackoverflow.com/questions/5141960/get-the-current-time-in-c
// https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm
// https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm
// https://support.sas.com/documentation/onlinedoc/ccompiler/doc/lr2/execvp.htm#:~:text=The%20execvp%20function%20is%20most,call%20to%20the%20fork%20function.&text=identifies%20the%20location%20of%20the,hierarchical%20file%20system%20(HFS).
// https://stackoverflow.com/questions/55743496/difference-between-exec-execvp-execl-execv
// https://www.geeksforgeeks.org/difference-between-exit-and-break-in-c-cpp/
// http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/exec.html
// https://www.geeksforgeeks.org/wait-system-call-c/
// https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
// https://www.tutorialspoint.com/cprogramming/c_array_of_pointers.htm
// https://www.programiz.com/c-programming/library-function/string.h/strcmp
// https://www.geeksforgeeks.org/fork-system-call/
// https://support.sas.com/documentation/onlinedoc/ccompiler/doc750/html/lr2/zid-7307.htm#:~:text=A%20successful%20call%20to%20execvp,call%20to%20execvp%20is%20unsuccessful.