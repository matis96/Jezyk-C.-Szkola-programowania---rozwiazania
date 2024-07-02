//zad6.c
#include <stdio.h>
int main(void)
{
    double masa = 3.0E-28;
    float litr = 1000.0;
    float ilosc;
    double wynik;
    printf("Ile masz litrow wody? ");
    scanf("%f", &ilosc);
    wynik = ilosc * litr * masa;
    printf("\nW tej objetosci jest %e czasteczek", wynik);
    return 0;
}
