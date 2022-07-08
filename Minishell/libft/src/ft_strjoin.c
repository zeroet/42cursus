/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:09:09 by flegg             #+#    #+#             */
/*   Updated: 2020/11/16 18:09:09 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1l;
	size_t	s2l;
	char	*res;

	if (!s1 || !s2)
		return ((void *)0);
	s1l = ft_strlen((char *)s1);
	s2l = ft_strlen((char *)s2);
	res = (char *)malloc((s1l + s2l + 1) * sizeof(char));
	if (!res)
		return ((void *)0);
	ft_memmove(res, s1, s1l);
	ft_memmove((res + s1l), s2, s2l);
	res[s1l + s2l] = 0;
	return (res);
}
