#include "main.h"

/**
 * get_specifier - format function
 * @s: format str
 *
 * Return: numb of bytes
 */

int (*get_specifier(char *S))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", printf_char},
		{"d", printf_char},
		{"i", printf_char},
		{"s", printf_char},
		{"%", printf_char},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - format function
 * @s: str
 * @ap: argument
 *@params: parameter struct
 *
 * Return: bytes no.
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}
