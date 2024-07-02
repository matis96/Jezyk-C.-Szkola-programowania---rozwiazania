//zad6.c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char imie[20];
    char nazwisko[40];
    printf("Jak masz na imie?\n");
    scanf("%s", imie);
    printf("Jak masz na nazwisko?\n");
    scanf("%s", nazwisko);
    printf("%s %s\n", imie, nazwisko);
    printf("%-*d %-*d", strlen(imie), strlen(imie), strlen(nazwisko), strlen(nazwisko));
    return 0;
}
