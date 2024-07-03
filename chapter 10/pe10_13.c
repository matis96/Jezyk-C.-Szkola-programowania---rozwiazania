//zad13.c
#include <stdio.h>
void pkt_a(double tab[3][5]);
double pkt_b(double tab[5]);
double pkt_c(double tab[3]);
double pkt_d(double tab[3][5]);
void wyswietl(double b[3], double c, double d);
int main(void)
{
    double dane[3][5];
    double b[3];
    double c,d;
    //double b0, b1, b2;
    pkt_a(dane);
    for (int i=0; i<3; i++)
        b[i]=pkt_b(dane[i]);
    c = pkt_c(b);
    d = pkt_d(dane);
    wyswietl(b, c, d);
    return 0;
}
void pkt_a(double tab[3][5])
{
    for (int i=0; i<3; i++)
    {
        printf("Podaj 5 wartosci typu double\n");
        for (int j=0; j<5; j++)
            scanf("%lf", &tab[i][j]);
    }
    printf("\nPodana tablica: \n");
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<5; j++)
            printf("%.2f ", tab[i][j]);
        putchar('\n');
    }

}

double pkt_b(double tab[5])
{
    double suma=0;
    for (int i=0; i<5; i++)
        suma += tab[i];
    return suma/5;
}

double pkt_c(double tab[3])
{
    double suma =0;
    for (int i=0; i<3; i++)
        suma += tab[i];
    return suma/3;
}

double pkt_d(double tab[3][5])
{
    double max = tab[0][0];
    for (int i=0; i<3; i++)
        for (int j=0; j<5; j++)
            if (max<tab[i][j])
                max = tab[i][j];
    return max;
}

void wyswietl(double b[3], double c, double d)
{
    putchar('\n');
    for (int i =0; i<3; i++)
        printf("Srednia dla zbioru #%d to %.2f\n", i, b[i]);

    printf("Srednia dla calego zbioru to %.2f\n", c);
    printf("Max = %.2f", d);
}

