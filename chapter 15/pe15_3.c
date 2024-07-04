//zad3.c
#include <stdio.h>
#include <limits.h>
#include <math.h>
int licz_bity(int );
int main(void)
{
    int x = 14141;
    int wynik;
    //char wbit[CHAR_BIT * sizeof(int)];
    //do_binar(x, wbit);
    wynik = licz_bity(x);
    //printf("%b", x);
    printf("%d", wynik);
    return 0;
}

int licz_bity(int n)
{
    int potega = 0;
    int licznik = 0;
    int i;
    while (n>=pow(2, potega))
        potega++;
    for (i=0; i<potega; i++, n>>=1)
        if (01 & n)
            licznik++;
    return licznik;
}


