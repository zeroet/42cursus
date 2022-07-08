#include "../include/libft.h"

static int	g_mem_used;

t_mem_node	*new_mem(t_mem_node **first, size_t size)
{
	t_mem_node	*tmp;
	t_mem_node	*last;

	if (!(g_mem_used++))
		*first = NULL;
	if (size < 1 || first == NULL)
		return (NULL);
	if (*first == NULL)
	{
		*first = new_mem_node(size);
		return (*first);
	}
	tmp = new_mem_node(size);
	last = last_mem_node(*first);
	last->next = tmp;
	tmp->prev = last;
	return (tmp);
}

void	*free_mem(t_mem_node **first, t_mem_node **mem_obj)
{
	t_mem_node	*tmp;

	if (mem_obj == NULL || *mem_obj == NULL)
		return (NULL);
	if ((*mem_obj)->data != NULL)
		free((*mem_obj)->data);
	(*mem_obj)->data = NULL;
	if ((*mem_obj)->prev != NULL)
		(*mem_obj)->prev->next = (*mem_obj)->next;
	if ((*mem_obj)->next != NULL)
		(*mem_obj)->next->prev = (*mem_obj)->prev;
	if (*first == *mem_obj)
	{
		if ((*mem_obj)->next != NULL)
			*first = (*mem_obj)->next;
		else
			*first = NULL;
	}
	free(*mem_obj);
	tmp = *mem_obj;
	*mem_obj = NULL;
	return (tmp);
}

void	*free_mem_by_ptr(t_mem_node **first, void **ptr)
{
	t_mem_node	*tmp;
	t_mem_node	*tmp2;

	if (ptr == NULL || *ptr == NULL || first == NULL)
		return (NULL);
	tmp = *first;
	while (tmp && tmp->data != *ptr)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	tmp2 = tmp;
	free_mem(first, &tmp);
	*ptr = NULL;
	if (tmp2 == *first)
		*first = NULL;
	return (tmp2);
}

void	free_all_mem(t_mem_node **first)
{
	t_mem_node	*tmp;

	if (first == NULL)
		return ;
	while (*first != NULL)
	{
		if ((*first)->data != NULL)
			free((*first)->data);
		tmp = *first;
		*first = (*first)->next;
		free(tmp);
	}
}

void	*add_mem_by_ptr(t_mem_node **first, void *ptr)
{
	t_mem_node	*tmp;
	t_mem_node	*last;

	if (!(g_mem_used++))
		*first = NULL;
	if (ptr == NULL || first == NULL)
		return (NULL);
	tmp = malloc(sizeof(t_mem_node));
	if (!tmp)
		return (NULL);
	tmp->data = ptr;
	tmp->next = NULL;
	if (*first == NULL)
	{
		*first = tmp;
		(*first)->prev = NULL;
		return (*first);
	}
	last = last_mem_node(*first);
	last->next = tmp;
	tmp->prev = last;
	return (tmp);
}
