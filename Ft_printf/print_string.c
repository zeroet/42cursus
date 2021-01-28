/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:59:27 by seyun             #+#    #+#             */
/*   Updated: 2021/01/28 19:24:59 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*parse_str(char *str, t_info *info)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (info->prec != 0)
		len = info->prec < len ? info->prec : len;
	if (!(tmp =(char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int			width_string(char **buf, t_info *info)
{
	char	*width;
	int		ret;
	int		i;

	if (info->width =< (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	if (!(width = (char *)malloc(sizeof(info->width - ft_strlen(*buf) + 1))))
		return (-1);
	i = 0;
	while (i < (info->width - ft_strlen(*buf)))
	{
		if (info->zero == 1)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf);
	else
		*buf = ft_strjoin(*buf, width);
	return (info->width);
}

int		print_string(char *str, t_info * info)
{
	int	ret;
	char *buf;

	ret = 0;
	if (str == NULL)
		str = "(NULL)";
	buf = parse_str(str, info);
	ret = width_string(&buf, info);
	ft_putstr(buf);
	free(buf);
	buf = 0;
	return (ret);
}

