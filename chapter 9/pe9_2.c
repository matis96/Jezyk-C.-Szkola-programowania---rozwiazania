//zad2.c
#include <stdio.h>

void rzad_zn(char ch, int i, int j);
int main(void)
{
    rzad_zn('y', 5, 10);
    return 0;
}

void rzad_zn(char ch, int i, int j)
{
    int k;
    for (k=0; k<i-1; k++)
        printf(" ");
    for (i; i<=j; i++)
        printf("%c", ch);

}
