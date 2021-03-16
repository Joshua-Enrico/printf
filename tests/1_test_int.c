#include "../holberton.h"

/**
 * Command to run test:
 * gcc ./_printf.c handle_print.c functions.c utils.c  get_flags.c get_width.c write_handlers.c tests/1_test_int.c
 * gcc ./_printf.c handle_print.c functions.c functions1.c functions2.c utils.c get_flags.c  tests/1_test_int.c
 */
int main(void)
{
    int len;
    int len1, len2;
    len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");

    len1 = printf("Length:[%d, %i]", len2, len2);
	printf(" => %d\n", len1);
	len2 = _printf("Length:[%d, %i]", len, len);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%d]", -762534);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%d]", -762534);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%d]", 762534);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%d]", 762534);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%d]", 5624);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%d]", 5624);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%+12d]", 5624);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%+12d]", 5624);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%+12d]", -5624);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%+12d]", -5624);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%- 12d]", 5624);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%- 12d]", 5624);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%- 12d]", 5624);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%- 12d]", 5624);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%+12d]", -5624);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%+12d]", -5624);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%-012d]", 120);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%-012d]", 120);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%-012d]", 324);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%-012d]", 324);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%-+012d]", 120);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%-+012d]", 120);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    len1 = printf("Negative:[%+012d]", 324);
	printf(" => %d\n", len1);
	len2 = _printf("Negative:[%+012d]", 324);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[%-9d]", 192);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[%-9d]", 192);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[% 7d]", 5624);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[% 7d]", 5624);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[% -8d]", 203);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[% -8d]", 203);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[% -8d]", 2431);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[% -8d]", 2431);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[% 08d]", 652);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[% 08d]", 652);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[% 0-8d]", 652);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[% 0-8d]", 652);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[% 08d]", -1230);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[% 08d]", -1230);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);

    // len1 = printf("Negative:[% 0-8d]", -1230);
	// printf(" => %d\n", len1);
	// len2 = _printf("Negative:[% 0-8d]", -1230);
	// printf(" => %d\n", len2);
	// printf("Correct: %d\n\n", len1 == len2);
    
}
