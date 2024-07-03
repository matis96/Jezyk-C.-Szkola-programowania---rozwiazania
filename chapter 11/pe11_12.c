//zad12.c
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 81
int LiczDuze(const char *);
int LiczMale(const char *);
int LiczInter(const char *);
int LiczCyfry(const char *);
int liczSlowa(const char *);
char *wczytaj(char *z, int ile);
int main(void)
{
    char test[MAX];
    while(wczytaj(test, 150) && test[0] != '\0')
    {
        printf("Podany lancuch ma %d slow, %d wielkich liter, %d malych liter, %d znakow przest. oraz %d cyfr\n",
               liczSlowa(test),
               LiczDuze(test), LiczMale(test), LiczInter(test), LiczCyfry(test));
    }
    return 0;
}
int LiczDuze(const char *lan)
{
    int licz =0;
    while (*lan)
    {
        if (isupper(*lan))
            licz++;
        lan++;
    }
    return licz;
}
int LiczMale(const char *lan)
{
    int licz =0;
    while (*lan)
    {
        if (islower(*lan))
            licz++;
        lan++;
    }
    return licz;
}
int LiczInter(const char *lan)
{
    int licz =0;
    while (*lan!='\0')
    {
        if (ispunct(*lan))
            licz++;
        lan++;
    }
    return licz;
}
int LiczCyfry(const char *lan)
{
    int licz =0;
    while (*lan)
    {
        if (isdigit(*lan))
            licz++;
        lan++;
    }
    return licz;
}
int liczSlowa(const char *lan)
{
    bool word = false;
    int slowa=0;
    while(*lan)
    {
        if (isalpha(*lan))
            if (!word)
        {
            slowa++;
            word = true;
        }
        if (isdigit(*lan)||ispunct(*lan)||isspace(*lan))
            word = false;
        lan++;
    }
    return slowa;
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
