/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:29:27 by seyun             #+#    #+#             */
/*   Updated: 2021/06/30 00:02:05 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


typedef struct s_list
{
	int num;
	struct s_list *prev;
	struct s_list *next;
}	t_list;


t_list createNode(int data)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->num = data;
	new->prev = NULL;
	new->next = NULL;
	return (*new);
}

t_list deleteNode(t_list *Node)
{
	Node->num = 0;
	Node->prev = NULL;
	Node->next = NULL;
	free(Node);
}

t_list getNodeat(t_list *head, int index)
{
	t_list *horse = head;
	int i = 0;

	while (horse != NULL)
	{
		if (i++ == index)
			return (horse);
		horse = horse->next;
	}
	return NULL;
}


int	main(void)
{
	t_list tmp;
	int a = 3;
	
	tmp = createNode(a);
	printf("%d", tmp.num);
	return (0);
}
