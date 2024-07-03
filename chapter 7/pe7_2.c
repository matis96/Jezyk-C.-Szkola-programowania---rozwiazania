//zad2.c
#include <stdio.h>
int main(void)
{
   char ch;
   int licznik=0;

   while ((ch=getchar())!='#')
   {
       printf("%c - %d, ", ch, ch);
       licznik++;
       if (licznik % 8 ==0)
        printf("\n");
   }
   return 0;
}
