#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void print_file_info(struct stat *fileStat) {
    printf("Size: %ld bytes\n", fileStat->st_size);
    printf("Permissions: %o\n", fileStat->st_mode & 0777);
    printf("Number of hard links: %ld\n", fileStat->st_nlink);
    printf("User ID: %d\n", fileStat->st_uid);
    printf("Group ID: %d\n", fileStat->st_gid);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;
    
    // Using stat()
    if (stat(argv[1], &fileStat) == 0) {
        printf("Using stat():\n");
        print_file_info(&fileStat);
    } else {
        perror("stat");
    }

   
    if (lstat(argv[1], &fileStat) == 0) {
        printf("Using lstat():\n");
        print_file_info(&fileStat);
    } else {
        perror("lstat");
    }

    
    int fd = open(argv[1], O_RDONLY);
    if (fd != -1) {
        if (fstat(fd, &fileStat) == 0) {
            printf("Using fstat():\n");
            print_file_info(&fileStat);
        } else {
            perror("fstat");
        }
        close(fd);
    } else {
        perror("open");
    }

   
    if (fstatat(AT_FDCWD, argv[1], &fileStat, 0) == 0) {
        printf("Using fstatat():\n");
        print_file_info(&fileStat);
    } else {
        perror("fstatat");
    }

    return 0;
}