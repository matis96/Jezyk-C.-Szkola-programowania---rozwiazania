//zad6.c
#include <stdio.h>
void szereg(double *x, double *y, double *z);
int main(void)
{
    double x = 5.81;
    double y = 4.89;
    double z = 3.81;
    szereg(&x, &y, &z);
    printf("%.2f %.2f %.2f", x,y,z);
    return 0;
}
void szereg(double *x, double *y, double *z)
{
   double temp;
   if (*x>*y)
   {
       temp = *y;
       *y=*x;
       *x=temp;

   }
   if (*y>*z)
   {
       temp = *z;
       *z=*y;
       *y=temp;

       if (*x>*y)
       {
           temp = *y;
           *y=*x;
           *x=temp;

       }
   }
}
