#include <stdlib.h>

#include "constants.h"

void free_args(char* args[MAX_ARGS]) {
    for (int i = 0; i < MAX_ARGS; ++i) {
        if (args[i] != NULL) args[i] = NULL;
        else break;
    }
}