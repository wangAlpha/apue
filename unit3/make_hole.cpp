#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ADBCDEFGHIJ";

int main() {
    int fd;
    if ((fd = creat("file.hole", O_CREAT)) < 0) {
        printf("creat error\n");
        exit(1);
    }

    if (write(fd, buf1, 10) != 10) {
        printf("buf1 write error\n");
        exit(1);
    }

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        printf("lseek error\n");
        exit(1);
    }

    if (write(fd, buf2, 10) != 10) {
        printf("buf2 write error\n");
        exit(1);
    }

    exit(0);
}

