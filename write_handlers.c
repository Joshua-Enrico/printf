#include "holberton.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * Return: Number of chars printed
 */
int handle_write_char(char c, char buffer[], int flags, int width)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * Return: Number of chars printed
 */
int write_number(int is_negative, int ind, char buffer[], int flags, int width)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-', length++;
	else if (flags & F_PLUS)
		extra_ch = '+', length++;
	else if (flags & F_SPACE)
		extra_ch = ' ', length++;

	return (write_num(ind, buffer, flags, width, length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @bff: Buffer
 * @flgs: Flags
 * @w: width
 * @l: Number length
 * @pd: Pading char
 * @ex_c: Extra char
 *
 * Return: Number of printed chars
 */
int write_num(int ind, char bff[], int flgs, int w, int l, char pd, char ex_c)
{
	int i, padd_start = 1;

	if (w > l)
	{
		for (i = 1; i < w - l + 1; i++)
			bff[i] = pd;
		bff[i] = '\0';
		if (flgs & F_MINUS && pd == ' ')/* Asign extra char to left of buffer */
		{
			if (ex_c)
				bff[--ind] = ex_c;
			return (write(1, &bff[ind], l) +
					write(1, &bff[1], i - 1));
		}
		else if (!(flgs & F_MINUS) && pd == ' ')/* extra char to left of buffer */
		{
			if (ex_c)
				bff[--ind] = ex_c;
			return (write(1, &bff[1], i - 1) +
				write(1, &bff[ind], l));
		}
		else if (!(flgs & F_MINUS) && pd == '0')/* extra char to left of padding */
		{
			if (ex_c)
				bff[--padd_start] = ex_c;
			return (write(1, &bff[padd_start], i - padd_start) +
				write(1, &bff[ind], l - (1 - padd_start)));
		}
	}
	if (ex_c)
		bff[--ind] = ex_c;
	return (write(1, &bff[ind], l));
}

int write_unsgnd(int is_negative, int ind,
char buffer[], int flags, int width)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) +
					write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) +
					write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}
