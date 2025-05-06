#include<stdio.h>
#include<unistd.h>
#include<utime.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc, char *argv[]){
	struct stat stat1;
	struct stat stat2;
	struct utimbuf times;

	if(stat(argv[1], &stat1)<0){
		printf("error");}
	if(stat(argv[2], &stat2)<0){
		printf("error");
	}

	printf("before copying");
	printf("atime %s, \n mtime: %s",ctime(&stat1.st_atime),ctime(&stat2.st_mtime));

	times.actime=stat2.st_atime;
	times.modtime=stat2.st_mtime;
	if(utime(argv[1], &times)<0){
		printf("error copying time");
	}
	stat(argv[1], &stat1);


        printf("after copying");
        printf("atime %s, \n mtime: %s",ctime(&stat1.st_atime),ctime(&stat2.st_mtime));
	return 0;}
