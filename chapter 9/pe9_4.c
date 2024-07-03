//zad4.c
#include <stdio.h>

double harmonic(double x, double y);
int main(void)
{
    double g = harmonic(5.5, 8.5);
    printf("%f", g);
    return 0;
}

double harmonic(double x, double y)
{
    return (2*x*y)/(x+y);
}
