//zad10.c
#include <stdio.h>
void suma(int tab1[], int tab2[], int tab3[], int n);
int main(void)
{
    int tab1[4]={2,4,5,8};
    int tab2[4]={1,0,4,6};
    int tab3[4];
    suma(tab1, tab2, tab3, 4);
     for (int i=0; i<4; i++)
        printf("%d ", tab3[i]);

     return 0;
}

void suma(int tab1[], int tab2[], int tab3[], int n)
{
    for (int i=0; i<n; i++)
        tab3[i]=tab1[i]+tab2[i];

}
