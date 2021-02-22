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
#include <ctype.h>
void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc,char *argv[]){

	if(argc<2){
		fprintf(stderr,"port not provided. program terminated\n");
		exit(1);
	}
	int sockfd, newsockfd, portno, n, clilen;
	char buffer[256];
	struct sockaddr_in serv_addr,cli_addr;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		error("Error Openinn Socket.");
	}
	memset(&serv_addr,0,sizeof(struct sockaddr_in));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
		error("Binding Faild.");
	
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
	if(newsockfd<0)error("Error on Accept\n");

/* *******above code is for connection only, do pretty stuff below of this******* */
	FILE *fp;
	int words;
	int word = 0;
	fp = fopen("testrecivied.txt","a");
	char ch;
	read(newsockfd,&words,sizeof(int));
	while(word!=words){
		read(newsockfd,&ch,sizeof(char));
		fprintf(fp,"%c",ch);
		word++;
	}	
	printf("\nThe file has been successfully reivied. It saved by name \" testrecivied.txt\" \n");
//Done
	close(newsockfd);
	close(sockfd);
	return 0;
}
