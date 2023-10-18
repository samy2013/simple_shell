#include "shell.h"

/**
 * **strtow - split string into words. Repeat delimiters are ignored
 * @stri: input string
 * @del: delimeter string
 * Return: pointer to an array of strings, or NULL on failure
 */

char **strtow(char *stri, char *del)
{
	int i, j, k, m, numb_word = 0;
	char **s;

	if (stri == NULL || stri[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (i = 0; stri[i] != '\0'; i++)
		if (!is_delim(stri[i], del) && (is_delim(stri[i + 1], del) || !stri[i + 1]))
			numb_word++;

	if (numb_word == 0)
		return (NULL);
	s = malloc((1 + numb_word) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numb_word; j++)
	{
		while (is_delim(stri[i], del))
			i++;
		k = 0;
		while (!is_delim(stri[i + k], del) && stri[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = stri[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - split string into words
 * @strin: the input string
 * @deli: the delimeter
 * Return: pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *strin, char deli)
{
	int i, j, k, m, numb_word2 = 0;
	char **s;

	if (strin == NULL || strin[0] == 0)
		return (NULL);
	for (i = 0; strin[i] != '\0'; i++)
		if ((strin[i] != deli && strin[i + 1] == deli) ||
		    (strin[i] != deli && !strin[i + 1]) || strin[i + 1] == deli)
			numb_word2++;
	if (numb_word2 == 0)
		return (NULL);
	s = malloc((1 + numb_word2) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numb_word2; j++)
	{
		while (strin[i] == deli && strin[i] != deli)
			i++;
		k = 0;
		while (strin[i + k] != deli && strin[i + k] && strin[i + k] != numb_word2)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = strin[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
