#include <unistd.h>
#include <cstdio>

int main() {
    printf("process ID %ld\n", (long)getpid());
    return 0;
}
