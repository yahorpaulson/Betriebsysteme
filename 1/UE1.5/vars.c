#include <stdio.h>
#include<stdint.h>

main(int argc, char const *argv[])
{
    char str[11];
    printf("Enter a String: ");
    //scanf("%10s", str);
    fgets(str,11,stdin);

    printf("%s\n",str);

    // sizeof evaluates the size of a variable
    char ch;
    double dbl;
    unsigned short ush;
    long long llng;

    printf("Size of character: %zu bytes\n", sizeof(ch));
    printf("Size of double: %zu bytes\n", sizeof(dbl));
    printf("Size of unsigned short: %zu bytes\n", sizeof(ush));
    printf("Size of long long: %zu bytes\n", sizeof(llng));
    printf("Size of uint_32t: %zu bytes\n", sizeof(uint32_t));
    printf("Size of uint_64t: %zu bytes\n", sizeof(uint64_t));





    getch();

    return 0;
}
