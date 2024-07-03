//zad7.c
#include <stdio.h>
void szescian(float x);
int main(void)
{
    float x;
    printf("Podaj liczbe:\n");
    scanf("%f", &x);
    szescian(x);
    return 0;
}

void szescian(float x)
{
    printf("%f", x*x*x);
}
