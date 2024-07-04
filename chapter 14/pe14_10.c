//zad10.c
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
#define NR 12
char menu(int );
char menu2(void);
void usunwiersz(void);
char *wczytaj(char *z, int ile);
typedef struct samolot{
    int miejsce;
    bool miejsce_zajete;
    bool rezerwacja;
    char imie[MAX];
    char nazwisko[MAX];
} SAMOLOT;
SAMOLOT miejsca[4][NR];
void liczba_miejsc(int );
void lista_miejsc(int );
void lista_alfabetyczna(int );
void klient(int );
void usun_miejsce(int );
void strlan(SAMOLOT *sortowany[], int num);
void wybierz_opcje(void (* fp)(int ), int);

int main(void)
{
    int i,j;
    char rejs;
    char wybor;
    int nr_rejs;
    FILE *wp;
    int rozmiar = sizeof(miejsca);
    void (*wfun)(int );
    for (j=0; j<4; j++)
        for (i=0; i<NR; i++)
        {
            miejsca[j][i].miejsce = i+1;
            miejsca[j][i].miejsce_zajete = false;
            miejsca[j][i].rezerwacja = false;
        //strcpy(miejsca[i].imie,"");
        //strcpy(miejsca[i].nazwisko,"");
        }
        if ((wp=fopen("miejsca3.dat", "rb"))==NULL)
    {
        fprintf(stderr, "Blad otwarcia pliku\n");
    }
    fread(miejsca, rozmiar, 1, wp);
    fclose(wp);
    while ((rejs = menu2())!='e')
    {
        switch (rejs)
        {
        case 'a':
            nr_rejs = 0;
            break;
        case 'b':
            nr_rejs = 1;
            break;
        case 'c':
            nr_rejs = 2;
            break;
        case 'd':
            nr_rejs = 3;
            break;
        }
        while ((wybor = menu(nr_rejs))!='f')
        {
            switch(wybor)
            {
            case 'a':
                wfun = liczba_miejsc;
                break;
            case 'b':
                wfun = lista_miejsc;
                break;
            case 'c':
                wfun = lista_alfabetyczna;
                break;
            case 'd':
                wfun = klient;
                break;
            case 'e':
                wfun = usun_miejsce;
                break;
            }
            wybierz_opcje(wfun, nr_rejs);
        }

    }
    if ((wp=fopen("miejsca3.dat", "wb"))==NULL)
        fprintf(stderr, "Blad zapisu\n");
    fwrite(miejsca, rozmiar, 1, wp);
    fclose(wp);
    return 0;
}

void wybierz_opcje(void (*fw)(int ), int n)
{
    (*fw)(n);
}
char menu(int n)
{
    char odp;
    int numer_rejsu[4]={102, 311, 444, 519};
    printf("Witaj na pokladzie linii nr %d\n", numer_rejsu[n]);
    puts("Aby wybrac opcje, wpisz jej oznaczenie literowe");
    puts("a) Pokaz liczbe pustych miejsc");
    puts("b) Pokaz liste pustych miejsc");
    puts("c) Pokaz alfabetyczna liste miejsc");
    puts("d) Zarezerwuj miejsce dla klienta");
    puts("e) Usun rezerwacje miejsca");
    puts("f) Powrot do poprzedniego menu");
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
char menu2(void)
{
    char odp;
    puts("Witamy w linii Colossus!");
    puts("Wybierz jeden z dostepnych rejsow");
    puts("a)102     b)311");
    puts("c)444     d)519");
    puts("e)koniec");
    odp = getchar();
    odp = tolower(odp);
    usunwiersz();
    while (strchr("abcde", odp) == NULL)
    {
        puts("Wpisz a, b, c, d lub e:");
        odp = tolower(getchar());
        usunwiersz();
    }
    return odp;
}
void liczba_miejsc(int n)
{
    int licznik = 0;
    int i=0;
    for (i; i<NR; i++)
        if (!miejsca[n][i].miejsce_zajete)
            licznik++;
    printf("Liczba wolnych miejsc: %d\n", licznik);
}
void lista_miejsc(int n)
{
    int i=0;
    puts("Lista pustych miejsc: ");
    for (i; i<NR; i++)
        if (!miejsca[n][i].miejsce_zajete)
            printf("%d ", miejsca[n][i].miejsce);
    puts("");
}
void lista_alfabetyczna(int n)
{
    //char *wsklan_naz[NR];
    //char *wsklan_imie[NR];
    SAMOLOT *ps[NR];
    int licz=0;
    int i;
    int k;
    for (i=0; i<NR; i++)
    {
        ps[i]=&miejsca[n][i];
        licz++;
    }
    strlan(ps, licz);
    for (k=0; k<licz; k++)
        if (ps[k]->miejsce_zajete)
            printf("%d %s %s, STATUS REZERWACJI: %s\n", ps[k]->miejsce, ps[k]->nazwisko, ps[k]->imie,
                    ps[k]->rezerwacja?"POTWIERDZONY":"NIEPOTWIERDZONY");
}
void klient(int n)
{
    int nr;
    char odp;
    puts("Podaj nr miejsca (1-12) ");
    //while (scanf("%d", nr)==1 || (nr<1 || nr >12))
        //puts("Podaj nr 1-12");
    proba: while (scanf("%d", &nr)!=1 || (nr<1 || nr >12))
        {puts("Podaj nr 1-12");
        usunwiersz();}
    //while (scanf("%d", &nr))
    if (miejsca[n][nr-1].miejsce_zajete)
    {
        puts("To miejsce jest zajete!");
        puts("Podaj nr miejsca (1-12) ");
            //continue;
        goto proba;
    }
    else
    {
        puts("Podaj swoje imie: ");
        //wczytaj(miejsca[nr-1].imie, MAX);
        scanf("%s", miejsca[n][nr-1].imie);
        usunwiersz();
        puts("Podaj swoje nazwisko: ");
        //wczytaj(miejsca[nr-1].nazwisko, MAX);
        scanf("%s", miejsca[n][nr-1].nazwisko);
        usunwiersz();
        miejsca[n][nr-1].miejsce_zajete = true;
        puts("Czy potwierdzasz rezerwacje? [T\\N]");
        odp = getchar();
        odp = tolower(odp);
        usunwiersz();
        while (strchr("tn", odp) == NULL)
        {
            puts("Wpisz '[T]ak' lub '[N]ie'");
            odp = tolower(getchar());
            usunwiersz();
        }
        if (odp == 't')
            miejsca[n][nr-1].rezerwacja = true;
        //break;
    }
    //printf("Twoje imie to %s\n", miejsca[nr-1].imie);
    //printf("Twoje nazwisko to %s\n", miejsca[nr-1].nazwisko);

}
void usun_miejsce(int n)
{
    int nr;
    puts("Podaj nr miejsca do usuniecia:");
    proba: while (scanf("%d", &nr)!=1 || (nr<1 || nr >12))
        puts("Podaj nr 1-12");
    if (!miejsca[n][nr-1].miejsce_zajete)
    {
        puts("To miejsce jest wolne!");
        goto proba;
    }
    else
    {
        usunwiersz();
        miejsca[n][nr-1].miejsce_zajete=false;
        strcpy(miejsca[n][nr-1].imie, "");
        strcpy(miejsca[n][nr-1].nazwisko, "");
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
