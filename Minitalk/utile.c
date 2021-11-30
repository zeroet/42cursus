/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:13:46 by seyun             #+#    #+#             */
/*   Updated: 2021/11/29 16:29:40 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int			signe;
	long long	nb;

	signe = 1;
	nb = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -signe;
		str++;
	}
	if (!('0' <= *str && *str <= '9'))
		exit (0);
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (nb * signe > 2147483647)
		exit(0);
	if (nb * signe < -2147483648)
		exit(0);
	return (nb * signe);
}

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	n_copy;
	char		*strr;

	len = ft_intlen(n);
	strr = (char *)malloc(len + 1);
	if (strr == NULL)
		return (NULL);
	strr[len--] = '\0';
	n_copy = (long int)n;
	if (n_copy == 0)
		strr[0] = '0';
	if (n_copy < 0)
	{
		strr[0] = '-';
		n_copy *= -1;
	}
	while (n_copy > 0)
	{
		strr[len--] = '0' + n_copy % 10;
		n_copy /= 10;
	}
	return (strr);
}
