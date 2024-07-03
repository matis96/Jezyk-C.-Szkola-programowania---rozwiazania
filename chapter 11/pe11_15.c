//zad15.c
#include <stdio.h>
int my_atoi(char *);
double potega(double a, int b);
int main(void)
{
    char test[10]="12938123";
    int wynik;
    wynik = my_atoi(test);
    printf("%d", wynik);
    return 0;

}
int my_atoi(char *s)
{
    int wynik=0;
    int pozycja = strlen(s);
    while (*s!='\0')
    {
        if (*s==0+48)
            wynik += 0*potega(10, pozycja-1);
        else if (*s==1+48)
            wynik += 1*potega(10, pozycja-1);
        else if (*s==2+48)
            wynik += 2*potega(10, pozycja-1);
        else if (*s==3+48)
            wynik += 3*potega(10, pozycja-1);
        else if (*s==4+48)
            wynik += 4*potega(10, pozycja-1);
        else if (*s==5+48)
            wynik += 5*potega(10, pozycja-1);
        else if (*s==6+48)
            wynik += 6*potega(10, pozycja-1);
        else if (*s==7+48)
            wynik += 7*potega(10, pozycja-1);
        else if (*s==8+48)
            wynik += 8*potega(10, pozycja-1);
        else if (*s==9+48)
            wynik += 9*potega(10, pozycja-1);
        else
            return 0;
        pozycja--;
        s++;
    }
    return wynik;
}
double potega(double a, int b) /* definicja funkcji */
{
double pot = 1;
int i;
for(i = 1; i <= b; i++)
pot *= a;
return pot; /* zwrot wartosci pot */
}
