#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "drzewo_zw.h"
char menu(void);
void dodajzw(Tree * ptree);
void usunzw(Tree * ptree);
void pokazzw(const Tree * ptree);
void szukajzw(Tree * ptree);
void wyswpoz(Pet pet);
void duzelit(char * lan);
char * wczytaj(char *z, int ile);
int main (void)
{
    Tree zwierz;
    char wybor;
    InitializeTree(&zwierz);
    while ((wybor = menu()) != 'q')
    {
        switch (wybor)
        {
            case 'd' : dodajzw(&zwierz);
            break;
            case 'w' : pokazzw(&zwierz);
            break;
            case 's' : szukajzw(&zwierz);
            break;
            case 'l' : printf("%d zwierzat w klubie.\n",
            LiczbaPozycji(zwierz));
            break;
            case 'u' : usunzw(&zwierz);
            break;
            default : puts("Blad w instrukcji switch");
        }
    }
    UsunWszystko(&zwierz);
    puts("Do widzenia.");
    return 0;
}

char menu(void)
{
    int ch;
    puts("Klub Zwierzat Domowych - baza danych czlonkow");
    puts("Podaj litere odpowiadajaca wybranej opcji:");
    puts("d) dodaj zwierze w) wyswietl liste zwierzat");
    puts("l) liczba zwierzat s) szukaj zwierzecia");
    puts("u) usun zwierze q) koniec");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') /* porzuca reszte wiersza */
            continue;
        ch = tolower(ch);
        if (strchr("dwlsuq",ch) == NULL)
            puts("Wpisz d, w, l, s, u lub q:");
        else
            break;
    }
    if (ch == EOF) /* sprawia, ze EOF konczy program */
        ch = 'q';
    return ch;
}

void dodajzw(Tree * wd)
{
    Pet *tymcz = (Pet*)malloc(sizeof(Pet));
    if (PelneDrzewo(wd))
        puts("Brak wolnych miejsc w klubie!");
    else
    {
        puts("Podaj imie zwierzecia:");
        wczytaj(tymcz->name, MAX);
        puts("Podaj gatunek zwierzecia:");
        wczytaj(tymcz->type, MAX);
        duzelit(tymcz->name);
        duzelit(tymcz->type);
        tymcz->next=NULL;
        AddPet(tymcz, wd);
    }
}
void pokazzw(const Tree * wd)
{
    if (PusteDrzewo(wd))
        puts("Brak pozycji!");
    else
        Przejdz(wd, wyswpoz);
}

void wyswpoz(Pet pet)
{
printf("Zwierze: %-19s Gatunek: %-19s\n", pet.name, pet.type);
}

void szukajzw(Tree * wd)
{
    Pet tymcz;
    if (PusteDrzewo(wd))
    {
        puts("Brak pozycji!");
        return; /* wychodzi z funkcji, jesli drzewo jest puste */
    }
    puts("Podaj imie zwierzecia, ktore chcesz znalezc:");
    wczytaj(tymcz.name, MAX);
    //puts("Podaj gatunek zwierzecia:");
    //wczytaj(tymcz.type, MAX);
    duzelit(tymcz.name);
    //duzelit(tymcz.type);
    /*printf("%s, %s ", tymcz.name, tymcz.type);
    if (WDrzewie(&tymcz, wd))
    {
        printf("jest czlonkiem klubu.\n");
    }
    else
        printf("nie jest czlonkiem klubu.\n");*/
    if (ImieWDrzewe(&tymcz, wd))
        ApplyToNode(&tymcz, wd, wyswpoz);
    else
        printf("Nie ma zwierzaka o podanym imieniu\n");
}

void usunzw(Tree * wd)
{
    Pet tymcz;
    if (PusteDrzewo(wd))
    {
        puts("Brak pozycji!");
        return; /* wychodzi z funkcji, jesli drzewo jest puste */
    }
    puts("Podaj imie zwierzecia, ktore chcesz usunac:");
    wczytaj(tymcz.name, MAX);
    puts("Podaj gatunek zwierzecia:");
    wczytaj(tymcz.type, MAX);
    duzelit(tymcz.name);
    duzelit(tymcz.type);
    printf("%s, %s ", tymcz.name, tymcz.type);
    if (DeletePet(&tymcz, wd))
        printf("zostal(a) usuniety/a z klubu.\n");
    else
        printf("nie jest czlonkiem klubu.\n");
}
void duzelit(char * lan)
{
while (*lan != '\0')
{
*lan = toupper(*lan);
lan++;
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
