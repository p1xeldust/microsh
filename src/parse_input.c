#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "set_env_vars.h"
#include "constants.h"

void parse_input(char* input, char** args) {
    char* token = strtok(input, " \n");
    int arg_count = 0;
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        if (strchr(token, '=') != NULL) {
            set_env_var(token);
        }
        else {
            // if not a env declaration -> use as args
            args[arg_count++] = token;
        }
        token = strtok(NULL, " \n");
    }
    args[arg_count] = NULL;
}
