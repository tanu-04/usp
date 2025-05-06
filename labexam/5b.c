#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char *argv[]){
	int fd=open(argv[1], O_RDWR);
	if(fd<0){
		printf("ëror opening file");}

	int fd1=dup(fd);
	int fd2=dup2(fd, 7);

	write(fd, "in fd", 6);
	write(fd1,"ïn fd1", 8);
	write(fd2, "in fd2",7);

	close(fd);
	return 0;}
