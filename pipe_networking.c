#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pipe_networking.h"

int server_handshake(int * from_client){
	int status;
	int * to_client;
	char received[MESSAGE_BUFFER_SIZE];
	char out[MESSAGE_BUFFER_SIZE];

	status = mkfifo("mario", 0644);
	*from_client = open("mario", O_RDONLY, 0644);

	read(*from_client, received, MESSAGE_BUFFER_SIZE);
	remove("mario");

	//BREAK UP RIGHT HERE

	*to_client = open(received, O_WRONLY, 0644);

	strcpy(out,"Hello");
	write(*to_client, out, MESSAGE_BUFFER_SIZE);

	return *to_client;
}

int client_handshake(int * to_server){
	int status;
	char out[MESSAGE_BUFFER_SIZE];
	char received[MESSAGE_BUFFER_SIZE];
	char out2[MESSAGE_BUFFER_SIZE];
	int * from_server;

	sprintf(out, "%d" ,getpid());
	status = mkfifo(out, 0644);

	*to_server = open("mario", O_WRONLY, 0644);
	write(*to_server, out, MESSAGE_BUFFER_SIZE);

	*from_server = open(out, O_RDONLY, 0644);
	read(*from_server, received, MESSAGE_BUFFER_SIZE);

	remove(out);
	write(*to_server, out2, MESSAGE_BUFFER_SIZE);

	return *from_server;
}
