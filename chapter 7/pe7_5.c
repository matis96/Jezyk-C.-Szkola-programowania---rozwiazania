//zad5.c
#include <stdio.h>
int main(void)
{
    char ch;
    int zmiana = 0;
    while ((ch = getchar())!='#')
    {
        switch(ch)
        {
        case '.':
            putchar('!');
            zmiana++;
            break;
        case '!':
            putchar('!');
            putchar('!');
            zmiana++;
            break;
        default:
            putchar(ch);

        }
    }
    printf("\nIlosc zmian to %d", zmiana);
    return 0;

}
