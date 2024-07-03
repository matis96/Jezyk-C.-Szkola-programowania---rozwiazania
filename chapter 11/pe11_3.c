//zad3.c
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
char * slowo(char *);
int main(void)
{
    char test[20];
    slowo(test);
    puts(test);
    return 0;
}
char * slowo(char *s)
{
   bool word = false;
   char ch;
   int i=0;
   while ((ch = getchar())!=EOF)
   {
       if(isspace(ch))
        {
            if (word)
                break;
            else
            {
                continue;
            }

        }
        if (!word)
            word = true;
        *(s+i)=ch;
        i++;
   }
   if (ch != '\n')
	while ((ch = getchar()) != '\n')
	    continue;
   return s;
}
