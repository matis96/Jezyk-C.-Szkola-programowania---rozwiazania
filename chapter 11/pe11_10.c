//zad10.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void * bezspacji(char *);
char *wczytaj(char *z, int ile);
int main(void)
{
    char test[30];
    while(wczytaj(test, 30) && test[0] != '\0')
    {
        bezspacji(test);
        puts(test);
    }
    return 0;
}

void * bezspacji(char *s)
{
    unsigned long i=0;
    while (1)
    {
        *(s-i)=*s;
        if(isspace(*s))
            i++;

        if(*s=='\0')
            break;
        s++;
    }
}
char *wczytaj(char *z, int ile)
{
    char * wynik;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    if (wynik) // wynik rozny od NULL
    {
	while (z[i] != '\n' && z[i] != '\0')
	    i++;
	if (z[i] == '\n')
	    z[i] = '\0'; // znak nowego wiersza -> znak pusty
	else // z[i] == '\0'
	    while (getchar() != '\n')
		continue;
}
    return wynik;
}
