#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>


int main(int argc,char *argv[])
{
	
    pid_t cpid;
    int max_size =100;
    char cmd[max_size]; //cmd is for full command line
    char *usercmd[max_size];
    int i=0;
    while(1)//10 for max it can 10 cmds
    {
        //memset(usercmd,0,max_size*max_size);
       //  memset(cmd,0,max_size);
        printf("\n\nEnter Shell command:");
        scanf("%s",cmd);
        pid_t ret;
        ret=fork();
        if(ret==0)
        {
            int k;
            k=execlp(cmd,usercmd,NULL);
    		    if(k<0)
		        {
			        perror("execlp");
			        exit(2);
		        }
            exit(0);
        }
        else
        if(ret>0)
       {
          int status;
          cpid=waitpid(-1,&status,0);
          printf("\nExit status %d",WEXITSTATUS(status));
       }
      else
      { 
        perror("fork error");
         exit(3);
       }
    }
}