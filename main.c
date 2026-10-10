#include <stdio.h>
#include <string.h>

#include "hello.h"

int main(int argc, char **argv)
{
    const char *name = (argc > 1 && argv[1][0] != '\0') ? argv[1] : NULL;
    (void)puts(hello_greet(name));
    return 0;
}
