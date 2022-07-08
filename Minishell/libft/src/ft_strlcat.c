/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:18:52 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:31:07 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	res = 0;
	while (src[res])
		res++;
	if (size < 1)
		return (res);
	i = 0;
	while (dst[i] && i < size)
		i++;
	res += i;
	j = 0;
	if (i < size)
	{
		while (src[j] && (i + 1) < size)
			dst[i++] = src[j++];
		dst[i] = 0;
	}
	return (res);
}
