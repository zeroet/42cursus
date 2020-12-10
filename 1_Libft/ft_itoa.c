/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:17:32 by seyun             #+#    #+#             */
/*   Updated: 2020/12/03 14:23:23 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_get_len(int n)
{
	int			len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*res;
	long long	tmp;

	sign = n < 0 ? -1 : 1;
	len = ft_get_len(n);
	len--;
	tmp = n < 0 ? -(long long)n : (long long)n;
	while (len >= 0)
	{
		res[len] = '0' + tmp % 10;
		tmp /= 10;
		len--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
