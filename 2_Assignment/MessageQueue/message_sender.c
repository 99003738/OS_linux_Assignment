#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int ret;
    mqd_t mqid;
    struct mq_attr attr;
    attr.mq_msgsize=256;    
    attr.mq_maxmsg=10;
    mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);  
    if(mqid<0)
    {
        perror("mq_open");
    exit(1);
    }   
    char msg[200];
    printf("Enter Message");
    scanf("%s",msg);
    int len=strlen(msg);
    ret=mq_send(mqid,msg,len,10);
    if(ret<0)
    {
        perror("fork error");
     exit(2);
   }
   return 0;
}