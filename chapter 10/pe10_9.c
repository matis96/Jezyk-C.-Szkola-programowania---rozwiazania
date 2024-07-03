//zad9.c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 3
#define M 5

void kopiujVLA(int n, int m, double zrodlo[n][m], double cel[n][m]);
void pokazVLA(int n, int m, double tab1[n][m], double tab2[n][m]);
int main(void)
{
    srand(time(NULL));

    double tab[N][M];
    double cel[N][M];

    for (int i=0; i<3; i++)
        for (int j=0; j<5; j++)
            tab[i][j]=rand() / (double) RAND_MAX;

    kopiujVLA(N,M, tab, cel);
    pokazVLA(N,M, tab, cel);

    return 0;
}

void kopiujVLA(int n, int m, double zrodlo[n][m], double cel[n][m])
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cel[i][j]=zrodlo[i][j];
}

void pokazVLA(int n, int m, double tab1[n][m], double tab2[n][m])
{
    printf("Oryginalna tablica: \n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%.2f ", tab1[i][j]);
        putchar('\n');
    }

    printf("Skopiowana tablica: \n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%.2f ", tab2[i][j]);
        putchar('\n');
    }
}
