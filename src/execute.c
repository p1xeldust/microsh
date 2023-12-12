#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void execute_command(char** args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // В дочернем процессе
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // В родительском процессе
        int status;
        waitpid(pid, &status, 0);
    }
}
