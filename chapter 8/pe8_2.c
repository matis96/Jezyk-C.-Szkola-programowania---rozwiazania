//zad2.c
#include <stdio.h>
int main(void)
{
    char ch;
    int licznik=0;
    while((ch=getchar())!=EOF)
    {
        ++licznik;
        if (ch=='\n')
            printf("\\n - %d, ", ch);
        else if (ch == '\t')
            printf("\\t - %d, ", ch);
        else if (ch<=64 && (ch!='\t'|| ch!='\n'))
            printf("^%c - %d, ", ch+64, ch);
        else
            printf("%c - %d, ", ch, ch);
        if (licznik>=10 || ch == '\n')
        {
            printf("\n");
            licznik = 0;
        }
    }
    return 0;
}
