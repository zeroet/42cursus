/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <ytak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:51:14 by ytak              #+#    #+#             */
/*   Updated: 2021/12/30 18:40:33 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printpercent(const char **str)
{
	if ((char)**str == '%')
	{
		ft_putchar('%');
		(*str)++;
		return (1);
	}
	return (0);
}

int	print_char(const char **str, va_list ap)
{
	while (**str)
	{
		else if ((char)**str == 's')
			return (print_s(str, ap));
		else if ((char)**str == 'd')
			return (print_diu(str, ap));
		else if ((char)**str == 'x')
			return (print_x(str, ap));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		return_value;
	va_list	ap;

	return_value = ft_strlen(str);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			return_value += print_char(&str, ap) - 2;
		}
		else
		{
			ft_putchar(*str);
			str++;
		}
	}
	va_end(ap);
	return (return_value);
}
