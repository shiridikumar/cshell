#include "prompt.h"
#include "headers.h"

char *path;

int main()
{
    path=(char *)malloc(200*sizeof(char));
    char initial[100];
    getcwd(initial,100);
    strcpy(path,initial);
    while (1)
    {
        prompt();
        size_t size = 200;
        char *c = (char *)malloc(200 * sizeof(char));
        gets(c);
        char * command= strtok(c," ");
        if(strcmp(command,"cd")==0)
            cd(c);
    }
}
