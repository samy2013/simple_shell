#include "shell.h"

/**
 * list_len - length of linked list
 * @pn: pointer to first node
 *
 * Return: list size
 */
size_t list_len(const list_t *pn)
{
	size_t i = 0;

	while (pn)
	{
		pn = pn->next;
		i++;
	}
	return (i);
}
/**
 * list_to_strings - returns an array of strings of the list->str
 * @hd: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *hd)
{
	list_t *node = hd;
	size_t i = list_len(hd), j;
	char **sts;
	char *st;

	if (!hd || !i)
		return (NULL);
	sts = malloc(sizeof(char *) * (i + 1));
	if (!sts)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		st = malloc(_strlen(node->st) + 1);
		if (!st)
		{
			for (j = 0; j < i; j++)
				free(sts[j]);
			free(sts);
			return (NULL);
		}

		st = _strcpy(st, node->st);
		sts[i] = st;
	}
	sts[i] = NULL;
	return (sts);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @pon: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *pon)
{
	size_t i = 0;

	while (pon)
	{
		_puts(convert_number(pon->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(pon->str ? pon->str : "(nil)");
		_puts("\n");
		pon = pon->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prfix: string to match
 * @chr: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prfix, char chr)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prfix);
		if (p && ((chr == -1) || (*p == chr)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (index);
		head = head->next;
		index++;
	}
	return (-1);
}
