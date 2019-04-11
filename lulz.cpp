#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <syscall.h>
#include <unistd.h>
#include <arpa/inet.h>
//#include <modules/client.h>
//#include <modules/server.h>

#define PASS (void)0
#define PORT 8000

void listen(char* address){
  PASS;
}

void help(){
  printf("\nconnect to somewhere:	nc [-options] hostname port(s)... \n"
          "listen for inbound:	nc -l [-options] [hostname [port]]\n\n"
          "options:\n"
        	"-4		use IPv4 addresses\n"
        	"-b		allow broadcasts\n"
        	"-e PROG		program to exec after establishing connection\n"
        	"-h		this cruft\n"
        	"-i [SECS]	delay interval for lines sent and ports scanned\n"
        	"-l		listen mode, for inbound connects\n"
        	"-n		numeric-only IP addresses, no DNS\n"
        	"-o FILE		hex dump of traffic\n"
        	"-p PORT		local port number (useful when listening)\n"
        	"-q [SECS]         quit SECS after EOF on stdin\n"
        	"-r		randomize local and remote ports\n"
        	"-s ADDR		local source address\n"
        	"-t		answer Telnet negotiation\n"
        	"-u		UDP mode\n"
        	"-v		verbose [repeat to be more verbose]\n"
        	"-w SECS		timeout for connects and final net reads\n"
          "-z		zero-I/O mode [used for scanning]\n\n");
}

int bind_socket(char *local_addr, char *local_port, int proto){
  int sockfd;

  if(local_addr || local_port){


    return sockfd;
  }
}

int main(int argc, char** argv){
  if (argc == 1){
    help();
    exit(0);
  }
  int x;

  struct sockaddr_in address;

  char *remote_port = NULL;
  char *remote_addr = NULL;
  char *locar_port = NULL;
  char *local_addr = NULL;


  char *o_lport;
  int o_listen = 0;


  while ((x = getopt (argc, argv, "46bc:e:hi::lno:p:q::rs:tuvw:z")) != EOF){
  switch (x){
    case '4':
      address.sin_family = AF_INET;
      break;
    case '6':
      printf("ipv6 is not supported yet xD\n");
      break;
    case 'l':
      o_listen++;
      if (address.sin_family != AF_INET){
        address.sin_family = AF_INET;
      }
      break;
    case 'p':
      break;
    default:
      printf ("Try nc -h for help\n");
      break;
    }
  }

  if (o_listen){


    int sockfd = bind_socket()


  }
}
