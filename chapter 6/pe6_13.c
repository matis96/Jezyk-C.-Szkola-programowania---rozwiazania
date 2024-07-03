//zad13.c
#include <stdio.h>
int main(void)
{
    int dwojka[8];
    int i, value;
    value = 1;
    for (i=0; i<8; i++)
    {
        dwojka[i]=value;
        value *=2;
    }
    i=0;
    do {
        printf("%d ", dwojka[i]);
        i++;
    } while(i<8);
    return 0;
}
