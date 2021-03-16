#include <limits.h>
#include <stdio.h>
#include "../holberton.h"

/**
 * Command to run test:
 * gcc ./tests/4_unsigned.c _printf.c handle_print.c functions.c utils.c get_flags.c get_width.c write_handlers.c
 */
int main(void)
{
	unsigned int ui;
	ui = (unsigned int)INT_MAX + 1024;
	int len1, len2;

	len1 = printf("Unsigned:[%u]", ui);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%u]", ui);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[%u]", -12932);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%u]", -12932);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[%u]", 10000000);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%u]", 10000000);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[%u]", -999999999999000000000000000);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%u]", -999999999999000000000000000);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[%u]", 9223372036854775807);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%u]", 9223372036854775807);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);
	
	len1 = printf("Unsigned:[%u]", -9223372036854775808);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%u]", -9223372036854775808);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[%u]", 0);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%u]", 0);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[%+-10u]", 231);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%+-10u]", 231);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[%+- 010u]", 231);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[%+- 010u]", 231);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned:[% 010u]", 231);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned:[% 010u]", 231);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Unsigned:[%# -010o]", 231);
	// printf(" => %d\n", len1);
	// len2 = _printf("Unsigned:[%# -010o]", 231);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Unsigned:[% #010x]", 231);
	// printf(" => %d\n", len1);
	// len2 = _printf("Unsigned:[% #010x]", 231);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);
}