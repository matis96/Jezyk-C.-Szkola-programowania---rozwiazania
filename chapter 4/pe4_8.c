//zad8.c
#include <stdio.h>
#define PALIWO 3.785
int main(void)
{
    float mila, galon;
    float USA, EU;
    const float KM = 1.609;
    printf("Ile mil przebyles?\n");
    scanf("%f", &mila);
    printf("Ile galonow zuzyles?\n");
    scanf("%f", &galon);
    USA = mila/galon;
    EU = (100*galon*PALIWO)/(KM * mila);
    printf("Zuzycie paliwa to %.1f mili/galon\n", USA);
    printf("Czyli %.1f litrow/100 km", EU);
    return 0;
}
