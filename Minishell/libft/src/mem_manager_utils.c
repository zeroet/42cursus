#include "../include/libft.h"

t_mem_node	*new_mem_node(size_t size)
{
	t_mem_node	*node;
	size_t		i;

	if (size < 1)
		return (NULL);
	node = malloc(sizeof(t_mem_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->data = malloc(size);
	if (!node->data)
	{
		free(node);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		*((unsigned char *)node->data + i) = 0;
		i++;
	}
	return (node);
}

t_mem_node	*last_mem_node(t_mem_node *first)
{
	t_mem_node	*tmp;

	if (first == NULL)
		return (NULL);
	tmp = first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_mem_node	*new_mem_assign(t_mem_node **first, void **ptr, size_t size)
{
	t_mem_node	*tmp;

	if (ptr == NULL)
		return (NULL);
	tmp = new_mem(first, size);
	if (!tmp)
		return (NULL);
	*ptr = tmp->data;
	return (tmp);
}
