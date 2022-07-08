/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:58:56 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:18:43 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (s1 == s2 || n < 1)
		return (s1);
	i = 0;
	if (s1 < s2)
	{
		while (i < n)
		{
			*((unsigned char *) s1 + i) = *((unsigned char *) s2 + i);
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			*((unsigned char *) s1 + n - 1) = *((unsigned char *) s2 + n - 1);
			n--;
		}
	}
	return (s1);
}
