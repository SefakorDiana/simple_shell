#include "main.h"

/**
 * _fput_number_helper - Prints number
 *
 * @fd: A file descriptor of the file that
 * the given number will be printed in
 * @number: number to be printed
 * Return: number of printed digits
 */
int _fput_number_helper(int fd, int number)
{
	int ret;
	char c;

	if (number == 0)
		return (0);
	ret = _fput_number_helper(fd, number / 10);
	c = number % 10 + 48;
	write(fd, &c, 1);
	return (1 + ret);
}

/**
 * _fput_number - Prints a given
 * number into a given file
 *
 * @fd: file descriptor
 * @number: to be printed
 * Return: the length of the printed
 * chars
 */
int _fput_number(int fd, int number)
{
	int printed;

	printed = 0;
	if (!number)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (number < 0)
	{
		write(fd, "-", 1);
		printed = 1;
		number *= -1;
	}
	return (printed + _fput_number_helper(fd, number));
}

/**
 * _fputs - Prints a  string
 * into given file descriptor
 *
 * @fd: file descriptor
 * @s: string to be printed
 * Return: number of character printed
 */
int _fputs(int fd, const char *s)
{
	return (write(fd, s, _strlen(s)));
}

/**
 * _fprint - Prints a number and string using
 * format specifiers
 *
 *
 * @fd: file descriptor
 * @format: format to be printed to given fd
 * and change place holder to specific values
 * Return: number of printed characters
 */
int _fprint(int fd, const char *format, ...)
{
	va_list ap;
	int index, print;
	int is_percent;

	va_start(ap, format);
	is_percent = 0;
	index = 0;
	print = 0;
	while (format[index])
	{
		if (format[index] == '%')
			is_percent = 1;
		else
		{
			if (is_percent)
			{
				if (format[index] == 'd')
					print += _fput_number(fd, va_arg(ap, int));
				else if (format[index] == 's')
					print += _fputs(fd, va_arg(ap, char *));
				else
					print += write(fd, &format[index - 1], 2);
			}
			else
				print += write(fd, format + index, 1);
			is_percent = 0;
		}
		index++;
	}
	va_end(ap);
	return (print);
}
