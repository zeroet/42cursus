/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:42:59 by seyun             #+#    #+#             */
/*   Updated: 2020/11/18 16:54:34 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *res;

	if (*s == '\0')
		return (0);
	res = 0;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	return ((char*)res);
}
