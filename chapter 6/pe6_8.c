//zad8.c
#include <stdio.h>
int main(void)
{
    float i,j, wynik;
    printf("Podaj dwie liczby zmiennoprzecinkowe:\n");
    while (scanf("%f%f", &i, &j)==2)
        {wynik = (i-j)/2.0;
        printf("%.2f\n", wynik);
        printf("Podaj dwie liczby zmiennoprzecinkowe:\n");
        }
    return 0;
}
