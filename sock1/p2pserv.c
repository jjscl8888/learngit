#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include<unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<signal.h>

void handler(int sig)
{
	printf("sig=%d\n",sig);
	exit(EXIT_SUCCESS);
}

int main()
{
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1)exit(-1);
	
	struct sockaddr_in servaddr;
	memset(&servaddr,0,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(5188);
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	socklen_t len=sizeof(servaddr);

	int on=1;
	setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	if(bind(sock,(struct sockaddr*)&servaddr,len)<0)exit(-1);
	
	if(listen(sock,SOMAXCONN)<0)exit(-1);
	
	struct sockaddr_in peeraddr;
	memset(&peeraddr,0,sizeof(peeraddr));
	socklen_t peerlen=sizeof(peeraddr);
	
	int conn=accept(sock,(struct sockaddr*)&peeraddr,&peerlen);
	printf("%s  %d\n",inet_ntoa(peeraddr.sin_addr),ntohs(peeraddr.sin_port));
	
	pid_t pid;
	pid=fork();
	if(pid==-1)
		exit(EXIT_FAILURE);
	else if(pid==0)
	{
		char recvbuf[1024];
        	while(1)
        	{
                memset(recvbuf,0,sizeof(recvbuf));
                int len=read(conn,recvbuf,sizeof(recvbuf));
		if(len==0){printf("peer close\n");break;}
                fputs(recvbuf,stdout);
		}
		printf("child close\n");
		kill(getppid(),SIGUSR1);
		close(conn);
		exit(EXIT_SUCCESS);
	}
	else{
		signal(SIGUSR1,handler);
		char sendbuf[1024];
		while(fgets(sendbuf,sizeof(sendbuf),stdin)!=NULL)
	        {
                	write(conn,sendbuf,sizeof(sendbuf));
			memset(sendbuf,0,sizeof(sendbuf));
        	}
		printf("parent close\n");
		close(conn);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
