//zad13.c
//zad12.c
#include <stdio.h>
#include <stdlib.h>
#define PLIK    "zad12.txt"
#define M 20
#define N 30

int main(void)
{
    int tabela[M][N];
    char tablica[M][N+1];
    int i, j;
    FILE *odczyt, *zapis;
    odczyt = fopen(PLIK, "r");
    zapis = fopen("zad13_red.txt", "w");
    for (i=0; i<M; i++)
        for (j=0; j<N; j++)
            fscanf(odczyt, "%d", &tabela[i][j]);
    for (i=0; i<M; i++)
    {
        for (j=0; j<N; j++)
        {
            switch(tabela[i][j])
            {
            case 0:
                fprintf(zapis, " ");
                tablica[i][j]=' ';
                putchar(' ');
                break;
            case 1:
                tablica[i][j]='.';
                fprintf(zapis, ".");
                putchar('.');
                break;
            case 2:
                tablica[i][j]=39;
                fprintf(zapis, "%c", 39);
                putchar(39); //apostrophe '
                break;
            case 3:
                tablica[i][j]=':';
                fprintf(zapis, ":");
                putchar(':');
                break;
            case 4:
                tablica[i][j]='~';
                fprintf(zapis, "~");
                putchar('~');
                break;
            case 5:
                tablica[i][j]='*';
                fprintf(zapis, "*");
                putchar('*');
                break;
            case 6:
                tablica[i][j]='=';
                fprintf(zapis, "=");
                putchar('=');
                break;
            case 7:
                tablica[i][j]='&';
                fprintf(zapis, "&");
                putchar('&');
                break;
            case 8:
                tablica[i][j]='%';
                fprintf(zapis, "%%");
                putchar('%');
                break;
            case 9:
                tablica[i][j]='#';
                fprintf(zapis, "#");
                putchar('#');
                break;
            default:
                break;
            }
        }
        tablica[i][M]='\0';
        if (i!=N-1)
        {
            fprintf(zapis, "\n");
            putchar('\n');
        }

    }
    fclose(odczyt);
    fclose(zapis);
    printf("\ntest\n");
    printf("miejsce 1;3 - %c\n", tablica[0][2]);
    printf("miejsce 20; 30 - %c\n", tablica[19][29]);
    printf("miejsce 8;1 - %c\n", tablica[7][0]);
    return 0;
}

