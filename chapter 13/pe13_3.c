//zad3.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define DLAN 50
char *wczytaj(char *z, int ile);
int main(void)
{
    FILE *pd, *pz;
    char plik_doc[DLAN]; // nazwa pliku dopisywanego
    char plik_zro[DLAN];
    int ch;
    puts("Podaj nazwe pliku docelowego:");
    wczytaj(plik_doc, DLAN);
    if ((pd = fopen(plik_doc, "w+")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia %s\n", plik_doc);
        exit(EXIT_FAILURE);
    }
    puts("Podaj nazwe pliku zrodlowego:");
    wczytaj(plik_zro, DLAN);
    if ((pz = fopen(plik_zro, "r")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia %s\n", plik_doc);
        exit(EXIT_FAILURE);
    }
    while( (ch = getc(pz))!=EOF)
    {
        ch=toupper(ch);
        putc(ch, pd);
        putchar(ch);
    }
    fclose(pz); fclose(pd);
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
