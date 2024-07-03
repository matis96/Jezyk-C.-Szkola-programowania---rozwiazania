//zad8.c
#include <stdio.h>
char pobierz_wybor(void);
char pobierz_pierwszy(void);
void dodawanie(void);
void odejmowanie(void);
void mnozenie(void);
void dzielenie(void);
float pobierz_liczbe(void);
float pobierz_dzielna(void);
int main(void)
{
    int wybor;
    while ( (wybor = pobierz_wybor()) != 'k')
    {
        switch (wybor)
        {
        case 'a': dodawanie();
                break;
        case 'b': odejmowanie();
                break;
        case 'c': mnozenie();
                break;
        case 'd': dzielenie();
                break;
        default: printf("Blad programu!\n");
                break;
        }

    }
    printf("Koniec.");
    return 0;
}
char pobierz_wybor(void)
{
    int ch;
    printf("Wybierz jedno z dzialan:\n");
    printf("a. dodawanie    b. odejmowanie\n");
    printf("c. mnozenie     d. dzielenie\n");
    printf("k. koniec\n");
    ch = pobierz_pierwszy();
    while ( (ch < 'a' || ch > 'd') && ch != 'k')
    {
        printf("Wybierz jedno z dzialan:\n");
        printf("a. dodawanie    b. odejmowanie\n");
        printf("c. mnozenie     d. dzielenie\n");
        printf("k. koniec\n");
        ch = pobierz_pierwszy();
    }
    return ch;
}

char pobierz_pierwszy(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}

void dodawanie(void)
{
    float j, k;
    printf("Podaj pierwsza liczbe: ");
    j = pobierz_liczbe();
    printf("Podaj druga liczbe: ");
    k = pobierz_liczbe();
    printf("%.2f + %.2f = %.2f\n", j, k, j+k);
    while ( getchar() != '\n')
        continue;
}

void odejmowanie(void)
{
    float j,k;
    printf("Podaj pierwsza liczbe: ");
    j = pobierz_liczbe();
    printf("Podaj druga liczbe: ");
    k = pobierz_liczbe();
    printf("%.2f - %.2f = %.2f\n", j, k, j-k);
    while ( getchar() != '\n')
        continue;
}

void mnozenie(void)
{
    float j,k;
    printf("Podaj pierwsza liczbe: ");
    j = pobierz_liczbe();
    printf("Podaj druga liczbe: ");
    k = pobierz_liczbe();
    printf("%.2f * %.2f = %.2f\n", j, k, j*k);
    while ( getchar() != '\n')
        continue;
}

void dzielenie(void)
{
    float j,k;
    printf("Podaj pierwsza liczbe: ");
    j = pobierz_liczbe();
    printf("Podaj druga liczbe: ");
    k = pobierz_dzielna();
    printf("%.2f / %.2f = %.2f\n", j, k, j/k);
    while ( getchar() != '\n')
        continue;
}

float pobierz_liczbe(void)
{
    float we;
    char ch;
    while( scanf("%f", &we) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" nie jest liczba.\n");
        printf("Podaj liczbe np. 2.5, -178E8 czy 3: ");
    }
    return we;
}

float pobierz_dzielna(void)
{
    float we;
    char ch;
    while( scanf("%f", &we) != 1 || we == 0)
    {
        if (we==0)
        {
            printf("Podaj liczbe inna niz 0: ");
            continue;
        }
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" nie jest liczba.\n");
        printf("Podaj liczbe np. 2.5, -178E8 czy 3: ");
    }
    return we;
}
