#include "../holberton.h"
#include <stdio.h>

/**
 * Command to run test:
 * gcc ./tests/0_printf_strings.c *.c
 */

int main(void)
{
	int len1, len2;

	len1 = printf("Hello", "");
	printf(" => %d\n", len1);
	len2 = _printf("Hello", "");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);


	len1 = printf("Hello %s ... %s", "...");
	printf(" => %d\n", len1);
	len2 = _printf("Hello %s ... %s", "...");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Hello %s ... %p %r", "Holberton");
	// printf(" => %d\n", len1);
	// len2 = _printf("Hello %s ... %p %r", "Holberton");
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);


	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Hello %c %c %c %c %c", 'H', 'l', 'b', 't', 'n');
	printf(" => %d\n", len1);
	len2 = _printf("Hello %c %c %c %c %c", 'H', 'l', 'b', 't', 'n');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Hello %%");
	printf(" => %d\n", len1);
	len2 = _printf("Hello %%");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Unknown:[%r]");
	// printf(" => %d\n", len1);
	// len2 = _printf("Unknown:[%r]");
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);
}
