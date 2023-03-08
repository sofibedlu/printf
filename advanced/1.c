Handle the following custom conversion specifiers:

b: the unsigned int argument is converted to binary

/***/
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%b\n", 98);
    return (0);
}

/****/
alex@ubuntu:~/c/printf$ ./a.out
1100010
