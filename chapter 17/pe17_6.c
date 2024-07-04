//zad6.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 100
#define MAX 1000
void wypelnij_tab(int tab[], int n);
void pokaz_tab(const int tab[], int n);
int porownaj(const void * w1, const void * w2);
int search_bin(const int tab[], int n, int x);

int main(void)
{
    int szuk;
    int znaleziono;
    int wart[NUM];
    wypelnij_tab(wart, NUM);
    puts("Lista losowa:");
    pokaz_tab(wart, NUM);
    qsort(wart, NUM, sizeof(int), porownaj);
    puts("\nLista uporzadkowana:");
    pokaz_tab(wart, NUM);
    printf("Podaj liczbe do znalezienia. q aby zakonczyc\n");
    while (scanf("%d", &szuk)==1)
    {
        znaleziono = search_bin(wart, NUM, szuk);
        printf("znaleziono %d: %d\n", szuk, znaleziono);
        printf("Podaj liczbe do znalezienia. q aby zakonczyc\n");
    }
    //printf("\nLiczba %d %s sie w zbiorze", szuk, search_bin(wart, NUM, szuk)?"nie1 znajduje":"znajduje");
    return 0;
}

int search_bin(const int tab[], int n, int x)
{
    int found = 0;
    int min = 0;
    int max = n-1;
    int av;
    while (max>min)
    {
        av = (min+max)/2;
        if (x>tab[av])
            min = av + 1;
        else if (x<tab[av])
            max = av -1;
        else
        {
            found = 1;
            break;
        }
    }
    if (x==tab[min])
        found = 1;
    return found;
}
void wypelnij_tab(int tab[], int n)
{
    srand((unsigned int) time(0));
    int index;
    int j;
    for( index = 0; index < n; index++)
    {
        tab[index] = rand()%(MAX+1);
        for (j=0; j<index; j++)
            if (tab[index]==tab[j])
            {
                tab[index]=rand()%n;
                j=0;
            }
    }
}
void pokaz_tab(const int tab[], int n)
{
int index;
for( index = 0; index < n; index++)
{
printf("%9d ", tab[index]);
if (index % 6 == 5)
putchar('\n');
}
if (index % 6 != 0)
putchar('\n');
}
/* porzadkuje w kolejnosci rosnacej */
int porownaj(const void * w1, const void * w2)
{
/* do odczytania wartosci potrzebne sa wskazniki do double */
const int * a1 = (const int *) w1;
const int * a2 = (const int *) w2;
if (*a1 < *a2)
return -1;
else if (*a1 == *a2)
return 0;
else
return 1;
}
