#include <stdio.h>    
#include <unistd.h>
#include<stdlib.h>
#include <fcntl.h>
#include<limits.h>
#include<string.h>
#include <dirent.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<errno.h>


struct bg_proc{
    int pid;
    char* name;
    int seq;
};

struct bg_proc bp[1000];

int b;
int s;

struct exit_proc{
    int status;
    int pid;
    char* name;
    int num;
};
int mem;

