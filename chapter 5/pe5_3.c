//zad3.c
#include <stdio.h>
int main(void)
{
    int dni, tyg, left;
    printf("Podaj ilosc dni\n");
    printf("Wpisz 0 aby zakonczyc program\n");
    scanf("%d", &dni);
    while(dni>0)
    {
        tyg = dni / 7;
        left = dni % 7;
        printf("%d dni to %d tyg, %d dni\n", dni, tyg, left);
        printf("Podaj ilosc dni\n");
        printf("Wpisz 0 aby zakonczyc program\n");
        scanf("%d", &dni);
    }
    return 0;
}
