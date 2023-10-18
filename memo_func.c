#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@z: the pointer to the memory area
 *@x: the byte to fill *z 
 *@c: the amount of bytes to be filled
 *Return: (z) a pointer to the memory area z
 */
char *_memset(char *z, char x, unsigned int c)
{
	unsigned int i;

	for (i = 0; i < c; i++)
		z[i] = x;
	return (z);
}

/**
 * f_free - free string of strings
 * @ss: string of strings
 */
void f_free(char **ss)
{
	char **altr = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(altr);
}

/**
 * _realloc - reallocates a block of memory
 * @poin: pointer to previous malloc'ated block
 * @old_s: byte size of previous block
 * @new_s: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *poin, unsigned int old_s, unsigned int new_s)
{
	char *p;

	if (!poin)
		return (malloc(new_s));
	if (!new_s)
		return (free(poin), NULL);
	if (new_s == old_s)
		return (poin);

	p = malloc(new_s);
	if (!p)
		return (NULL);

	old_s = old_s < new_s ? old_s : new_s;
	while (old_s--)
		p[old_s] = ((char *)poin)[old_s];
	free(poin);
	return (p);
}
