#include "holberton.h"

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			flags = get_flags(format, &i);
			width = get_width(format, &i);
			/* precision = handle_precision(); */
			/* size = handle_size(); */
			/* Last one handles type and print */
			++i;
			printed = handle_print(format, &i, list, buffer, flags, width);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	va_end(list);

	return (printed_chars);
}
