#include "headers.h"

char *path;
char *invoked;
int *bgproc;
int proc;
char *user;
char *sysname;
char *prev;
int f;

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
    check_exitted();
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
    char *sta;
    char *finished;
    finished=(char *)malloc(200*sizeof(char));
    if(mem!=0){
        printf("\n");
    }
    sta=(char *)malloc(20*sizeof(char));
    for(int i=0;i<mem;i++){
        sta=(WIFEXITED(ep[i].status))?strcpy(sta,"Normally"):strcpy(sta,"Abnormally");
        sprintf(finished,"%s with pid %d exited %s\n%s@%s:~%s>",ep[i].name,ep[i].pid,sta,user,sysname,path);
        write(1,finished,strlen(finished));
    }
    mem=0;
}
int main()
{
    prev=(char *)malloc(200*sizeof(char));
    char * hist_path=(char *)malloc(100*sizeof(char));
    strcpy(hist_path,getenv("HOME"));
    struct stat st;
    strcat(hist_path,"/history2021121005osn.txt");
    f=open(hist_path,O_RDWR|O_CREAT|O_RDONLY);
    chmod(hist_path, S_IRWXU);
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
    char *buff=(char *)malloc(501*sizeof(char));
    char *hist_comm=(char *)malloc(501*sizeof(char));
    char *buffer=(char *)malloc(501*sizeof(char));
    
    while (1)
    {
        prompt();
        size_t size = 200;
        char c[1000];
        char *d;
        d=(char *)malloc(1000*sizeof(int));
        gets(c);
        char **arr = (char **)malloc(100 * sizeof(char *));
        int i=0;
        for (int i = 0; i < 100; i++) {
            arr[i] = (char *)malloc(100* sizeof(char));
        }
        strcpy(d,c);
        int comm=split(c,arr);
        sprintf(hist_comm,"%*s",-500,d);
        strcat(hist_comm,"\n");
        stat(hist_path,&st);
        long long file_size=st.st_size;
        lseek(f,file_size-500,SEEK_SET);
        read(f,buffer,500);
        sprintf(buff,"%*s",-500,buffer);
        strcat(buff,"\n");
        int k;
        if(strncmp(buff,hist_comm,500)!=0){
            lseek(f,file_size,SEEK_SET);
            write(f,hist_comm,500);
        }
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
        else if(strcmp(arr[0],"repeat")==0){
            repeat(d,arr,comm);
        }
        else if(strcmp(arr[0],"history")==0){
            history(d,arr,comm,f,hist_path);
        }
        else if(strcmp(arr[0],"exit")==0){
            break;
        }
        else{
            //printf("system command");
            syscom(d,arr,comm,f);
        }
    }
    close(f);
}
