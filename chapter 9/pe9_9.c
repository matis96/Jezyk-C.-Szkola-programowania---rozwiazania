//zad8.c
#include <stdio.h>
#include <stdlib.h>
double potega(double a, int b);

int main(void)
{
    double xpot;
    double a = 0;
    int b = 0;
    xpot = potega(a,b);
    printf("%.2f do potegi %d wynosi %.3f", a, b, xpot);

}

double potega(double a, int b)
{
    double pot = 1;
    if (a==0 && b==0)
    {
        printf("Niewlasciwe dzialanie!\n");
        return 1;
    }
    else if (a==0)
        return 0;
    else if (b==0)
        return 1;
    else
        pot *= a * potega(a, abs(b)-1);
    if (b<0)
        pot = 1/pot;
    return pot;
}
