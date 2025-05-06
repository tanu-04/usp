#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
int main(){
	DIR *dp;
	struct dirent *dir;
	int fd,n;	
	dp=opendir(".");
	if(dp){
		while((dir=readdir(dp))!=NULL){
			fd=open(dir->d_name, O_RDWR, 0777);
			if(fd==-1){
				continue;}
			n=lseek(fd, 0, SEEK_END);
			close(fd);
			if(n==0){
				unlink(dir->d_name);}}
		closedir(dp);
	}
	else{
		perror("opendir");}
	return 0;}
