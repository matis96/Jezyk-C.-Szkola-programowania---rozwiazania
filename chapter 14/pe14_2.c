//zad2.c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "zad2.h"
extern struct miesiac miesiace[];
int dni(int , char *, int );
int main(void)
{
    int suma;
    int rok, dzien;
    int numer_miesiac;
    char nazwa_miesiac[20];
    bool wybor_miesiac = false;
    printf("Podaj rok: ");
    scanf("%d", &rok);
    printf("Podaj miesiac: ");
    if (scanf("%d", &numer_miesiac))
    {
        strcpy(nazwa_miesiac, miesiace[numer_miesiac-1].nazwa);
        wybor_miesiac = true;
    }

    if (!wybor_miesiac)
        scanf("%s", nazwa_miesiac);
    for (int index = 0; index<12; index++)
        if (strcmp(nazwa_miesiac, miesiace[index].skrot)==0)
        {
            strcpy(nazwa_miesiac, miesiace[index].nazwa);
            break;
        }
    printf("Podaj dzien: ");
    scanf("%d", &dzien);
    suma = dni(rok, nazwa_miesiac, dzien);
    printf("Do %d, %d.%s minelo %d  dni", rok, dzien, nazwa_miesiac, suma);
    return 0;
}
int dni(int rok, char *nazwa_miesiac, int dzien)
{
    bool rok_przestepny = false;
    int index, suma, x=0;
    if (rok%4==0)
        rok_przestepny = true;
	for (index = 0; index<12; index++)
        if (strcmp(nazwa_miesiac, miesiace[index].nazwa)==0)
            x=index;
    for (index=0, suma =0; index<x; index++)
        suma += miesiace[index].dni;
    suma += dzien;
    if (rok_przestepny && index>1)
        suma +=1;
    return suma;
}
