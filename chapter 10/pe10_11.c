//zad11.c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wyswietl(int tab[][5], int n);
void pomnoz(int tab[][5], int tab2[][5], int n);

int main(void)
{
    srand(time(NULL));
    int tab[3][5];
    int tab2[3][5];

    for (int i=0; i<3; i++)
        for (int j=0; j<5; j++)
            tab[i][j]=rand() % 100;

    pomnoz(tab, tab2, 3);
    printf("Oryginalna tablica: \n");
    wyswietl(tab,3);
    printf("\nPodwojona tablica: \n");
    wyswietl(tab2, 3);

    return 0;

}

void wyswietl(int tab[][5], int n)
{
    for (int i=0; i<n; i++)
    {
         for (int j=0; j<5; j++)
            printf("%d ", tab[i][j]);
        putchar('\n');
    }

}

void pomnoz(int tab[][5], int tab2[][5], int n)
{
    for (int i=0; i<n; i++)
    {
         for (int j=0; j<5; j++)
            tab2[i][j]=2*tab[i][j];
    }
}
