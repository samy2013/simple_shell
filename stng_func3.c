#include "shell.h"

/**
 **_strncpy - copy string
 *@des: destination string to be copied to
 *@sr: source string
 *@n: number of characters to be copied
 *Return: concatenated string
 */
char *_strncpy(char *des, char *sr, int n)
{
	int i, k;
	char *str = des;

	i = 0;
	while (sr[i] != '\0' && i < n - 1)
	{
		des[i] = sr[i];
		i++;
	}
	if (i < n)
	{
		k = i;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (str);
}

/**
 **_strncat - concatenate two strings
 *@des: first string
 *@sr: second string
 *@n: amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *des, char *sr, int n)
{
	int i, k;
	char *str = des;

	i = 0;
	k = 0;
	while (des[i] != '\0')
		i++;
	while (sr[k] != '\0' && k < n)
	{
		des[i] = sr[k];
		i++;
		k++;
	}
	if (k < n)
		des[i] = '\0';
	return (str);
}


/**
 **_strchr - locates character in string
 *@s: string to be parsed
 *@c: character to look for
 *Return: (s) pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
