#include <limits.h>
#include <stdio.h>
#include "../holberton.h"

/**
 * Command to run test:
 * gcc ./tests/8_flag_chars.c _printf.c handle_print.c get_flags.c get_width.c functions.c utils.c
 * gcc ./tests/8_flag_chars.c _printf.c handle_print.c get_flags.c functions.c functions1.c functions2.c utils.c
 */
int main(void)
{
	int len1, len2;
	int addrs[1];

	len1 = printf("Flag: [%+ d]", 1230);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%+ d]", 1230);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%+ d]", -231);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%+ d]", -231);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [% d]", 239);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [% d]", 239);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [% i]", 490);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [% i]", 490);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [% i]", -43);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [% i]", -43);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%+ p]", addrs);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%+ p]", addrs);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [% p]", addrs);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [% p]", addrs);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%#o]", 231);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%#o]", 231);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%#x]", 231);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%#x]", 231);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%#X]", 231);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%#X]", 231);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("% 20hu", 4);
	// printf(" => %d\n", len1);
	// len1 = printf("% 45hu", 4);
	// printf(" => %d\n", len1);
	// len1 = printf("%045hu", 4);
	// printf(" => %d\n", len1);
	// len1 = printf("%50hu", 4);
	// printf(" => %d\n", len1);
	// len1 = printf("%3hu03", 3);
	// printf(" => %d\n", len1);

	// printf("%lu\n", 23);
	// printf("%-+lu\n", 23);
	// printf("%-+-+-+llu\n", 23);
	// printf("%#x\n", 0);
	// printf("%#x\n", 1);

	// printf("%+###6x\n", 16);
}