//zad2.c
#include <stdio.h>
#include <string.h>
int main(void)
{
    char imie[20];
    printf("Jak masz na imie?\n");
    scanf("%s", imie);
    printf("\"%s\"\n", imie);
    printf("\"%20s\"\n", imie);
    printf("\"%-20s\"\n", imie);
    printf("%*s\n", strlen(imie)+3, imie);
    return 0;
}
