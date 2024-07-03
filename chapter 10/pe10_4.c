//zad4.c
#include <stdio.h>
int max_index(float t[], int n);
int main(void)
{
    int max;
    float t[10]={8.11, 3.52, 0.11, 8.99, 90.00, 91.82, 13.52, 0.007, 167.9, 53.41};
    max = max_index(t, 10);
    printf("%d", max);
    return 0;
}
int max_index(float t[], int n)
{
    int i, k;
    float max = t[0];
    for (i=1; i<n; i++)
        if (t[i]>max)
            k=i-1;
    return k;
}
