//zad2.c
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
    {
        lan[i]=getchar();
        if (lan[i]==' '||lan[i]=='\t'||lan[i]=='\n')
            break;
    }

    lan[i]='\0';
    return lan;
}
