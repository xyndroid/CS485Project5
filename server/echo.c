/*
 * echo - read and echo text lines until client closes connection
 */
/* $begin echo */
#include "csapp.h"
#define STORAGE_LIM 20

void echo(int connfd, char** argv) 
{
    size_t n; 
    char buf[MAXLINE]; 
    rio_t rio;
	
	unsigned int clientKey;
	unsigned int skey;
	char str[100];
	char *MachineName;
	int TCPport;
	int SecretKey;
	char *variableName;
	char *value;
	int *resultLength;
	int status;
	int skey_status = 1;
	int tmp;
	int index;
	int length = 0;
    Rio_readinitb(&rio, connfd);

	skey = atoi(argv[2]);
	char ***storage = NULL;	

	// read secret key from client and check
	n = Rio_readnb(&rio, &clientKey, sizeof(clientKey));

	clientKey = ntohl(clientKey);
	printf("server received %d bytes\n", (int)n);
	printf("server received %d\n", clientKey);
	
	if(clientKey != skey){
		skey_status = 0;
		skey_status = htonl(skey_status);
		Rio_writen(connfd, &skey_status, sizeof(skey_status));
	}
	n = Rio_readnb(&rio, buf, MAXLINE);
	printf("server received %d bytes\n", (int)n);	
	printf("server received %s bytes\n", buf);
	
	// ssSet
	if(buf[0] == '0'){
		// allocate space for storage
		if (storage == NULL){
			storage = (char ***) malloc (sizeof(char**) * STORAGE_LIM);
			index = 0;
		}
		storage[index] = (char **) malloc (sizeof(char *) * 2);
		storage[index][0] = (char *) malloc (sizeof(char) * ((23-8)));
		storage[index][0] = substr(buf, 8, 23);
		storage[index][1] = (char *) malloc (sizeof(char) * (sizeof(length) + 1));
		storage[index][1] = substr(buf, 28, 28+length);
		index = index + 1;
	}else if(buf[0] == '1'){
		printf("simpleget function is being called\n");
					
	}else if(buf[0] == '2'){
	}else if(buf[0] == '3'){
	}
/* $end echo */
}

char * substr(char *str, int start, int stop){
	
	return 
}
