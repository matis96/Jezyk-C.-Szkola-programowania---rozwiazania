//zad8.c
#include <stdio.h>
int main(void)
{
    int dzielna, dzielnik, wynik;
    printf("Program obliczajacy reszte z dzielenia\n");
    printf("Ppodaj dzielnik (liczba calkowita): ");
    scanf("%d", &dzielnik);
    printf("Podaj dzielna: ");
    scanf("%d", &dzielna);
    while (dzielna> 0 )
    {
        wynik = dzielna % dzielnik;
        printf("%d %% %d wynosi %d\n", dzielna, dzielnik, wynik);
        printf("Podaj dzielna (<=0, aby zakonczyc): ");
        scanf("%d", &dzielna);
    }
    printf("Koniec");
    return 0;
}
