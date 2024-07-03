//zad9.c
#include <stdio.h>

void Temperatura(double temp);
int main(void)
{
    double temp;
    int k;
    printf("Podaj temperature w stopniach Fahrenheita\n");
    k = scanf("%lf", &temp);
    while (k == 1){
       Temperatura(temp);
       printf("Podaj temperature w stopniach Fahrenheita (wpisz k aby zakonczyc)\n");
       k = scanf("%lf", &temp);
    }

}

void Temperatura(double temp)
{
    double Celsjusz, Kelwin;
    const double Faht_to_Cel = 32.0;
    const double Cel_to_Kel = 273.16;
    Celsjusz = 5.0/9.0*(temp-Faht_to_Cel);
    Kelwin = Celsjusz + Cel_to_Kel;
    printf("Temperatura w Fehrenheitach: %.2f, stopniach Celsjusza: %.2f, Kelwinach: %.2f\n", temp, Celsjusz, Kelwin);
}
