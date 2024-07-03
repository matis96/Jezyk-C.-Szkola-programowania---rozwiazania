//zad6.c
#include <stdio.h>
int main(void)
{
    int granica_dolna, granica_gorna;
    int i;
    printf("Podaj dolna granice tabeli: ");
    scanf("%d", &granica_dolna);
    printf("Podaj gorna granice tabeli: ");
    scanf("%d", &granica_gorna);
    printf("liczba    kwadrat    szescian\n");
    for (i=granica_dolna; i<=granica_gorna; i++)
        printf("%5d     %5d     %5d\n", i, i*i, i*i*i);
    return 0;
}
