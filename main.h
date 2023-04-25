#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE     1
#define CONVERT_UNSIGNED      2


/**
 * struct parameters - params struct
 * @precision: precision specified
 * @unsign: unsigned value
 */

typedef struct parameters
{
	unsigned int unsign :		1;

	unsigned int precision;
} params_t;

/**
 * struct specifier - struct
 * @specifier: specifier format
 * @f: function
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int printf_pointer(va_list ap, params_t *params);
int printf_percent(va_list ap, params_t *params);
int printf_int(va_list ap, params_t *params);
int printf_char(va_list ap, params_t *params);
int printf_string(va_list ap, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t params);

int _putchar(int c);
int _puts(char *str);

int _printf(const char *format, ...);

void init_params(params_t *params, va_list ap);

int get_modifier(char *s, params_t *params);
int print_from_to(char *start, char *stop, char *except);
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

#endif

