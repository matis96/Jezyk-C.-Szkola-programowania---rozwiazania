//zad7b.c
#include <stdio.h>
#include <stdlib.h>
#define BUF 256
void my_fgets(char *, int, FILE *);
int main(int argc, char *argv[])
{
    FILE *we1, *we2;
    char wiersz1[BUF];
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
    while (1)
    {
        if (!feof(we1))
        {
            my_fgets(wiersz1, BUF, we1);
            printf("%s ", wiersz1);
        }
        if (feof(we1))
            wiersz1[0]='\0';
        if (!feof(we2))
        {
            my_fgets(wiersz1, BUF, we2);
            printf("%s", wiersz1);
        }
        if (!feof(we2))
            putchar('\n');
        if (feof(we2))
        {

            //wiersz1[0]='\0';
            putchar('\n');
        }

        if (feof(we1)&&feof(we2))
        {
            printf("Done!");
            break;
        }

    }

    fclose(we1);
    fclose(we2);

    return 0;
}

void my_fgets(char *string, int num, FILE * stream)
{
    fgets(string, num, stream);
//changes \n to \0
    while (*string!='\0')
    {
        if (*string=='\n')
        {
            *string = '\0';
            break;
        }

        string++;
    }
}
