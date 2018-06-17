#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>

auto const MAXLINE = 4096u;

int main() {
  char buf[MAXLINE];
  pid_t pid;
  int status;
  printf("%% ");
  while (fgets(buf, MAXLINE, stdin) != nullptr) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }
    if ((pid = fork()) < 0) {
      printf("fork error");
      exit(1);
    } else if (pid == 0) {
      execlp(buf, buf, (char *)0);
      // err_ret("couldn't execute: %s", buf);
      exit(127);
    }
    if ((pid = waitpid(pid, &status, 0)) < 0) {
      printf("waitpid error");
      exit(1);
    }
    printf("%% ");
  }
  return 0;
}