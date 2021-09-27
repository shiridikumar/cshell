#include "headers.h"

void pipecom(char *d,char **arr, int comm)
{
    char *command=(char *)malloc(1000*sizeof(char));
    strcpy(command,"");
    for(int i=0;i<comm;i++){
        strcat(command,arr[i]);
    }
    char** newarr=(char **)malloc(100*sizeof(char*));
    for(int i=0;i<100;i++)
    {
        newarr[i]=(char *)malloc(100*sizeof(char));
    }
    char *sub_arr=(char *)malloc(100*sizeof(char));
    int prev=0,coun=0;
    for(int i=0;i<strlen(command);i++){
        if(command[i]=='|'){
            strncpy(newarr[coun],command+prev,i-prev);
            prev=i;
        }
        coun++;
        printf("%s\n",newarr[coun-1]);
    }
}