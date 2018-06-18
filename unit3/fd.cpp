#include <unistd.h>
#include <cstdio>
#include <sys/param.h>

int main() {
    printf("%ld\n", sysconf(_SC_OPEN_MAX));
    return 0;
}

