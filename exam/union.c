/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:06:13 by seyun             #+#    #+#             */
/*   Updated: 2021/06/28 18:10:23 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	tab[256];
	unsigned char *s1;
	unsigned char *s2;
	int	i;

	i = 0;
	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2]'
		while (i < 256)
		{
			tab[i] = 0;
			i++;
		}
		i = 0;
		while (s1[i] != '\0')
		{
			if (tab[s1[i]] == 0)
			{
				ft_putchar(s1[i]);
				tab[s1][i] = 1;
			}
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			if (tab[(int)s2[i]] == 0)
			{
				ft_putchar(s2[i]);
				tab[s2[i]] = 1;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
