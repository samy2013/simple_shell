#include "shell.h"

/**
 * _strlen - return string length 
 * @sr: string length check
 *
 * Return: integer length the string
 */
int _strlen(char *sr)
{
	int i = 0;

	if (!sr)
		return (0);

	while (*sr++)
		i++;
	return (i);
}

/**
 * _strcmp - compare two strangs
 * @sr1: first strang
 * @sr2: second strang
 *
 * Return: negative if string1 < string2, positive if string1 > string2, 0 if string1 == string2
 */
int _strcmp(char *sr1, char *sr2)
{
	while (*sr1 && *sr2)
	{
		if (*sr1 != *sr2)
			return (*sr1 - *sr2);
		sr1++;
		sr2++;
	}
	if (*sr1 == *sr2)
		return (0);
	else
		return (*sr1 < *sr2 ? -1 : 1);
}

/**
 * starts_with - check if ndle start with hstack
 * @hstack: string search
 * @ndle: substring to find
 *
 * Return: address of next char of hstack or NULL
 */
char *starts_with(const char *hstack, const char *ndle)
{
	while (*ndle)
		if (*ndle++ != *hstack++)
			return (NULL);
	return ((char *)hstack);
}

/**
 * _strcat - concatenat two strings
 * @destin: the destination buffer
 * @srce: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *destin, char *srce)
{
	char *retu = destin;

	while (*destin)
		destin++;
	while (*srce)
		*destin++ = *srce++;
	*destin = *srce;
	return (retu);
}
