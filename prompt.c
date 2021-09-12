#include "prompt.h"
#include "headers.h"
extern char *path;
extern char *invoked;
void prompt() {
    char *user;
    int cmp;
    user=(char *)malloc(30*sizeof(char));
    user=getlogin();
    char * sysname;
    sysname=(char *)malloc(30*sizeof(char));
    gethostname(sysname,HOST_NAME_MAX+1);
    cmp=strncmp(path,invoked,strlen(invoked));
    if(cmp==0){
        path+=strlen(invoked);
    }
    printf("%s@%s:~%s>",user,sysname,path);    
    
}
