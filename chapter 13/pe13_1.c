//zad1.c
#include <stdio.h>
#include <stdlib.h> // prototyp funkcji exit()
int main()
{
    int ch; // przechowuje kolejne odczytywane znaki
    char plik[20];
    FILE *wp; // "wskaznik plikowy"
    unsigned long licznik = 0;
    puts("Podaj nazwe pliku:");
    scanf("%s", plik);

    if ((wp = fopen(plik, "r")) == NULL)
    {
        printf("Nie mozna otworzyc %s\n", plik);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(wp)) != EOF)
    {
        putc(ch,stdout);
        licznik++;
    }
    fclose(wp);
    printf("\nPlik %s zawiera %lu znakow\n", plik, licznik);
    return 0;
}
