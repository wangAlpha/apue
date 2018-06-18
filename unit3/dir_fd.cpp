#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd = open("/dev/fd/2", O_WRONLY);
  printf("fd = %d\n", fd);
  write(fd, "Hello World\n", 13);
  return 0;
}
