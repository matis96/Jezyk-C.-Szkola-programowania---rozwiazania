// pe4_1.c
#include <stdio.h>
int main(void)
{
    char imie[20];
    char nazwisko[20];

    printf("Jak masz na imie?\n");
    scanf("%s", imie);
    printf("Jak masz na nazwisko?\n");
    scanf("%s", nazwisko);
    printf("%s, %s", nazwisko, imie);
    return 0;
}
