#include "shell.h"

/**
 * be_free - frees a pointer and NULLs the address
 * @potr: pointer address to free
 * Return: 1 if free, else 0.
 */
int be_free(void **potr)
{
	if (potr && *potr)
	{
		free(*potr);
		*potr = NULL;
		return (1);
	}
	return (0);
}
