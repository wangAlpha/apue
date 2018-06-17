#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]) {
  int c;
  while ((c = getc(stdin)) != EOF) {
    if (putc(c, stdout) == EOF) {
      printf("output error");
      exit(1);
    }
  }

  if (ferror(stdin)) {
    printf("input error");
    exit(1);
  }
  return 0;
}