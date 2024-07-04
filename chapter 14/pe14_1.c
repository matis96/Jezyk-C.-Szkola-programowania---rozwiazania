//zad1.c
#include <stdio.h>
#include <string.h>
#include "zad1.h"
//extern struct miesiac miesiace[];
int dni(char *);
int main(void)
{   int suma;
    suma = dni("Marzec");
    printf("%d", suma);
    return 0;
}

int dni(char *msc)
{
	int index, suma, x=0;
	for (index = 0; index<12; index++)
        if (strcmp(msc, miesiace[index].nazwa)==0)
            x=index;
    if (x==0)
    {
        printf("Nie ma takiego miesiaca!\n");
        return -1;
    }
    for (index=0, suma =0; index<(x+1); index++)
        suma += miesiace[index].dni;
	return suma;
}
