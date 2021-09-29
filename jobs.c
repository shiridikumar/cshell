#include "headers.h"

void jobs(char *c, char **arr,int comm){
    char *status=(char *)malloc(100*sizeof(char));
    int temp_id;
    int temp_seq;
    char * temp_name=(char *)malloc(100*sizeof(char));
    for (int i=0;i<b;i++){
        for(int j=0;j<b-1;j++){
            if(strcmp(bp[j].name,bp[j+1].name)>0){
                temp_id=bp[j].pid;temp_name=bp[j].name;temp_seq=bp[j].seq;
                bp[j].pid=bp[j+1].pid;bp[j].name=bp[j+1].name;bp[j].seq=bp[j+1].seq;
                bp[j+1].pid=temp_id;bp[j+1].name=temp_name;bp[j+1].seq=temp_seq;
            }
        }
    }
    int flag=0;
    char *state=(char *)malloc(50*sizeof(char));
    for(int i=0;i<b;i++){
        pinfo_status(c,bp[i].pid,1,status);
        if(strcmp(status,"E")!=0){
            if(strcmp(status,"R")==0)
                strcpy(state,"Running");
            else if(strcmp(status,"S")==0){
                strcpy(state,"Stopped");}
            else if(strcmp(status,"T")==0){
                strcpy(state,"Stopped");
            }
            else{
                strcpy(state,"Zombie");
            }
            if(comm==1){
                flag=1;
            }
            else{
                if(strcmp(arr[1],"-r")==0){
                    flag=(strcmp(state,"Running")==0)?1:0;
                }
                if(strcmp(arr[1],"-s")==0){
                    flag=(strcmp(state,"Stopped")==0)?1:0;
                }
            }
            if(flag==1){
                printf("[%d] %s %s [%d]\n",bp[i].seq,state,bp[i].name,bp[i].pid);
            }
        }
        strcpy(status,"");
    }


}