#include "headers.h"
#include "prompt.h"
extern char * path;

void cd(char *c)
{
    char *directory = strtok(NULL, " ");
    char d[100];
    if (chdir(directory) != 0)
    {
        perror("Directory");
    }
    else
    {
        char *wd=getcwd(d,100);
        strcpy(path,wd);
    }
}