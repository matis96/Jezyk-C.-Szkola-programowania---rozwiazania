//zad7.c
#include <stdio.h>
int main(void)
{
    float cal = 2.54;
    float wzrost;
    printf("Ile masz wzrostu w cm? ");
    scanf("%f", &wzrost);
    printf("Mierzysz %.2f cali, czyli %.1f cm", wzrost*cal, wzrost);
    return 0;
}
