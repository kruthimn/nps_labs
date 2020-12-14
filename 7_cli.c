#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<netinet/in.h>

void str_cli(FILE *fp,int sockfd)
{
int bufsize=1024,n;
char *buf=malloc(bufsize);

while(fgets(buf,bufsize,fp)!=NULL)
{
send(sockfd,buf,50,0);
//fputs(buf,stdout);
}
printf("\EOF\n");
}


int main(int argc,char *argv[])
{
int sockfd;
struct sockaddr_in addr;
addr.sin_family=AF_INET;
addr.sin_port=htons(15001);

if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("Socket created\n");

inet_pton(AF_INET,argv[1],&addr.sin_addr);
if(connect(sockfd,(struct sockaddr*)&addr,sizeof(addr))==0)
printf("Socket connected\n");
str_cli(stdin,sockfd);
return close(sockfd);
}

