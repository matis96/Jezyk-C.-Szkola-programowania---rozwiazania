//zad1.c
#include <stdio.h>
#include <math.h>
int bin2dec(char *);
int main(void)
{
    char * wbin = "10110110";
    char * kopia = wbin;
    printf("%d", bin2dec(wbin));
    return 0;
}
int bin2dec(char * wbin)
{
    char * kopia = wbin;
    int licznik=0;
    int suma =0;
    int potega = 0;
    while (*kopia++)
        licznik++;
    while (licznik-->0)
    {
        if (wbin[licznik]=='1')
            suma += pow(2, potega);
        potega++;
    }
    return suma;
}
