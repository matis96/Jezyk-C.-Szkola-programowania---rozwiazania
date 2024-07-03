//zad6.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[1000];
    int k=0;
    int i, j;
    int ones, twos, threes, fours, fives, sixes, sevens, eights, nines, tens;
    ones=twos=threes=fours=fives=sixes=sevens=eights=nines=tens=0;
    for (k; k<10; k++)
    {
        srand(k);
        for (i=k*100; i<(k+1)*100; i++)
            tab[i]=rand()%10+1;
    }
    for (j=0; j<1000; j++)
    {
        switch(tab[j])
        {
            case 1: ones++; break;
            case 2: twos++; break;
            case 3: threes++; break;
            case 4: fours++; break;
            case 5: fives++; break;
            case 6: sixes++; break;
            case 7: sevens++; break;
            case 8: eights++; break;
            case 9: nines++; break;
            case 10: tens++; break;
            default: printf("Co to za numer??\n"); break;
        }

    }
    printf("Liczba 1: %d\n", ones);
    printf("Liczba 2: %d\n", twos);
    printf("Liczba 3: %d\n", threes);
    printf("Liczba 4: %d\n", fours);
    printf("Liczba 5: %d\n", fives);
    printf("Liczba 6: %d\n", sixes);
    printf("Liczba 7: %d\n", sevens);
    printf("Liczba 8: %d\n", eights);
    printf("Liczba 9: %d\n", nines);
    printf("Liczba 10: %d\n", tens);

    return 0;
}
