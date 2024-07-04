//zad7.c
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define LEWO    0
#define SRODEK  1
#define PRAWO   2

#define MASKA_TYP       0xFF
#define MASKA_ROZM      0xFF00
#define MASKA_WYR       0x30000
#define WYR_L           0x00000
#define WYR_S           0x10000
#define WYR_P           0x20000
#define BOLD            0x40000
#define ITALIC          0x80000
#define UNDERLINE       0x100000


struct wl_czcionki {
    unsigned int    typ        : 8;
    unsigned int    rozmiar    : 7;
    unsigned int               : 1;
    unsigned int    wyrownanie : 2;
    bool            bold       : 1;
    bool            italic     : 1;
    bool            underline  : 1;
};
void wyswietl(const unsigned long);
void zmien_wyr(void);
char pokaz_menu(void);
void usunwiersz(void);
unsigned long czcionki;
int main(void)
{
    char wybor;
    int czc_typ, czc_rozmiar;
    czcionki &= ~MASKA_TYP;
    czcionki |= 0;
    czcionki &= ~MASKA_ROZM;
    czcionki |= (0<<8);
    czcionki &= ~MASKA_WYR;
    czcionki |= WYR_L;
    czcionki ^= BOLD;
    czcionki ^= ITALIC;
    wyswietl(czcionki);
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
            czcionki &= ~MASKA_TYP;
            czcionki |= czc_typ;
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
            czcionki &= ~MASKA_ROZM;
            czcionki |= (czc_rozmiar<<8);
            break;
        case 'w': zmien_wyr(); break;
        case 'b': czcionki ^= BOLD; break;
        case 'i': czcionki ^= ITALIC; break;
        case 'u': czcionki ^=UNDERLINE ; break;
        }
        wyswietl(czcionki);
    }
    return 0;
}
void wyswietl(const unsigned long ul)
{
    printf("Typ Rozmiar        Wyrownanie      Wytl.   Kurs.   Podkr.\n");
    printf("%-3d %-3d          ", ul & 255, (ul>>8)&127);
    switch(ul & MASKA_WYR)
    {
        case WYR_L   : printf("  lewo        "); break;
        case WYR_S : printf("  srodek      "); break;
        case WYR_P  : printf("  prawo       "); break;
    }
    printf("    %-8s%-8s%-5s\n",
           (ul & BOLD)==BOLD?"wl":"wyl", (ul & ITALIC) == ITALIC?"wl":"wyl",
           (ul & UNDERLINE) == UNDERLINE?"wl":"wyl" );
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
void zmien_wyr(void)
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
    czcionki &= ~MASKA_WYR;
    switch (typ)
    {
        //czcionki &= ~MASKA_WYR;
        case 0: czcionki |= WYR_L; break;
        case 1: czcionki |= WYR_S; break;
        case 2: czcionki |= WYR_P; break;
    }
}

void usunwiersz(void)
{
    while (getchar()!='\n')
        continue;
}

