#include <stdio.h>
#include <ctype.h>
char get_first(void);

int main(void)
{
	char fnc; //The first non-whitespace character

	printf("Enter your characters: ");
	fnc = get_first();
	printf("The first non-whitespace character encountered is %c.\n", fnc);

	return 0;
}

char get_first(void)
{
	char ch;

	while (!(isprint(ch = getchar()))||ch==' ')
		continue;
	while (getchar() != '\n')
		continue;

	return ch;
}
