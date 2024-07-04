//zad11.c
#include <stdio.h>
#include <math.h>
void przeksztalc(double zrodlo[], double cel[], int n, double (*fp)(double ));
double moja_fun1(double );
double moja_fun2(double );
int main(void)
{
    int n=100;
    int i;
    double zrodlo[n];
    double cel[n];
    double (*wfun)(double );
    for (i=0; i<n; i++)
        zrodlo[i]=i;
    /*for (i=0; i<n; i++)
    {
        printf("%.2f ", zrodlo[i]);
        if (i%10==0)
            printf("\n");
    }*/
    //printf("koniec zrodla\n");
    wfun = moja_fun2; //wybieranie funkcji
    przeksztalc(zrodlo, cel, n, wfun);
    for (i=0; i<n; i++)
    {
        printf("%.2f ", cel[i]);
        if (i%10==0)
            printf("\n");
    }

    //printf("\ntest: cos(1) = %.2f", cos(1));

    return 0;
}
void przeksztalc(double zrodlo[], double cel[], int n, double (*fw)(double ))
{
    int i=0;
    for (i; i<n; i++)
        cel[i]=fw(zrodlo[i]);
}

double moja_fun1(double x)
{
    double y;
    y = x * 1.5;
    return y;
}
double moja_fun2(double x)
{
    double y;
    y = x * x;
    return y;
}
