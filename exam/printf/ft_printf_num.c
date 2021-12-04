/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <ytak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:22:40 by ytak              #+#    #+#             */
/*   Updated: 2021/12/04 18:01:10 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_per(size_t nbr, char *base, int *len_i)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		ft_putnbr(nbr / base_len, base, len_i);
		ft_putnbr(nbr % base_len, base, len_i);
	}
	else
	{
		ft_putchar(base[nbr % base_len]);
		(*len_i)++;
	}
	return (0);
}	

int	ft_putnbr(long long nbr, char *base, int *len_i)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
		(*len_i)++;
	}
	if (nbr >= base_len)
	{
		ft_putnbr(nbr / base_len, base, len_i);
		ft_putnbr(nbr % base_len, base, len_i);
	}
	else
	{
		ft_putchar(base[nbr % base_len]);
		(*len_i)++;
	}
	return (0);
}

int	print_diu(const char **str, va_list ap)
{
	int	j;

	j = 0;
	if ((char)**str == 'i' || (char)**str == 'd')
	{
		ft_putnbr(va_arg(ap, int), "0123456789", &j);
		(*str)++;
		return (j);
	}
	else
	{
		ft_putnbr(va_arg(ap, unsigned int), "0123456789", &j);
		(*str)++;
		return (j);
	}	
	return (0);
}

int	print_x(const char **str, va_list ap)
{
	int	j;

	j = 0;
	if ((char)**str == 'x')
	{
		ft_putnbr(va_arg(ap, unsigned int), "0123456789abcdef", &j);
		(*str)++;
		return (j);
	}
	else
	{
		ft_putnbr(va_arg(ap, unsigned int), "0123456789ABCDEF", &j);
		(*str)++;
		return (j);
	}
	return (0);
}

int	print_p(const char **str, va_list ap)
{
	int	j;

	if ((char)**str == 'p')
	{
		write(1, "0x", 2);
		j = 0;
		ft_putnbr_per(va_arg(ap, long long), "0123456789abcdef", &j);
		(*str)++;
		return (j + 2);
	}
	return (0);
}
