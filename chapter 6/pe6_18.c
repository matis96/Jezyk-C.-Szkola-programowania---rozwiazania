//zad18.c
#include <stdio.h>
#define DUNBAR 150
int main(void)
{
    int znajomi = 5;
    int tyg =0;
    while (znajomi < DUNBAR)
    {
        tyg++;
        znajomi -= tyg;
        znajomi *=2;
        printf("Liczba znajomych w %d tyg to %d\n", tyg, znajomi);
    }
    return 0;
}
