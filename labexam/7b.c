#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(){
	pid_t pid=fork();
	if(pid==0){
		printf("child procssrunning :%d",getpid());
		exit(0);
	}
	sleep(5);
	system("ps -l");


	wait(NULL);
	printf("zombie cleaned");
	system("ps -l");

	return 0;}

