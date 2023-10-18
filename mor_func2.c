#include "shell.h"

/**
 * _erratoi - convert string to integer
 * @str:  string will convert
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *str)
{
	int i = 0;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	for (i = 0;  str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * prnt_err - prints an error message
 * @inf: the parameter & return info struct
 * @es: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void prnt_err(info_t *inf, char *es)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(es);
}

/**
 * print_dec - function prints decimal number base 10
 * @inp: input
 * @filedes: filedescriptor to write to
 * Return: number of characters printed
 */
int print_dec(int inp, int filedes)
{
	int (*__putchar)(char) = _putchar;
	int i, coun = 0;
	unsigned int _abs_, current;

	if (filedes == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		coun++;
	}
	else
		_abs_ = inp;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			coun++;
		}
		current %= i;
	}
	__putchar('0' + current);
	coun++;

	return (coun);
}

/**
 * conv_numb - converter function
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *conv_numb(long int numb, int bas, int flg)
{
	static char *arr;
	static char buffer[50];
	char sin = 0;
	char *ptr;
	unsigned long n = numb;

	if (!(flg & CONVERT_UNSIGNED) && numb < 0)
	{
		n = -numb;
		sin = '-';

	}
	arr = flg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % bas];
		n /= bas;
	} while (n != 0);

	if (sin)
		*--ptr = sin;
	return (ptr);
}

/**
 * rem_com - function replaces first instance of '#' with '\0'
 * @add: address of the string to modify
 *
 * Return: Always 0;
 */
void rem_com(char *add)
{
	int i;

	for (i = 0; add[i] != '\0'; i++)
		if (add[i] == '#' && (!i || add[i - 1] == ' '))
		{
			add[i] = '\0';
			break;
		}
}
