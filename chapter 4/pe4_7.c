//zad7.c
#include <stdio.h>
#include <float.h>
int main(void)
{
    double x =1.0/3.0;
    float y = 1.0/3.0;
    printf("%.4f, %.12f, %.16f\n", x, x, x);
    printf("%.4f, %.12f, %.16f\n", y, y, y);
    printf("float precyzja = %d\n", FLT_DIG);
    printf("double precyzja = %d", DBL_DIG);
    return 0;
}
