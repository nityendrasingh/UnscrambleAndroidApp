#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
	
#define BUFSIZE 1024
#define SIZE 20

void getserverip_port(char **args, char *ip, char *s_port);

void getserverip_port(char **args, char *ip, char *s_port)
{

        char **arg1;
        int i, j;
        char c;

        arg1 = args;
        i = j = 0;
        c = *arg1[2];
        while(c != '\0'){
                ip[i] = c;
                c = *++arg1[2];
                i++;
        }
        ip[i] = '\0';
        c = *++arg1[2];
        while (c != '\0'){
                s_port[j] = c;
                c = *++arg1[2];
                j++;
        }
        s_port[j] = '\0';
}

void commandline_parse(int argc , char *args[], char *ip, char *s_port, char *c_port, char *c_name)
{
	if (argc != 4){
		//printf("usage: ./client1 -s serveraddress:port -p clientport -n clientname\n");
                  printf("usage: ./clienthw clientname serverip serverport\n");
                  printf("argc : %d\n",argc); 
	}else if (argc == 4){
		//if (strcmp(args[1], "-s" ) == 0){
			getserverip_port(args, ip, s_port);
		//}
		//if(strcmp(args[3], "-p") == 0)
			//strcpy(c_port, args[4]);
		//if(strcmp(args[5] , "-n") == 0)
			strcpy(c_name, args[1]);
	}
}


//JOIN
void join(char *c_name,int sockfd1)
{
//printf("i'm inside client : %s\n", c_name);

int num,m;
num= strlen(c_name);
char buff[21];
strcpy(buff,("CCO"));
buff[4]='\0';
strcat(buff,c_name);
buff[num+4]='\0';
printf("%s\n",buff);
send(sockfd1, buff, strlen(buff), 0);

/*char join_resp[50]; 
int recv_msglen=recv(sockfd1,join_resp,60,0);
join_resp[recv_msglen]='\0';
printf("%s\n",join_resp);

/*SBCP message for JOIN: end*/

}


//

		
void send_recv(int i, int sockfd)
{
	char send_buf[BUFSIZE];
	char recv_buf[BUFSIZE];
	int nbyte_recvd;
	
	if (i == 0){
		fgets(send_buf, BUFSIZE, stdin);
		if (strcmp(send_buf , "quit\n") == 0) {
			exit(0);
		}else
			send(sockfd, send_buf, strlen(send_buf), 0);
	}else {
		nbyte_recvd = recv(sockfd, recv_buf, BUFSIZE, 0);
                  if (nbyte_recvd == 0) {
			printf("Server Shutdown !%d\n", i);
                          exit(0);
		};
		               
                recv_buf[nbyte_recvd] = '\0';
                char err[5];int e;
                for (e=0;e<5;e++)
                  { err[e]=recv_buf[e];}
                    //printf("%s\n",err);
                if(strcmp(err,"Error")==0)
                   {printf("%s\n" , recv_buf);
                     exit(0);}
		printf("%s" , recv_buf);
		fflush(stdout);
	}
}
		
		
void connect_request(int *sockfd, struct sockaddr_in *server_addr,char *ip,char *s_port,char *c_name)
{
	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Socket");
		exit(1);
	}
	server_addr->sin_family = AF_INET;
	server_addr->sin_port = htons(atoi(s_port));
	server_addr->sin_addr.s_addr = inet_addr(ip);
	memset(server_addr->sin_zero, '\0', sizeof server_addr->sin_zero);
	
	if(connect(*sockfd, (struct sockaddr *)server_addr, sizeof(struct sockaddr)) == -1) {
		perror("connect");
		exit(1);
	}
                      

}

	
int main(int argc, char *argv[])
{
	int sockfd, fdmax, i;
	struct sockaddr_in server_addr;
	fd_set master;
	fd_set read_fds;
	char ip[SIZE], s_port[SIZE], c_name[16],c_port[SIZE];
	
	commandline_parse(argc, argv, ip, s_port, c_port, c_name);
	
          printf("%s started\n", c_name);
          
	
	connect_request(&sockfd, &server_addr,ip,s_port,c_name);
 
	FD_ZERO(&master);
        FD_ZERO(&read_fds);
        FD_SET(0, &master);
        FD_SET(sockfd, &master);
	fdmax = sockfd;
	
       //JOIN Initiated 
          join(c_name,sockfd);
          //printf(">");
       //

    

	while(1){
                //printf(">");
		read_fds = master;
		if(select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1){
			perror("select");
			exit(4);
		}
		
		for(i=0; i <= fdmax; i++ )
			if(FD_ISSET(i, &read_fds)){printf(">");
				send_recv(i, sockfd);}
	}
	printf("client-quited\n");
	close(sockfd);
	return 0;
}

