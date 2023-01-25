// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>



int main(int argc, char const *argv[]) 
{ 
    	int n;
	struct hostent *server;
	
	// check to see if user input is valid
	if (argc < 3){
		fprintf(stderr, "usage %s hostname port", argv[0]);
		exit(0);
	}
	
	printf("%s", argv[1]);
	server = gethostbyname(argv[1]);
    	if (server == NULL) {
        	fprintf(stderr,"ERROR, no such host\n");
        	exit(0);
    	}
	
	char socket_read_buffer[1024];
	

	// TODO: Fill out the server ip and port
	std::string server_ip = argv[1];	
	std::string server_port = argv[2];
	
	int opt = 1;
	int sockfd = -1;

	// TODO: Create a TCP socket()
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		fprintf(stderr,"ERROR OPENING SOCKET\n");
		exit(0);
	}
	// Enable reusing address and port
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}

	// Check if the client socket was set up properly
	if(sockfd == -1){
		printf("Error- Socket setup failed");
		return -1;
	}
	
	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	// Connecting to the server	
	if(connect(sockfd, server_addr->ai_addr, server_addr->ai_addrlen)<0){
		printf("Connection Issue, error code: %s",strerror(errno));
	}

	// Retreiving user input
	printf("Please enter the message: ");
	bzero(socket_read_buffer,1024);
	fgets(socket_read_buffer,1023,stdin);

	// Sending user input to the server
	n = send(sockfd,socket_read_buffer,strlen(socket_read_buffer),0); 
	if (n < 0){
        	printf("Issue when writing\n");
   		exit(0);
	}

	// Receiving messages from server
    	bzero(socket_read_buffer,1024);
    	n = read(sockfd,socket_read_buffer,1023);
    	if (n < 0){
        	printf("Issue when reading\n");
		exit(0);
    	}
    	printf("%s\n",socket_read_buffer); // printing received message

    	close(sockfd); //Closing socket
    	freeaddrinfo(server_addr); //Freeing memory allocated, no seg fault
   	return 0;
} 

