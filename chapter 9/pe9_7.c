//zad7.c
#include <stdio.h>
#include <ctype.h>

int znak_nr(char ch);
int main(void)
{
    char ch;
    while ((ch=getchar())!=EOF)
    {
        while (getchar() != '\n')
                continue;
        printf("%c - %d\n", ch, znak_nr(ch));
    }
    return 0;
}

int znak_nr(char ch)
{
    if (isalpha(ch))
    {
        printf("To jest litera!\n");
        tolower(ch);
        return ch-'a'+1;
    }
    else
    {
        printf("To nie jest litera!\n");
        return -1;
    }

}
