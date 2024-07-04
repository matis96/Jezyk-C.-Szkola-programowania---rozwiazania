//zad3.c
/* ksiazki.c -- spis wielu ksiazek */
#include <stdio.h>
#include <string.h>
char * wczytaj(char * z, int ile)
#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 100 /* maksymalna liczba ksiazek */
struct ksiazka { /* definiuje szablon ksiazka */
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
};
void srt_struct(struct ksiazka *dzielo[], int );
int main(void)
{
    struct ksiazka bibl[MAXKS]; /* tablica struktur typu ksiazka */
    struct ksiazka * wsk_ksiazki[MAXKS];
    int licznik = 0;
    float suma = 0;
    int index;
    printf("Podaj tytul ksiazki.\n");
    printf("Aby zakonczyc, nacisnij [enter] na poczatku wiersza.\n");
    while (licznik < MAXKS && wczytaj(bibl[licznik].tytul, MAXTYT) != NULL && bibl[licznik].tytul[0] != '\0')
    {
        printf("Teraz podaj autora.\n");
        wczytaj(bibl[licznik].autor, MAXTYT);
        printf("Teraz podaj wartosc.\n");
        scanf("%f", &bibl[licznik].wartosc);
        wsk_ksiazki[licznik]=&bibl[licznik];
        licznik++;
        while (getchar() != '\n')
            continue; /* czysci wiersz wejsciowy */
        if (licznik < MAXKS)
            printf("Podaj kolejny tytul.\n");
    }
    srt_struct(wsk_ksiazki, licznik);
    if (licznik >0)
        for (index = 0; index < licznik; index++)
            suma += bibl[index].wartosc;
    if (licznik > 0)
    {
        printf("Oto lista Twoich ksiazek:\n");
        for (index = 0; index < licznik; index++)
            //printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul, bibl[index].autor, bibl[index].wartosc);
            printf("%s, autor: %s, cena: %.2f zl\n",
                   wsk_ksiazki[index]->tytul, wsk_ksiazki[index]->autor, wsk_ksiazki[index]->wartosc);
        printf("Calkowita wartosc: %.2f", suma);
    }
    else
        printf("Zadnych ksiazek? Szkoda\n");
    return 0;
    }
char * wczytaj(char *z, int ile)
{
    char * wynik;
    char * tutaj;
    wynik = fgets(z, ile, stdin);
    if (wynik)
    {
        tutaj = strchr(z, '\n'); // szukamy nowego wiersza
        if (tutaj) // jesli adres jest rozny od NULL
            *tutaj = '\0'; // zamieniamy znak nowego wiersza na pusty
        else
        while (getchar() != '\n')
            continue;
    }
    return wynik;
}

void srt_struct(struct ksiazka *dzielo[], int num)
{
    struct ksiazka *temp;
    int dol, szuk;
    for (dol = 0; dol < num-1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if (strcmp(dzielo[dol]->tytul,dzielo[szuk]->tytul) > 0)
            {
                temp = dzielo[dol];
                dzielo[dol]=dzielo[szuk];
                dzielo[szuk]=temp;
            }
}
