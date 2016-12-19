#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pipe_networking.h"

void process( char * s );

int main() {

  int to_client, from_client;
  char buffer[MESSAGE_BUFFER_SIZE];

  to_client = server_handshake( &from_client );

  while(1 == 1){
    read( from_client, buffer, sizeof(buffer) );
    process( buffer );
    write( to_client, buffer, sizeof(buffer));
  }
  while(1 == 1){
    printf("Hello!\n");
  }

  return 0;
}




void process( char * s ) {

  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
}
