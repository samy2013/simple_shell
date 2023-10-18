#include "shell.h"

/**
 * _strcpy - copy string
 * @dst: the destination
 * @e: the source
 *
 * Return: pointer of destination
 */
char *_strcpy(char *dst, char *srce)
{
	int i = 0;

	if (dst == srce || srce == 0)
		return (dst);
	while (srce[i])
	{
		dst[i] = srce[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

/**
 * _strdup - duplicate string
 * @st: string to duplicate
 *
 * Return: duplicated string pointer
 */
char *_strdup(const char *st)
{
	int len = 0;
	char *re;

	if (st == NULL)
		return (NULL);
	while (*st++)
		len++;
	re = malloc(sizeof(char) * (len + 1));
	if (!re)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--st;
	return (re);
}


/**
 *_puts - prints input string
 *@stri: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *stri)
{
	int i = 0;

	if (!stri)
		return;
	while (stri[i] != '\0')
	{
		_putchar(stri[i]);
		i++;
	}
}


/**
 * _putchar - write character ch to stdout
 * @ch: character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}
