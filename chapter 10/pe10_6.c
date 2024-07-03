//zad6.c
#include <stdio.h>
void odwroc(double tab[], int n);
int main(void)
{
    int i;
    double t[10]={8.11, 3.52, 0.11, 8.99, 90.00, 91.82, 13.52, 0.007, 167.9, 53.41};
    odwroc(t, 10);
    for (i=0; i<10; i++)
        printf("%.2f ", t[i]);
    return 0;
}
void odwroc(double tab[], int n)
{
    int i;
    double temp;
    for (i=0; i<n/2; i++)
    {
        temp = tab[i];
        tab[i]= tab[n-1-i];
        tab[n-1-i]=temp;
    }

}
