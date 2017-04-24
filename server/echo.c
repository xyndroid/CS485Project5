/*
 * echo - read and echo text lines until client closes connection
 */
/* $begin echo */
#include "csapp.h"
#define STORAGE_LIM 20

char *substr(char *str, int start, int stop);

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
	uint32_t length = 0;
    Rio_readinitb(&rio, connfd);

	skey = atoi(argv[2]);
	char ***storage = NULL;	
	
	printf("print here:\n");
	n = Rio_readnb(&rio, buf, strlen(buf));
	Fputs(buf, stdout);

/*
	// read secret key from client and check
	n = Rio_readnb(&rio, &clientKey, sizeof(clientKey));
	
	clientKey = ntohl(clientKey);
	printf("server received %d bytes\n", (int)n);
	printf("server received %d\n", clientKey);
	
//	if(clientKey != skey){
//		skey_status = 0;
//		skey_status = htonl(skey_status);
//		Rio_writen(connfd, &skey_status, sizeof(skey_status));
//	}
	n = Rio_readnb(&rio, buf, MAXLINE);
	printf("server received %d bytes\n", (int)n);	
	printf("server received %s bytes\n", buf);
	
	printf("buf is %s\n", buf);

	
	char* variable;
	
	// ssSet
	if(buf[0] == '0'){
		printf("calling ssSet\n");
		// allocate space for storage
		if (storage == NULL){
			storage = (char ***) malloc (sizeof(char**) * STORAGE_LIM);
			index = 0;
		}
		variable = substr(buf,3,18);
		printf("varible name is %d bytes\n", strlen(variable));	
		printf("variables is %s\n", variable);	

		variable = substr(buf,19,22);
	//	variable = ntohl(variable);
		printf("varible name is %d bytes\n", strlen(variable));	
		printf("variables is %s\n", variable);	

//		n = Rio_readnb(&rio, &length, sizeof(length));
		length = ntohl(length);
		printf("server received %d bytes\n",sizeof( length));	
		printf("server received %d \n", length);	
	



		storage[index] = (char **) malloc (sizeof(char *) * 2);
		storage[index][0] = (char *) malloc (sizeof(char) * ((23-8)));
		storage[index][0] = substr(&buf, 8, 23);
		storage[index][1] = (char *) malloc (sizeof(char) * (sizeof(length) + 1));
		//storage[index][1] = substr(buf, 28, 28+length);
		index = index + 1;
	}else if(buf[0] == '1'){
		printf("simpleget function is being called\n");
				
	}else if(buf[0] == '2'){
	}else if(buf[0] == '3'){
	}
*/
/* $end echo */
}

char *substr(char *str, int start, int stop){
	char *tmp;
	int j = 0;
	int i = 0;
	tmp = (char*) malloc ((sizeof(char) * (stop - start + 1)));
	for(i = 0; i < strlen(str); i++){
		if(i > start && i < stop){
			tmp[j] = str[i];
			j++;
		}
	}
	return tmp;
}
