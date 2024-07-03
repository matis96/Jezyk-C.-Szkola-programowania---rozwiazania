//zad3.c
#include <stdio.h>
#include <iso646.h>
int main(void)
{
    int x;
    int p = 0;
    int suma_p=0;
    int np = 0;
    int suma_np=0;
    float srednia_p, srednia_np;
    do
    {
      scanf("%d", &x);
      if (x%2==0 and x!=0)
        {
            suma_p += x;
            p++;
        }
      if (x%2!=0 and x!=0)
      {
          suma_np += x;
          np++;
      }
    } while (x!=0);
    if (p>0)
    {
        srednia_p = suma_p/p;
        printf("Wpisano %d l. parzystych. Ich srednia to %.2f\n", p, srednia_p);
    }
    if (np>0)
    {
        srednia_np = suma_np/np;
        printf("Wpisano %d l. nieparzystych. Ich srednia to %.2f", np, srednia_np);
    }


    return 0;
}
