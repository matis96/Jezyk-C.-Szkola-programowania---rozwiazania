//zad3.c
#include <stdio.h>
void wyswietl(char ch, int x, int y);
int main(void)
{
    wyswietl('y', 5, 8);
    return 0;
}

void wyswietl(char ch, int x, int y)
{
    int i,j;
    for (i=0; i<x; i++)
    {
        for (j=0; j<y; j++)
            printf("%c", ch);
        printf("\n");
    }
}
