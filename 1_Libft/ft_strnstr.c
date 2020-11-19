/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:04:04 by seyun             #+#    #+#             */
/*   Updated: 2020/11/18 17:25:20 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	const char	*tmp;
	size_t		i;
	size_t		j;

	if (*s2)
		return (s1);
	i = 0;
	j = 0;
	while (i < len)
	{
		tmp = s1[i];
		while (s1[i] == s2[j])
		{
			j++;
			i++;
			if (i == len)
				break ;
		}
		i++;
	}
	if (*s2 == 0)
		return (tmp);
	return (0);
}
