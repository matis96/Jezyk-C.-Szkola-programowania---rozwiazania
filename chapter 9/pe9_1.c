//zad1.c
#include <stdio.h>

double min(double x, double y);
int main(void)
{
    double test;
    test = min(2.8, 10.5);
    printf("%f", test);
    return 0;
}

double min(double x, double y)
{
    return (x>y)?y:x;
}
