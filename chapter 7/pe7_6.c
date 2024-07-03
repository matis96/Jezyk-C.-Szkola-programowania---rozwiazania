//zad6.c
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    char ch;
    int ot = 0;
    bool flaga_o = false;
    while ((ch = getchar())!='#')
    {

        if (ch == 't' && flaga_o)
            ot++;
        if (ch=='o')
            flaga_o = true;

        else flaga_o = false;
    }
    printf("\n%d powtorzen", ot);
    return 0;
}
