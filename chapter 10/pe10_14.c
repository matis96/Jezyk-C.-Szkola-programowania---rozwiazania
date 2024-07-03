//zad14.c
#include <stdio.h>

#define ROWS 3
#define COL 5
void pkt_a(int n, int m, double tab[n][m]);
double pkt_b(int m, double tab[m]);
double pkt_c(int n, double tab[n]);
double pkt_d(int n, int m, double tab[n][m]);
void wyswietl(int n, double b[n], double c, double d);
int main(void)
{
    double dane[ROWS][COL];
    double b[3];
    double c,d;
    pkt_a(ROWS, COL, dane);
    for (int i=0; i<ROWS; i++)
        b[i]=pkt_b(COL, dane[i]);
    c = pkt_c(ROWS, b);
    d = pkt_d(ROWS, COL, dane);
    wyswietl(ROWS, b, c, d);
    return 0;
}
void pkt_a(int n, int m, double tab[n][m])
{
    for (int i=0; i<n; i++)
    {
        printf("Podaj %d wartosci typu double\n", COL);
        for (int j=0; j<m; j++)
            scanf("%lf", &tab[i][j]);
    }
    printf("\nPodana tablica: \n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%.2f ", tab[i][j]);
        putchar('\n');
    }
}

double pkt_b(int m, double tab[m])
{
    double suma=0;
    for (int i=0; i<m; i++)
        suma += tab[i];
    return suma/COL;
}

double pkt_c(int n, double tab[n])
{
    double suma =0;
    for (int i=0; i<n; i++)
        suma += tab[i];
    return suma/ROWS;
}

double pkt_d(int n, int m, double tab[n][m])
{
    double max = tab[0][0];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (max<tab[i][j])
                max = tab[i][j];
    return max;
}

void wyswietl(int n, double b[n], double c, double d)
{
     putchar('\n');
    for (int i =0; i<n; i++)
        printf("Srednia dla zbioru #%d to %.2f\n", i, b[i]);

    printf("Srednia dla calego zbioru to %.2f\n", c);
    printf("Max = %.2f", d);
}
