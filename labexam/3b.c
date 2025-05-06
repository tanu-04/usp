#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
int main(){
	DIR *dp;
	struct dirent *dir;
	int fd,n;
	struct stat filestat;
	dp=opendir(".");
	if(dp){
		
		while((dir=readdir(dp))!=NULL){
			if(stat(dir->d_name, &filestat)==0){
				printf("Inode:%ld\t perms: %o\t Link :%ld\t uid: %ld \t size:%ld", filestat.st_ino, filestat.st_nlink, filestat.st_uid, filestat.st_size);
			}
		}
		closedir(dp);
		
	}
	else{
		perror("eror");}
	return 0;
}

