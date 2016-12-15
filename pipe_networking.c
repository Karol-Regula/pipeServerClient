#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int server_handshake(int * from_client){
	int status;
	int fdKnown;
	int fdPrivate;
	char received[MESSAGE_BUFFER_SIZE];
	char out[MESSAGE_BUFFER_SIZE];

	status = mkfifo("mario", 0644);
	fdKnown = open("mario", O_RDONLY, 0644);

	read(fdKnown, recieved, MESSAGE_BUFFER_SIZE);
	remove("mario");

	fdPrivate = open(*recieved, O_WRONLY, 0644);


	strcpy();
	write(fdPrivate, );
}

int client_handshake(int * to_server){
	char temp[MESSAGE_BUFFER_SIZE];
	int fdKnown;
	int fdPrivate;
	sprintf(temp, "%d" ,getpid());
	mkfifo(temp), 0644);

	fdKnown = open("mario", O_WRONLY, 0644);
	write(fdKnown, temp, MESSAGE_BUFFER_SIZE;

	open(*temp, O_RDONLY, 0644);

}
