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
        char c[300];
        char d[300];
        gets(c);
        char **arr = (char **)malloc(100 * sizeof(char *));
        int i=0;
        for (int i = 0; i < 100; i++) {
            arr[i] = (char *)malloc(100* sizeof(char));
        }
        strcpy(d,c);
        int comm=split(c,arr);

        if(strcmp(arr[0],"cd")==0)
            cd(d,arr,comm);

        if(strcmp(arr[0],"echo")==0)
            echo(d,arr,comm);
        if(strcmp(arr[0],"pwd")==0)
            pwd(d,arr,comm);
        if(strcmp(arr[0],"ls")==0){
            ls(d,arr,comm);
        }
    }
}
