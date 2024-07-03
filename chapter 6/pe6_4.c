//zad4.c
#include <stdio.h>
#define ROW 6
int main(void)
{
    int i, count;
    char k;
    count = 0;
    for (i=0; i<=ROW; i++)
    {

        for (k='A'+count; k<'A'+i+count; k++)
            printf("%c", k);
        count += i;
        printf("\n");
    }
    return 0;
}
