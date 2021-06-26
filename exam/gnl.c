/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:33:00 by seyun             #+#    #+#             */
/*   Updated: 2021/06/26 17:33:05 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_find_char(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_calloc(int len, int count)
{
	char *new;
	int size;
	int i;

	i = 0;
	size = len * count;
	if (!(new = malloc(size)))
		return (NULL);
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}

char	*ft_add_char(char *str, char c)
{
	char *new;
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	new = (char *)ft_calloc(len + 2, sizeof(char));
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	if (str)
		free(str);
	return (new);
}

char	*ft_substr(const char *str, int start, int len)
{
	char *new;
	int i;

	i = 0;
	new = (char *)ft_calloc(len + 1, sizeof(char));
	while (i < len && str[start])
	{
		new[i] = str[start];
		i++;
		start++;
	}
	return (new);
}

int		get_next_line(char **line)
{
	static char *str;
	char buffer[1];
	int point;
	char *tmp;

	if ((!line) || ((!str) && (!(str = ft_calloc(1, sizeof(char))))))
		return (-1);
	while (read(0, buffer, 1) > 0)
	{
		str = ft_add_char(str, buffer[0]);
		if (buffer[0] == '\n')
			break;
	}
	if ((point = ft_find_char(str, '\n')) >= 0)
	{
		*line = ft_substr(str, 0, point);
		tmp = str;
		str = ft_substr(str, point + 1, ft_find_char(str, '\0'));
		free(tmp);
		return (1);
	}
	*line = ft_substr(str, 0, '\n');
	return (0);
}
