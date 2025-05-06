#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc, char* argv[]){
	if(argc==4){
		if(link(argv[1], argv[2])==0){
		printf("hardlink done");}
	}
	else if(argc==3){
		if(symlink(argv[1],argv[2])==0){
		printf("soft link done");}}
	
	return 0;}
