#include "main.h"

/**
 * print_char - help function print
 *  @c: the parameter
 *  Return: number of char printed
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - help fuction print
 *  @c: the string to be printed
 *  Return: the number of string printed
 */

int print_string(char *c)
{
	int len = 0;

	while (c[len] != '\0')
		len++;

	return (write(1, c, len));
}
/**
 * _printf - a function print to handle c, s and %
 * @format: the first argument in variadic
 * Return: the number of char printed
 */
int _printf(const char *format, ...)
{
	int char_printed = 0;
	va_list arg_list;

	va_start(arg_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_printed++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_printed++;
			}
			else if (*format == 'c')
			{
				char_printed += print_char(va_arg(arg_list, int));
			}
			else if (*format == 's')
			{
				char_printed += print_string(va_arg(arg_list, char *));
			}
			else if ((format[-1] == '%') &&
					((format[-2] == '%') || ((format[-1] != '%'))))
				write(1, format, 1);
		}
		format++;
	}
	va_end(arg_list);
	return (char_printed);
}
