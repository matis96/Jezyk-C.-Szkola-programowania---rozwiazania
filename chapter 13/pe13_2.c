//zad2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROZMIAR_BUF 4096
#define DLAN 50
void dopisz(FILE *zrodlo, FILE *cel);
int main(int argc, char *argv[])
{
    FILE *pd, *pz;
    //char plik_doc[DLAN];
    //char plik_zro[DLAN];
    int k;
    int pliki =0;
    printf("Liczba odczytanych argumentow %d\n", argc);
    //plik_doc = argv[1];
    if ((pd = fopen(argv[1], "a+b")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(pd, NULL, _IOFBF, ROZMIAR_BUF) != 0)
    {
        fputs("Nie mozna utworzyc bufora wyjsciowego\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (k=3; k<=argc; k++)
    {
        //plik_zro = argv[k];
        if (strcmp(argv[k-1], argv[1]) == 0)
            fputs("Nie mozna dopisac pliku do siebie\n",stderr);
        else if ((pz = fopen(argv[k-1], "rb")) == NULL)
            fprintf(stderr, "Blad otwarcia pliku %s\n", argv[k-1]);
        else
        {
            if (setvbuf(pz, NULL, _IOFBF, ROZMIAR_BUF) != 0)
            {
                fputs("Nie mozna utworzyc bufora wejsciowego\n",stderr);
                continue;
            }
            dopisz(pz, pd);
            if (ferror(pz) != 0)
                fprintf(stderr,"Blad odczytu pliku %s\n", argv[k-1]);
            if (ferror(pd) != 0)
                fprintf(stderr,"Blad zapisu pliku %s\n", argv[1]);
            fclose(pz);
            pliki++;
            //printf("Plik %s dopisany.\n", plik_zro);
            //puts("Kolejny plik (pusty wiersz konczy program):");
        }
    }
    printf("Koniec. Dopisano %d plikow.\n", pliki);
    fclose(pd);
    return 0;
}

void dopisz(FILE *zrodlo, FILE *cel)
{
    size_t bajty;
    static char temp[ROZMIAR_BUF]; // jednorazowy przydzial bufora
    while ((bajty = fread(temp,sizeof(char),ROZMIAR_BUF,zrodlo)) > 0)
        fwrite(temp, sizeof (char), bajty, cel);
}
