//zad3.c
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int mala_litera = 0;
    int wielka_litera = 0;
    int znaki = 0;
    char ch;
    while((ch=getchar())!=EOF)
    {
        znaki++;
        if (islower(ch))
            mala_litera++;
        if (isupper(ch))
            wielka_litera++;
    }
    znaki = znaki - mala_litera - wielka_litera;
    printf("W tekscie jest %d malych liter, %d wielkich liter oraz %d pozostalych znakow", mala_litera, wielka_litera, znaki);
    return 0;
}
