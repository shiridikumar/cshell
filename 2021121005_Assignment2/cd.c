#include "headers.h"
extern char *path;
extern char *invoked;
extern *prev;
void cd(char *c, char **arr, int comm)
{
    char *directory = (char *)malloc(300 * sizeof(char));
    int i = 0, j = 0;
    char d[100];
    if (comm == 1)
    {
        if (chdir(invoked)!= 0)
        {
            perror("Directory");
            
        }
        else{
             strcpy(prev,path);
            char *wd = getcwd(d, 100);
            strcpy(path, wd);


        }
    }
    else if(strcmp(arr[1],"~")==0 || strcmp(arr[1],"")==0){
        if (chdir(invoked)!= 0)
        {
            perror("Directory");
            
        }
        else{
            strcpy(prev,path);
            char *wd = getcwd(d, 100);
            strcpy(path, wd);

        }

    }
    else if(strcmp(arr[1],"-")==0){
     
        if (chdir(prev)!= 0)
        {
            perror("Directory");
            
        }
        else{
            strcpy(prev,path);
            char *wd = getcwd(d, 100);
            strcpy(path, wd);

        }

    }
    
    else if(comm>2){
        printf("Invalid no of aguments\n");
    }
    else

    {
        strcpy(directory, arr[1]);
        if (chdir(directory) != 0)
        {
            perror("Directory");
        }
        else
        {
            strcpy(prev,path);
            char *wd = getcwd(d, 100);
            strcpy(path, wd);
        }
    }
}