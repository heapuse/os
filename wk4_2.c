#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int i = 1;
    printf("%d\n",getpid());
    if(!fork() && i == 1)
    {
        printf("C1\nParent's pid : %d\nCurrent pid : %d\n\n",getppid(),getpid());
    }
    else
    {
        wait(NULL);
        i++;
    }

    if(!fork() && i == 2)
    {
        printf("C2\nParent's pid : %d\nCurrent pid : %d\n\n",getppid(),getpid());
        i++;
        if(!fork() && i == 3)
        {
            printf("C4\nParent's pid : %d\nCurrent pid : %d\n\n",getppid(),getpid());
            i++;
            if(!fork() && i == 4)
                printf("C7\nParent's pid : %d\nCurrent pid : %d\n\n",getppid(),getpid());
            else    
                wait(NULL);
        }
        else
            wait(NULL);    
    }
    else
    {
        wait(NULL);
        i += 3;
    }
    if(!fork() && i == 5)
    {
        printf("C3\nParent's pid : %d\nCurrent pid : %d\n\n",getppid(),getpid());
        i++;
        if(!fork() && i == 6)
            printf("C5\nParent's pid : %d\nCurrent pid : %d\n\n",getppid(),getpid());
        else
        {
            wait(NULL);
            i++;
        }
        if(!fork() && i == 7)
            printf("C6\nParent's pid : %d\nCurrent pid : %d\n\n",getppid(),getpid());
        else
            wait(NULL);
    }
    else
        wait(NULL);
    
}