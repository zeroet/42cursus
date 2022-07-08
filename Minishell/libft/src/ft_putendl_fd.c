/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 23:32:55 by flegg             #+#    #+#             */
/*   Updated: 2022/07/07 23:12:19 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	endl;

	if (!s)
		return ;
	while (*s)
		if ((write(fd, s++, 1)) == -1)
			exit(1);
	endl = '\n';
	if ((write(fd, &endl, 1)) == -1)
		exit(1);
	return ;
}
