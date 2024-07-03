//zad1.c
#include <stdio.h>
int main(void)
{
    char litery[26];
    char i;
    int j;

    for (i='a', j = 0;j<26; i++, j++){	
	litery[j]=i;
        printf("%c", litery[j]);}
    return 0;
}
