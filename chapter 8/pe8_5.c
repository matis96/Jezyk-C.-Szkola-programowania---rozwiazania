//zad5.c
#include <stdio.h>
int main(void)
{
    int proba=50;
    int upper_limit = 100;
    int bottom_limit = 0;
    char odpowiedz;
    printf("Wybierz liczbe od 1 do 100. Sprobuje ja odgadnac.\n");
    printf("Czy twoja liczba wynosi %d?\n", proba);
    printf("Wpisz (w)ieksza, (m)niejsza lub (r)owna.\n");
    while((odpowiedz = getchar())!='r')
    {
        if (odpowiedz == 'w')
        {
            bottom_limit = proba;
            proba = (upper_limit+bottom_limit)/2;
            printf("Czy twoja liczba wynosi %d?\n", proba);
        }
        else if (odpowiedz == 'm')
        {
            upper_limit=proba;
            proba = (upper_limit+bottom_limit)/2;
            printf("Czy twoja liczba wynosi %d?\n", proba);
        }
        else
            printf("Przykro mi, rozumiem tylko w, m lub r.\n");
        while (getchar() != '\n')
            continue;

    }
    printf("Wiedzialem, ze mi sie uda!\n");
    return 0;
}
