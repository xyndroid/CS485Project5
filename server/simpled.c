/* 
 * simpled.c - The server 
 */ 
#include "csapp.h"
#include <string.h>

#define ENVMAX 20
#define TYPE 1

//int simpleGet(char *MachineName, int TCPport, int SecretKey, char *variableName, char *value, int *resultLength);

void echo(int, char**);

int main(int argc, char **argv) 
{
	/* API variables definition */
    int listenfd, connfd, port;
    socklen_t clientlen;
    struct sockaddr_in clientaddr;
	struct hostent *hp;
	char *haddrp;
	size_t n;
	rio_t rio;
	char buf[MAXLINE];

    if (argc != 3) {
	    fprintf(stderr, "usage: %s <port> <key>\n", argv[0]);
	    exit(0);
    }

    port = atoi(argv[1]);	// integer between 0 and 64k

	printf("port: %d, key: %d\n", port);

    listenfd = Open_listenfd(port);

    while (1) {

		printf("Accepted\n");
    	
        clientlen = sizeof(clientaddr);
    	
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);

		hp = Gethostbyaddr( (const char *)&clientaddr.sin_addr.s_addr, sizeof(clientaddr.sin_addr.s_addr), AF_INET);

		haddrp = inet_ntoa(clientaddr.sin_addr);

		printf("server connected to %s (%s)\n", hp->h_name, haddrp);

		echo(connfd, argv);
  }

	Close(connfd);

    exit(0);

}

/*
int simpleGet(char *MachineName, int TCPport, int SecretKey, char *variableName, char *value, int *resultLength){
	printf("simpleGet was called! YEAH");
}
*/
/* $end simpled server */
