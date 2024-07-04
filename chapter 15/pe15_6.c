//zad6.c
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
//wyrownanie
#define LEWO    0
#define SRODEK  1
#define PRAWO   2

struct wl_czcionki {
    unsigned int    typ        : 8;
    unsigned int    rozmiar    : 7;
    unsigned int    wyrownanie : 2;
    bool            bold       : 1;
    bool            italic     : 1;
    bool            underline  : 1;
};

void pokaz_ustawienia(const struct wl_czcionki * );
char pokaz_menu(void);
void usunwiersz(void);
void zmien_wyr(struct wl_czcionki *);
int main(void)
{
    char wybor;
    int czc_typ;
    int czc_rozmiar;
    struct wl_czcionki czcionka = {0, 34, PRAWO, false, true, false};
    pokaz_ustawienia(&czcionka);
    while ((wybor=pokaz_menu())!='k')
    {
        switch (wybor)
        {
        case 't':
            printf("Podaj typ czcionki (0-255): ");
            //scanf("%d", &czc_typ);
            while ((scanf("%d", &czc_typ)!=1) || (czc_typ<0 || czc_typ >255))
            {
                puts("Wpisz liczbe z przedzialu 0-255");
                usunwiersz();
            }

            usunwiersz();
            czcionka.typ &= 0;
            czcionka.typ |= czc_typ;
            break;
        case 'r':
            printf("Podaj rozmiar czcionki (0-127): ");
            //scanf("%d", &czc_rozmiar);
            while ((scanf("%d", &czc_rozmiar)!=1) || (czc_rozmiar<0 || czc_rozmiar >127))
            {
                puts("Wpisz liczbe z przedzialu 0-127");
                usunwiersz();
            }
            usunwiersz();
            czcionka.rozmiar &=0;
            czcionka.rozmiar |= czc_rozmiar;
            break;
        case 'w': zmien_wyr(&czcionka); break;
        case 'b': czcionka.bold ^= 1; break;
        case 'i': czcionka.italic ^= 1; break;
        case 'u': czcionka.underline ^=1 ; break;
        }
        pokaz_ustawienia(&czcionka);
    }
    return 0;
}

void pokaz_ustawienia(const struct wl_czcionki *czcionka)
{
    printf("Typ Rozmiar        Wyrownanie      Wytl.   Kurs.   Podkr.\n");
    //printf("%3s %7s\n", "Typ", "Rozmiar");
    printf("%-3d %-3d          ", czcionka->typ, czcionka->rozmiar);
    switch(czcionka->wyrownanie)
    {
        case LEWO   : printf("  lewo        "); break;
        case SRODEK : printf("  srodek      "); break;
        case PRAWO  : printf("  prawo       "); break;
    }
    printf("    %-8s%-8s%-5s\n", czcionka->bold?"wl":"wyl", czcionka->italic?"wl":"wyl", czcionka->underline?"wl":"wyl" );
}
char pokaz_menu(void)
{
    char odp;
    printf("t) zmiana czcionki r) zmiana rozmiaru      w) zmiana wyrownania\n" );
    printf("b) przelacz wytluszczenie   i) przelacz kursywe\n"  );
    printf("u) przelacz podkreslenie\n");
    printf("k) wyjscie\n");
    odp = getchar();
    usunwiersz();
    odp = tolower(odp);
    while (strchr("trwbiuk", odp) == NULL)
    {
        puts("Wpisz t, r, w, b, i, u lub k:");
        odp = tolower(getchar());
        usunwiersz();
    }
    return odp;
}
void zmien_wyr(struct wl_czcionki *czcionka)
{
    int typ;
    printf("Jaki typ wyrownania?\n");
    printf("0 - w lewo, 1 - do srodka, 2 - w prawo\n");
    while ((scanf("%d", &typ)!=1) || (typ<0 || typ >2))
    {
        puts("Wpisz 0, 1 lub 2");
        usunwiersz();
    }

    usunwiersz();
    switch (typ)
    {
        case 0: czcionka->wyrownanie = LEWO; break;
        case 1: czcionka->wyrownanie = SRODEK; break;
        case 2: czcionka->wyrownanie = PRAWO; break;
    }
}

void usunwiersz(void)
{
    while (getchar()!='\n')
        continue;
}
