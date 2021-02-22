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
#include <ctype.h>
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

	struct sockaddr_in serv_addr;
	struct hostent *server;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
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

	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)error("connection faild");

/* *******above code is for connection, only do pretty stuff below of this******* */

	FILE *fp;
	int words = 0;
	fp = fopen("test.txt","r");
	char ch;
	while((ch=fgetc(fp))!=EOF){
			words++;
	}
	printf("Words: %d\n",words);	
	write(sockfd,&words,sizeof(int));
	rewind(fp);
	char cp;
	while((cp=fgetc(fp))!=EOF){
		write(sockfd,&cp,sizeof(char));
	}
	printf("The file has been successfully sent. Thank you\n");
//Done
	close(sockfd);
	return 0;
}

