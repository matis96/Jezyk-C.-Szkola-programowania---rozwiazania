//zad5.c
#include <stdio.h>
int main(void)
{
    char input, j,k;
    int i, odstep, row;
    printf("Podaj litere do piramidy: ");
    scanf("%c", &input);
    row = input - 'A'+1;
    for (i=0; i<row; i++)
        {
            for (odstep=row-1-i;odstep>=0; odstep--)
                printf(" ");
            for (j='A'; j<='A'+i; j++)
                printf("%c", j);
            for (k=j-2;k>='A'; k--)
                printf("%c",k);
            printf("\n");
        }
    return 0;
}
