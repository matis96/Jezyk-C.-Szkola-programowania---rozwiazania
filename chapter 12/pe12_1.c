/* zad1.c -- uzycie zmiennych globalnych */
#include <stdio.h>
//int jednostki = 0; /* zmienna zewnetrzna */
void krytyka(int *);
int main(void)
{
int jednostki; /* powtorna (opcjonalna) deklaracja */
printf("Ile funtow masla miesci sie w barylce?\n");
scanf("%d", &jednostki);
while ( jednostki != 56)
krytyka(&jednostki);
printf("Musiales podejrzec!\n");
return 0;
}
void krytyka(int * jednostki)
{
/* pominieto powtorna (opcjonalna) deklaracje */
printf("Nie masz szczescia, sprobuj ponownie.\n");
scanf("%d", jednostki);
}
