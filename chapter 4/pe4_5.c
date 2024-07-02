//zad5.c
#include <stdio.h>
int main(void)
{
    float mb_s, mb, time;
    printf("Jaka masz predkosc pobierania?\n");
    scanf("%f", &mb_s);
    printf("Jaki jest rozmiar pliku?\n");
    scanf("%f", &mb);
    time = mb*8/mb_s;
    printf("Przy %.2f megabitow na sekunde plik o rozmiarze %.2f megabajta\n", mb_s, mb);
    printf("zostanie pobrany w %.2f sekundy", time);
    return 0;
}
