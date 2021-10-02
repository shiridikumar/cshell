#include "headers.h"

void fg(char *d, char **arr, int comm)
{
    int gp;
    int gpid;
    int flag = 0;
    sscanf(arr[1], "%d", &gp);
    for (int i = 0; i < b; i++)
    {
        if (gp == bp[i].seq)
        {
            gpid = bp[i].pid;
            flag = 1;
            printf("%s\n",bp[i].name);
            break;
        }
    }
    if (flag == 0)
    {
        printf("No Job exists\n");
    }
    else
    {
        int dup_pid = getpgrp();
        signal(SIGTTIN, SIG_IGN);
        signal(SIGTTOU, SIG_IGN);
        tcsetpgrp(STDIN_FILENO, gpid);
        tcsetpgrp(STDOUT_FILENO, gpid);
        int status;
        waitpid(gpid, &status, 0);
        tcsetpgrp(STDIN_FILENO, dup_pid);
        tcsetpgrp(STDOUT_FILENO, dup_pid);
        signal(SIGTTIN, SIG_DFL);
        signal(SIGTTOU, SIG_DFL);
    }
}