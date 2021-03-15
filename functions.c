#include "holberton.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width)
{
	char c = va_arg(types, int);

	return handle_write_char(c, buffer, flags, width);
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
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

	return write(1, &buffer[0], length);
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags, int width)
{
	return (write(1, "%%", 1));
}

int print_int(va_list types, char buffer[], int flags, int width)
{
	int length = 0, i = BUFF_SIZE - 2;
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
	
	return write_number(is_negative, i, buffer, flags, width);
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[], int flags, int width)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

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

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * 
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[], int flags, int width)
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);

	if (num == 0)
		return write(1, "0", 1);

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return write_unsigned(0, i, buffer, flags, width);
	// return (write(1, &buffer[i], BUFF_SIZE - i) - 1);
}


/************************* PRINT UNSIGNED NUMBER IN OCTAL  *************************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags, int width)
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);

	if (num == 0)
		return write(1, "0", 1);

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


/************************* PRINT UNSIGNED NUMBER IN HEXADECIMAL *************************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * 
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width)
{
	return print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width);
}


/************************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL *************************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * 
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width)
{
	return print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X', width);
}


/************************* PRINT HEXX NUM IN LOWER OR UPPER *************************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * 
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width)
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);

	if (num == 0)
		return write(1, "0", 1);

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

/************************* PRINT POINTER *************************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * 
 * Return: Number of chars printed
 */
int print_pointer(va_list types, char buffer[], int flags, int width)
{
	int i = BUFF_SIZE - 2;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	if (addrs == NULL)
		return write(1, "(nil)", 5);

	buffer[BUFF_SIZE - 1] = '\0';
	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[i--] = map_to[num_addrs % 16];
		num_addrs /= 16;
	}

	buffer[i--] = 'x';
	buffer[i--] = '0';

	if (flags & F_PLUS)
		buffer[i--] = '+';
	else if (flags & F_SPACE)
		buffer[i--] = ' ';

	i++;

	return (write(1, &buffer[i], BUFF_SIZE - i) - 1);
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * 
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		return write(1, "(null)", 6);

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * 
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[], int flags, int width)
{
	char *str;
	int i, count = 0;

	str = va_arg(types, char *);

	if (str == NULL)
	{
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
	;
	for(i = i - 1; i >= 0; i--)
	{
		char z = str[i];
		write(1, &z, 1);
		count++;
	}
	return(count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * 
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer [], int flags, int width)
{
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(types, char *);
    if (str == NULL)
        str = "(AHYY)";
    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
              x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[j])
        {
          x = str[i];
            write(1, &x, 1);
            count++;
        }
    }
    return (count);

}
