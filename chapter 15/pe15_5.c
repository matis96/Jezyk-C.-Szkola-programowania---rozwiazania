//zad5.c
#include <stdio.h>
#include <limits.h>
#define BITS sizeof(unsigned int) * CHAR_BIT
#define MASKA 1<<(BITS-1)

unsigned int obroc_l(unsigned int, int );
int main(void)
{
    unsigned int x = 73;
    unsigned int y = obroc_l(x, 4);
    printf("%u", y);
    return 0;
}
unsigned int obroc_l(unsigned int n, int x)
{
    int leftbit;
    int i;
    for (i=0; i<x; i++)
    {
        leftbit = n & MASKA;
        n<<=1;
        if (leftbit)
            n |= 01;
    }
    return n;
}
