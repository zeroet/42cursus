/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:56:24 by seyun             #+#    #+#             */
/*   Updated: 2021/11/27 14:23:53 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dest && i < size)
	{
		++i;
		++dest;
	}
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		i++;
	}
	if (i < size)
		*dest = 0;
	while (*src++)
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}

static size_t	get_row(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*from;
	size_t	idx;
	size_t	size;

	res = (char **)malloc(sizeof(char *) * get_row(s, c) + 1);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - from + 1;
			res[idx] = (char *)malloc(size);
			ft_strlcpy(res[idx++], from, size);
		}
		else
			++s;
	}
	res[idx] = 0;
	return (res);
}

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	while (size--)
	{
		if (*(char *)p1 != *(char *)p2)
			return (*(unsigned char *)p1 - *(unsigned char *)p2);
		p1++;
		p2++;
	}
	return (0);
}
