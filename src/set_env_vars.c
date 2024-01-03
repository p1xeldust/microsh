#include <string.h>
#include <stdlib.h>

#include "constants.h"

void set_env_var(char* input) {
    char* var_name = strtok(input, "=");
    char* var_value = strtok(NULL, "=");
    if (var_value != NULL) {
        setenv(var_name, var_value, 1);
    } else {
        setenv(var_name, NULL, 1);
    }
    return;
}
