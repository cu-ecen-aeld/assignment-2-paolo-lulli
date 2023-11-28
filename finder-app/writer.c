#include<stdio.h>
#include<syslog.h>

void usage(){
  printf("Usage: writer <destination-file> <string-message>");
}

int main(int argc, char *argv[]){
  openlog("writer", LOG_PID, LOG_USER);
  if (argc == 0){
    syslog(LOG_ERR, "Missing arguments");
    usage();
    closelog();
    return 1;
  }
  FILE *fp;
  char *filename = argv[1];
  char *payload = argv[2];
  if(argc != 3){
    syslog(LOG_ERR, "Wrong number of arguments");
	  usage();
    closelog();
    return 1;
  }
  
  if((fp = fopen(filename, "w")) != NULL){
    fprintf(fp, payload);
    syslog(LOG_INFO, "Written content on file: %s", filename);
    closelog();
  } else {
    perror("Could not open file");
    syslog(LOG_ERR, "Could not open file for writing");
    closelog();
    return 1;
  }
}
