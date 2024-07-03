//zad15.c
#include <stdio.h>
int main(void)
{
    char lancuch[256];
    int i=0;
    printf("Wprowadz tekst: ");
    do
    {
        scanf("%c", &lancuch[i]);
        i++;
    } while(lancuch[i-1]!='\n');
    while (i>0)
    {
        printf("%c", lancuch[i-1]);
        i--;
    }
    return 0;
}
