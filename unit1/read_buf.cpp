#include <cstdio>
#include <cstdlib>
#include <unistd.h>

const auto BUFFSIZE = 4096u;

int main(int argc, char const *argv[]) {
  int n;
  char buf[BUFFSIZE];

  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      printf("write error");
      exit(1);
    }
  }

  if (n < 0) {
    printf("read error");
    exit(1);
  }
  return 0;
}
