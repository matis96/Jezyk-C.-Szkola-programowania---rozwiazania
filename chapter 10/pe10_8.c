//zad8.c
#include <stdio.h>

void kopiuj_tab(double zrodlo[], double cel[], int n);
int main(void)
{
    double zrodlo[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double cel[3];
    kopiuj_tab(zrodlo+3, cel, 3);
    for (int i=0; i<3; i++)
        printf("%.2lf ", cel[i]);
    return 0;
}

void kopiuj_tab(double zrodlo[], double cel[], int n)
{

    for (int i=0; i <n; i++)
        cel[i]=zrodlo[i];
}
