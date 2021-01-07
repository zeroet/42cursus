/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:24:23 by seyun             #+#    #+#             */
/*   Updated: 2020/11/26 16:09:57 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
