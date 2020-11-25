/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 23:10:44 by seyun             #+#    #+#             */
/*   Updated: 2020/11/25 23:14:35 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int res;
	int	sign;

	res = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += (sign * (*(str++) - '0'));
	}
	return (res);
}
