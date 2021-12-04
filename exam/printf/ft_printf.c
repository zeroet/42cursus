/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <ytak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:51:14 by ytak              #+#    #+#             */
/*   Updated: 2021/08/23 16:52:04 by ytak             ###   ########.fr       */
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
		if ((char)**str == 'c')
			return (print_c(str, ap));
		else if ((char)**str == 's')
			return (print_s(str, ap));
		else if ((char)**str == 'd' || (char)**str == 'i' || (char)**str == 'u')
			return (print_diu(str, ap));
		else if ((char)**str == 'x' || (char)**str == 'X')
			return (print_x(str, ap));
		else if ((char)**str == 'p')
			return (print_p(str, ap));
		else
			return (printpercent(str));
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
