# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Munir Bshara

## Lab Question Answers

Answer for Question 1: 




### QC.1

Argc denotes the amount of command line inputs. *argv[] denotes a pointer to an array which contains the various command line inputs. This array will always be of size argc.

### QC.2

A UNIX file descriptor is a number in the file descriptor table that uniquely identifies an open file in the computer's operating system. Every file must have at least 1 file descriptor and this descriptor is a non-negative integer. Intuitively, the file descriptor table contains all the file descriptors on a computer's operating system.
---
Citation: https://www.computerhope.com/jargon/f/file-descriptor.html

### QC.3

A struct is a way to group many variables in one place. These variables can be of different types. Sockaddr_in is a structure which is used to handle internet addresses. The structure is in the form of:
	'struct sockaddr_in {
        	short            sin_family;  
        	unsigned short   sin_port;    
        	struct in_addr   sin_addr;    
        	char             sin_zero[8];  
        };'
Citation: https://linuxhint.com/sockaddr-in-structure-usage-c/

### QC.4

	The input parameters for socket() in order are:
		int domain: Specifies communication domain
		int type: Specifies communication semantics
		int protocol: Specifies protocol value. Internet Protocol is 0.
	The reurn value for socket() is an int which will return the file descriptor of a socket if successful, otherwise returns -1.
	Citation: https://man7.org/linux/man-pages/man2/socket.2.html

### QC.5

	The input parameters for bind() in order are:
		int sockfd: The file descriptor referring to the socket
		const struct sockaddr *addr: The address
		socklen_t addrlen: size in bytes of the adress structure which addr points to.
	Citation: https://man7.org/linux/man-pages/man2/bind.2.html
	
	The input parameters for listen() in order are:
		int sockfd: The file descriptor referring to the socket
		int backlog: Maximum length of the queue of pending connections for sockfd.
	Citation: https://man7.org/linux/man-pages/man2/listen.2.html

### QC.6

	We use a while(1) because this allows us to have more than one connection to the server since after one message is sent and received, the socket does not close and it continues waiting for a new socket connection and message. If this while loop isnt there, only 1 message would be able to be sent as the socket will close not after the first.
	If there are multiple simultaneous connections, the server will wait on the first client message before accepting the other messages. And thus if the first client never sends a message, even if the other clinets sned their message, the message will never be received by the server. Also, there is no way to close the socket since there is no way to exit the while loop, this forces the user to have to use an exit or kill command on the server.

### QC.7

	Fork is used to create new processes called child processes. These child processes can run concurrently with the parent process. This means that as the parent process which in this case would the initial connection to the server, if a new connection is formed with a new client then this would create a child process so that both can communicate with the server at the same time without having to wait for the the initial parent process.
	Citation: https://www.geeksforgeeks.org/fork-system-call/

### Extra Q??
