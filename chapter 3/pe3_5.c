//zad5.c
#include <stdio.h>
int main(void)
{
    unsigned int sek = 31560000;
    int wiek;
    printf("Ile masz lat? ");
    scanf("%d", &wiek);
    sek = sek * sek;
    printf("\nZyjesz juz %d sekund", sek);
    return 0;
}
