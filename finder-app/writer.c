#include<stdio.h>

void usage(){
  printf("Usage: writer <destination-file> <string-message>");
}

int main(int argc, char *argv[]){
  if (argc == 0){
    usage();
    return 1;
  }
  FILE *fp;
  char *filename = argv[1];
  char *payload = argv[2];
  if(argc != 3){
	  usage();
    return 1;
  }
  
  if((fp = fopen(filename, "w")) != NULL){
    fprintf(fp, payload);
  } else {
    perror("Could not open file");
    return 1;
  }
}
