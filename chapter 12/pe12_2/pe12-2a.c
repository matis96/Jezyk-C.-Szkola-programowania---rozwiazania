#include <stdio.h>
#include "pe12-2a.h"
static int tryb;
static float dystans;
static float paliwo;

void wybierz_tryb(int wybor)
{
    if (wybor==0)
        tryb=0;
    else if (wybor==1)
        tryb=1;
    else
        printf("Podano nieprawidlowa wartosc. Wybrano system %s.\n", tryb?"1(US)":"0(metryczny)");
}

void pobierz_dane(void)
{
    if (tryb==0)
    {
        printf("Wprowadz przebyta odleglosc w kilometrach: ");
        scanf("%f", &dystans);
        printf("Wprowadz zuzyte paliwo w litrach: ");
        scanf("%f", &paliwo);
    }
    if (tryb==1)
    {
        printf("Wprowadz przebyta odleglosc w milach: ");
        scanf("%f", &dystans);
        printf("Wprowadz zuzyte paliwo w galonach: ");
        scanf("%f", &paliwo);
    }
}

void wyswietl_dane(void)
{
    if (tryb==0)
        printf("Zuzycie paliwa wynioslo %.2f litrow na 100 km.\n", (paliwo/dystans)*100.0);
    if (tryb==1)
        printf("Zuzycie paliwa wynioslo %.1f mil na galon.\n", dystans/paliwo);
}
