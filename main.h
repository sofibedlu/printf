#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct select - select specifier
 *
 * @specifier: characters after %
 * @fun: pointer to function
 */
struct select
{
	char *specifier;
	int (*fun)(va_list);
};
typedef struct select speci;
int printDecimal(va_list args);
int character(va_list args);
int string(va_list args);
int percent(va_list args);
int _printf(const char *format, ...);
int _write(char c);

#endif
