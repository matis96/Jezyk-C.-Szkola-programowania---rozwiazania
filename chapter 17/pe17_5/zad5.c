#include <stdio.h>
#include "stos.h"
#include <string.h>
char * wczytaj(char *z, int ile);

int main(void)
{
    printf("Podaj lancuch do odwrocenia. Enter aby zakonczyc\n");
    Stos slowa;
    Pozycja ch;
    char temp[MAXSTOS];
    //Pozycja *x;
    InicjujStos(&slowa);
    int i =0;
    while (wczytaj(temp, MAXSTOS)!=NULL && temp[0]!='\0')
    {
        while (temp[i]!='\0')
            Poloz(temp[i++], &slowa);
        i=0;
        while (Zdejmij(&ch, &slowa))
            putchar(ch);
        printf("\nPodaj lancuch do odwrocenia. Pusty wiersz aby zakonczyc\n");
    }
    return 0;
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
