#include"func.h"
int main(int argc,char *argv[])
{
		if(argc!=3)
		{
				printf("error args\n");
						return -1;

		}
		int sfd;
	    sfd=socket(AF_INET,SOCK_STREAM,0);
		if(-1==sfd)
		{
				perror("socket");
				return -1;
		}
		struct sockaddr_in seraddr;
		bzero(&seraddr,sizeof(seraddr));
		seraddr.sin_family=AF_INET;
		seraddr.sin_port=htons(atoi(argv[2]));
		seraddr.sin_addr.s_addr=inet_addr(argv[1]);
    	int ret=connect(sfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
		if(-1==ret)
		{
				perror("connect");  
				return -1;
		}
        char buf[1000]={0};
		int len;
		int fd;
		recvn(sfd,(char*)&len,sizeof(len));//接收长度
		recvn(sfd,buf,len);//接收内容文件名
		fd=open(buf,O_RDWR|O_CREAT,0666);
        if(-1==fd)
		{
			perror("open");
			return -1;
		}

		while(1)
		{
		  recvn(sfd,(char*)&len,sizeof(len));
          if(len>0)
		  {
		    bzero(buf,sizeof(buf));
		    recvn(sfd,buf,len);
            write(fd,buf,len);
		  }
		  else
		  {
				  break;
		  }
		}
		close(fd);
		close(sfd);
}
