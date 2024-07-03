//zad9.c
#include <stdio.h>
float obl(float i, float j);
int main(void)
{
    float i,j;
    printf("Podaj dwie liczby zmiennoprzecinkowe:\n");
    while (scanf("%f%f", &i, &j)==2)
       {
       obl(i, j);
       printf("Podaj dwie liczby zmiennoprzecinkowe:\n");}
    return 0;
}
float obl(float i, float j)
{
    float wynik;
    wynik = (i-j)/2.0;
    printf("%.2f\n", wynik);
    return wynik;
}
