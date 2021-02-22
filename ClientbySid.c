/*
 * For better explanation & understanding  see Files "ClientbySid.c","ServerbySid.c" for TCP,"HammingServer.c" for UDP.
 *
 */



/* filename server_ipaddress portno

argv[0] filename
argv[1] server_ipaddress
argv[2] portno

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
/* exit(0) indicates that the program terminated without errors. exit(1) indicates that there were an error. You can use different values other than 1 to differentiate between different kind of errors. */
	}
	
	int sockfd, portno, n;
	char buffer[256];

	struct sockaddr_in serv_addr;
	struct hostent *server;
/*   The variable server is a pointer to a structure of type hostent. This structure is defined in the header file netdb.h as follows:

struct  hostent {
        char    *h_name;        //official name of host 
        char    **h_aliases;    // alias list 
        int     h_addrtype;     // host address type 
        int     h_length;       // length of address 
        char    **h_addr_list;  // list of addresses from name server 
#define h_addr  h_addr_list[0]  // address, for backward compatiblity 
};

It defines a host computer on the Internet. The members of this structure are:

h_name       Official name of the host.

h_aliases    A zero  terminated  array  of  alternate
             names for the host.

h_addrtype   The  type  of  address  being  returned;
             currently always AF_INET.

h_length     The length, in bytes, of the address.

h_addr_list  A pointer to a list of network addresses
             for the named host.  Host addresses are
             returned in network byte order.

Note that h_addr is an alias for the first address in the array of network addresses. 

 */

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		error("Error Openinn Socket.");
	}
	memset(&serv_addr,0,sizeof(serv_addr));

	portno = atoi(argv[2]);		
	
	server = gethostbyname(argv[1]);
	/*
		argv[1] contains the name of a host on the Internet, e.g. localhost/loopback The function:

     struct hostent *gethostbyname(char *name)

Takes such a name as an argument and returns a pointer to a hostent containing information about that host. The field char *h_addr contains the IP address. If this structure is NULL, the system could not locate a host with this name. 
	*/
	if(server == NULL){
		fprintf(stderr,"Error , no such host");
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);

	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)error("connection faild");

/* *******above code is for connection, only do pretty stuff below of this******* */

	while(1){
		memset(buffer,0,256);
		printf("Client: ");
		fgets(buffer,255,stdin);
		n = write(sockfd,buffer,strlen(buffer));
		if(n<0)error("Erroe on writing");

		memset(buffer,0,256);
		n = read(sockfd,buffer,255);
		if(n<0)error("Error on reading");
		printf("Server: %s",buffer);
	
		int i = strncmp("Bye",buffer,3);
		if(i==0)break;
	}

//Done
	close(sockfd);
	return 0;
}

