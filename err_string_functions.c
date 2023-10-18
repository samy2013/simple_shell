#include "shell.h"

/**
 *_eputs - prints an input string
 * @stri: the string to be printed
 * Return: Nothing
 */
void _eputs(char *stri)
{
	int i = 0;

	if (!stri)
		return;
	while (stri[i] != '\0')
	{
		_eputchar(stri[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @ch: The character to print
 * @fdes: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char ch, int fdes)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fdes, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @stri: the string to be printed
 * @fdes: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *stri, int fdes)
{
	int i = 0;

	if (!stri)
		return (0);
	while (*stri)
	{
		i += _putfd(*stri++, fdes);
	}
	return (i);
}
