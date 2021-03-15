#include "holberton.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @list: List of arguments to be printed
 */
int get_width(const char *format, int *i)
{
	int j, curr_i;
	int width = 0;
	
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else
		{
			break;
		}
	}

	*i = curr_i - 1;

	return (width);
}