/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:38:51 by seyun             #+#    #+#             */
/*   Updated: 2021/01/06 17:17:09 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t		ft_strlen(char *ptr)
{
	size_t	size;

	size = 0;
	while (ptr[size])
		size++;
	return (size);
}

char		*ft_strjoin(char *dest, char *src)
{
}
