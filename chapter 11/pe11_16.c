//zad16.c
#include <stdio.h>
#include <ctype.h>
void toMale(char *);
void toDuze(char *s);
int main(int argc, char *argv[])
{
    int licznik;
    if (argv[1][0]=='-'&&argv[1][1]=='p')
        for (licznik = 2; licznik < argc; licznik++)
        printf("%s ", argv[licznik]);
    else if (argv[1][0]=='-'&&argv[1][1]=='u')
        for (licznik = 2; licznik < argc; licznik++)
    {
        toDuze(argv[licznik]);
        printf("%s ", argv[licznik]);
    }
    else if (argv[1][0]=='-'&&argv[1][1]=='l')
        for (licznik = 2; licznik < argc; licznik++)
    {
        toMale(argv[licznik]);
        printf("%s ", argv[licznik]);
    }
    else
        for (licznik = 1; licznik < argc; licznik++)
        printf("%s ", argv[licznik]);

    return 0;
}
void toMale(char *s)
{
    while(*s!='\0')
    {
        *s=tolower(*s);
        s++;
    }

}
void toDuze(char *s)
{
    while(*s!='\0')
    {
        *s=toupper(*s);
        s++;
    }

}

