//zad8.c
#include <stdio.h>
#define WYNAGRODZENIE1  35
#define WYNAGRODZENIE2  37
#define WYNAGRODZENIE3  40
#define WYNAGRODZENIE4  45

#define NADGODZINY      1.50
#define PODATEK1        0.15
#define PODATEK2        0.2
#define PODATEK3        0.25
int main(void)
{
    int h, brutto, netto, podatek, wybor, stawka;
    do {
        printf("***************************************************************\n");
        printf("Podaj liczbe odpowiadajaca zadanej stawce wynagrodzenia lub opcji:\n");
        printf("1) 35 zl/godz.                  2) 37 zl/godz.\n");
        printf("3) 40 zl/godz.                  4) 45 zl/godz.\n");
        printf("5) wyjscie\n");
        printf("***************************************************************\n");
        scanf("%d", &wybor);

        switch (wybor)
        {
        case 1:
        case 35:
            stawka = WYNAGRODZENIE1;
            break;
        case 2:
        case 37:
            stawka = WYNAGRODZENIE2;
            break;
        case 3:
        case 40:
            stawka = WYNAGRODZENIE3;
            break;
        case 4:
        case 45:
            stawka = WYNAGRODZENIE4;
            break;
        case 5:
            return 0;
        default:
            printf("Podaj cyfre z zakresu 1-5\n");
            continue;
        }

        printf("Ile godzin przepracowales? ");
        scanf("%d", &h);
        if (h>40)
        brutto = (h-40)*NADGODZINY*stawka + 40 * stawka;
        else
            brutto = h * stawka;
        if (brutto > 1800)
            podatek = PODATEK1 * 1200 + PODATEK2 * 600 + (brutto - 1800) * PODATEK3;
        else if (brutto>1200)
            podatek = PODATEK1 * 1200 + (brutto - 1200) * PODATEK2;
        else
            podatek = brutto * PODATEK1;
        netto = brutto - podatek;
        printf("Wynagrodzenie brutto wynosi %d zl, podatek %d zl, netto %d zl\n", brutto, podatek, netto);
    } while (wybor != 5);
    return 0;
}
