//zad6.c
#include <stdio.h>
//#define LANCUCH "LANCUCH TESTOWY"
int znajduje_sie_w(char, const char *);
int main(void)
{
    char c;
    char test[40];
    puts("Podaj lancuch testowy");
    scanf("%s", test);
    puts("Podaj znak do sprawdzenia, EOF aby zakonczyc");
    if (c != '\n')
			while (getchar() != '\n')
				continue;
    while((c=getchar())!=EOF)
    {

        printf("W tym wierszu %s znajduje sie %c.\n", znajduje_sie_w(c, test)?"\b":"nie", c);
        puts("Podaj lancuch testowy");
        scanf("%s", test);
        puts("Podaj znak do sprawdzenia, EOF aby zakonczyc");
        if (c != '\n')
			while (getchar() != '\n')
				continue;
    }
    puts("Bye");
    return 0;
}
int znajduje_sie_w(char c, const char *lan)
{
    char *wl;
    wl = lan;
    while(*wl)
    {
        if (*wl == c)
            return 1;
        *wl++;
    }
    return 0;
}
