/* wielrzut.c -- wielokrotny rzut koscmi */
/* kompilowac z rzutkosc.c */
#include <stdio.h>
#include <stdlib.h> /* potrzeba funkcji srand() */
#include <time.h> /* potrzeba funkcji time() */
#include "rzutkosc.h" /* potrzeba funkcji rzucaj_n_razy() */
/* i zmiennej liczba_rzutow */
int main(void)
{
    int rzuty, wynik, kolejki, kostki;
    int scianki, status;
    int k;
    srand((unsigned int) time(0)); /* losowe ziarno */
    //printf("Podaj liczbe scianek, 0 oznacza koniec.\n");
    printf("Podaj liczbe kolejek, k oznacza koniec\n"); //dodane
    //while (scanf("%d", &scianki) == 1 && scianki > 0)
    while (scanf("%d", &kolejki)==1 && kolejki>0) //dodane
    {
        //printf("Ile rzutow?\n");
        printf("Podaj liczbe scianek i liczbe kostek.\n");
        //if ((status = scanf("%d", &rzuty)) != 1)
        if ((status = scanf("%d %d", &scianki, &kostki)) != 2) //dodane
        {
            if (status == EOF)
            break; /* przerwanie petli */
            else
            {
                printf("Nalezy podac liczbe calkowita.");
                printf(" Sprobujmy jeszcze raz.\n");
                while (getchar() != '\n')
                    continue; /* odrzucenie niepoprawnego wejscia */
                //printf("Ile scianek? 0 oznacza koniec.\n");
                printf("Ile scianek? 0 oznacza koniec.\n"); //dodane
                continue; /* nowy przebieg petli*/
            }
        }
        //wynik = rzucaj_n_razy(rzuty, scianki);
        //printf("Wyrzucono razem %d uzywajac %d %d-sciennych kosci.\n",
        //wynik, rzuty, scianki);
        printf("Oto %d kolejek %d %d-sciennych rzutow.\n", kolejki, kostki, scianki); //dodane
        for (k=0; k<kolejki; k++) //dodane
        {
            wynik = rzucaj_n_razy(1, kostki*scianki);
            if (wynik<kostki)
                k--;
            else
                printf("%d ", wynik);
        }
        printf("\n");//dodane
        //printf("Podaj liczbe scianek, 0 oznacza koniec.\n");
        printf("Podaj liczbe kolejek, k oznacza koniec.\n");
    }
    //printf("Funkcja rzucaj() zostala wywolana %d razy.\n",
    //liczba_rzutow); /* zmienna zewnetrzna */
    printf("ZYCZE DUZO SZCZESCIA!\n");
    return 0;
}
