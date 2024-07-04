/* lista.c -- funkcje realizujaca operacje na liscie */
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
/* funkcje lokalne */
//static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel);
/* funkcje interfejsu */
/* inicjalizuje liste jako pusta */
void InicjujListe(Lista * wlista)
{
    wlista->pozycje = 0;
}
/* zwraca prawde, jesli lista jest pusta */
bool PustaLista(const Lista * wlista)
{
if (wlista->pozycje == 0)
return true;
else
return false;
}
/* zwraca prawde, jesli lista jest pelna */
bool PelnaLista(const Lista * wlista)
{
    if (wlista->pozycje == MAXROZM)
        return true;
    else
        return false;
}
/* zwraca liczbe wezlow */
unsigned int LiczbaPozycji(const Lista * wlista)
{
    return wlista->pozycje;
}
/* tworzy wezel przechowujacy pozycje i dodaje go na koncu */
/* listy wskazywanej przez wlista (wolna implementacja) */
bool DodajPozycje(Pozycja pozycja, Lista * wlista)
{
    //Wezel * wnowy;
    //Wezel * szuk = *wlista;
    //wnowy = (Wezel *) malloc(sizeof(Wezel));
    if (wlista->pozycje == MAXROZM)
        return false; /* konczy funkcje w razie niepowodzenia */
//    KopiujDoWezla(pozycja, wnowy);
//    wnowy->nast = NULL;
//    if (szuk == NULL) /* lista jest pusta, wnowy nalezy */
//    * wlista = wnowy; /* wiec umiescic na jej poczatku */
    else
//    {
//    while (szuk->nast != NULL)
//    szuk = szuk->nast; /* znajduje koniec listy */
//    szuk->nast = wnowy; /* dodaje wnowy na koncu */
//    }
    wlista->wpisy[wlista->pozycje++] = pozycja;

    return true;
}
/* "odwiedza" kazdy wezel i wykonuje funkcje wskazywana przez wfun */
void Przejdz (const Lista * wlista, void (* wfun)(Pozycja pozycja) )
{
    int i;
    for (i=0; i<wlista->pozycje; i++)
        (*wfun)(wlista->wpisy[i]);

//    Wezel * wsk = *wlista; /* od poczatku listy */
//    while (wsk != NULL)
//    {
//    (*wfun)(wsk->pozycja); /* stosuje funkcje do pozycji */
//    wsk = wsk->nast; /* przechodzi do nastepnego wezla */
//    }
}
/* zwalnia pamiec przydzielona przez malloc() i ustawia wskaznik na NULL
*/
void CzyscListe(Lista * wlista)
{
    wlista->pozycje=0;
    //int i;
    //for (i=0; i<wlista->pozycje; i++)
        //free((wlista->wpisy++));
//Wezel * wsk;
//while (*wlista != NULL)
//{
//wsk = (*wlista)->nast; // zapisuje adres wezla
//free(*wlista); // zwalnia wezel
//*wlista = wsk; // przechodzi do nastepnego wezla
//}
}
/* definicja funkcji lokalnej */
/* kopiuje element do wezla */
/*static void KopiujDoWezla(Pozycja pozycja, Wezel * wwezel)
{
wwezel->pozycja = pozycja;
}*/

