#include <unistd.h>
#include <cstdio>
#include <fcntl.h>

int main()
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("cannot seek\n"); 
    } else {
        printf("seek OK\n");
    }
    return 0;
}

