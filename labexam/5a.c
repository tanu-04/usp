#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	struct stat status;
	stat(argv[1], &status);
	
	if(S_ISREG(status.st_mode)){printf("is regular");}
	else if(S_ISDIR(status.st_mode)){printf("is directory");}
	else if(S_ISCHR(status.st_mode)){printf("is CHSR");}
	else if(S_ISBLK(status.st_mode)){printf("is BLOCK DEVICE");}
	else if(S_ISFIFO(status.st_mode)){printf("is FIFO");}
	else if(S_ISLNK(status.st_mode)){printf("is LINK");}
	else if(S_ISSOCK(status.st_mode)){printf("is SOCKET");}
	return 0;}

	
