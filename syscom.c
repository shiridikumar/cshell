#include "headers.h"

void syscom(char *c, char **arr, int comm)
{
    char *command;
    strcpy(command, c);
    char **args;
    int x = 111;
    args = (char **)malloc((comm + 1) * sizeof(char **));
    int count = 0;
    int flag = 0;
    for (int j = 0; j < comm; j++)
    {
        if (strcmp(arr[j], "&") != 0)
        {
            args[count++] = arr[j];
        }
        else{
            flag=1;
        }
    }
    args[count] = NULL;
    int status;
    if (comm < 1)
    {
        printf("Invalid no of arguments\n");
    }
    else
    {
        if (flag == 1)
        {
            //background process
            x = fork();
            if (x == 0)
            {
                setpgid(0, 0);
                execvp(args[0], args);
            }
        }
        else
        {
            //foreground process
            x = fork();
            if (x == 0)
            {
                execvp(args[0], args);
            }
            else
            {
                waitpid(x, &status, 0);
            }
        }
    }
}
