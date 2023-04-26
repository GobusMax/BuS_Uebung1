#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    if (fork() == 0) {
        write(1, " A ", 1);
        if (fork() == 0) {
            write(1, " B ", 1);
        } else if (wait(NULL) > 0) {
            write(1, " C ", 1);
        }
    } else {
        fork();
        write(1, " D ", 1);
        if (fork() == 0) {
            write(1, " E ", 1);
        } else {
            write(1, " F ", 1);
        }
    }
    return 0;
}