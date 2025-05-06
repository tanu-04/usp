#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char file_name[100];
    printf("enter file_name");
    scanf("%s", file_name);

    int fd=open(file_name, O_RDONLY);
    if(fd<0){
        perror("open error");
        return 1;
    }

    off_t size=lseek(fd, 0, SEEK_END);
    char ch;
    while(size-- >0){
        lseek(fd, size, SEEK_SET);
        read(fd, &ch, 1);
        write(1, &ch,1);

    }
    close(fd);
    return 0;


}