#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <syscall.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PASS (void)0
#define PORT 8000

void keep_alive(){

  PASS;

}

void help(){

printf("hey\nusage:\nserver 'address'\nbai\n");

}

int main(int argc, char** argv){
  char *message = "hello";
  if (argc > 1){
    PASS;
  }
  else{
    help();
    exit(0);
  }

  // defining struct address from existing struct in socket.h sockaddr_in,
  // backlog is the ammount of "unprocessed requests"
  const int backlog = 3;
  struct sockaddr_in address;

  //passing "args" to address
  address.sin_family = AF_INET;
  address.sin_port = htons( PORT );
  inet_pton(AF_INET, argv[1], &address.sin_addr);

  //passing length of address to a variable that is of the data type socklen_t
  int addrlen = sizeof(address);

  //creating buffer
  char buffer[8192];
  memset(&buffer, 0, sizeof(buffer));

  //creating a socket from the class/object socket from <sys/socket.h>
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // bind socket
  if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0){
    printf("error binding socket\n");
  }

  printf("listening on port %d\n", PORT);
  if (listen(sockfd, backlog) < 0){
    printf("bind failed");
  }

  int new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

  //valread = read(sockfd, &buffer, sizeof(buffer));
  int valread = read(new_socket, buffer, sizeof(buffer));
  printf("Client says: %s\n", buffer);
  send(new_socket, message, strlen(message), 0);
  printf("\nmessage sent\n");

  return 0;
}
