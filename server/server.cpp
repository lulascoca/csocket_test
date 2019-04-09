#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 1997

int main(){
  // defining struct address from existing struct in socket.h sockaddr_on
  struct sockaddr_in address;
  //passing "args" to address
  address.sin_family = AF_INET;
  address.sin_port = htons( PORT );
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  //creating buffer
  char buffer[1024];
  memset(&buffer, 0, sizeof(buffer));

  int addrlen = sizeof(address);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // bind socket
  bind(sockfd, (struct sockaddr *)&address, sizeof(address));
  return 0;
}
