//zad3.c
#include <stdio.h>
float min_tab(float t[], int n);
int main(void)
{
    float min;
    float t[10]={8.11, 3.52, 0.11, 8.99, 90.00, 91.82, 13.52, 0.007, 167.9, 53.41};
    min = min_tab(t, 10);
    printf("%.3f", min);
    return 0;
}
float min_tab(float t[], int n)
{
    int i;
    float min;
    min = t[0];
    for (i=1; i<n; i++)

        if (t[i]<min)
            min = t[i];

    return min;
}
