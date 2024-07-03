//zad9.c
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int i, k;
    printf("Podaj liczbe calkowita >1 ");
    scanf(" %d", &i);
    for (k=2; k<=i; k++)
    {
        if (isprime(k))
            printf("%d ", k);
    }
    return 0;

}

int isprime(int i)
{
    int dziel;
    bool pierwsza;
    for (dziel = 2, pierwsza = true; dziel*dziel<=i; dziel++)
    {
        if (i % dziel ==0)
        {
            pierwsza = false;
            return 0;
        }
    }
    if (pierwsza)
        return 1;
}
