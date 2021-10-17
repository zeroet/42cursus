/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:06:58 by seyun             #+#    #+#             */
/*   Updated: 2021/10/17 01:28:10 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_cnt_a(t_cnta *a)
{
	a->ra_cnt = 0;
	a->rb_cnt = 0;
	a->pb_cnt = 0;
	return ;
}

void	init_cnt_b(t_cntb *b)
{
	b->ra_cnt = 0;
	b->rb_cnt = 0;
	b->pa_cnt = 0;
	return ;
}
