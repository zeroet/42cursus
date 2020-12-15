/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:00:18 by seyun             #+#    #+#             */
/*   Updated: 2020/12/15 22:54:25 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t size)
{
	void *res;

	res = dest;
	while (size--)
		*(char*)dest-- = (unsigned char)val;
	return (res);
}
