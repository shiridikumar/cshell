#include "headers.h"

void jobs(char *c, char **arr,int comm){
    char *status=(char *)malloc(100*sizeof(char));
    for (int i=0;i<b;i++){
        pinfo_status(c,bp[i].pid,1,status);
        printf("[%d] %d %s %s\n",i+1,bp[i].pid,bp[i].name,status);
    }
}