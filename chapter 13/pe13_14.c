//zad14.c
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PLIK    "zad12.txt"
void popraw_obraz(int tab[][30], int n);
int main(void)
{
    int tabela[20][30];
    char tablica[20][31];
    int i, j;
    FILE *odczyt, *zapis;
    odczyt = fopen(PLIK, "r");
    zapis = fopen("zad13_red.txt", "w");
    for (i=0; i<20; i++)
        for (j=0; j<30; j++)
            fscanf(odczyt, "%d", &tabela[i][j]);
    popraw_obraz(tabela, 20);
    /*for (i=0; i<20; i++)
    {
        for (j=0; j<30; j++)
            printf("%d ", tabela[i][j]);
        putchar('\n');
    }*/
    for (i=0; i<20; i++)
    {
        for (j=0; j<30; j++)
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
        tablica[i][30]='\0';
        if (i!=19)
        {
            fprintf(zapis, "\n");
            putchar('\n');
        }

    }

    fclose(odczyt);
    fclose(zapis);
    return 0;
}
void popraw_obraz(int tab[][30], int n)
{
    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<30; j++)
        {
            if ((i==0 && j==0)||(i==0 && j==20) || (i==19 && j==0) || (i==19 && j==29)) //4 rogi
            {
                if (i==0 && j==0)//lewy górny róg
                    if (abs(tab[i][j]-abs(tab[i][j+1]))>1 && abs(tab[i][j]-abs(tab[i+1][j]))>1)
                        tab[i][j] = (int) round((tab[i][j+1]+tab[i+1][j])/2.0);
                else if (i==0 && j==29 ) //prawy górny róg
                    if (abs(tab[i][j]-abs(tab[i][j-1]))>1 && abs(tab[i][j]-abs(tab[i+1][j]))>1)
                        tab[i][j] = (int) round((tab[i][j-1]+tab[i+1][j])/2.0);
                else if (i==19 && j==0) //lewy dolny róg
                    if (abs(tab[i][j]-abs(tab[i-1][j]))>1 && abs(tab[i][j]-abs(tab[i][j+1]))>1)
                        tab[i][j] = (int) round((tab[i-1][j]+tab[i][j+1])/2.0);
                else //prawy dolny rog
                    if (abs(tab[i][j]-abs(tab[i][-1]))>1 && abs(tab[i][j]-abs(tab[i-1][j]))>1)
                        tab[i][j] = (int) round((tab[i][j-1]+tab[i-1][j])/2.0);
            }
            else if (i==0 || j==0 || i==(n-1) || j==29) //krawedzie
            {
                if (i==0) // gorna krawedz
                    if (abs(tab[i][j]-abs(tab[i][j-1]))>1 && abs(tab[i][j]-abs(tab[i][j+1]))>1 && abs(tab[i][j]-abs(tab[i+1][j]))>1)
                        tab[i][j]= (int) round((tab[i][j-1]+tab[i][j+1]+tab[i+1][j])/3.0);
                else if (j==0) //lewa krawedz
                    if (abs(tab[i][j]-abs(tab[i-1][j]))>1 && abs(tab[i][j]-abs(tab[i][j+1]))>1 && abs(tab[i][j]-abs(tab[i+1][j]))>1)
                        tab[i][j]= (int) round((tab[i-1][j]+tab[i][j+1]+tab[i+1][j])/3.0);
                else if (i==(n-1)) //dolna krawedz
                    if (abs(tab[i][j]-abs(tab[i][j-1]))>1 && abs(tab[i][j]-abs(tab[i][j+1]))>1 && abs(tab[i][j]-abs(tab[i-1][j]))>1)
                        tab[i][j]= (int) round((tab[i][j-1]+tab[i][j+1]+tab[i-1][j])/3.0);
                else //prawa krawedz
                    if (abs(tab[i][j]-abs(tab[i][j-1]))>1 && abs(tab[i][j]-abs(tab[i][j+1]))>1 && abs(tab[i][j]-abs(tab[i+1][j]))>1)
                        tab[i][j]= (int) round((tab[i][j-1]+tab[i][j+1]+tab[i+1][j])/3.0);

            }
            else
            {
                if (abs(tab[i][j]-tab[i-1][j])>1 && abs(tab[i][j]-tab[i+1][j])>1 && abs(tab[i][j]-tab[i][j-1])>1 && abs(tab[i][j]-tab[i][j+1])>1)
                    tab[i][j]= (int) round((tab[i-1][j]+tab[i+1][j]+tab[i][j-1]+tab[i][j+1])/4.0);
            }
        }
}
