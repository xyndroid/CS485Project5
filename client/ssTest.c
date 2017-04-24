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

    if (argc != 5) {
	    fprintf(stderr, "usage: %s <host> <port number> <secret key> <variable name> <value>\n", argv[0]);
	    exit(0);
    }

    host = argv[1];     	// string - length of the host name shouldn't exceed 40 characters
    port = atoi(argv[2]);	// integer - shouldn't exceed 64k
    skey = atoi(argv[3]);	// integer - should be between 0 and 2^32 - 1
    varname = argv[4];		// string
//	value = (char *) malloc ( sizeof(char) * (strlen(argv[5]) + 1));
	value = argv[5];

    /* all the setups are made through Open_clientfd. */
  	clientfd = Open_clientfd(host, port);
    
    /* initializes "rio" */
    Rio_readinitb(&rio, clientfd);

	Rio_writen(clientfd, "hello", 5);
//	Rio_writen(clientfd, "friend", 7);
//	Rio_writen(clientfd, "this is test", 13);

	Rio_readnb(&rio, buf, strlen(buf));
	Fputs(buf, stdout);

    Close(clientfd); //line:netp:echoclient:close

    exit(0);

}
