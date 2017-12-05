#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
        int sockfd,portno=8000;
        struct sockaddr_in serv_addr;
        char filename[256],c[2000];
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        bzero((char*)&serv_addr,sizeof(serv_addr));
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_port=htons(portno);
        serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
        connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
        printf("Enter the filename with path\n");
        scanf("%s",filename);
        write(sockfd,filename,255);
        bzero(c,2000);
        recv(sockfd,c,1999,0);
        printf("recieved:\n%s",c);
        close(sockfd);
        return 0;
}
