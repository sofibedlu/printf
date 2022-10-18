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
	int numChars;

	speci selector[] = {

		{"c", character},
		{"s", string},
		{"%", percent},
		{"d", printDecimal},
		{"i", printDecimal},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	numChars = checkForSpeci(format, selector, args);
	va_end(args);
	return (numChars);
}
