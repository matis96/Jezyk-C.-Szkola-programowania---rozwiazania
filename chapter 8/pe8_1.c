//zad1.c
#include <stdio.h>
int main(void)
{
    int licznik=0;
    char ch;
    while((ch=getchar())!=EOF)
    {
        licznik++;
    }
    printf("%d znakow", licznik);
    return 0;
}
