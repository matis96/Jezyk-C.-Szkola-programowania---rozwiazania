//zad11.c
#include <stdio.h>
int main(void)
{
    int tablica[8];
    int i;
    printf("Podaj 8 liczb calkowitych: ");
    for (i=0; i<8; i++)
    {
        scanf("%d", &tablica[i]);
    }
    for (i=7; i>=0; i--)
        printf("%d", tablica[i]);
    return 0;
}
