//zad2.c

#include <stdio.h>

#define SR_HARM2(X,Y)   2/((1/X)+(1/Y))

int main(void)
{
    double x = 5;
    double y = 9;
    printf("%.2f", SR_HARM2(x, y));
    return 0;
}
