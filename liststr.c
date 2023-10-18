#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @n: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int n)
{
	list_t *nw_hd;

	if (!head)
		return (NULL);
	nw_hd = malloc(sizeof(list_t));
	if (!nw_hd)
		return (NULL);
	_memset((void *)nw_hd, 0, sizeof(list_t));
	nw_hd->n = n;
	if (str)
	{
		nw_hd->str = _strdup(str);
		if (!nw_hd->str)
		{
			free(nw_hd);
			return (NULL);
		}
	}
	nw_hd->next = *head;
	*head = nw_hd;
	return (nw_hd);
}
/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @strin: str field of node
 * @n: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *strin, int n)
{
	list_t *nw_nd, *nd;

	if (!head)
		return (NULL);

	nd = *head;
	nw_nd = malloc(sizeof(list_t));
	if (!nw_nd)
		return (NULL);
	_memset((void *)nw_nd, 0, sizeof(list_t));
	nw_nd->n = n;
	if (strin)
	{
		nw_nd->strin = _strdup(str);
		if (!nw_nd->strin)
		{
			free(nw_nd);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = nw_nd;
	}
	else
		*head = nw_nd;
	return (nw_nd);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @p: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *p)
{
	size_t i = 0;

	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @ind: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int ind)
{
	list_t *nd, *prev_nd;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!ind)
	{
		nd = *head;
		*head = (*head)->next;
		free(nd->str);
		free(nd);
		return (1);
	}
	nd = *head;
	while (nd)
	{
		if (i == ind)
		{
			prev_nd->next = nd->next;
			free(nd->str);
			free(nd);
			return (1);
		}
		i++;
		prev_nd = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @hd_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **hd_ptr)
{
	list_t *nd, *next_nd, *hd;

	if (!hd_ptr || !*hd_ptr)
		return;
	hd = *hd_ptr;
	nd = hd;
	while (nd)
	{
		next_nd = nd->next;
		free(nd->str);
		free(nd);
		nd = next_nd;
	}
	*hd_ptr = NULL;
}
