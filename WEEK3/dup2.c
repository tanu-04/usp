#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd1, fd2, new_fd1, new_fd2;

    
    fd1 = open("file1.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd1 == -1) {
        perror("Error opening file");
        return 1;
    }

  
    write(fd1, "Hello, this is the original file descriptor.\n", 45);

    new_fd1 = dup(fd1);  
    if (new_fd1 == -1) {
        perror("Error with dup");
        close(fd1);
        return 1;
    }

    
    write(new_fd1, "This is written using dup().\n", 28);

   
    fd2 = open("file2.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd2 == -1) {
        perror("Error opening second file");
        close(fd1);
        close(new_fd1);
        return 1;
    }

    new_fd2 = 5;  
    if (dup2(fd2, new_fd2) == -1) {  
        perror("Error with dup2");
        close(fd1);
        close(new_fd1);
        close(fd2);
        return 1;
    }

    
    write(new_fd2, "This is written using dup2() on fd 5.\n", 38);

    
    close(fd1);
    close(new_fd1);
    close(fd2);
    close(new_fd2);

    return 0;
}
