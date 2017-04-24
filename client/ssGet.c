/*
 * ssGet.c - An get client
 * This client should get value of variable
 * from server.
 */
#include "csapp.h"
#include <string.h>
#include <arpa/inet.h>

#define TYPE 1

int main(int argc, char **argv) 
{
    int clientfd, port;
    char *host, buf[MAXLINE];
    char *varname;
    int skey;
    rio_t rio;
    size_t n;

	uint32_t tmp;
	int skey_status = 1;
	char type[1] = "1";

	/*  The command line arguments must be five */
	/* 
		argv[0] - name of this program
		argv[1] - server DNS name or IP address
		argv[2] - port number
		argv[3] - secret key
		argv[4] - variable name
	*/

    if (argc != 5) {
	    fprintf(stderr, "usage: %s <host> <port number> <secret key> <variable name>\n", argv[0]);
	    exit(0);
    }

    host = argv[1];     	// string - length of the host name shouldn't exceed 40 characters
    port = atoi(argv[2]);	// integer - shouldn't exceed 64k
    skey = atoi(argv[3]);	// integer - should be between 0 and 2^32 - 1
    varname = argv[4];		// string

    if(strlen(varname) > 15){
        fprintf(stderr, "The file name length should be less than 80 characters.\n"); 
        exit(0);    
    }

    /* all the setups are made through Open_clientfd. */
  	clientfd = Open_clientfd(host, port);
    
    /* initializes "rio" */
    Rio_readinitb(&rio, clientfd);


	/* * *
	 * * * 
	 * * */

	tmp = htonl(skey);

	// send 4 byte password
    Rio_writen(clientfd, &tmp, sizeof(tmp)); 	// write n bytes  - send 

	// key secret key status
	Rio_readnb(&rio, &skey_status, sizeof(skey_status));
	skey_status = ntohl(skey_status);
	printf("key status is %d", skey_status);
	if(skey_status == 0){
		printf("failed\n");
		Close(clientfd);
		exit(0);
	}
	// type of the client - 1
	Rio_writen(clientfd, "1", 1);

	// padding with three zeros
	Rio_writen(clientfd, "xxx", 3);

	Rio_writen(clientfd, varname, 23 - 8);
	
    Close(clientfd); //line:netp:echoclient:close

    exit(0);

}
/* $end echoclientmain */
