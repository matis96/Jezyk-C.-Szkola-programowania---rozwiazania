// zad1.c
#include <stdio.h>
int main(void)
{
    int spacja=0;
    int enter=0;
    int znak=0;
    char ch;

    printf("Wprowadz dane wejsciowe (# aby zakonczyc)\n");
    while((ch=getchar())!='#')
        {
            if (ch == ' ')
                spacja++;
            else if (ch == '\n')
                enter++;
            else
                znak++;
        }
    printf("W tekscie jest %d spacji, %d znakow nowej linii oraz %d znakow", spacja, enter, znak);
    return 0;
}
