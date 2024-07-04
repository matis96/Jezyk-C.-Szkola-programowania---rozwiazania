//zad7.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 10 /* maksymalna liczba ksiazek */
struct ksiazka { /* utworzenie szablonu ksiazka */
    //int pozycja;
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
    //bool usuniete;
};
char *wczytaj(char * z, int ile);
bool odpowiedz(void);
//void sortuj(FILE *stream, )
void zmien(struct ksiazka *);

int main(void)
{
    struct ksiazka bibl[MAXKS]; /* tablica struktur */
    int licznik = 0;
    int index, licznikp;
    int numer;
    char ch;
    FILE * pksiazki;
    int rozmiar = sizeof (struct ksiazka);
    bool odp, odp2; //odpowiedz na T/N
    if ((pksiazki = fopen("ksiazki.dat", "rb")) == NULL)
    {
        fputs("Nie moge otworzyc pliku ksiazki.dat\n",stderr);
        exit(1);
    }
    rewind(pksiazki); /* przejscie na poczatek pliku */
    while (licznik < MAXKS && fread(&bibl[licznik], rozmiar, 1, pksiazki) == 1)
    {
        if (licznik == 0)
            puts("Biezaca zawartosc pliku ksiazki.dat:");
        printf("%s by %s: %.2f zl\n", bibl[licznik].tytul,
        bibl[licznik].autor, bibl[licznik].wartosc);
        puts("Czy zmienic lub usunac powyzsza mozycje?");
        puts("a) Nie,   b) zmienic,     c) usunac");
        ch = getchar();
        while (getchar() != '\n')
                continue; // porzucenie reszty wiersza
        switch (ch)
        {
        case 'a':
        case 'A':
            break;
        case 'b':
        case 'B':
            zmien(&bibl[licznik]);
            break;
        case 'c':
        case 'C':
            licznik--;
            break;
        default:
            break;
        }
        licznik++;
    }
    licznikp = licznik;
    /*puts("Czy chcesz zmienic zawartosc pliku? [T/N]");
    odp = odpowiedz();
    if (odp)
    {
        puts("Podaj nr pozycji");
        scanf("%d ", &numer);
        puts("Czy chcesz usunac tytul? [T/N]");
        odp2 = odpowiedz();
        if (odp2)
        {
            bibl[numer].usuniete = true;
        }
    }*/
    if (licznik == MAXKS)
    {
        fputs("Plik ksiazki.dat jest pelny.", stderr);
        exit(2);
    }
    fclose(pksiazki);
    puts("Podaj nowe tytuly ksiazek.");
    puts("Aby zakonczyc, nacisnij [enter] na poczatku wiersza.");
    while (licznik < MAXKS && wczytaj(bibl[licznik].tytul, MAXTYT) != NULL && bibl[licznik].tytul[0] != '\0')
    {
        //bibl[licznik].pozycja = licznik + 1;
        puts("Teraz podaj autora.");
        wczytaj(bibl[licznik].autor, MAXAUT);
        puts("Teraz podaj wartosc.");
        scanf("%f", &bibl[licznik++].wartosc);
        while (getchar() != '\n')
        continue; /* czysci wiersz wejsciowy */
        if (licznik < MAXKS)
        puts("Podaj nastepny tytul.");
    }
    if ((pksiazki = fopen("ksiazki.dat", "wb")) == NULL)
    {
        fputs("Nie moge otworzyc pliku ksiazki.dat\n",stderr);
        exit(3);
    }
    if (licznik > 0)
    {
        //rewind(pksiazki);   //dodane
        puts("Oto lista Twoich ksiazek:\n");
        for (index = 0; index < licznik; index++)
            //if (bibl[index].usuniete!=false)
            printf("%s, autor: %s, cena: %.2f zl\n", bibl[index].tytul,
        bibl[index].autor, bibl[index].wartosc);
            //if (bibl[index].usuniete!=false)
                //fprintf(pksiazki, "%d. %s, autor: %s, cena: %.2f zl\n", bibl[index].pozycja, bibl[index].tytul,
                //bibl[index].autor, bibl[index].wartosc)
        fwrite(&bibl[0], rozmiar, licznik, pksiazki);
    }
    else
        puts("Zadnych ksiazek? Szkoda\n");
    puts("Koniec.\n");
    fclose(pksiazki);
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
                continue; // porzucenie reszty wiersza
    }
    return wynik;
}

void zmien(struct ksiazka *ks)
{
    puts("Podaj nowy tytul ksiazki");
    wczytaj(ks->tytul, MAXTYT);
    puts("Teraz podaj autora");
    wczytaj(ks->autor, MAXAUT);
    puts("Teraz podaj nowa wartosc");
    scanf("%f", &ks->wartosc);
    while (getchar() != '\n')
        continue; /* czysci wiersz wejsciowy */

}

bool odpowiedz(void)
{
    char ch=getchar();
    while (getchar() != '\n')
                continue; // porzucenie reszty wiersza
    if (ch=='T' || ch == 't')
        return true;
    else
        return false;
}
