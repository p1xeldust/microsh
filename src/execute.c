#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void execute_command(char** args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Can't fork subprocess");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // В дочернем процессе
        if (execvp(args[0], args) == -1) {
            printf("Can't execute %s: command not found\n", args[0]);
            exit(EXIT_FAILURE);
        }
    } else {
        // В родительском процессе
        int status;
        waitpid(pid, &status, 0);
    }
}
