#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fcntl.h>
int main(){
	pid_t pid=fork();
	if(pid==0){
		sleep(2);
		printf("child exxec:%d\n",getpid());
		exit(40);
	}

	else{
		int status;
		printf("parents waiting for status");
		wait(&status);
		if(WIFEXITED(status)){
			printf("child exited with status:%d\n",WEXITSTATUS(status));}
		
	}


	pid=fork();
	if(pid==0){
		sleep(1);

		printf("child exxec :%d\n", getpid()); 
		exit(41);
	}
	else{
		int status;
		printf("parents waiting for status");
		waitpid(pid, &status, 0);  
		if(WIFEXITED(status)){                                                                                                          printf("child exited with status:%d\n",WEXITSTATUS(status));}                                                                                                                                                                   }

	return 0;
}
