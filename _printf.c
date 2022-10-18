#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * _printf - based on format specifiers print
 * to the standard output
 *
 * @format: character string
 * Return: int
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, j, n;
	int value = 0;
	int chars = 0;

	speci selector[] = {

		{"c", character},
		{"s", string},
		{"%", percent},
		{"d", printDecimal},
		{"i", printDecimal},
		{NULL, NULL}
	};

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; selector[j].specifier != NULL; j++)
			{
				if (format[i + 1] == *selector[j].specifier)
				{
					value = selector[j].fun(args);
					if (value == -1)
						return (-1);
					chars += value;
					break;
				}
			}
			if (selector[j].specifier == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write(format[i]);
					_write(format[i + 1]);
					chars += 2;
				}
				else
					return (-1);
			}
			if (selector[j].specifier == NULL && format[i + 1] == ' ')
			{
				while (format[i + 1 + n] == ' ')
					n++;
				_write(' ');
				chars++;
				for (j = 0; selector[j].specifier != NULL; j++)
				{
					if (format[i + 1 + n] == *selector[j].specifier)
					{
						value = selector[j].fun(args);
						if (value == -1)
							return (-1);
						chars += value;
						break;
					}
				}
			}
			i++;
		}
		else
		{
			_write(format[i]);
			chars++;
		}

	}
	va_end(args);
	return (chars);
}
