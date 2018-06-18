#include <cstdio>
#include <fcntl.h>
#include <cstdlib>

void set_fl(int fd, int flags) {
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        printf("fcntl F_GETFL error \n");
        exit(1);
    }
    val |= flags;

    if (fcntl(fd, F_SETFL, val) < 0) {
        printf("fcntl F_GETFL error\n");
        exit(1);
    }
}
