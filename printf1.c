#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *str_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
	{
		format++;
		if (*format == 'c')
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			count++;
		}
		else if (*format == 's')
		{
			str_arg = va_arg(args, char *);
			while (*str_arg)
			{
				write(1, str_arg, 1);
				str_arg++;
				count++;
			}
		}
		else if (*format == '%')
		{
			write(1, "%", 1);
			count++;
		}
	}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
