/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:47:53 by seyun             #+#    #+#             */
/*   Updated: 2022/02/08 16:52:38 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_chr_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_put_line(char *buf)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	while (j < i)
	{
		result[j] = buf[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_return_left(char *buf, int index_r)
// saves the rest after the '\n'
{
	char	*r_left;
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	r_left = malloc(sizeof(char) * (index_r - i + 1));
	if (!r_left)
		return (NULL);
	j = 0;
	while (buf[i] != '\0')
		r_left[j++] = buf[i++];
	r_left[j] = '\0';
	free(buf);
	return (r_left);
}

char	*ft_strjoin(char *left, char *buf)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (ft_strlen(left) + ft_strlen(buf) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (left != NULL && left[i])
	{
		res[i] = left[i];
		i++;
	}
	j = 0;
	while (buf != NULL && buf[j])
	{
		res[i] = buf[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
