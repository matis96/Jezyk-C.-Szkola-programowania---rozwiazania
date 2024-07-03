//zad9.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int main(void)
{
FILE *wp, *wp_licz;
int licznik;
char slowa[MAX];
if ((wp_licz = fopen("licz_slowek.txt", "r"))== NULL)
    licznik = 0;
else
    fscanf(wp_licz, "%d", &licznik);
fclose(wp_licz);
wp_licz = fopen("licz_slowek.txt", "w");
if ((wp = fopen("slowka", "a+")) == NULL)
{
fprintf(stdin,"Nie moge otworzyc pliku \"slowka\".\n");
exit(EXIT_FAILURE);
}
puts("Podaj slowa, ktore maja zostac dodane do pliku;");
puts("Aby zakonczyc, wpisz #.");
while ((fscanf(stdin,"%20s", slowa) == 1) && (slowa[0] != '#'))
{
    licznik++;
    fprintf(wp, "%d-%s ", licznik, slowa);
}
fprintf(wp_licz, "%d", licznik);
puts("Zawartosc pliku:");
rewind(wp); // przejdz do poczatku pliku
while (fscanf(wp,"%s",slowa) == 1)
puts(slowa);
puts("Gotowe!\n");
if (fclose(wp) != 0)
fprintf(stderr,"Blad przy zamykaniu pliku.\n");
return 0;
}
