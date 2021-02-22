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

void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc,char *argv[]){

	if(argc<2){
		fprintf(stderr,"port not provided. program terminated\n");
		exit(1);
	}
	int sockfd, portno, n;
	socklen_t clilen;
	char buffer[256];
	memset(buffer,0,256);
	struct sockaddr_in serv_addr,cli_addr;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
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
	
	clilen = sizeof(cli_addr);
/* 
NAME

    recvfrom - receive a message from a socket

SYNOPSIS

    #include <sys/socket.h>

    ssize_t recvfrom(int socket, void *restrict buffer, size_t length,
           int flags, struct sockaddr *restrict address,
           socklen_t *restrict address_len);

DESCRIPTION

    The recvfrom() function shall receive a message from a connection-mode or connectionless-mode socket. It is normally used with connectionless-mode sockets because it permits the application to retrieve the source address of received data.

    The recvfrom() function takes the following arguments:

    socket
        Specifies the socket file descriptor.
    buffer
        Points to the buffer where the message should be stored.
    length
        Specifies the length in bytes of the buffer pointed to by the buffer argument.
    flags
        Specifies the type of message reception. Values of this argument are formed by logically OR'ing zero or more of the following values:

        MSG_PEEK
            Peeks at an incoming message. The data is treated as unread and the next recvfrom() or similar function shall still return this data.
        MSG_OOB
            Requests out-of-band data. The significance and semantics of out-of-band data are protocol-specific.
        MSG_WAITALL
            On SOCK_STREAM sockets this requests that the function block until the full amount of data can be returned. The function may return the smaller amount of data if the socket is a message-based socket, if a signal is caught, if the connection is terminated, if MSG_PEEK was specified, or if an error is pending for the socket.

    address
        A null pointer, or points to a sockaddr structure in which the sending address is to be stored. The length and format of the address depend on the address family of the socket.
    address_len
        Specifies the length of the sockaddr structure pointed to by the address argument.

    The recvfrom() function shall return the length of the message written to the buffer pointed to by the buffer argument. For message-based sockets, such as [RS] [Option Start]  SOCK_RAW, [Option End] SOCK_DGRAM, and SOCK_SEQPACKET, the entire message shall be read in a single operation. If a message is too long to fit in the supplied buffer, and MSG_PEEK is not set in the flags argument, the excess bytes shall be discarded. For stream-based sockets, such as SOCK_STREAM, message boundaries shall be ignored. In this case, data shall be returned to the user as soon as it becomes available, and no data shall be discarded.

    If the MSG_WAITALL flag is not set, data shall be returned only up to the end of the first message.

    Not all protocols provide the source address for messages. If the address argument is not a null pointer and the protocol provides the source address of messages, the source address of the received message shall be stored in the sockaddr structure pointed to by the address argument, and the length of this address shall be stored in the object pointed to by the address_len argument.

    If the actual length of the address is greater than the length of the supplied sockaddr structure, the stored address shall be truncated.

    If the address argument is not a null pointer and the protocol does not provide the source address of messages, the value stored in the object pointed to by address is unspecified.

    If no messages are available at the socket and O_NONBLOCK is not set on the socket's file descriptor, recvfrom() shall block until a message arrives. If no messages are available at the socket and O_NONBLOCK is set on the socket's file descriptor, recvfrom() shall fail and set errno to [EAGAIN] or [EWOULDBLOCK].

RETURN VALUE

    Upon successful completion, recvfrom() shall return the length of the message in bytes. If no messages are available to be received and the peer has performed an orderly shutdown, recvfrom() shall return 0. Otherwise, the function shall return -1 and set errno to indicate the error.

 */
	//recvfrom(sockfd,buffer,255,0,(struct sockaddr *)&cli_addr,&clilen);
	//printf("\nClient : %s",buffer);

/* *******above code is for connection, only do pretty stuff below of this******* */

int data[10];
int test[10];
int p,p1,p2,p4;
printf("The data received is: ");
for(int i=0;i<7;i++){
	n = recvfrom(sockfd,&data[i],sizeof(data[i]),0,(struct sockaddr *)&cli_addr,&clilen);
	if(n<0)printf("Error while receiving");
	printf("%d",data[i]);
}
printf("\nEnter data to tested: \n");
for(int i=0;i<7;i++){
	scanf("%d",&test[i]);
}
p1= test[6]^test[4]^test[2]^test[0];
p2= test[5]^test[4]^test[1]^test[0];
p4= test[3]^test[2]^test[1]^test[0];

p = (4*p4)+(2*p2)+p1;
printf("The data for testing is: ");
	for(int i=0;i<7;i++){
		printf("%d",test[i]);
	}
if(p==0){printf("No Error");}
else{
	printf("\nThe Error is at position %d",p);
	printf("\nThe correct data is:");
	if(test[7-p]==0)
		test[7-p]=1;
	else
		test[7-p]=0;

	for(int i=0;i<7;i++){
		printf("%d",test[i]);
	}
}
printf("\n");

//Done
	//close(newsockfd);
	close(sockfd);
	return 0;
}

