//zad4.c
#include <stdio.h>
int main(void)
{
    float cm, wzrost;
    char imie[20];
    printf("Ile masz wzrostu w cm?\n");
    scanf("%f", &cm);
    printf("Jak masz na imie?\n");
    scanf("%s", imie);
    wzrost = cm/100;
    printf("%s, masz %.2f metra wzrostu", imie, wzrost);
    return 0;
}
