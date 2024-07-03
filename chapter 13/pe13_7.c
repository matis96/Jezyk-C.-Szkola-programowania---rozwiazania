//zad7.c
#include <stdio.h>
#include <stdlib.h>
#define BUF 256
int main(int argc, char *argv[])
{
    FILE *we1, *we2;
    char wiersz1[BUF], wiersz2[BUF];
    if (argc<3)
    {
        fprintf(stderr, "Sposob uzycia: %s nazwa_pliku nazwa_pliku\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((we1 = fopen(argv[1], "r"))==NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku \"%s\".\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((we2 = fopen(argv[2], "r"))==NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku \"%s\".\n", argv[2]);
        exit(EXIT_FAILURE);
    }

}
