#include <string.h>
#include <stdio.h>

#include "set_env_vars.h"
#include "parse_input.h"
#include "constants.h"
#include "execute.h"

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_ARGS];

    while (1) {
        printf("microshell $ ");
        fgets(input, sizeof(input), stdin);

        parse_input(input, args);

        if (args[0] != NULL) {
            if (!strcmp(args[0], "exit")) {
                break;
            }
            if (!strcmp(args[0], "export")) {
                if(args[1] != NULL)
                    set_env_var(args[1]);
                continue;
            }
            execute_command(args);
        }
    }

    return 0;
}
