//pe2_5.c
#include <stdio.h>
void br(void);
void ic(void);

int main(void)
{
    br(); printf(", "); ic();
    printf("\n"); ic();
    printf("\n"); br();
    return 0;
}

void br(void)
{
    printf("Brazylia, Rosja");
}

void ic(void)
{
    printf("Indie, Chiny");
}
