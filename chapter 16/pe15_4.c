//zad4.c
#include <stdio.h>
#include <limits.h>
#include <math.h>
int nr_bit(int , int);
int main(void)
{
    printf("%d", nr_bit(73,1));
    return 0;
}
int nr_bit(int n, int x)
{
    int potega = 0;
    while (n>=pow(2, potega))
        potega++;
    if (x>potega)
        return -1;
    n>>=x;
    if (01&n)
        return 1;
    else
        return 0;
}
