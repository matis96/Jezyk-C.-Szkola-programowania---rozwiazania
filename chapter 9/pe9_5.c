//zad5.c
#include <stdio.h>
void wieksze_od(double *x, double *y);
int main(void)
{
    double x = 9.13;
    double y = 1.22;
    wieksze_od(&x,&y);
    printf("%.2f %.2f", x, y);
    return 0;
}

void wieksze_od(double *x, double *y)
{
    double temp;
    temp = *x;
    if (temp > *y)
        *y=*x;
    else
        *x = *y;
}
