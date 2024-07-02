//zad3.c
#include <stdio.h>
int main(void)
{
    float liczba;

    printf("Wpisz liczbe zmiennoprzecinkowa\n");
    scanf("%f", &liczba);

    printf("Wpisano liczbe %.1f lub %.1e\n", liczba, liczba);
    printf("Wpisono liczbe %+.3f lub %.3E", liczba, liczba);
    return 0;
}
