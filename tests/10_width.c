#include <limits.h>
#include <stdio.h>
#include "../holberton.h"

/**
 * Command to run test:
 * gcc ./tests/10_width.c _printf.c handle_print.c get_flags.c get_width.c  write_handlers.c functions.c utils.c
 */
int main(void)
{
	int len1, len2;
	int addrs[1];

	len1 = printf("Flag: [%+5c]", 'H');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%+5c]", 'H');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%-5c]", 'H');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%-5c]", 'H');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%+05c]", 'H');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%+05c]", 'H');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%-05c]", 'H');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%-05c]", 'H');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%+0c]", 'H');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%+0c]", 'H');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%-0c]", 'H');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%-0c]", 'H');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%-0c]", '\0');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%-0c]", '\0');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%-8c]", '\0');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%-8c]", '\0');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%8c]", '\0');
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%8c]", '\0');
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%10s]", NULL);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%10s]", NULL);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%-10s]", NULL);
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%-10s]", NULL);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%-10s]", "Hey");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%-10s]", "Hey");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%10s]", "Hey");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%10s]", "Hey");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%2s]", "Hey");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%2s]", "Hey");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%2s]", "\0");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%2s]", "\0");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%s]", "\0");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%s]", "\0");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [%s]", "\0Hello");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [%s]", "\0Hello");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);


	len1 = printf("Flag: [% -10%]", "\0Hello");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [% -10%]", "\0Hello");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Flag: [% 10%]", "World!");
	printf(" => %d\n", len1);
	len2 = _printf("Flag: [% 10%]", "World!");
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [%+5d]", 1230);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [%+5d]", 1230);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [%+ 6d]", -231);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [%+ 6d]", -231);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [% 2d]", 239);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [% 2d]", 239);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [% 7i]", 490);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [% 7i]", 490);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [% 5i]", -43);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [% 5i]", -43);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [%+ 9p]", addrs);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [%+ 9p]", addrs);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [% 12p]", addrs);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [% 12p]", addrs);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [%#16o]", 231);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [%#16o]", 231);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [%#16x]", 231);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [%#16x]", 231);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// len1 = printf("Flag: [%#9X]", 231);
	// printf(" => %d\n", len1);
	// len2 = _printf("Flag: [%#9X]", 231);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

	// printf("%5c\n", 'H');
	// printf("%+5d\n", 23);
	// printf("%#7o\n", 93);
	// printf("%#7x\n", 54);
	// printf("%#7X\n", 34);
	// printf("%-#19p 3498\n", &len1);

	// printf("%0d\n", 34);
}