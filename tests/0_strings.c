#include "../holberton.h"
#include <stdio.h>

/**
 * Command to run test:
 * gcc ./tests/0_strings.c _printf.c handle_print.c  functions.c functions1.c functions2.c utils.c get_flags.c
 */
int main(void)
{
	int len;
	int len2;

	_printf("Hello Holberton\n");
	printf("Hello Holberton\n");

	_printf("Hello %s School...\n", "Holberton");
	printf("Hello %s School...\n", "Holberton");

	_printf("Hello %c %c %c %c %c\n", 'H', 'l', 'b', 't', 'n');
	printf("Hello %c %c %c %c %c\n", 'H', 'l', 'b', 't', 'n');

	_printf("Hello %%\n");
	printf("Hello %%\n");

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
}