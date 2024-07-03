//zad5.c
#include <stdio.h>
float roznica_tab(float tab[], int n);
int main(void)
{
    float roznica;
    float t[10]={8.11, 3.52, 0.11, 8.99, 90.00, 91.82, 13.52, 0.007, 167.9, 53.41};
    roznica = roznica_tab(t, 10);
    printf("%.3f", roznica);
    return 0;
}

float roznica_tab(float tab[], int n)
{
    float min, max;
    int i;
    min = max = tab[0];
    for (i=1; i<n; i++)
    {
        if (tab[i]<min)
            min = tab[i];
        if (tab[i]>max)
            max = tab[i];
    }
    return max-min;
}
