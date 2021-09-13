#include "headers.h"

void syscom(char *c, char **arr, int comm)
{
    char *command;
    strcpy(command, c);
    char **args;
    int x = 111;
    args = (char **)malloc((comm + 1) * sizeof(char **));
    int count = 0;
    for (int j = 0; j < comm; j++)
    {
        if (strcmp(arr[j], "&") != 0)
        {
            args[count++] = arr[j];
        }
    }
    args[count] = NULL;
    if (comm > 3)
    {
        printf("Invalid no of arguments\n");
    }
    else
    {
        if (comm == 3)
        {
            if (strcmp(arr[2], "&") == 0)
            {
                //background process
                x = fork();
                if (x == 0)
                {
                    execvp(args[0], args);
                }
            }
            else if (strcmp(arr[1], "&") == 0)
            {
                //backgorund process
                x = fork();
                if (x == 0)
                {
                    execvp(args[0], args);
                }
            }
            else
            {
                //fore ground process
                x = fork();
                if (x == 0)
                {
                    execvp(args[0], args);
                }
                else
                {
                    wait();
                }
            }
        }
        else if (comm == 2)
        {
            if (strcmp(arr[1], "&") == 0)
            {
                //background process
                x = fork();
                if (x == 0)
                {
                    execvp(args[0], args);
                    exit(1);
                }
                else{
                    printf("printf %d child id\n",x);
                }
            }
            else
            {
                printf("foreground\n");
                //foreground process
                x = fork();
                printf("%d", x);
                if (x == 0)
                {
                    printf("Child process id :%d", getpid());
                    execvp(args[0], args);
                }
                else
                {
                    printf("child process id %d",x);
                    printf("This is parent prcess\n");
                    wait();
                    printf("Im not waiting child process\n");
                }
            }
        }
        else
        {
            x = fork();
            if (x == 0)
            {
                execvp(args[0], args);
            }
            else
            {
                wait();
            }
            //foreground  process
        }
    }
}
