//zad10.c
#include <stdio.h>
#include <stdlib.h>
//#define PLIK    "zad10.txt"
//#define BUF 256
//void my_fgets(char *, int, FILE *);
int main(void)
{
    FILE *file;
    long licznik;
    char plik[40];
    char ch;
    puts("Podaj nazwe pliku:");
    scanf("%s", plik);
    if ((file = fopen(plik, "r"))==NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku \"%s\".\n", plik);
        exit(EXIT_FAILURE);
    }
    printf("Podaj pozycje w pliku:\n");
    while (scanf("%ld", &licznik)==1 && licznik>=0)
    {
        fseek(file, licznik, SEEK_SET);
        while ((ch=getc(file))&&ch!='\n')
        {
             if (ch==EOF)
             {
                 fprintf(stderr, "Proba przekroczenia pliku");
                 break;
             }
             putchar(ch);
        }
        printf("\nPodaj pozycje w pliku:\n");
    }


    fclose(file);
    return 0;
}

