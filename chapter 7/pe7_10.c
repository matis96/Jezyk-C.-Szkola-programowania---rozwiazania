//zad10.c
#include <stdio.h>
int main(void)
{
    float dochod, podatek, prog;
    int wybor;
    printf("Kategorie:\n");
    printf("1- stan wolny, 2- glowa rodziny, 3- malzenstwo, rozliczanie wspolne, 4 - malzenstwo, rozliczanie osobne\n");
    do
    {
        printf("Wprowadz kategorie\n");
        scanf("%d", &wybor);
        printf("Wprowadz dochod\n");
        scanf("%f", &dochod);
        switch (wybor)
        {
        case 1:
            prog = 17850;
            break;
        case 2:
            prog = 23900;
            break;
        case 3:
            prog = 29750;
            break;
        case 4:
            prog = 14875;
            break;
        default:
            break;
        }
        if (dochod > prog)
            podatek = 0.15*prog + 0.28 * (dochod - prog);
        else
            podatek = 0.15*dochod;
        printf("podatek wynosi %.2f\n", podatek);
    } while (1);
    return 0;
}
