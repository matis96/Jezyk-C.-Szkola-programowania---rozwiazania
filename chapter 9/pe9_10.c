//zad10.c
#include <stdio.h>

void to_base_n(int n, int base);

int main(void)
{
    to_base_n(129,8);
    return 0;
}

void to_base_n(int n, int base)
{
	int r;
    r = n % base;
    if (n >= base)
    to_base_n(n / base, base);
    putchar(r+'0');
    return;

}
