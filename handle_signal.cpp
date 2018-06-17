#include <sys/wait.h>
#include <signal.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

static void sig_int(int);

auto const MAXLINE = 4096;

int main() {
    char buf[MAXLINE];
    pid_t pid;
    int status;
    
    if (signal(SIGINT, sig_int) == SIG_ERR) {
        printf("signal error");
        exit(1);
    } 
    printf("%% ");

    while (fgets(buf, MAXLINE, stdin) != nullptr) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        } 

        if ((pid = fork()) < 0) {
            printf("fork error");
            exit(1);
        } else if (pid == 0) {
            execl(buf, buf, (char *)0);
            // err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            printf("waitpid error");
            exit(1);
        }
    }

    exit(1);
}

void sig_int(int signo) {
    printf("interrupt\n%% ");
}