/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:02:43 by seyun             #+#    #+#             */
/*   Updated: 2021/01/27 16:24:38 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.f"

int		print_nbr(unsigned long long nbr, t_info *info)
{
	int ret;

	ret = 0;
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if (info->type == 'd' || info-> 'i')
	{
		info->sign *= -1;
		nbr *= -1;
	}
	

