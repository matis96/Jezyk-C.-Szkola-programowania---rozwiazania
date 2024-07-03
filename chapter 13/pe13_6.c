//zad6.c
#include <stdio.h>
#include <stdlib.h> // dla exit()
#include <string.h>
#define DL 40
char *wczytaj(char *z, int ile);
int main(void)
{
    FILE *we, *wy; // deklaracja 2 wskaznikow plikowych
    int ch;
    char nazwa[DL]; // miejsce na nazwy pliku wyjsciowego
    char nazwa2[DL];
    int licznik = 0;
    puts("Podaj nazwe pliku do zmiany:");
    wczytaj(nazwa, DL);
    if ((we = fopen(nazwa, "r")) == NULL)
    {
        fprintf(stderr, "Nie moglem otworzyc pliku \"%s\".\n", nazwa);
        exit(EXIT_FAILURE);
    }
    strncpy(nazwa2,nazwa, DL-5); // kopiuje nazwe pliku do tablicy
    nazwa[DL-5] = '\0';
    strcat(nazwa2,".red"); // dodaje .red do nazwy
    if ((wy = fopen(nazwa2, "w")) == NULL)
    { // otwiera plik do zapisu
        fprintf(stderr,"Nie mozna utworzyc pliku wyjsciowego.\n");
        exit(EXIT_FAILURE);
    }
    // kopiowanie danych
    while ((ch = getc(we)) != EOF)
        if (licznik++ % 3 == 0)
            putc(ch, wy); // wyswietla co trzeci znak
    // sprzatanie
    if (fclose(we) != 0 || fclose(wy) != 0)
        fprintf(stderr,"Blad przy zamykaniu plikow.\n");
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
