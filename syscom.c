#include "headers.h"

void syscom(char *c,char **arr, int comm){
    char *command;
    strcpy(command,c);

    int x=fork();

    if(x==0){
        printf("process %d\n",getpid());
        execvp(arr[0],NULL);
    }
    printf("%d",x);
}

