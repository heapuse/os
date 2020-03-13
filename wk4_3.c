#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int status = 1;
int main(int argc,char** argv)
{
    pid_t pid;
    pid = fork();
    if(pid == -1)
    {
        perror("fork failed\n");
        return EXIT_FAILURE;
    }
    else if(pid == 0)
    {
        printf("[Parent] : Entering Child Process \n");
        if(execlp("./array","array",argv[1],NULL) == -1)
        {
            perror("execlp failed\n");
            status = 0;
            return EXIT_FAILURE;
        }
    }
    else 
    {
        if(status)
        {
            printf("[Parent] : Waiting for child process\n");
            wait(NULL);
            printf("[Parent] : Child with pid %d finished and unloaded \n",pid);
        }
    }
}