/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:34:44 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:55:43 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	ft_intlen(int n)
{
	int		res;
	long	tmp;

	res = 1;
	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		res++;
	}
	while (tmp / 10 > 0)
	{
		res++;
		tmp = tmp / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	digit;
	long	ln;

	digit = ft_intlen(n);
	ln = n;
	res = (char *)malloc((digit + 1) * sizeof(char));
	if (!res)
		return ((void *)0);
	res[digit--] = 0;
	if (n < 0)
	{
		res[0] = '-';
		ln = -ln;
	}
	res[digit--] = (ln % 10) + '0';
	while (ln / 10 > 0)
	{
		ln = ln / 10;
		res[digit--] = (ln % 10) + '0';
	}
	return (res);
}
