//zad8.c
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
#define NR 12
char menu(void);
void usunwiersz(void);
char *wczytaj(char *z, int ile);

typedef struct samolot{
    int miejsce;
    bool miejsce_zajete;
    char imie[MAX];
    char nazwisko[MAX];
} SAMOLOT;
SAMOLOT miejsca[NR];
void liczba_miejsc(void);
void lista_miejsc(void);
void lista_alfabetyczna(void);
void klient(void);
void usun_miejsce(void);
void strlan(SAMOLOT *sortowany[], int num);
int main(void)
{

    int i = 0;
    char wybor;
    FILE *wp;
    int rozmiar = sizeof(SAMOLOT);
    //ustawienie wartosci pocz¹tkowych
    for (i; i<NR; i++)
    {
        miejsca[i].miejsce = i+1;
        miejsca[i].miejsce_zajete = false;
    }
    if ((wp=fopen("miejsca.dat", "rb"))==NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku\n");
    }
    fread(miejsca, rozmiar, NR, wp);
    fclose(wp);
    while ((wybor = menu())!='f')
    {
        switch(wybor)
        {
        case 'a':
            liczba_miejsc();
            break;
        case 'b':
            lista_miejsc();
            break;
        case 'c':
            lista_alfabetyczna();
            break;
        case 'd':
            klient();
            break;
        case 'e':
            usun_miejsce();
            break;
        }
    }
    if ((wp=fopen("miejsca.dat", "wb"))==NULL)
        fprintf(stderr, "Blad zapisu\n");
    fwrite(miejsca, rozmiar, NR, wp);
    fclose(wp);
    return 0;
}
char menu(void)
{
    char odp;
    puts("Aby wybrac opcje, wpisz jej oznaczenie literowe");
    puts("a) Pokaz liczbe pustych miejsc");
    puts("b) Pokaz liste pustych miejsc");
    puts("c) Pokaz alfabetyczna liste miejsc");
    puts("d) Zarezerwuj miejsce dla klienta");
    puts("e) Usun rezerwacje miejsca");
    puts("f) Koniec");
    odp = getchar();
    odp = tolower(odp);
    usunwiersz();
    while (strchr("abcdef", odp) == NULL)
    {
        puts("Wpisz a, b, c, d, e lub f:");
        odp = tolower(getchar());
        usunwiersz();
    }
    return odp;
}
void liczba_miejsc()
{
    int licznik = 0;
    int i=0;
    for (i; i<NR; i++)
        if (!miejsca[i].miejsce_zajete)
            licznik++;
    printf("Liczba wolnych miejsc: %d\n", licznik);
}
void lista_miejsc()
{
    int i=0;
    puts("Lista pustych miejsc: ");
    for (i; i<NR; i++)
        if (!miejsca[i].miejsce_zajete)
            printf("%d ", miejsca[i].miejsce);
    puts("");
}
void lista_alfabetyczna()
{
    SAMOLOT *ps[NR];
    int licz=0;
    int i;
    int k;
    for (i=0; i<NR; i++)
    {
        ps[i]=&miejsca[i];
        licz++;
    }
    strlan(ps, licz);
    for (k=0; k<licz; k++)
        if (ps[k]->miejsce_zajete)
            printf("%d %s %s\n", ps[k]->miejsce, ps[k]->nazwisko, ps[k]->imie);
}
void klient()
{
    int nr;
    puts("Podaj nr miejsca (1-12) ");
    proba: while (scanf("%d", &nr)!=1 || (nr<1 || nr >12))
        puts("Podaj nr 1-12");
    if (miejsca[nr-1].miejsce_zajete)
    {
        puts("To miejsce jest zajete!");
        puts("Podaj nr miejsca (1-12) ");
        goto proba;
    }
    else
    {
        puts("Podaj swoje imie: ");
        scanf("%s", miejsca[nr-1].imie);
        usunwiersz();
        puts("Podaj swoje nazwisko: ");
        scanf("%s", miejsca[nr-1].nazwisko);
        usunwiersz();
        miejsca[nr-1].miejsce_zajete = true;
    }
    //printf("Twoje imie to %s\n", miejsca[nr-1].imie);
    //printf("Twoje nazwisko to %s\n", miejsca[nr-1].nazwisko);

}

void usun_miejsce()
{
    int nr;
    puts("Podaj nr miejsca do usuniecia:");
    proba: while (scanf("%d", &nr)!=1 || (nr<1 || nr >12))
        puts("Podaj nr 1-12");
    if (!miejsca[nr-1].miejsce_zajete)
    {
        puts("To miejsce jest wolne!");
        goto proba;
    }
    else
    {
        usunwiersz();
        miejsca[nr-1].miejsce_zajete=false;
        strcpy(miejsca[nr-1].imie, "");
        strcpy(miejsca[nr-1].nazwisko, "");
    }

}
void usunwiersz(void)
{
    while (getchar()!='\n')
        continue;
}
char *wczytaj(char *z, int ile)
{
char * wynik;
char * tutaj;
wynik = fgets(z, ile, stdin);
if (wynik)
{
tutaj = strchr(z, '\n'); // szukamy nowego wiersza
if (tutaj) // jesli adres jest rozny od NULL
*tutaj = '\0'; // zamieniamy znak nowego wiersza na pusty
else
while (getchar() != '\n')
continue; // porzucenie reszty wiersza
}
return wynik;
}

void strlan(SAMOLOT *sortowany[], int num)
{
    SAMOLOT *temp;
    int dol, szuk;
    for (dol = 0; dol < num-1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if (strcmp(sortowany[dol]->nazwisko,sortowany[szuk]->nazwisko) > 0)
            {
                temp = sortowany[dol];
                sortowany[dol] = sortowany[szuk];
                sortowany[szuk] = temp;
            }
}
