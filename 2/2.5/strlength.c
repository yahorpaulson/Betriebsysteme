#include "strlength.h"
#include <stdio.h>

int main(int argc, char const* argv[])
{
    char str[5] = "Hello";

    printf("%u\n", strlength(str));
    return 0;
}
