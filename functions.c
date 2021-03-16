#include "holberton.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[], int flags, int width)
{
	int length = 0, i = 0;

	char *str = va_arg(types, char *);

	if (str == NULL)
		str = "(null)";

	for (; str[length] != '\0'; length++)
		buffer[length] = str[length];

	buffer[length] = '\0';

	if (width > length)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - length; i++)
			buffer[BUFF_SIZE - i - 2] = ' ';

		if (flags & F_MINUS)
			return (write(1, &buffer[0], length) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - length));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - length) +
					write(1, &buffer[0], length));
	}

	/* HANDLE SPECIAL CASES WHEN PRINTING STR*/
	/* Pending ...... */

	return (write(1, &buffer[0], length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags, int width)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	write(1, "%%", 1);
	return(1);
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[], int flags, int width)
{

	int i = BUFF_SIZE - 2;

	int is_negative = 0;
	int n = va_arg(types, int);
	unsigned int num;

	if (n == 0)
		return (write(1, "0", 1));

	buffer[BUFF_SIZE - 1] = '\0';

	num = (unsigned int)n;

	if (n < 0)
	{
		num = (unsigned int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[], int flags, int width)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
