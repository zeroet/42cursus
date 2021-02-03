/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:20:45 by seyun             #+#    #+#             */
/*   Updated: 2021/02/03 15:06:48 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(int c, t_info *info)
{
	int ret;

	ret = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		ret += ft_putchar(c);
	ret += put_width(info->width, 1, info->zero);
	if (info->minus == 0)
		ret += ft_putchar(c);
	return (ret);
}

int		put_width(int width, int len, int zero)
{
	int ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		ret++;
		len++;
	}
	return (ret);
}
