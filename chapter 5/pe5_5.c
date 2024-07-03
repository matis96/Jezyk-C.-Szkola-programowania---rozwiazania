//zad5.c
#include <stdio.h>
int main(void)
{
    int licznik, suma, dni; /* instrukcja deklaracji */
    licznik = 0; /* instrukcja przypisania */
    suma = 0; /* jak wyzej */
    printf("Ile dni obliczyc? ");
    scanf("%d", &dni);
    while (licznik++ < dni) /* instrukcja */
        suma = suma + licznik; /* while */
    printf("suma = %d\n", suma); /* instrukcja wywolania funkcji */
    return 0; /* instrukcja zwrotu */
}
