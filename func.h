 #include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/time.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/sem.h>
#include<time.h>
#include<pthread.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/uio.h>
#include<sys/epoll.h>
typedef struct{
        pid_t pid;
   	    int pfd;//子进程管道的对端
		short busy;//标识进程是否忙绿

}Daa,*pData;
 typedef struct{
     	int len ;
     	char buf[1000];
    }train;
   #define FILENAME "file"
   void  make_child(pData p,int pro_num);	
   void  child_handle(int pfd);
   void send_fd(int ,int ,short);
   void recv_fd(int ,int * ,short*);
   void trans_file(int);
   int sendn(int ,char*,int);
