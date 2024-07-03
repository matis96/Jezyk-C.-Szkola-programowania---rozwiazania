//zad2.c
#include <stdio.h>

void kopiuj_tab(double tab1[], double tab2[], int n);
void kopiuj_wsk(double tab1[], double tab2[], int n);
void kopiuj_wsk3(double tab1[], double tab2[], double tab3[]);
int main(void)
{
    int i;
    double zrodlo[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double cel1[5];
    double cel2[5];
    double cel3[5];
    //kopiuj_tab(zrodlo, cel1, 5);
    kopiuj_wsk3(zrodlo, cel3, zrodlo+5);
    for (i=0; i<5; i++)
        printf("%.2f ", cel3[i]);
    return 0;
}

void kopiuj_tab(double tab1[], double tab2[], int n)
{
    int i;
    for (i=0; i <n; i++)
    {
        tab2[i]=tab1[i];
    }
}

void kopiuj_wsk(double tab1[], double tab2[], int n)
{
    int i;
    for (i=0; i<n; i++)
        *(tab2+i)=*(tab1+i);
}

void kopiuj_wsk3(double tab1[], double tab2[], double tab3[])
{
    double * wsk;
    int i;
    for (wsk=tab1, i=0; wsk<tab3; wsk++, i++)
    {
        *(tab2+i)=*(tab1+i);
    }
}

