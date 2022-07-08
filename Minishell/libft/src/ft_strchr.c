/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:15:38 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:27:45 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ls;

	ls = (char *)s;
	while (*ls)
	{
		if (*ls == (char)c)
			return (ls);
		ls++;
	}
	if (c == 0)
		return (ls);
	else
		return ((char *)0);
}
