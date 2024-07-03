//zad11.c
#include <stdio.h>
int Fibonacci(int N);
int main (void)
{
    int k = Fibonacci(10);
    printf("%d", k);
    return 0;
}

int Fibonacci(int N)
{
    int Fib1 = 1;
    int Fib2 = 1;
    int temp;
    int n;
    for (n=2; n<N; n++)
    {
        temp = Fib1+Fib2;
        Fib1=Fib2;
        Fib2=temp;
    }
    return temp;
}
