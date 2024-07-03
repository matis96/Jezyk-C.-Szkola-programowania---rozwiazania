//zad7a1.c
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    FILE *we1, *we2;
    char ch1, ch2;
    if (argc!=3)
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
    ch1 = getc(we1);
    ch2 = getc(we2);
    while (ch1!=EOF || ch2!=EOF)
    {
        while (ch1!=EOF && ch1!='\n')
        {
            putchar(ch1);
            ch1=getc(we1);
        }
        if (ch1!=EOF)
        {
            putchar('\n');
            ch1=getc(we1);
        }
        while (ch2!=EOF && ch2!='\n')
        {
            putchar(ch2);
            ch2=getc(we2);
        }
        if (ch2!=EOF)
        {
            putchar('\n');
            ch2=getc(we2);
        }
    }




    fclose(we1);
    fclose(we2);

    return 0;
}

