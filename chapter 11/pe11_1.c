//zad1.c
#include <stdio.h>
#define MAX 20
char * n_znak(char * lan, int );

int main(void)
{
    char test[MAX];
    n_znak(test, 15);
    puts(test);
    return 0;
}

char * n_znak(char * lan, int n)
{
    int i = 0;
    for (i; i<n; i++)
        lan[i]=getchar();
    lan[i]='\0';
    return lan;
}
