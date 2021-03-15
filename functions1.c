#include "holberton.h"
#include <stdio.h>


/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[], int flags)
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);

	if (num == 0)
		return (write(1, "0", 1));

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write(1, &buffer[i], BUFF_SIZE - i) - 1);
}

/*************** PRINT UNSIGNED NUMBER IN OCTAL  ******************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags)
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);

	if (num == 0)
		return (write(1, "0", 1));

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH)
		buffer[i--] = '0';

	i++;

	return (write(1, &buffer[i], BUFF_SIZE - i) - 1);
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL******************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 *
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x'));
}

/*********** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X'));
}

/*********** PRINT HEXX NUM IN LOWER OR UPPER ************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
			   int flags, char flag_ch)
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);

	if (num == 0)
		return (write(1, "0", 1));

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write(1, &buffer[i], BUFF_SIZE - i) - 1);
}
