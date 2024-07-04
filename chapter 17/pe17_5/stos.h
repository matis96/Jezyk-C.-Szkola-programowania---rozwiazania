/* stos.h -- interfejs stosu */
#include <stdbool.h>
/* TUTAJ WSTAW DEFINICJE TYPU POZYCJA */
/* NA PRZYKLAD, typedef int Pozycja */
typedef int Pozycja;
#define MAXSTOS 100
typedef struct stos
{
Pozycja pozycje[MAXSTOS]; /* przechowuje informacje */
int gora; /* indeks pierwszego wolnego miejsca */
} Stos;
/* dzialanie: inicjalizuje stos */
/* warunek wstepny: ws wskazuje na stos */
/* warunek koncowy: stos zostaje zainicjalizowany jako pusty */
void InicjujStos(Stos * ws);
/* dzialanie: sprawdza, czy stos jest pelny */
/* warunek wstepny: ws wskazuje na wczesniej zainicjowany stos */
/* warunek koncowy: zwraca true, jesli stos jest pelny, */
/* w przeciwnym wypadku - false */
bool PelnyStos(const Stos * ws);
/* dzialanie: sprawdza, czy stos jest pusty */
/* warunek wstepny: ws wskazuje na wczesniej zainicjowany stos */
/* warunek koncowy: zwraca true, jesli stos jest pusty, */
/* w przeciwnym wypadku - false */
bool PustyStos(const Stos * ws);
/* dzialanie: kladzie pozycje na stosie */
/* warunek wstepny: ws wskazuje na wczesniej zainicjowany stos */
/* warunek koncowy: jesli stos nie jest pusty, pozycja zostaje */
/* umieszczona na stosie, a funkcja zwraca true; */
/* w przeciwnym wypadku stos pozostaje */
/* niezmieniony, a funkcja zwraca false */
bool Poloz(Pozycja pozycja, Stos * ws);
/* dzialanie: zdejmuje pozycje ze stosu */
/* warunek wstepny: ws wskazuje na wczesniej zainicjowany stos */
/* warunek koncowy: jesli stos nie jest pusty, pozycja z gory */
/* stosu zostaje skopiowana do *wpozycja */
/* i usunieta ze stosu, a funkcja zwraca true. */
/* Jesli usunieto ostatnia pozycje, stos jest */
/* zerowany (inicjowany). Jesli stos byl pusty */
/* juz wczesniej, pozostaje on bez zmian, a */
/* funkcja zwraca false. */
bool Zdejmij(Pozycja *wpozycja, Stos * ws);
