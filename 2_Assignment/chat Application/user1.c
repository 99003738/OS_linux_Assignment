# include<unistd.h>
# include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>

int main()
{
    int fd;
    char *chatfifo="/tmp/chatfifo";
    mkfifo(chatfifo,0666);

    char chat1[100],chat2[100];
    while(1)
    {
        fd=open(chatfifo,O_WRONLY);
        scanf("%s",chat2);

        write(fd,chat2,strlen(chat2)+1);
        fd=open(chatfifo,O_RDONLY);

        read(fd,chat1,sizeof(chat1));
        printf("User 2: %s\n",chat1);
        
        close(fd);
    }
    return 0;
}