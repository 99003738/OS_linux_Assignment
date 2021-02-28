#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>

int main()
{
    int fd1,fd2;

    char *chatfifo="/tmp/chatfifo";

    mkfifo(chatfifo, 0666);

    char chat1[100],chat2[100];

    while(1)
    {
        fd1=open(chatfifo,O_RDONLY);
        read(fd1,chat1,100);

        printf("USer1: %s\n",chat1);
        close(fd1);

        fd2=open(chatfifo,O_WRONLY);
        scanf("%s\n",chat2);
        write(fd2,chat2,strlen(chat2)+1);
        close(fd2);
    }
    return 0;
}