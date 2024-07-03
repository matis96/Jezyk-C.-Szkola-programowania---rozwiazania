//zad14.c
#include <stdio.h>
#define SIZE 8
int main(void)
{
    double tab1[SIZE], tab2[SIZE];
    int i;
    printf("Podaj wartosci tablicy: ");
    for (i=0; i<SIZE; i++)
        scanf("%lf", &tab1[i]);
    tab2[0]=tab1[0];
    for (i=1; i<SIZE; i++)
        tab2[i]=tab2[i-1]+tab1[i];
    for (i=0; i<SIZE; i++)
        printf("%8.2lf", tab1[i]);
    printf("\n");
    for (i=0; i<SIZE; i++)
        printf("%8.2lf", tab2[i]);

    return 0;
}
