/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:10:50 by seyun             #+#    #+#             */
/*   Updated: 2021/12/04 18:23:46 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_argument(char **av)
{
	char	**str;
	int		i;

	i = 0;
	if (av != 5)
		ft_strexit("Error : give 5 arguments!");
	str = ft_split(av, ' ');
	while (str[i])
	{
		if (!ft_only_digit(str[i]))
			ft_strexit("ERROR: give only digit arguments!");

	}:
}

int	main(int ac, char **av)
{
	if (validate_argument(av))
		strexit("ERROR:");
	
	
}
