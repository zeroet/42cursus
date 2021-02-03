/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:31:40 by seyun             #+#    #+#             */
/*   Updated: 2021/02/03 12:46:20 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2, int free_target)
{
	char	*res;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	i = -1;
	while (++i < s1_len)
		res[i] = s1[i];
	if (free_target == 1 || free_target == 3)
		free(s1);
	j = 0;
	while (j < s2_len)
		res[i++] = s2[j++];
	if (free_targat == 2 || free_target == 3)
		free(s2);
	res[i] = 0;
	return (res);
}
