#include "prompt.h"
#include "headers.h"
extern char *path;
void prompt() {
    char *user;
    user=(char *)malloc(30*sizeof(char));
    user=getlogin();
    char * sysname;
    sysname=(char *)malloc(30*sizeof(char));
    gethostname(sysname,HOST_NAME_MAX+1);
    printf("%s@%s:~%s>",user,sysname,path);    
    
}
