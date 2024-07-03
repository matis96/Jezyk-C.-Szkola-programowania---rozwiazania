//zad17.c
#include <stdio.h>
#define WYPLATA 100000
#define WYGRANA 1000000
#define rate 0.08
int main(void)
{
    int konto, lata;
    lata =0;
    konto = WYGRANA;
    while (konto>0)
    {
        konto += konto*rate-WYPLATA;
        lata++;
    }
    printf("%d", lata);
    return 0;
}
