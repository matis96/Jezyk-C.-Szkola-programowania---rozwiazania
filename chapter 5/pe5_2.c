//zad2.c
#include <stdio.h>
int main(void)
{
    int x,y;
    printf("Podaj liczbe calkowita\n");
    scanf("%d", &x);
    y=x+10;
    while(x<y+1)
    {
        printf("%d\n", x);
        x++;
    }
    return 0;
}
