#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include<string.h>
#include <sys/socket.h>
       #include <netinet/in.h>
       #include <arpa/inet.h>
#include<unistd.h>


int main()
{
	int sock=socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in servaddr;
        memset(&servaddr,0,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_port=htons(5188);
        servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        socklen_t len=sizeof(servaddr);
        if(connect(sock,(struct sockaddr*)&servaddr,len)<0)exit(-1);	

	char sendbuf[1024];
	memset(sendbuf,0,sizeof(sendbuf)); 
	while(fgets(sendbuf,sizeof(sendbuf),stdin)!=NULL)
	{
		fputs(sendbuf,stdout);
		write(sock,sendbuf,sizeof(sendbuf));
		memset(sendbuf,0,sizeof(sendbuf));
		read(sock,sendbuf,sizeof(sendbuf));
		memset(sendbuf,0,sizeof(sendbuf));
	}
	close(sock);
	return 0;
}
