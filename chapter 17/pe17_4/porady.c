// porady.c -- korzysta z interfejsu "kolejka"
// kompilowac lacznie z kolejka.c
#include <stdio.h>
#include <stdlib.h> // dla funkcji rand() and srand()
#include <time.h> // dla funkcji time()
#include "kolejka.h"
#define MIN_W_GODZ 60.0
bool nowyklient(double x); // czy jest nowy klient?
Pozycja czasklienta(long kiedy); // ustawia parametry klienta
int main(void)
{
    Kolejka kol1, kol2;
    Pozycja tymcz; // dane o nowym kliencie
    int godz; // liczba godzin symulacji
    int nagodz; // srednia liczba nowych klientow na godz.
    long cykl, gran_cyklu; // licznik petli, granica
    long kol_czek1 = 0;
    long odeslani1 = 0; // klienci odeslani z braku miejsca
    long klienci1 = 0; // klienci, ktorzy weszli do kolejki
    long obsluzeni1 = 0; // obsluzeni w czasie symulacji
    long suma_kol1 = 0; // kumulatywna dlugosc kolejki
    int czas_czek = 0; // czas do obsluzenia nastepnego klienta
    double min_na_k; // sredni czas miedzy przybylymi klientami

    //2 kolejka
    long kol_czek2 = 0; // kumulatywny czas stania w kolejce
    long odeslani2 = 0; // klienci odeslani z braku miejsca
    long klienci2 = 0; // klienci, ktorzy weszli do kolejki
    long obsluzeni2 = 0; // obsluzeni w czasie symulacji
    long suma_kol2 = 0; // kumulatywna dlugosc kolejki


    InicjujKolejke(&kol1);
    InicjujKolejke(&kol2);
    srand((unsigned int)time(0)); // losowa inicjalizacja funkcji rand()
    puts("Studium przypadku: Punkt porad Zygmunta Prywaciarza");
    puts("Podaj liczbe godzin symulacji:");
    scanf("%d", &godz);
    gran_cyklu = MIN_W_GODZ * godz;
    puts("Podaj srednia liczbe klientow w ciagu godziny:");
    scanf("%d", &nagodz);
    min_na_k = MIN_W_GODZ / nagodz;
    //pierwsze okienko
    for (cykl = 0; cykl < gran_cyklu; cykl++)
    {
        if (nowyklient(min_na_k))
        {
        if (PelnaKolejka(&kol1))
            odeslani1++;
        else
        {
            klienci1++;
            tymcz = czasklienta(cykl);
            Ustaw(tymcz, &kol1);
        }
        }
        if (czas_czek <= 0 && !PustaKolejka(&kol1))
        {
            Odlacz (&tymcz, &kol1);
            czas_czek = tymcz.czaskons;
            kol_czek1 += cykl - tymcz.przybycie;
            obsluzeni1++;
        }
        if (czas_czek > 0)
            czas_czek--;
        suma_kol1 += LiczbaPozycji(&kol1);
    }
    //drugie okienko
    czas_czek = 0;
    for (cykl = 0; cykl < gran_cyklu; cykl++)
    {
        if (nowyklient(min_na_k))
        {
        if (PelnaKolejka(&kol2))
            odeslani2++;
        else
        {
            klienci2++;
            tymcz = czasklienta(cykl);
            Ustaw(tymcz, &kol2);
        }
        }
        if (czas_czek <= 0 && !PustaKolejka(&kol2))
        {
            Odlacz (&tymcz, &kol2);
            czas_czek = tymcz.czaskons;
            kol_czek2 += cykl - tymcz.przybycie;
            obsluzeni2++;
        }
        if (czas_czek > 0)
            czas_czek--;
        suma_kol2 += LiczbaPozycji(&kol2);
    }
    //okienko 1
    if (klienci1 > 0)
    {
        printf("klienci przyjeci do pierwszego okienka: %ld\n", klienci1);
        printf(" klienci obsluzeni: %ld\n", obsluzeni1);
        printf(" klienci odeslani: %ld\n", odeslani1);
        printf(" srednia dlugosc kolejki: %.2f\n",
        (double) suma_kol1 / gran_cyklu);
        printf(" sredni czas oczekiwania: %.2f minut\n",
        (double) kol_czek1 / obsluzeni1);
    }
    else
        puts("Brak klientow w oknie 1!");
    //okienko 2
    puts("");
    if (klienci2 > 0)
    {
        printf("klienci przyjeci do drugiego okienka: %ld\n", klienci2);
        printf(" klienci obsluzeni: %ld\n", obsluzeni2);
        printf(" klienci odeslani: %ld\n", odeslani2);
        printf(" srednia dlugosc kolejki: %.2f\n",
        (double) suma_kol2 / gran_cyklu);
        printf(" sredni czas oczekiwania: %.2f minut\n",
        (double) kol_czek2 / obsluzeni2);
    }
    else
        puts("Brak klientow w oknie 1!");
    //suma kolejek
    puts("");
    if (klienci1 + klienci2 > 0)
    {
        printf("klienci przyjeci do dwoch okienek: %ld\n", klienci1+klienci2);
        printf(" klienci obsluzeni: %ld\n", obsluzeni1+obsluzeni2);
        printf(" klienci odeslani: %ld\n", odeslani1+odeslani2);
        printf(" srednia dlugosc kolejki: %.2f\n",
               ((double)suma_kol1/gran_cyklu + (double)suma_kol2/gran_cyklu)/2.0);
        printf(" sredni czas oczekiwania: %.2f minut\n",
               ((double) kol_czek1/obsluzeni1 + (double) kol_czek2/obsluzeni2)/2.0);
    }
    else
        puts("Brak klientow w oknie 1!");
    WyczyscKolejke(&kol1);
    WyczyscKolejke(&kol2);
    puts("Do widzenia.");
    return 0;
}
// x = sredni czas w minutach miedzy wejsciem kolejnych klientow
// wartoscia zwracana jest True, jesli w tej minucie pojawil sie klient
bool nowyklient(double x)
{
    if (rand() * x / RAND_MAX < 1)
    return true;
    else
    return false;
}
// kiedy jest czasem wejscia klienta do kolejki
// funkcja zwraca strukture typu Pozycja z czasem przybycia
// ustawionym na kiedy i czasem konsultacji ustawionym na
// wartosc losowa z przedzialu 1 - 3
Pozycja czasklienta(long kiedy)
{
    Pozycja klient;
    klient.czaskons = rand() % 3 + 1;
    klient.przybycie = kiedy;
    return klient;
}

