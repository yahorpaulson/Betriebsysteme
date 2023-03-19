#include "strlength.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc == 2) {
        printf("%u\n", strlength(argv[1]));
    } else {
        printf("False argument exception\n");
    }

    return 0;
}
