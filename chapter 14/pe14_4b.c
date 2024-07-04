//zad4b.c
//zad4a.c
#include <stdio.h>
#define MAX 20
#define TAB 3

struct dane_os {
    char imie[MAX];
    char imie2[MAX];
    char nazwisko[MAX];
};
struct osoba{
    long long int PESEL;
    struct dane_os nazwa;
};
void wyswietl(struct osoba osoby);
int main(void)
{
    int i;
    struct osoba osoby[TAB] ={
	    {87010567839, "Janek", "Kamil", "Kowalski"}},
            {65092301159, {"Michael", "Junior", "Jordan"}},
            {64890127923, {"Pawel", "", "Kazmierczak"}}
        };
    for (i=0; i<TAB; i++)
        wyswietl(osoby[i]);
    return 0;
}

void wyswietl(struct osoba osoby)
{
        printf("%s, %s ", osoby.nazwa.nazwisko, osoby.nazwa.imie);
        if (osoby.nazwa.imie2[0] != '\0')
            printf("%c. ", osoby.nazwa.imie2[0]);
        printf("-- %lld\n", osoby.PESEL);
}
