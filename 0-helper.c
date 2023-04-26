#include "main.h"

int printf_percent(__attribute__((unused))va_list list)
{
	_write_char('%');
	return (1);
}

/**
 * printf_int - Prints a int
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int printf_int(va_list list)
{
	_write_char('i');
	return (1);
}

/**
 * printf_string - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int printf_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_write_char(str[i]);
	return (i);
}
