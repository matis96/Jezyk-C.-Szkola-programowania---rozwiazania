//zad11.c
#include <stdio.h>
#define CENA_ARBUZ  1.25
#define CENA_BURAK  0.65
#define CENA_CEBULA 0.89
#define RABAT       0.05
#define PROG        100
#define WAGA1       5
#define WAGA2       20
#define PRZESYLKA1  3.50
#define PRZESYLKA2  10
#define PRZESYLKA3  8.10
int main(void)
{
    int arbuz, burak, cebula, waga, kg;
    float zamowienie, rabat, po_rabacie, przesylka;
    arbuz = burak = cebula = 0;
    char wybor;
    printf("A - arbuzy, B- buraki, C - cebula, K- end\n");
    while ((wybor = getchar()) != 'K')
    {
        switch (wybor)
        {
        case 'A':
            printf("Wprowadz liczbe kg: ");
            scanf("%d", &kg);
            arbuz += kg;
            break;
        case 'B':
            printf("Wprowadz liczbe kg: ");
            scanf("%d", &kg);
            burak += kg;
            break;
        case 'C':
            printf("Wprowadz liczbe kg: ");
            scanf("%d", &kg);
            cebula += kg;
            break;
        //case 'K':
            //break;
        //case '\n':
            //break;
        default:
            printf("\nWpisz A, B, C lub K by zakonczyc\n");
            //break;
        }
    }

    zamowienie = arbuz * CENA_ARBUZ + burak * CENA_BURAK + cebula * CENA_CEBULA;
    if (zamowienie> PROG)
        rabat = zamowienie - zamowienie * (1-rabat);
    po_rabacie = zamowienie - rabat;
    waga = arbuz + burak + cebula;
    if (waga<=WAGA1)
        przesylka = PRZESYLKA1;
    else if (waga<=WAGA2)
        przesylka =  PRZESYLKA2;
    else
        przesylka = PRZESYLKA3 * waga;

    printf("arbuz kosztuje %.2f zl za kg, burak %.2f zl, cebula %.2f zl\n", CENA_ARBUZ, CENA_BURAK, CENA_CEBULA);
    printf("Zamowiono %d arbuzow za %.2f zl, %d burakow za %.2f zl, %d cebuli za %.2f zl\n",
           arbuz, CENA_ARBUZ*arbuz, burak, CENA_BURAK*burak, cebula, CENA_CEBULA * cebula);
    printf("Wartosc zamowienia to %.2f zl, rabat wynosi %.2f zl, a przesylka %.2f zl\n", zamowienie, rabat, przesylka);
    printf("Calosc zamowienia wynosi %.2f", zamowienie-rabat + przesylka);
    return 0;
}
