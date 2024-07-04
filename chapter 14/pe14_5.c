//zad5.c
#include <stdio.h>
#include "zad5.h"
#define ROZMIAR 4
int wczytaj_oceny(struct student *);
void srednia(struct student *, int );
void wyswietl(struct student *, int *, int );
void srednia_wszystkich(struct student *, int);
int main(void)
{
    int i;
    int liczba_ocen[ROZMIAR];
    struct student dane[ROZMIAR] =
    {
        {{"Janek", "Kowalski"}},
        {{"Zuzanna", "Kurczak"}},
        {{"Bartosz", "Dlugopolski"}},
        {{"Pawel", "Wozniak"}}
    };
    //struct student *pstudenci[ROZMIAR]
    for (i=0; i<ROZMIAR; i++)
    {
        liczba_ocen[i] = wczytaj_oceny(&dane[i]);
        srednia(&dane[i], liczba_ocen[i]);
    }
    wyswietl(dane, liczba_ocen, ROZMIAR);
    srednia_wszystkich(dane, ROZMIAR);
    return 0;

}
int wczytaj_oceny(struct student *ocena)
{
    int licznik=0;
    printf("Podaj ocene dla %s. Ocena -1 konczy zadanie.\n", ocena->person.nazwisko);
    while (scanf("%f", &ocena->oceny[licznik]) == 1 && ocena->oceny[licznik] != -1 && licznik<10)
    {
        //printf("\n%.2f", ocena->oceny[licznik]);
        //while(getchar() != '\n')
            //continue;
        licznik++;
        puts("Podaj kolejna ocene: ");
    }
    return licznik;
}

void srednia(struct student *ocena, int liczba_ocen)
{
    int i;
    float suma=0;
    for (i=0; i<liczba_ocen; i++)
    {
        suma += ocena->oceny[i];
    }
    (*ocena).srednia = suma/((float) liczba_ocen);
}

void wyswietl(struct student osoba[], int ilosc_ocen[], int n)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        printf("%s %s ma nastepujace oceny: ", osoba[i].person.imie, osoba[i].person.nazwisko);
        for (j=0; j<ilosc_ocen[i]; j++)
            printf("%.2f ", osoba[i].oceny[j]);
        printf("\ni srednia %.2f\n", osoba[i].srednia);
    }
}

void srednia_wszystkich(struct student studenci[], int n)
{
    float srednia_sum=0;
    int i;
    for (i=0; i<n; i++)
        srednia_sum +=studenci[i].srednia;
    printf("Srednia ocen wszystkich studentow to %.2f", srednia_sum/n);
}
