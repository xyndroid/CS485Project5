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
	char *value;

	/*  The command line arguments must be five */
	/* 
		argv[0] - name of this program
		argv[1] - server DNS name or IP address
		argv[2] - port number
		argv[3] - secret key
		argv[4] - variable name
		argv[5] - value
	*/

    if (argc != 6) {
	    fprintf(stderr, "usage: %s <host> <port number> <secret key> <variable name> <value>\n", argv[0]);
	    exit(0);
    }

    host = argv[1];     	// string - length of the host name shouldn't exceed 40 characters
    port = atoi(argv[2]);	// integer - shouldn't exceed 64k
    skey = atoi(argv[3]);	// integer - should be between 0 and 2^32 - 1
	varname = (char*) calloc (sizeof(char), (15));
    varname = argv[4];		// string
	value = (char *) calloc ( sizeof(char), (strlen(argv[5]) + 1));
	value = argv[5];

    if(strlen(varname) > 15){
        fprintf(stderr, "The variable name length should be less than 15 characters.\n"); 
        exit(0);    
    }

    if(strlen(value) > 100){
        fprintf(stderr, "The value length should be less than 100 characters.\n"); 
        exit(0);    
    }

    /* all the setups are made through Open_clientfd. */
  	clientfd = Open_clientfd(host, port);
    
    /* initializes "rio" */
    Rio_readinitb(&rio, clientfd);


//	Rio_writen(clientfd, "hello", 6);
//	Rio_writen(clientfd, "friend", 7);
//	Rio_writen(clientfd, "this is test", 13);
	/* * *
	 * * * 
	 * * */

	tmp = htonl(skey);

	// send 4 byte password
    Rio_writen(clientfd, &tmp, sizeof(tmp)); 	// write n bytes  - send 

	// key secret key status
//	Rio_readnb(&rio, &skey_status, sizeof(skey_status));
//	skey_status = ntohl(skey_status);
//	printf("key status is %d", skey_status);
//	if(skey_status == 0){
//		printf("failed\n");
//		Close(clientfd);
//		exit(0);
//	}
	// type of the client - 0 and buffer
	Rio_writen(clientfd, "0xxx", 4);

/*
	int j = strlen(varname) + 1;
	int i = 0;
	for(i = 0; i < 14; i++){
		if(i > strlen(varname)){
			varname[j] = 'X';
			j++;
		}
	}

	varname[j] = '\0';
*/
	Fputs(varname, stdout);
	Rio_writen(clientfd, varname, 23 - 8);

	uint32_t tmp2;	

	tmp2 = strlen(value);
	printf("\nThe legnth of tmp2 is: %zd \n", tmp2);
	tmp2 = htonl(tmp2);
	Rio_writen(clientfd, &tmp2, sizeof(tmp2));
	printf("The valueh of tmp2 is: %s \n", value);

//	Rio_writen(clientfd, value, 4);

//	Riio_writen(clientfd, value, strlen(value));
	
    Close(clientfd); //line:netp:echoclient:close

    exit(0);

}
/* $end echoclientmain */
