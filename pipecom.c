#include "headers.h"

void pipecom(char *d,char **arr, int comm,char *hist_comm,char * hist_path,char *buffer,char *buff)
{
    char *command=(char *)malloc(1000*sizeof(char));
    strcpy(command,"");
    for(int i=0;i<comm;i++){
        strcat(command," ");
        strcat(command,arr[i]);
    }
    char** newarr=(char **)malloc(100*sizeof(char*));
    for(int i=0;i<100;i++)
    {
        newarr[i]=(char *)malloc(100*sizeof(char));
    }
    int prev=0,coun=0;
    for(int i=0;i<strlen(command);i++){
        if(command[i]=='|'){
            strncpy(newarr[coun],command+prev,i-prev);
            prev=i+1;
        }
        coun++;
    }
    strncpy(newarr[coun++],command+prev,strlen(command)-prev);
    int pipe_in,pipe_out;
    for(int i=0;i<coun;i++){
        pipe_out=open("pipe_out.txt",O_CREAT|O_WRONLY);
        if(dup2(pipe_out,1)<0){
            perror("Unable to execute pipe command");
        }
        char **sub_arr = (char **)malloc(100 * sizeof(char *));
        int i = 0;
        int ends[2];
        if(pipe(ends)<0){
            perror("could not create pipe");
        }
        dup2(ends[1],1);
        execute(newarr[i],hist_comm, hist_path, buffer, buff);
        dup2(ends[0],0);
    }
    

}