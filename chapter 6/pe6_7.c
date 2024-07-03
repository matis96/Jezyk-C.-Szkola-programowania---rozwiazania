//zad7.c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char slowo[20];
    int index, i;
    printf("Podaj slowo:\n");
    scanf("%s", slowo);
    index = strlen(slowo);
    for (i = index; i>0; i--)
        printf("%c", slowo[i-1]);
    return 0;
}
