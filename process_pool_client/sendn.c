#include"func.h"
void sendn(int sfd,char *buf ,int len)
{
		int total=0;//累计发送
		int ret;//实际发送
		while(total<len)
		{
			 ret=send(sfd,buf+total,len-total,0);
			 total=total+ret;		
		}
}
void recvn(int sfd,char *buf ,int len)
{
		int total=0;//累计发送的字符
		int ret;//实际发送的字符
		while(total<len)
		{
			 ret=recv(sfd,buf+total,len-total,0);
			 total=total+ret;		
		}
}
