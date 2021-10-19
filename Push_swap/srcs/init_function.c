/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:06:58 by seyun             #+#    #+#             */
/*   Updated: 2021/10/19 14:23:58 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_cnt_a(t_cnta *a)
{
	a->ra_cnt = 0;
	a->rb_cnt = 0;
	a->pb_cnt = 0;
	a->big_pivot = 0;
	a->small_pivot = 0;
	return ;
}

void	init_cnt_b(t_cntb *b)
{
	b->ra_cnt = 0;
	b->rb_cnt = 0;
	b->pa_cnt = 0;
	b->big_pivot = 0;
	b->small_pivot = 0;
	return ;
}

void	init_pivot_a(t_dlst **lst, int len, t_cnta *a)
{
	a->big_pivot = init_big_pivot(*lst, len);
	a->small_pivot =init_small_pivot(*lst, len);
	return ;
}

void	init_pivot_b(t_dlst **lst, int len, t_cntb *b)
{
	b->big_pivot = init_big_pivot(*lst, len);
	b->small_pivot = init_small_pivot(*lst, len);
	return ;
}


