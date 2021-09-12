#include "prompt.h"
#include "headers.h"

void syscom(char *c,char **arr, int comm){
    char *command;
    strcpy(command,c);
    system(command);

}