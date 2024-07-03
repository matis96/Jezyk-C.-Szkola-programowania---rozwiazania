//zad8.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DLAN 50
char *wczytaj(char *z, int ile);
int main(int argc, char *argv[])
{
    FILE *wp;
    char plik_zro[DLAN];
    int j, licznik;
    int k;
    int ch;
    if (argc<2)
    {
        fprintf(stderr, "Sposob uzycia: %s nazwa_pliku, nazwa_pliku, ...", argv[0]);
        exit(EXIT_FAILURE);
    }
    else if(argc==2)
    {
        ch = argv[1][0];
        puts("Podaj nazwe pliku (pusty wiersz konczy program):");
        while (wczytaj(plik_zro, DLAN) && plik_zro[0] != '\0')
        {
            licznik = 0;
            if ((wp = fopen(plik_zro, "r")) == NULL)
                fprintf(stderr, "Blad otwarcia pliku %s\n", plik_zro);
            else
            {
                while ((j=getc(wp))!=EOF)
                    if(j==ch)
                        licznik++;
                fclose(wp);
                printf("W pliku %s znak %c wystepuje %d razy\n", plik_zro, ch, licznik);

            }
            puts("Podaj nazwe pliku (pusty wiersz konczy program):");

        }
    }
    else
    {
        ch = argv[1][0];
        for (k=2; k<argc; k++)
        {
            licznik = 0;
            if ((wp = fopen(argv[k], "r")) == NULL)
                fprintf(stderr, "Blad otwarcia pliku %s\n", argv[k]);
            else
            {
                while ((j=getc(wp))!=EOF)
                    if(j==ch)
                        licznik++;
                fclose(wp);
                printf("W pliku %s znak %c wystepuje %d razy\n", argv[k], ch, licznik);
            }

        }
    }
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

