/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:44:51 by seyun             #+#    #+#             */
/*   Updated: 2022/02/08 16:54:41 by seyun            ###   ########.fr       */
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

int	ft_putnbr(long int nbr)
{
	int res;

	res = 0;
	if (nbr < 0)
	{
		res = ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		res += ft_putnbr(nbr / 10);
	res += ft_putchar(nbr % 10 + '0');
	return (res);
}

int	ft_puthex(unsigned long nbr)
{
	int res;
	char *base;

	res = 0;
	base = "0123456789abcdef";

	if (nbr > 15)
		res += ft_puthex(nbr / 16);
	res += ft_putchar(base[nbr % 16]);
	return (res);
}

int ft_format(char c, va_list ap)
{
	int res = 0;

	if (c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, unsigned long)));
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
	char *hello = "hello";
	int	forty_two = 42;
	int	max_int = 2147483647;
	int	min_int = -2147483648;

	printf("\n\ns flag\n");
	printf("\t\t-real(%d)\n", printf("s:%s", hello));
	printf("\t\t-mine(%d)\n", ft_printf("s:%s", hello));
	printf("\t\t-real(%d)\n", printf("s:%s", NULL));
	printf("\t\t-mine(%d)\n", ft_printf("s:%s", NULL));

	printf("\n\nd flag\n");
	printf("\t\t-real(%d)\n", printf("d:%d", forty_two));
	printf("\t\t-mine(%d)\n", ft_printf("d:%d", forty_two));
	printf("\t\t-real(%d)\n", printf("d:%d", -forty_two));
	printf("\t\t-mine(%d)\n", ft_printf("d:%d", -forty_two));
	printf("\t\t-real(%d)\n", printf("d:%d", max_int));
	printf("\t\t-mine(%d)\n", ft_printf("d:%d", max_int));
	printf("\t\t-real(%d)\n", printf("d:%d", min_int));
	printf("\t\t-mine(%d)\n", ft_printf("d:%d", min_int));

	printf("\n\nx flag\n");
	printf("\t\t-real(%d)\n", printf("x:%x", forty_two));
	printf("\t\t-mine(%d)\n", ft_printf("x:%x", forty_two));
	printf("\t\t-real(%d)\n", printf("x:%x", -forty_two));
	printf("\t\t-mine(%d)\n", ft_printf("x:%x", -forty_two));

	//multi
	printf("\n\nmulti flag\n");
	printf("\t\t-real(%d)\n", printf("s:%s d:%d x:%x", hello, forty_two, -forty_two));
	printf("\t\t-mine(%d)\n", ft_printf("s:%s d:%d x:%x", hello, forty_two, -forty_two));
	return (0);
}
