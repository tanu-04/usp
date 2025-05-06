#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char *argv[]){	
	int n=atoi(argv[2]);
	int fd=open(argv[1], O_RDWR);
	if(fd<0){
		printf("ëror opemning file");}

	char buffer[n+1];
	read(fd,buffer,n);
	buffer[n]='\0';

	dup2(fd, 1);
	printf("%s",buffer);
	close(fd);
	return 0;}
