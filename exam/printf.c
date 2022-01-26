/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:44:51 by seyun             #+#    #+#             */
/*   Updated: 2022/01/26 21:57:34 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int res = 0;

	if (s == NULL)
	{
		res += write(1, "(null)", 6);
		return (res);
	}
	while (*s)
		res += write(1, s++, 1);
	return (res);
}

int	ft_putnbr(int nbr)
{
	int res;

	res = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		res += ft_putnbr(nbr / 10);
	res += ft_putchar(nbr % 10 + '0');
	return (res);
}

int	ft_puthex(int nbr)
{
	int res;
	char *base;

	res = 0;
	base = "0123456789abcdef";

	if (nbr > 15)
		res += ft_puthex(nbr / 16);
	res += ft_puthex(base[nbr % 16]);
	return (res);
}

int ft_format(char c, va_list ap)
{
	int res = 0;

	if (c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'x')
		return (ft_putnbr(va_arg(ap, unsigned long)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (res);
}

int ft_printf(char *s, ...)
{
	int res = 0;
	int i = 0;
	va_list ap;

	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{	
			res += ft_format(s[i + 1], ap);
			i++;
		}
		else
			res += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (res);
}

int	main(void)
{
	int	a;
	int b;
	char *str = NULL;
	int res = 0;
	int res2 =0;

	a = -399;
	b = 900;
	ft_printf("Hello world\n");
	printf("Hello world\n");
	ft_printf("%s, %d, %x, %%%, %%, %%%%\n", "TEST", a, b);
	ft_printf("-399 = %d\n", a);
	ft_printf("900 in hex = %x\n", b);
	printf("900 in hex = %x\n", b);
	ft_printf("%s\n", str);
	printf("%s\n", str);
	printf("%%\n");
	ft_printf("%%\n");
	res = printf("%%%%\n");
	res2 = ft_printf("%%%%\n");
	printf("%d %d\n", res, res2);
	return (0);
}
