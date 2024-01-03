#include <string.h>
#include <stdlib.h>

#include "constants.h"

void set_env_var(char* input) {
    char* var_name = strtok(input, "=");
    char* var_value;
    if ((var_value = strtok(NULL, "=")) != NULL) {
        setenv(var_name, var_value, 1);
    } else {
        setenv(var_name, "", 1);
    }
    return;
}
