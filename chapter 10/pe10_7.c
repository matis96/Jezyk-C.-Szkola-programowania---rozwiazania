//zad7.c
#include <stdio.h>
void kopiuj_tab(double zrodlo[], double cel[], int n);
int main(void)
{
    int i, k;
    double tab[2][5]={{8.11, 3.52, 0.11, 8.99, 90.00}, {91.82, 13.52, 0.007, 167.9, 53.41}};
    double cel[2][5];
    for (i=0; i<2; i++)
        kopiuj_tab(tab[i], cel[i], 5);
    for (i=0; i<2; i++)
    {
        for (k=0; k<5; k++)
            printf("%.2lf ", cel[i][k]);
        printf("\n");
    }
    return 0;
}

void kopiuj_tab(double zrodlo[], double cel[], int n)
{
    int i;
    for (i=0; i <n; i++)
        cel[i]=zrodlo[i];
}
