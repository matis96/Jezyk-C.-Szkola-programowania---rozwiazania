#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "drzewo.h"
#define MAXROZM 30
void clean_word(char *);
void wyswpoz(Pozycja);
char menu(void);
void szukajsl(const Drzewo *wd);
void dodaj_slowo(char *, Drzewo *);
char * wczytaj(char *z, int ile);

int main(void)
{
    FILE *wp;
    Pozycja pozycja;
    Drzewo slowa;
    char wybor;
    InicjujDrzewo(&slowa);
    if ((wp = fopen("test.txt", "r"))==NULL)
        fprintf(stderr, "Blad otwarcia pliku");
    while (fscanf(wp, "%s", pozycja.slowo)==1)
    {

        clean_word(pozycja.slowo);
        DodajPozycje(&pozycja, &slowa);
    }
    fclose(wp);
    while ((wybor = menu()) != 'q')
    {
        switch (wybor)
        {
        case 'a':
            if (PusteDrzewo(&slowa))
                puts("Brak pozycji");
            else
                Przejdz(&slowa, wyswpoz);
            break;
        case 'b': szukajsl(&slowa);
            break;
        default: puts("Blad w instrukcji switch");
        }
    }
    if (PusteDrzewo(&slowa))
        puts("Brak pozycji");
    //else
        //Przejdz(&slowa, wyswpoz);
    UsunWszystko(&slowa);
    return 0;
}
void wyswpoz(Pozycja pozycja)
{
    printf("Slowo %s, l.wystapien %d\n", pozycja.slowo, pozycja.powtorzenie);
}
void clean_word(char *temp)
{
    char *change;
    while (*temp!='\0')
    {
        *temp = tolower(*temp);
        if (*temp=='(' || *temp=='"' || *temp=='#' || *temp=='@' || *temp=='$' || *temp=='*')
        {
            change = temp;
            while (*change!='\0')
            {
                *change = *(change+1);
                change++;
            }

        }
        if (*temp=='-')
        {
            temp++;
            continue;
        }
        if (ispunct(*temp))
            *temp='\0';
        temp++;
    }
}

char menu(void)
{
    int ch;
    puts("Podaj litere odpowiadajaca wybranej opcji");
    puts("a) Lista wszystkich slow");
    puts("b) wystepowanie poszczegolnego slowa");
    puts("q) Koniec");
    while ((ch=getchar()) != 'q')
    {
        while (getchar()!='\n')
            continue;
        ch = tolower(ch);
        if (strchr("abq", ch) == NULL)
            puts("Wpisz a,b lub q");
        else
            break;
    }
    return ch;
}

void szukajsl(const Drzewo *wd)
{
    Pozycja tymcz;
    puts("Podaj slowo do sprawdzenia (wpisz male litery)");
    wczytaj(tymcz.slowo, MAXROZM);
    const Pozycja * szuk;
    szuk = WhereInTree(&tymcz, wd);
    if (szuk != NULL)
        printf("slowo %s pojawia sie %d razy\n", tymcz.slowo, szuk->powtorzenie);
    else
        printf("Nie ma takiego slowa\n");
}

void dodaj_slowo(char *temp, Drzewo *wd)
{
    Pozycja tymcz;
    strcpy(tymcz.slowo, temp);
    //tymcz.powtorzenie = 1;
    if (PelneDrzewo(wd))
        puts("Brak wolnego miejsca");
    else if (WDrzewie(&tymcz, wd))
    {
        tymcz.powtorzenie = wd->korzen->pozycja.powtorzenie +1;
        //wd->korzen->pozycja.powtorzenie +=1;
        return;
    }
    else
    {
        tymcz.powtorzenie = 1;
        DodajPozycje(&tymcz, wd);
    }

}

char * wczytaj(char *z, int ile)
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
continue;
}
return wynik;
}
