//zad12.c
#include <stdio.h>
int main(void)
{
    float limit;
    int i, parzyste;
    float suma, suma2;
    printf("Podaj limit szeregu: ");
    scanf("%f", &limit);
    while (limit > 0)
    {
        suma =0;
        suma2 =0;
        for (i=2; i<=limit; i++)
            suma += 1.0/i;
        printf("%lf\n", suma);
        parzyste = 1;
        for (i=2; i<=limit; i++)
        {
            parzyste *= -1;
            suma2 += parzyste * (1.0/i);
        }
        printf("%lf\n", suma2);
        printf("Podaj limit szeregu: ");
        scanf("%f", &limit);
    }
    return 0;
}
