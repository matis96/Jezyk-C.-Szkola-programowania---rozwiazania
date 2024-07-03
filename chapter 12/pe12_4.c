//zad4.c
#include <stdio.h>
void wywolaj(void);

int main(void)
{
    char ch;
    printf("Nacisnij enter aby wywolac funkcje!\n");
    while ((ch=getchar())!=EOF)
    {
        wywolaj();
        printf("Nacisnij enter aby wywolac funkcje!\n");
    }
    return 0;
}

void wywolaj(void)
{
    static int proba=1;
    printf("Proba wywolania: %d\n", proba++);
}
