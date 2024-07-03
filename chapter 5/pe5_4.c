//zad4.c
#include <stdio.h>
#define CAL 2.54
#define STOPA 30.48
int main(void)
{
    float cm, in;
    int ft;
    printf("Podaj wzrost w centymetrach: ");
    scanf("%f", &cm);
    while(cm>0)
    {
        ft = cm / STOPA;
        in = (cm - ft * STOPA)/CAL;
        printf("%.1f cm = %d stop, %.1f cali\n", cm, ft, in);
        printf("Podaj wzrost w centymetrach (<=0 - koniec): ");
        scanf("%f", &cm);
    }
    printf("Do widzenia!");
    return 0;
}
