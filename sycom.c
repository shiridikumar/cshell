#include "prompt.h"
#include "headers.h"

void syscom(char *c,char **arr, int comm){
    char *command;
    strcpy(command,arr[0]);
    system(command);

}