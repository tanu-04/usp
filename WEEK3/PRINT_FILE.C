#include <stdio.h>
#include <sys/stat.h>

void print_file_type(const char *filename) {
    struct stat fileStat;

    if (stat(filename, &fileStat) == -1) {
        perror("stat");
        return;
    }

    if (S_ISREG(fileStat.st_mode)) 
        printf("%s: Regular file\n", filename);
    else if (S_ISDIR(fileStat.st_mode)) 
        printf("%s: Directory\n", filename);
    else if (S_ISLNK(fileStat.st_mode)) 
        printf("%s: Symbolic link\n", filename);
    else if (S_ISCHR(fileStat.st_mode)) 
        printf("%s: Character device\n", filename);
    else if (S_ISBLK(fileStat.st_mode)) 
        printf("%s: Block device\n", filename);
    else if (S_ISFIFO(fileStat.st_mode)) 
        printf("%s: FIFO (named pipe)\n", filename);
    else if (S_ISSOCK(fileStat.st_mode)) 
        printf("%s: Socket\n", filename);
    else
        printf("%s: Unknown type\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    print_file_type(argv[1]);
    return 0;
}