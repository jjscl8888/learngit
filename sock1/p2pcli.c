#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include<string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<signal.h>

void handler(int sig)
{       
        printf("sig=%d\n",sig);
        exit(EXIT_SUCCESS);
}

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
                int len=read(sock,recvbuf,sizeof(recvbuf));
                if(len==0){printf("peer close\n");break;}
                fputs(recvbuf,stdout);
                }
                printf("child close\n");
                kill(getppid(),SIGUSR1);
                close(sock);
                exit(EXIT_SUCCESS);
        }
        else{
                signal(SIGUSR1,handler);
                char sendbuf[1024];
                while(fgets(sendbuf,sizeof(sendbuf),stdin)!=NULL)
                {
                        write(sock,sendbuf,sizeof(sendbuf));
                        memset(sendbuf,0,sizeof(sendbuf));
                }
                printf("parent close\n");
                close(sock);
                exit(EXIT_SUCCESS);
        }

	return 0;
}
