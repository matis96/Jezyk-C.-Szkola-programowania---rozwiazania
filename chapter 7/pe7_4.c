//zad4.c
#include <stdio.h>
int main(void)
{
    char ch;
    int zmiana = 0;
    while ((ch = getchar())!='#')
    {
        if (ch == '.')
        {
            putchar('!');
            zmiana++;
        }
        else if (ch == '!')
        {
            putchar('!');
            putchar('!');
            zmiana++;
        }
        else putchar(ch);
    }
    printf("Ilosc zmian to %d", zmiana);
    return 0;

}
