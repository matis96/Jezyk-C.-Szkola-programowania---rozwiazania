//zad2.c
#include <stdio.h>
#include <math.h>
#include <limits.h>
int bin2dec(char *);
char * do_binar(int n, char * wl);
void pokaz_binar(const char * lan);
int main(int argc, char *argv[])
{
    //char *wbin1 = "00101101";
    //char *wbin2 = "10110110";
    char negacja1[CHAR_BIT * sizeof(int)];
    char negacja2[CHAR_BIT * sizeof(int)];
    char koniunkcja[CHAR_BIT * sizeof(int)];
    char alternatywa[CHAR_BIT * sizeof(int)];
    char xor[CHAR_BIT * sizeof(int)];
    int l1 = bin2dec(argv[1]);
    int l2 = bin2dec(argv[2]);
    //printf("%d %d %d\n", l1, l2, l1 | l2);
    do_binar(~l1, negacja1);
    pokaz_binar(negacja1);
    puts("");
    do_binar(~l2, negacja2);
    pokaz_binar(negacja2);
    puts("");
    int kon = l1 & l2;
    do_binar(kon, koniunkcja);
    pokaz_binar(koniunkcja);
    puts("");
    int alt = l1 | l2;
    do_binar(alt, alternatywa);
    pokaz_binar(alternatywa);
    puts("");
    do_binar(l1 ^ l2, xor);
    pokaz_binar(xor);
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
char * do_binar(int n, char * wl)
{
int i;
static int rozmiar = CHAR_BIT * sizeof(int);
for (i = rozmiar - 1; i >= 0; i--, n >>= 1)
wl[i] = (01 & n) + '0';
wl[rozmiar] = '\0';
return wl;
}
void pokaz_binar(const char * lan)
{
int i = 0;
while (lan[i]) /* nie znak null */
{
putchar(lan[i]);
if(++i % 4 == 0 && lan[i])
putchar(' ');
}
}
