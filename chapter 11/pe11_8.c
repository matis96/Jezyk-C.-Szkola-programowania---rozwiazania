//zad8.c
#include <stdio.h>

char * zawiera_lan(char *, char *);
int main(void)
{
    char test[20]="pula";
    char test2[10]="ul";
    char *ch;
    ch = zawiera_lan(test, test2);
    printf("%s znajduje sie w %s na pozycji %lu", test2, test, ch-test);
    return 0;
}

char * zawiera_lan(char *s1, char *s2)
{
    int i;
    while (*s1!='\0')
    {
        i=0;
        while (*(s1+i)==*(s2+i))
        {
            i++;
            if (*(s2+i)=='\0')
                return s1;
        }
        s1++;

    }
    return NULL;
}
