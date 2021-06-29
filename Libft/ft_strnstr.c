/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:04:04 by seyun             #+#    #+#             */
/*   Updated: 2021/04/19 12:35:54 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litt, size_t len)
{
	size_t		len_b;
	size_t		len_l;
	size_t		size;

	if (*litt == 0)
		return ((char *)big);
	len_b = ft_strlen(big);
	len_l = ft_strlen(litt);
	if (len_b < len_l || len < len_l)
		return (0);
	size = len_b > len ? len : len_b;
	while (size-- >= len_l)
	{
		if (ft_memcmp(big, litt, len_l) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
