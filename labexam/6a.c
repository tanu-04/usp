#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(int argc, char *argv[]	){
	mode_t new_umask;
	struct stat stat1;

	printf("ënetr octal umask\n");
	scanf("%o", &new_umask);

	umask(new_umask);
	int fd =open(argv[1], O_WRONLY| O_CREAT, 0777);
	close(fd);

	stat(argv[1], &stat1);
	printf("%o\n", stat1.st_mode &0777);
	




	chmod(argv[1], 0777);
	stat(argv[1], &stat1);
	printf("%o\n", stat1.st_mode& 0777);
	
	return 0;}
