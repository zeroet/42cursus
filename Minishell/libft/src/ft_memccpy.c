/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:50:17 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:17:47 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	if (n < 1)
		return ((void *)0);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)s1 + i) = *((unsigned char *)s2 + i);
		if (*((unsigned char *)s2 + i) == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return ((void *)0);
}
