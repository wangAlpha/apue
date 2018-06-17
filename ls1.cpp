#include <cstdio>
#include <cstdlib>
#include <dirent.h>

void err_quit(const char *str) {
  printf("%s", str);
  exit(1);
}

void err_sys(const char *str) { printf("%s", str); }

int main(int argc, char *argv[]) {
  DIR *dp;
  struct dirent *dirp;
  if (argc != 2) {
    err_quit("usage: ls directory_name");
  }

  if ((dp = opendir(argv[1])) == nullptr) {
    // err_sys("can't open %s", argv[1]);
    // sprintf()
  }
  // printf("%d");

  while ((dirp = readdir(dp)) != nullptr) {
    printf("%s\n", dirp->d_name);
  }
  closedir(dp);

  return 0;
}
