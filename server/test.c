#include <stdio.h>     // not even this is right oh yea old skool
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "perm.h"

#define FILENAME "words_alpha.txt"

char * get_input(){
    char * response;
    fgets(response,189819,stdin); // nice reasonable
    return response;
}

int file_length(char *file_name){
        long length;
        FILE * f = fopen (file_name, "rb");

        if (f){
                fseek (f, 0, SEEK_END);
                length = ftell (f);
                fseek (f, 0, SEEK_SET);
                return length;
        }
        else{
                perror("file not found");
                exit(1);
        }
}

void get_file(char *filename){
    FILE * fdd = fopen(FILENAME, "r");

    char * buf;

    if (fdd == NULL) {
        exit(1);
    } else {
        printf("test");
        char * temp;
        while(temp = get_input()){
            while(fscanf(fdd, "%s", buf) ==  1){
                int n = strlen(buf);
                if(*temp == 'a' || *temp == 'i' || *temp == 'A' || *temp == 'I'){
                    printf("%s\n", temp);
                    return;
                } else {
                    printf("put stuff here\n");
                    return;
                }
            }
        }
    }
}


int main(){
    get_file(FILENAME);

    return 0;
}
