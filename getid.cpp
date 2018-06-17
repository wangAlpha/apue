#include <unistd.h>
#include <cstdio>
#include <cstdlib>

int main() {
    printf("uid = %d, gid = %d\n", getuid(), getuid());
    return 0;
}

