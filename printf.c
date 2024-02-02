#include "main.h"

/**
 * _print_char - Prints a character
 * @args: The list of arguments
 * @count: The current count of printed characters
 *
 * Return: The updated count of printed characters
 */
static int _print_char(va_list args, int count)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * _print_string - Prints a string
 * @args: The list of arguments
 * @count: The current count of printed characters
 *
 * Return: The updated count of printed characters
 */
static int _print_string(va_list args, int count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}

	return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				count = _print_char(args, count);
			}
			else if (*format == 's')
			{
				count = _print_string(args, count);
			}
			else if (*format == '%')
			{
				count += _putchar('%');
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}

