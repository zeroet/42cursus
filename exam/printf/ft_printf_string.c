/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <ytak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:17:15 by ytak              #+#    #+#             */
/*   Updated: 2021/08/23 14:22:15 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	write_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_s(const char **str, va_list ap)
{
	int		i;
	char	*s;

	i = 0;
	if ((char)**str == 's')
	{
		s = va_arg(ap, char *);
		(*str)++;
		if (!s)
			return (write_null());
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		return (ft_strlen(s));
	}
	return (0);
}

int	print_c(const char **str, va_list ap)
{
	int	i;

	if ((char)**str == 'c')
	{
		i = va_arg(ap, int);
		write(1, &i, 1);
		(*str)++;
		return (1);
	}
	return (0);
}
