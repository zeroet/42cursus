/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 13:50:54 by seyun             #+#    #+#             */
/*   Updated: 2021/10/13 22:55:13 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**************** header ***********************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_dlst
{
	int num;
	struct s_dlst *prev;
	struct s_dlst *next;
}			t_dlst;

/************** globale utiles functions  ****************/

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *str)
{
	int	sign;
	long long num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != 0)
	{	
		if (!(*str >= '0' && *str <= '9'))
			ft_error();
		num *= 10;
		num += (*(str++) - '0');
	}
	if (sign == -1)
		num *= -1;
	if (num < -2147483648 || num > 2147483647)
		ft_error();
	return ((int)num);
}

/********************** stack functions ****************/

int	check_duplicates(t_dlst *lst)
{
	t_dlst *new;

	new = lst->prev;
	while (lst != new)
	{
		if (new->num == lst->num)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	dlst_clear(t_dlst *lst)
{
	t_dlst *tmp;

	lst->prev->next = NULL;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	init_stack(t_dlst **lst, t_dlst *node)
{
	if (!lst || !node)
		return ;
	if (*lst == 0)
		*lst = node;
	else
	{
		(*lst)->prev->next = node;
		node->prev = (*lst)->prev;
		(*lst)->prev = node;
		node->next = *lst;
	}
	if (check_duplicates(*lst))
	{
		dlst_clear(*lst);
		ft_error();
	}
	
}

t_dlst *creat_node(int num)
{
	t_dlst *new_node;

	new_node = (t_dlst *)malloc(sizeof(t_dlst));
	if (new_node == NULL)
		return (0);
	new_node->num = num;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

/***************** main ***********************/

int main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	while (*(++argv) != 0)
		init_stack(&stack_a, creat_node(ft_atoi(*argv)));
	return (0);
}
