#include "shell.h"

/**
 * inter_ac - returns true if shell is interactive mode
 * @inf: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int inter_ac(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_del - checks if character is a delimeter
 * @ch: the char to check
 * @del: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_del(char ch, char *del)
{
	while (*del)
		if (*del++ == ch)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int i, sin = 1, flg = 0, out;
	unsigned int res = 0;

	for (i = 0;  str[i] != '\0' && flg != 2; i++)
	{
		if (str[i] == '-')
			sin *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flg = 1;
			res *= 10;
			res += (str[i] - '0');
		}
		else if (flg == 1)
			flg = 2;
	}

	if (sin == -1)
		out = -res;
	else
		out = res;

	return (out);
}
