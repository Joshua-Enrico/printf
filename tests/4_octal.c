#include <limits.h>
#include <stdio.h>
#include "../holberton.h"

/**
 * Command to run test:
 * gcc ./tests/4_octal.c _printf.c handle_print.c functions.c functions1.c functions2.c utils.c get_flags.c
 */
int main(void)
{
	unsigned int ui;
	ui = (unsigned int)INT_MAX + 1024;
	int len1, len2;

	len1 = printf("Unsigned octal:[%o]", ui);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", ui);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", -12932);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", -12932);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", 10000000);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", 10000000);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", 12390);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", 12390);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", -12390);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", -12390);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", -999999999999000000000000000);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", -999999999999000000000000000);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", -124903284);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", -124903284);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", 64);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", 64);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", 6);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", 6);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", 8);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", 8);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", 9223372036854775807);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", 9223372036854775807);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);
	
	len1 = printf("Unsigned octal:[%o]", -9223372036854775808);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", -9223372036854775808);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned octal:[%o]", 0);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned octal:[%o]", 0);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);
}