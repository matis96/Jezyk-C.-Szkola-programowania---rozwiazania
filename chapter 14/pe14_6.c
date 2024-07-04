//zad6.c
//strona 690
#include <stdio.h>
#include <string.h>
#define DL 20
#define NR 19
struct zawodnik {
    int numer;
    char imie[DL];
    char nazwisko[DL];
    int rzut2;
    int trafienie2;
    int asysta;
    int faul;
    float skutecznosc;
};

int main(void)
{
    struct zawodnik gracze[NR] = {0, "", "", 0, 0, 0, 0, 0};
    struct zawodnik temp;
    struct zawodnik druzyna = {0, "DRUZYNA", "", 0, 0, 0, 0, 0};
    FILE *wp;
    int i=0;
    int rozmiar = sizeof (struct zawodnik);
    wp = fopen("zawodnicy.txt", "r");
    rewind(wp);
    while (fscanf(wp, "%d %s %s %d %d %d %d", &temp.numer, temp.imie, temp.nazwisko, &temp.rzut2, &temp.trafienie2, &temp.asysta, &temp.faul)==7)
    {
        gracze[temp.numer].numer = temp.numer;
        strcpy(gracze[temp.numer].imie, temp.imie);
        strcpy(gracze[temp.numer].nazwisko, temp.nazwisko);
        gracze[temp.numer].rzut2 += temp.rzut2;
        gracze[temp.numer].trafienie2 += temp.trafienie2;
        gracze[temp.numer].asysta += temp.asysta;
        gracze[temp.numer].faul += temp.faul;
    }
    printf("%4s %-12s %-12s %-12s %-16s %-6s %-6s %-10s\n", "Nr", "imie", "nazwisko", "rzuty za 2", "trafienia za 2", "asysty", "faule", "skutecznosc");
    gracze[i].skutecznosc = ((float) gracze[i].trafienie2 / (float) gracze[i].rzut2);
    printf("%4d %-12s %-12s %-12d %-16d %-6d %-6d %-10.2f\n", gracze[i].numer, gracze[i].imie, gracze[i].nazwisko,
                   gracze[i].rzut2, gracze[i].trafienie2, gracze[i].asysta, gracze[i].faul, gracze[i].skutecznosc);
    druzyna.rzut2 += gracze[i].rzut2; druzyna.trafienie2 +=gracze[i].trafienie2; druzyna.asysta +=gracze[i].asysta;
    druzyna.faul += gracze[i].faul;
    for (i=1; i<NR; i++)
        if (gracze[i].numer != 0)
        {
            gracze[i].skutecznosc = ((float) gracze[i].trafienie2 / (float) gracze[i].rzut2);
            druzyna.rzut2 += gracze[i].rzut2; druzyna.trafienie2 +=gracze[i].trafienie2; druzyna.asysta +=gracze[i].asysta;
            druzyna.faul += gracze[i].faul;
            printf("%4d %-12s %-12s %-12d %-16d %-6d %-6d %-10.2f\n", gracze[i].numer, gracze[i].imie, gracze[i].nazwisko,
                   gracze[i].rzut2, gracze[i].trafienie2, gracze[i].asysta, gracze[i].faul, gracze[i].skutecznosc);
        }

    druzyna.skutecznosc = ((float)druzyna.trafienie2 / (float) druzyna.rzut2);
    printf("     %-25s %-12d %-16d %-6d %-6d %-10.2f", druzyna.imie, druzyna.rzut2, druzyna.trafienie2, druzyna.asysta,
           druzyna.faul, druzyna.skutecznosc);


    fclose(wp);
    return 0;
}
