/*
 * For better explanation & understanding  see Files "ClientbySid.c","ServerbySid.c" for TCP,"HammingServer.c" for UDP.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg){
	perror(msg);
	exit(1);
}
int main(int argc,char *argv[]){
	
	if(argc<3){
		fprintf(stderr,"usage %s hostname port\n",argv[0]);
		exit(1);
	}
	int sockfd, portno, n;
	char buffer[256];
	socklen_t len;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0){
		error("Error Openinn Socket.");
	}
	memset(&serv_addr,0,sizeof(serv_addr));

	portno = atoi(argv[2]);		
	
	server = gethostbyname(argv[1]);
	if(server == NULL){
		fprintf(stderr,"Error , no such host");
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);
	len = sizeof(serv_addr);
	//sendto(sockfd,buffer,,0,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

/* *******above code is for connection, only do pretty stuff below of this******* */

int data[10];
printf("Plese input 4 bits of data\n");
scanf("%d",&data[0]);
scanf("%d",&data[1]);
scanf("%d",&data[2]);
scanf("%d",&data[4]);

// calculation fro even parity encoding
data[6]= data[4]^data[2]^data[0];
data[5]= data[4]^data[1]^data[0];
data[3]= data[2]^data[1]^data[0];

//sending the encoded data to clients
for(int i=0; i<7; i++){
	n = sendto(sockfd,&data[i],sizeof(data[i]),0,(struct sockaddr *)&serv_addr,len);
	if(n<0)printf("Error while sending");
}

printf("\nThe data sent is: ");
for(int i=0; i<7; i++){
	printf("%d",data[i]);
}
printf("\n");
//Done
	close(sockfd);
	return 0;
}



