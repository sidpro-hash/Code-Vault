/*
 * For better explanation & understanding  see Files "ClientbySid.c","ServerbySid.c" for TCP,"HammingServer.c" for UDP.
 *
 */


/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
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

//if we pass a value to a program, value of argc would be 2 (one for argument and one for program name) 
//Argv[0] is the name of the program , After that till argv[argc-1] every element is command -line arguments.

int main(int argc,char *argv[]){

//We know most famous file descriptors are 0, 1 and 2. 0 corresponds to STDIN , 1 to STDOUT , and 2 to STDERR 
	
	if(argc<2){
		fprintf(stderr,"port not provided. program terminated\n");
		exit(1);
/* exit(0) indicates that the program terminated without errors. exit(1) indicates that there were an error. You can use different values other than 1 to differentiate between different kind of errors. */
	}
	
	int sockfd, newsockfd, portno, n, clilen;
	char buffer[256];


//      sockfd and newsockfd are file descriptors
/*In simple words, when you open a file, the operating system creates an entry to represent that file and store the information about that opened file. So if there are 100 files opened in your OS then there will be 100 entries in OS (somewhere in kernel). These entries are represented by integers like (...100, 101, 102....). This entry number is the file descriptor. So it is just an integer number that uniquely represents an opened file in operating system. If your process opens 10 files then your Process table will have 10 entries for file descriptors.

Similarly when you open a network socket, it is also represented by an integer and it is called Socket Descriptor.Socket is nothing but a file in UNIX operating system. Even everything is treated as a file in UNIX Operating system. Whenever we create a socket an entry is made in the file descriptor table which contains standard i/o and standard errors and other details. The file descriptor acts as a pointer to the File Table which contains information about what action is to be taken i.e read, write, etc, and it contains pointers to the inode table of that particular file and as you might know inode contains all the necessary deatils of a file.*/

//portno stores the port number on which the server accepts connections. 

//n is the return value for the read() and write() calls; i.e. it contains the number of characters read or written. 

//clilen is for store sizeof client address. 

//The server reads characters from the socket connection into this buffer. 

	struct sockaddr_in serv_addr,cli_addr;

/*
A sockaddr_in is a structure containing an internet address. This structure is defined in <netinet/in.h>. Here is the definition:

struct sockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
};

An in_addr structure, defined in the same header file, contains only one field, a unsigned long called s_addr. The variable serv_addr will contain the address of the server, and cli_addr will contain the address of the client which connects to the server. 
*/

/*
struct in_addr {
		u_long S_addr;
};*/

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		error("Error Openinn Socket.");
	}
	memset(&serv_addr,0,sizeof(struct sockaddr_in)); /* void * memset ( void * ptr, int value, size_t num ); 
ptr 		Pointer to the block of memory to fill.
value		Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
num 		Number of bytes to be set to the value. size_t is an unsigned integral type. */
	portno = atoi(argv[1]);		/*function is used to convert a string argument to an integer.If strn is a valid input, then the function returns the equivalent integer number for the passed string number. If no valid conversion takes place, then the function returns zero.*/
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);    		/*The htons function takes a 16-bit number in host byte order and returns a 16-bit number in network byte order used in TCP/IP networks (the AF_INET or AF_INET6 address family). The htons function can be used to convert an IP port number in host byte order to the IP port number in network byte order.*/

// INADDR_ANY
/*
Usually there are several interfaces on a specific machine, i.e. the pseudo-interface loopback where the machine can reach itself, ethernet, WLAN, VPN... . Each of these interfaces can have multiple IP addresses assigned. For example, loopback usually has 127.0.0.1 and with IPv6 also ::1, but you can assign others too. Ethernet or WLAN have the IP addresses on the local network, i.e. 172.16.0.34 or whatever.

If you bind a socket for receiving data to a specific address you can only receive data sent to this specific IP address. For example, if you bind to 127.0.0.1 you will be able to receive data from your own system but not from some other system on the local network, because they cannot send data to your 127.0.0.1: for one any data to 127.0.0.1 will be sent to their own 127.0.0.1 and second your 127.0.0.1 is an address on your internal loopback interface which is not reachable from outside.

You can also bind a socket to a catch-all address like 0.0.0.0 (Ipv4) and :: (Ipv6). In this case it is not bound to a specific IP address but will be able to receive data send to any IP address of the machine.
*/


//sockaddr is a generic descriptor for any kind of socket operation, whereas sockaddr_in is a struct specific to IP-based communication (IIRC, "in" stands for "InterNet").
//Structure used by kernel to store most addresses.
/*
struct sockaddr {
	u_short	sa_family;		//address family 
	char	sa_data[14];		// up to 14 bytes of direct address 
};
*/	
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
		error("Binding Faild.");
	
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
	if(newsockfd<0)error("Error on Accept\n");

/* *******above code is for connection, only do pretty stuff below of this******* */

	while(1){
		memset(buffer,0,256);
		n = read(newsockfd,buffer,255);
		if(n<0)error("Error on reading");
		printf("Client: %s",buffer);
		memset(buffer,0,256);
		printf("Server: ");
		fgets(buffer,255,stdin);
		n = write(newsockfd,buffer,strlen(buffer));
		if(n<0)error("Erroe on writing");
		int i = strncmp("Bye",buffer,3);
		if(i==0)break;
	}

//Done
	close(newsockfd);
	close(sockfd);
	return 0;
}
