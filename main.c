#include "headers.h"

char *path;
char *invoked;
int *bgproc;
int proc;

struct bg_proc bp[100];
b=0;

struct exit_proc ep[100];
mem=0;

void exitted(){
    int status;
    int x=waitpid(-1,&status,WNOHANG);
    for(int j=0;j<b;j++){
        if(x==bp[j].pid){
            ep[mem].pid=x;ep[mem].status=status;
            ep[mem].name=bp[j].name;
            mem++;
            break;
        }
    }
    /*if(x>0){
        printf("Process %d exitted succesfully\n",x);
        if(WIFEXITED(status)){
            printf("Exitted normally\n");
        }
        else{
            printf("Exitted abnormally\n");
        }
    }*/
}

void check_exitted(){
    for(int i=0;i<mem;i++){
        printf("%s with pid %d exited %s\n",ep[i].name,ep[i].pid,(WIFEXITED(ep[i].status))?"Nomrally":"Abnormally");
    }
    mem=0;
}
int main()
{
    invoked=(char *)malloc(200*sizeof(char));
    path=(char *)malloc(200*sizeof(char));
    char initial[100];
    getcwd(initial,100);
    strcpy(path,initial);
    strcpy(invoked,initial);
    proc=0;
    //signal(SIGTSTP,NULL);
    //signal(SIGCONT,NULL);
    signal(SIGCHLD,exitted);
    bgproc=(int *)malloc(1000*sizeof(int));
    while (1)
    {
        check_exitted();
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
        else if(strcmp(arr[0],"echo")==0)
            echo(d,arr,comm);
        else if(strcmp(arr[0],"pwd")==0)
            pwd(d,arr,comm);
        else if(strcmp(arr[0],"ls")==0){
            ls(d,arr,comm);
        }
        else if(strcmp(arr[0],"pinfo")==0){
            pinfo(d,arr,comm);
        }
        else if(strcmp(arr[0],"bg")==0){
            bg(d,arr,comm);
        }
        else if(strcmp(arr[0],"repeat")==0){
            repeat(d,arr,comm);
        }
        else{
            syscom(d,arr,comm);
        }
    }
}
