//zad5.c
#include <stdio.h>
#define MAX 30
char * czyZnak(char *, char );
int main(void)
{
    char test[MAX];
    char znak;
    char *check;
    puts("Podaj lancuch do sprawdzenia");
    fgets(test, MAX, stdin);
    puts("Podaj znak do sprawdzenia");
    scanf("%c", &znak);
    while (znak!='\n')
    {
        if (znak != '\n')
			while (getchar() != '\n')
				continue;
        check = czyZnak(test, znak);
        if (check)
            printf("Lancuch po %c to %s\n", znak, check);
        else
            puts("Nie ma takiego znaku");
        puts("Podaj lancuch do sprawdzenia");
        fgets(test, MAX, stdin);
        puts("Podaj znak do sprawdzenia");
        scanf("%c", &znak);

    }

    return 0;

}

char * czyZnak(char *s, char c)
{
    while(*s!='\0')
    {
        if (*s==c)
            return s+1;
        s++;
    }
    return NULL;
}
