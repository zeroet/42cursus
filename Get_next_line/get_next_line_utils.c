/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:38:51 by seyun             #+#    #+#             */
/*   Updated: 2021/01/15 12:03:40 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int			ft_strlcpy(char *dest, const char *src, int size)
{
	int		i;

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

int			ft_strlcat(char *dest, const char *src, int size)
{
	int		 i;

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

char		*ft_strdup(char *ptr)
{
	int		len;
	int		i;
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

char		*ft_strjoin(char *s1,  char *s2)
{
	int		s1_len;
	int		s2_len;
	int		len;
	char	*res;

	if (!(s1) &&!(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len + 1;
	if (!(res = (char *)malloc(len)))
		return (0);
	ft_strlcpy(res, s1, len);
	ft_strlcat(res, s2, len);
	return (res);
}
