#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int a = 4;
    int* b = NULL; //pointer

    printf("\n0: a=%d &a=%p *(&a)=%d", a, &a, *(&a));
    printf("\n0: b=%p &b=%p\n", b, &b);

    int* c = b = (int*)malloc(sizeof(int) * 4); //allocate memory for 4 int elements
    *b = 10; // put 10 on the first element

    printf("\n1: b=%p *b=%d &b=%p", b, *b, &b);
    printf("\n1: c=%p *c=%d &c=%p\n", c, *c, &c);

    b[2] = 20; //put 20 on the third element
    b++; //pointer b points now to the next (second) element
    *(b + 2) = 30; //b[3] = 30 //put 30 to the last element
    *(b--) = 40; //b[2] = 40 //put 40 on the second element and pointer b boints on the first element

    for (int i = 0, *pi = c; i < 4; ++i, ++pi) {
        printf("\n2: b[%ld]=%d (addr=%p)", pi - c, *pi, pi);
    }
    printf("\n");

    free(b); //free up the space that was allocated
    b = &a; //put the value with address of a

    printf("\n3: a=%d &a=%p *(&a)=%d", a, &a, *(&a));
    printf("\n3: b=%p *b=%d &b=%p\n", b, *b, &b);

    printf("\n4: size(int)=%zu, size(int*)=%zu\n", sizeof(*b), sizeof(b));

    return EXIT_SUCCESS;
}
