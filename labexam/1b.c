#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	char filename[10];
	printf("enter filename");
	scanf("%s",filename);
	
	int fd=open(filename, O_RDWR| O_CREAT, 0644);
	if(fd==0){
		printf("open error");
		return 1;}
	int pid=fork();
	if(pid==0){
		printf("CHILD\n");
		write(fd, "child\n", 6);}
	else{
		//sleep(1);
		printf("parent\n");
		write(fd, "parent\n",7);}
	close(fd);
	return 0;}
	 
