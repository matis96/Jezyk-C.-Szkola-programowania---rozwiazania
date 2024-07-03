//zad4.c
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int slowa = 0;
    //int litery = 0;
    int znaki = 0;
    char ch;
    while((ch=getchar())!=EOF)
    {
        znaki++;
        if (isspace(ch))
        {
            slowa++;
            znaki--;
        }
    }
    printf("Srednia liczba liter w slowie wynosi %d", znaki/slowa);
    return 0;
}
