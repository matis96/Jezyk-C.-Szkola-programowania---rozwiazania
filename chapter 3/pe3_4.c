//pe3_4.c
#include <stdio.h>
int main(void)
{
    float x;
    printf("Podaj liczbe zmiennoprzecinkowa: ");
    scanf("%f", &x);
    printf("\nPodana liczba to %f lub %e lub %a", x, x, x);
    return 0;
}
