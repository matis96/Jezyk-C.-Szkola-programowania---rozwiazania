//zad11.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 256
int main(int argc, char *argv[])
{
    FILE *file;
    char wiersz[BUF];
    if (argc<3)
    {
        fprintf(stderr, "Sposob uzycia pliku: %s lancuch nazwa_pliku", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *lancuch=argv[1];
    if ((file = fopen(argv[2], "r"))==NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku \"%s\".\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(wiersz, BUF, file)!=NULL)
    {
        if (strstr(wiersz, lancuch))
            fputs(wiersz, stdout);
        else
        {
            printf("Nie ma takiego lancucha w pliku %s", argv[2]);
            break;
        }

    }
    fclose(file);
    return 0;
}
