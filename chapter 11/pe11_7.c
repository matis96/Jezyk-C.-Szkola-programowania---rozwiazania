//zad7.c
#include <stdio.h>
char * my_strncpy(char *, char *, int);
int main (void)
{
    char s2[20]="Lancuch testowy";
    char s1[20]="";
    my_strncpy(s1, s2, 10);
    puts(s1);
    return 0;
}
char * my_strncpy(char *s1, char *s2, int n)
{
    int i = 0;
    for (i; i<n; i++)
    {
        *(s1+i)=*(s2+i);
    }
    return s1;
}
