//zad13.c
#include <stdio.h>
int main(int argc, char *argv[])
{
    int licznik;
    for (licznik=argc-1; licznik > 0; licznik--)
        printf("%s ", argv[licznik]);
    printf("\n");
    return 0;
}
