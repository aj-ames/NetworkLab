#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
        int sockfd,newsockfd,portno=8000,clienlen;
        char filename[256],c[2000];
        struct sockaddr_in serv_addr,clien_addr;
        int fd;
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        bzero((char*)&serv_addr,sizeof(serv_addr));
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_addr.s_addr=INADDR_ANY;
        serv_addr.sin_port=htons(portno);
        bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
        listen(sockfd,5);
        printf("Server waiting for client \n");
        clienlen=sizeof(clien_addr);
        newsockfd=accept(sockfd,(struct sockaddr*)&clien_addr,&clienlen);
        read(newsockfd,filename,255);
        fd=open(filename,O_RDONLY,0);
        read(fd,c,1999);
        send(newsockfd,c,1999,0);
        close(newsockfd);
        return 0;
}
