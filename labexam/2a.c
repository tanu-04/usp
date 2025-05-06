#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	char filename[10];
	printf("enter filename");
	scanf("%s",filename);

	struct stat filestat;
	if(stat(filename, &filestat)<0){
		printf("error");
		return 1;
	}
	printf("%ld",filestat.st_size);
	printf("%ld",filestat.st_ino);

	printf("%ld",filestat.st_nlink);

	printf("%ld",filestat.st_uid);
	printf("%o", filestat.st_mode & 07777);
	return 0;}
