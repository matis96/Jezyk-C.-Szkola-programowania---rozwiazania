#include <stdio.h>
int main(void)
{
    int wiek, dni;
    wiek = 23;
    dni = wiek * 365;
    printf("Jan Kowalski");
    printf("\nJan\nKowalski\n");
    printf("Jan ");
    printf("Kowalski");
    printf("\nJan, Wycieczkowa 13");
    printf("\nZyjesz %d lat, czyli %d dni", wiek, dni);
    return 0;
}
