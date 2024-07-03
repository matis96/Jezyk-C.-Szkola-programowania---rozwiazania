//zad5.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GRAN 100
void srtint(int *tab[], int num);
int main(void)
{
    int los[GRAN];
    int *wskint[GRAN];
    int licz=0;
    int k;
    srand((unsigned int) time(0));
    for (licz; licz<GRAN; licz++)
    {
        los[licz] = rand()%10+1;
        wskint[licz]=los[licz];
    }
    srtint(wskint, licz);
    for (k=0; k<licz; k++)
    {
        printf("%d ", wskint[k]);
    }

    return 0;
}

void srtint(int *tab[], int num)
{
    int *temp;
    int dol, szuk;
    for (dol=0; dol<num; dol++)
        for (szuk=dol+1; szuk<num; szuk++)
            if (tab[szuk]>tab[dol])
            {
                temp = tab[dol];
                tab[dol] = tab[szuk];
                tab[szuk]= temp;
            }
}
