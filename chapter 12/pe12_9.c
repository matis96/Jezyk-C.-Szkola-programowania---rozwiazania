//zad9.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 400

char ** get_words(int );
static void isword(char **, char **);

int main(void)
{
    int i, n;
    char ** words;
    printf("Podaj liczbe slow do wprowadzenia: ");
    if ((scanf("%d", &n)) && n>0)
    {
        while (getchar()!='\n')
            continue;
        words = get_words(n);

        printf("Oto wprowadzone slowa:\n");
        for (i=0; i<n; i++)
            printf("%s\n", words[i]);
    }
    free(words);
    return 0;
}

char ** get_words(int n)
{
    char tmp[LIMIT];
    char *word_start;
    char *word_end;
    int word_length;
    int i;

    char **word_array = (char **)malloc(n*sizeof(char *));
    printf("Wprowadz %d slow:\n", n);
    word_start = fgets(tmp, LIMIT, stdin);

    for (i=0; i<n; i++)
    {
        isword(&word_start, &word_end);

        if (*word_start =='\0')
            break;

        word_length = word_end-word_start;
        word_array[i]=(char *)malloc((word_length+1)*sizeof(char));
        if (word_array[i]!= NULL)
        {
            strncpy(word_array[i], word_start, word_length);
            word_array[i][word_length]='\0';
        }
        word_start = word_end;

    }

    if (i<n)
        for (;i<n; i++)
        {
            word_array[i]= (char *)malloc(sizeof(char));
            word_array[i]='\0';
        }

    return word_array;
}

static void isword(char **start, char **end)
{
    while (isspace(**start))
        (*start)++;
    *end = *start;
    while (!(isspace(**end)) && **end!='\0')
        (*end)++;
}
