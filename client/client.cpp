#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <syscall.h>
#include <unistd.h>

#define PORT 8000

int main(int argc, char *argv[]){
  /*for (int i = 0; i < argc; ++i){
    printf("%s\n", argv[i]);
  }*/

  char *message = "hello from the other siiide";

  char buffer[1024];
  memset(&buffer, 0, sizeof(buffer));

  int sock = socket(AF_INET, SOCK_STREAM, 0);

  //create struct for server address
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons( PORT );
  inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

  //connect
  connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

  //send data i guess XD
  send(sock, message, strlen(message), 0);
  printf("message sent\n");

  read(sock, &buffer, sizeof(buffer));
  printf("Server says: %s\n", buffer);

  return 0;
}
