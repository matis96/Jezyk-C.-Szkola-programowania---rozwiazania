//zad14.c
#include <stdio.h>
#include <stdlib.h>
double potega(double a, int b);
int main(int argc, char *argv[])
{
    double podstawa, xpot;
    int wykladnik;
    podstawa = atof(argv[1]);
    wykladnik = atoi(argv[2]);
    xpot = potega(podstawa, wykladnik);
    printf("%.3g do potegi %d to %.5g\n", podstawa, wykladnik, xpot);
    return 0;

}
double potega(double a, int b) /* definicja funkcji */
{
double pot = 1;
int i;
for(i = 1; i <= b; i++)
pot *= a;
return pot; /* zwrot wartosci pot */
}
