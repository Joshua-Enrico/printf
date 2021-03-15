#ifndef HOL_H
#define HOL_H
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fn: The function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int);
};


/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fm_t: The function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(char fmt, va_list list, char buffer[], int flags, int width);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[], int flags, int width);
int print_string(va_list types, char buffer[], int flags, int width);
int print_percent(va_list types, char buffer[], int flags, int width);

/* Functions to print numbers */
int print_int(va_list types, char buffer[], int flags, int width);
int print_binary(va_list types, char buffer[], int flags, int width);
int print_unsigned(va_list types, char buffer[], int flags, int width);
int print_octal(va_list types, char buffer[], int flags, int width);
int print_hexadecimal(va_list types, char buffer[], int flags, int width);
int print_hexa_upper(va_list types, char buffer[], int flags, int width);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[], int flags, int width);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[], int flags, int width);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[], int flags, int width);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[], int flags, int width);

/* width handler */
int handle_write_char(char c, char buffer[], int flags, int width);
int write_number(int is_positive, int ind, char buffer[], int flags, int width);
int write_unsigned(int is_negative, int ind, char buffer[], int flags, int width);

/****************** UTILS ******************/
int len(char *);
int is_printable(char);
int append_hexa_code(char , char[], int);
int is_digit(char);

#endif /* HOL_H */
