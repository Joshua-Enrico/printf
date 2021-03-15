#include "holberton.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments
 * @list: List of arguments to be printed
 * @flags: Calculates active flags
 * Return: 1 or 2;
 */
int handle_print(char fmt, va_list list, char buffer[], int flags, int width)
{
    int i, printed_chars = -1;
    fmt_t fmt_types[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'i', print_int},
        {'d', print_int},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hexadecimal},
        {'X', print_hexa_upper},
        {'p', print_pointer},
        {'S', print_non_printable},
        {'r', print_reverse},
        {'R', print_rot13string},
        {'\0', NULL}
    };

    for (i = 0; fmt_types[i].fmt != '\0'; i++)
        if (fmt == fmt_types[i].fmt)
        {
            printed_chars = fmt_types[i].fn(list, buffer, flags, width);
            break;
        }

    /* UNKNOWN */
    if (fmt_types[i].fmt == '\0')
    {
        write(1, "%%", 1);
        write(1, &fmt, 1);
        return 2;
    }

	return (printed_chars);
}
