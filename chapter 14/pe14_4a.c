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
void wyswietl(struct osoba osoby[], int n);
int main(void)
{
    struct osoba osoby[TAB] ={
	    {87010567839, "Janek", "Kamil", "Kowalski"}},
            {65092301159, {"Michael", "Junior", "Jordan"}},
            {64890127923, {"Pawel", "", "Kazmierczak"}}
        };
    wyswietl(osoby, TAB);
    return 0;
}

void wyswietl(struct osoba osoby[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%s, %s ", osoby[i].nazwa.nazwisko, osoby[i].nazwa.imie);
        if (osoby[i].nazwa.imie2[0] != '\0')
            printf("%c. ", osoby[i].nazwa.imie2[0]);
        printf("-- %lld\n", osoby[i].PESEL);
    }
}
