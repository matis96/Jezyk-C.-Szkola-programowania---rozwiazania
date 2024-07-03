//zad4.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *wp;
    int k;
    int ch;
    for (k=1; k<argc; k++)
    {
        if ((wp = fopen(argv[k], "r")) == NULL)
        {
            fprintf(stderr, "Blad otwarcia %s\n", argv[k]);
            exit(EXIT_FAILURE);
        }
        while ((ch=getc(wp))!=EOF)
            putchar(ch);
        printf("\n");
        fclose(wp);
    }
    return 0;
}
