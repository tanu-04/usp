
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    const char *dirname = "new_directory";

    // Create directory with read, write, and execute permissions for the owner
    if (mkdir(dirname, 0777) == 0) {
        printf("Directory created successfully.\n");
    } else {
        perror("mkdir");
    }

    return 0;
}
