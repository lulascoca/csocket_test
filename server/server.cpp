#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

#define PORT 1997

int main(){
  // defining struct address from existing struct in socket.h sockaddr_on
  struct sockaddr_in address;
  //passing "args" to address
  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);
  inet_aton("192.168.1.83", &myaddr.sin_addr.s_addr);

  //creating buffer
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  int addrlen = sizeof(address);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  int setsockopt(sockfd);

  int bind(sockfd, *address, );

  return 0;
}
