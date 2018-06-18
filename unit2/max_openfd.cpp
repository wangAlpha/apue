#include <sys/param.h>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("%ld\n", sysconf(_SC_OPEN_MAX));

    return 0;
}

