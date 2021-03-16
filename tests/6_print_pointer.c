#include <limits.h>
#include <stdio.h>
#include "../holberton.h"

/**
 * Command to run test:
 * gcc ./tests/6_print_pointer.c _printf.c handle_print.c functions.c functions1.c functions2.c utils.c get_flags.c
 */
int main(void)
{
	int len1, len2;

	int arr[3];

	void *addr;
	addr = (void *)0x7ffe637541f0;
	
	len1 = printf("Address:[%p]", addr);
	printf(" => %d\n", len1);
	len2 = _printf("Address:[%p]", addr);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Address: [%p] NULL addrs", NULL);
	printf(" => %d\n", len1);
	len2 = _printf("Address: [%p] NULL addrs", NULL);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Address: [%p] INT addrs", &len1);
	printf(" => %d\n", len1);
	len2 = _printf("Address: [%p] INT addrs", &len1);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Address: [%p] addrs", &len2);
	printf(" => %d\n", len1);
	len2 = _printf("Address: [%p] addrs", &len2);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Address: [%p] ARR addrs", arr);
	printf(" => %d\n", len1);
	len2 = _printf("Address: [%p] ARR addrs", arr);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Address: [%p] addrs", &arr[1]);
	printf(" => %d\n", len1);
	len2 = _printf("Address: [%p] addrs", &arr[1]);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);

	len1 = printf("Address: [%p] addrs", &arr[0]);
	printf(" => %d\n", len1);
	len2 = _printf("Address: [%p] addrs", &arr[0]);
	printf(" => %d\n", len2);
	printf("Correct: %d\n\n", len1 == len2);
}