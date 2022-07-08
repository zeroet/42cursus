/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:48:08 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:43:47 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return ((void *)0);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return ((void *)0);
	i = 0;
	while (i < len && s[start + i] && start < ft_strlen(s))
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
