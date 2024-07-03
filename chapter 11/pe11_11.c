//zad11.c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define ROZMIAR 81
#define GRAN 10
void menu(void);
char *wczytaj(char *z, int ile);
void opcja1(char *lancuchy[], int num);
void opcja2(char *lancuchy[], int num);
void opcja3(char *lancuchy[], int num);
void opcja4(char *lancuchy[], int num);
int slowo(char *);
int main(void)
{
    char dane[GRAN][ROZMIAR];
    char *ASCII[GRAN];
    char *pierwotne[GRAN];
    char *dlugosc[GRAN];
    char *dlugosc_slowo[GRAN];
    int licz = 0;
    int wybor;
    printf("Podaj maksymalnie %d wierszy\n", GRAN);
    printf("Aby zakonczyc wywolaj EOF\n");
    while (licz < GRAN && wczytaj(dane[licz], ROZMIAR) != NULL && dane[licz][0] != '\0')
    {
        ASCII[licz] = dane[licz];
        pierwotne[licz] = dane[licz];
        dlugosc[licz]=dane[licz];
        dlugosc_slowo[licz]=dane[licz];
        licz++;
    }
    menu();
    scanf("%d", &wybor);
    while (wybor!=5)
    {
        switch(wybor)
        {
           case 1: opcja1(pierwotne, licz); break;
           case 2: opcja2(ASCII, licz); break;
           case 3: opcja3(dlugosc, licz); break;
           case 4: opcja4(dlugosc_slowo, licz); break;
           case 5: break;
           default: printf("Zly wybor! Sprobuj jeszcze raz\n"); break;
        }

        scanf("%d", &wybor);
    }

    opcja4(dlugosc_slowo, licz);
    return 0;
}

void menu(void)
{
    printf("1. wyswietl pierwotna liste lancuchow\n");
    printf("2. wyswietl lancuchy w porzadku ASCII\n");
    printf("3. wyswietl lancuchy wedlug dlugosci (rosnaco)\n");
    printf("4. wyswietl lancuchy wedlug dlugosci pierwszego slowa\n");
    printf("5. koniec\n");
}
char *wczytaj(char *z, int ile)
{
char * wynik;
int i = 0;
wynik = fgets(z, ile, stdin);
if (wynik) // wynik rozny od NULL
{
while (z[i] != '\n' && z[i] != '\0')
i++;
if (z[i] == '\n')
z[i] = '\0'; // znak nowego wiersza -> znak pusty
else // z[i] == '\0'
while (getchar() != '\n')
continue;
}
return wynik;
}

void opcja1(char *lancuchy[], int num)
{
    int k =0;
    for (k; k<num; k++)
        puts(lancuchy[k]);
}
void opcja2(char *lancuchy[], int num)
{
char *temp;
int dol, szuk;
for (dol = 0; dol < num-1; dol++)
for (szuk = dol + 1; szuk < num; szuk++)
if (strcmp(lancuchy[dol],lancuchy[szuk]) > 0)
{
temp = lancuchy[dol];
lancuchy[dol] = lancuchy[szuk];
lancuchy[szuk] = temp;
}
 int k =0;
    for (k; k<num; k++)
        puts(lancuchy[k]);
}
void opcja3(char *lancuchy[], int num)
{
    char *temp;
int dol, szuk;
for (dol = 0; dol < num-1; dol++)
for (szuk = dol + 1; szuk < num; szuk++)
if (strlen(lancuchy[szuk])<strlen(lancuchy[dol]))
{
temp = lancuchy[dol];
lancuchy[dol] = lancuchy[szuk];
lancuchy[szuk] = temp;
}
 int k =0;
    for (k; k<num; k++)
        puts(lancuchy[k]);
}

void opcja4(char *lancuchy[], int num)
{
char *temp;
int dol, szuk;
for (dol = 0; dol < num-1; dol++)
for (szuk = dol + 1; szuk < num; szuk++)
if (slowo(lancuchy[szuk])>slowo(lancuchy[dol]))
{
temp = lancuchy[dol];
lancuchy[dol] = lancuchy[szuk];
lancuchy[szuk] = temp;
}
 int k =0;
    for (k; k<num; k++)
        puts(lancuchy[k]);
}

int slowo(char *s)
{
   bool word = false;
   int i=0;
   while (*s!='/0')
   {
       if(isspace(*s++))
        {
            if (word)
                break;
            else
            {
                continue;
            }

        }
        if (!word)
            word = true;
        i++;
   }
   return i;
}

