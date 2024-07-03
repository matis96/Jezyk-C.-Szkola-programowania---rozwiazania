//zad8.c
// pe12-8.c
#include <stdio.h>
int * stworz_tablice (int elem, int wart);
void pokaz_tablice (const int tab[], int n);
int main (void)
{
    int * wt;
    int rozmiar;
    int wartosc;
    printf("Podaj liczbe elementow: ");
    while (scanf(" %d", &rozmiar) == 1 && rozmiar > 0)
    {
        printf("Podaj wartosc poczatkowa: ");
        scanf("%d", &wartosc);
        wt = stworz_tablice(rozmiar, wartosc);
        if (wt)
        {
            pokaz_tablice(wt, rozmiar);
            free(wt);
        }
        printf("Podaj liczbe elementow (<1 - koniec): ");
    }
    printf("Koniec.\n");
    return 0;
}
int * stworz_tablice (int elem, int wart)
{
    int * wsk;
    int i;
    wsk = (int *) malloc(elem*sizeof(int));
    for (i=0; i<elem; i++)
        wsk[i]=wart;
    return wsk;

}

void pokaz_tablice (const int tab[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (i%8==0&&i!=0)
            printf("\n");
        printf("%d ", tab[i]);

    }

    printf("\n");
}

