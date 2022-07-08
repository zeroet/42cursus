/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:10:20 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:28:34 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*ls;

	ls = (char *)s;
	res = ((char *)0);
	while (*ls)
	{
		if (*ls == (char)c)
			res = ls;
		ls++;
	}
	if (c == 0)
		return (ls);
	else
		return (res);
}
