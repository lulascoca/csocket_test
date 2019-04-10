#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <syscall.h>
#include <unistd.h>

#define PORT 8000

int main(){
  char *message = "hello";

  // defining struct address from existing struct in socket.h sockaddr_on
  const int backlog = 3;
  struct sockaddr_in address;
  //passing "args" to address
  address.sin_family = AF_INET;
  address.sin_port = htons( PORT );
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  socklen_t addrlen = sizeof(address);

  //creating buffer
  char buffer[8192];
  memset(&buffer, 0, sizeof(buffer));

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
