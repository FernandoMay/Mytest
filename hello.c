#include <stdio.h>
#include <string.h>

#include "hello.h"

const char *hello_greet(const char *name)
{
    static char buffer[128];

    if (name == NULL || name[0] == '\0') {
        (void)snprintf(buffer, sizeof(buffer), "Hello world!");
    } else {
        (void)snprintf(buffer, sizeof(buffer), "Hello %s!", name);
    }
    return buffer;
}
