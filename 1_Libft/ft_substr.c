/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:43:13 by seyun             #+#    #+#             */
/*   Updated: 2020/11/17 21:43:16 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		size;
	char	*res;

	size = len - start;
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	res = tmp;
	while (size--)
		*(tmp++) = s[start++];
	tmp = 0;
	return (res);
}
