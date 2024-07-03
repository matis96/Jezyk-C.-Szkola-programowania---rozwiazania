//pe5_1.c
#include <stdio.h>
#define CZAS 60
int main(void)
{
    int min, godz, min2;
    printf("Podaj liczbe minut\n");
    printf("Podaj <0 aby zakonczyc\n");
    scanf("%d", &min);
    while (min > 0)
    {
        godz = min / CZAS;
        min2 = min % CZAS;
        printf("%d to %d h i %d min\n", min, godz, min2);
        printf("Podaj liczbe minut lub wpisz 0 aby zakonczyc program\n");
        scanf("%d", &min);
    }

    return 0;
}
