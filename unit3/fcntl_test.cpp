#include <cstdio>
#include <cstdlib>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int val;
  if (argc != 2) {
    // error_quit("usage: a.out <descriptor#>");
  }

  if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
    // err_sys("fcntl error for fd %d", atoi(argv[1]));
  }

  switch (val & O_ACCMODE) {
  case O_RDONLY:
    printf("read only");
    break;
  case O_WRONLY:
    printf("write only");
    break;
  case O_RDWR:
    printf("read write");
  default:
//    printf("unknown access mode\n");
    break;
  }
  printf("\n");
  return 0;
}
