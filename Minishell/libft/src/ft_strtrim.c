/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 02:01:32 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:47:02 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	if (c == 0)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*res;

	if (!s1 || !set)
		return ((void *)0);
	start = (char *)s1;
	while (is_in_set(*start, set) && *start)
		start++;
	end = start;
	while (*end)
		end++;
	while (is_in_set(*(end - 1), set) && end != start)
		end--;
	res = (char *)malloc(end - start + sizeof(char));
	if (!res)
		return ((void *)0);
	ft_memmove(res, start, ((end - start) / sizeof(char)));
	res[(end - start) / sizeof(char)] = 0;
	return (res);
}
