/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:45:44 by seyun             #+#    #+#             */
/*   Updated: 2020/12/15 12:53:35 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t size)
{
	while (size--)
	{
		*(char*)dest++ = *(char*)src;
		if (*(unsigned char*)src++ == (unsigned char)c)
			return (dest);
	}
	return (0);
}
