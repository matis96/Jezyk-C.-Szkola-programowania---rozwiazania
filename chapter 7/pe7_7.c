//zad7.c
#include <stdio.h>
#define WYNAGRODZENIE 40
#define NADGODZINY 1.50
#define PODATEK1 0.15
#define PODATEK2 0.2
#define PODATEK3 0.25
int main(void)
{
    int h, brutto, netto, podatek;
    printf("Podaj ile godzin przepracowales w tygodniu: ");
    scanf("%d", &h);
    if (h>40)
        brutto = (h-40)*NADGODZINY*WYNAGRODZENIE + 40 * WYNAGRODZENIE;
    else
        brutto = h * WYNAGRODZENIE;
    if (brutto > 1800)
        podatek = PODATEK1 * 1200 + PODATEK2 * 600 + (brutto - 1800) * PODATEK3;
    else if (brutto>1200)
        podatek = PODATEK1 * 1200 + (brutto - 1200) * PODATEK2;
    else
        podatek = brutto * PODATEK1;
    netto = brutto - podatek;
    printf("Wynagrodzenie brutto wynosi %d zl, podatek %d zl, netto %d zl", brutto, podatek, netto);
    return 0;
}
