#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * character - print charcter type;
 * @args: argument
 * Return: int
 */
int character(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}
/**
 * string - print string
 * @args: argument
 * Return: int
 */
int string(va_list args)
{
	char *s;
	int i = 0;

	s = va_arg(args, char *);
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			_write(s[i]);
			i++;
		}
		return (i);
	}
	return (0);
}
/**
 * percent - print %
 * @args: argument
 * Return: int
 */
int percent(__attribute__((unused))va_list args)
{
	_write('%');
	return (1);
}
/**
 * printDecimal - print integer;
 * @args: argument
 * Return: int
 */
int printDecimal(va_list args)
{
	int i = 0;
	int num;
	int div = 1;

	num = va_arg(args, int);
	if (num < 0)
	{
		_write('-');
		i = i + 1;
		num = num * -1;
	}
	while (num / div > 9)
	{
		div = div * 10;
	}
	while (div != 0)
	{
		_write('0' + num / div);
		num = num % div;
		div = div / 10;
		i++;
	}
	return (i);
}
