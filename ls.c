#include "headers.h"

void display(int lf,int af,char * dir){

    struct dirent *s;
    struct stat st;
    DIR *di=opendir(dir);
    printf("%s:\n",dir);
    while ((s = readdir(di)) != NULL){
        stat(s->d_name,&st);
        if (!(af) && s->d_name[0] == '.')
            continue;
            if(lf){
                printf("%s %d bytes\n",s->d_name,st.st_size);
            }
        else{
        printf("%s\n", s->d_name);
        }

    }
    printf("\n");
}
void ls(char *c,char **arr,int comm ){
    char dir[200];
    getcwd(dir,200);
    char temp[200];
    int lf=0;
    int af=0,count;
    if(comm==1){
        lf=0;
        af=0;
    }
    char * token=strtok(c,"ls");
    int i=1;
    while(i<comm){
        if(arr[i][0]=='-'){
            if(strcmp(arr[i],"-a")==0)
                af=1;

            if(strcmp(arr[i],"-l")==0)
                lf=1;

            if(strcmp(arr[i],"-al")==0 || strcmp(arr[i],"-la")==0)
                af=1;lf=1;
        }
        i++; 
    }
    i=1,count=0;
    while(i<comm){
        if(arr[i][0]!='-'){
            strcpy(temp,dir);
            strcat(temp,"/");
            strcat(temp,arr[i]);
            display(lf,af,temp);
            count++;
        }
        i++;
    }
    (count==0)?display(lf,af,dir):count+0;

}