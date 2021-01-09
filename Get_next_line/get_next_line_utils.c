/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:38:51 by seyun             #+#    #+#             */
/*   Updated: 2021/01/09 12:27:37 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *ptr)
{
	size_t	size;

	size = 0;
	while (ptr[size])
		size++;
	return (size);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
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

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;

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

char		*ft_strdup(const char *ptr)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(ptr);
	if (!(res = malloc(len + 1)))
		return (0);
	i = 0;
	while (len--)
		res[i++] = *ptr++;
	res[i] = 0;
	return (res);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = malloc(len)))
		return (0);
	ft_strlcpy(res, s1, len);
	ft_strlcat(res, s2, len);
	return (res);
}
