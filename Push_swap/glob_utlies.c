/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_utlies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:56:20 by seyun             #+#    #+#             */
/*   Updated: 2021/10/14 13:58:55 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *str)
{
	int	sign;
	long long num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str != 0)
	{	
		if (!(*str >= '0' && *str <= '9'))
			ft_error();
		num *= 10;
		num += (*(str++) - '0');
	}
	if (sign == -1)
		num *= -1;
	if (num < -2147483648 || num > 2147483647)
		ft_error();
	return ((int)num);
}

