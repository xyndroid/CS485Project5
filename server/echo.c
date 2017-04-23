/*
 * echo - read and echo text lines until client closes connection
 */
/* $begin echo */
#include "csapp.h"

void echo(int connfd, char** argv) 
{
    size_t n; 
    char buf[MAXLINE]; 
    rio_t rio;
	
	unsigned int clientKey;
	unsigned int skey;
	
    Rio_readinitb(&rio, connfd);

	skey = atoi(argv[2]);

	// read secret key from client and check
	n = Rio_readnb(&rio, &clientKey, sizeof(clientKey));

	clientKey = ntohl(clientKey);

	printf("server received %d bytes\n", (int)n);

	printf("server received %d\n", clientKey);

	if(clientKey != argv[2]){

		Rio_writen(connfd, "Invalid secret key", 18);

	}

	n = Rio_readnb(&rio, buf, MAXLINE);
	printf("server received %d bytes\n", (int)n);

	n = Rio_readnb(&rio, buf, MAXLINE);
	printf("server received %d bytes\n", (int)n);
	
}
/* $end echo */

