#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * checkForSpeci - look gor the correct char in the struct
 * @format: the string to look for
 * @args: arguments
 * @selector: struct array
 * Return: number of charactor
 */
int checkForSpeci(const char *format, speci selector[], va_list args)
{
	int i, j, value, chars = 0;

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
			i++;
		}
		else
		{
			_write(format[i]);
			chars++;
		}
	}
	return (chars);
}
