#include <unistd.h>
/**
 * _write - print on the standarde output
 * @c: character
 * Return: bytes;
 */

int _write(char c)
{
	return (write(1, &c, 1));
}
