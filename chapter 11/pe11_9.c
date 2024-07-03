//zad9.c
#include <stdio.h>
void * odwroc(char *);
char *wczytaj(char *z, int ile);
int main(void)
{
    char test[50];
    while(wczytaj(test, 50) && test[0] != '\0')
    {
        odwroc(test);
        printf("%s\n", test);
    }
    return 0;
}

void * odwroc(char *start)
{
    char *end = start;
    char temp;
    while (*(end+1)!='\0')
        end++;
    while(start<end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
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

