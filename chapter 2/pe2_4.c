//pe2_4.c
#include <stdio.h>
void panJan(void);
void wstawaj(void);

int main(void)
{
    printf("Panie Janie!");
    panJan();
    wstawaj();
    return 0;
}

void panJan(void)
{
    printf("\nPanie Janie!");
}

void wstawaj(void)
{
    printf("\nRano wstan!");
}
