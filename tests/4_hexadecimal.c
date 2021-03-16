#include <limits.h>
#include <stdio.h>
#include "../holberton.h"

/**
 * Command to run test:
 * gcc ./tests/4_hexadecimal.c _printf.c handle_print.c funciones.c functions1.c functions2.c utils.c
 */
int main(void)
{
	unsigned int ui;
	ui = (unsigned int)INT_MAX + 1024;
	int len1, len2;

	len1 = printf("Unsigned hexadecimal:[%x, %X]", ui, ui);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", ui, ui);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", -ui, -ui);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", -ui, -ui);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", -12932, -12932);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", -12932, -12932);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", 10000000, 10000000);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", 10000000, 10000000);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", 12390, 12390);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", 12390, 12390);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", -12390, -12390);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", -12390, -12390);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", -999999999999000000000000000, -999999999999000000000000000);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", -999999999999000000000000000, -999999999999000000000000000);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", -124903284, -124903284);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", -124903284, -124903284);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", 64, 64);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", 64, 64);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", 6, 6);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", 6, 6);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", 16, 16);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", 16, 16);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", 9223372036854775807, 9223372036854775807);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", 9223372036854775807, 9223372036854775807);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);
	
	len1 = printf("Unsigned hexadecimal:[%x, %X]", -9223372036854775808, -9223372036854775808);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", -9223372036854775808, -9223372036854775808);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Unsigned hexadecimal:[%x, %X]", 0, 0);
	printf(" => %d\n", len1);
	len2 = _printf("Unsigned hexadecimal:[%x, %X]", 0, 0);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);
}
