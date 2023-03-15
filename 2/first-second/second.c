#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> //is added
#include <unistd.h>

#define NUM 100000

int main(int argc, char** argv)
{
    int vals[NUM];

    int fdIn = open("/dev/urandom", O_RDONLY); //open read only file
    for (int i = 0; i < NUM; i++) {
        read(fdIn, vals + i, sizeof(int));
    }
    close(fdIn);

    int fdOut = open("out.second", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    //S_IRUSR Read permission for the file owner
    // S_IWUSR Write permission for the file owner
    for (int i = 0; i < NUM; i++) {
        vals[i] = fabsf(vals[i]); //absolute value in double
        write(fdOut, vals + i, sizeof(int));
    }
    close(fdOut);

    return EXIT_SUCCESS;
}
