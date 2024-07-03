//zad10.c
#include <stdio.h>
int main(void)
{
    int ll, ul, suma;
    int i;
    printf("Podaj dolna i gorna granice przedzialu liczb calkowitych: ");
    scanf("%d %d", &ll, &ul);
    while (ll<ul)
    {
        suma = 0;
        for (i=ll; i<=ul; i++)
            suma += i*i;
        printf("Suma kwadratow od %d do %d wynosi %d\n", ll*ll, ul*ul, suma);
        printf("Podaj nastepny przedzial: ");
        scanf("%d %d", &ll, &ul);
    }
    printf("Koniec");
    return 0;
}
