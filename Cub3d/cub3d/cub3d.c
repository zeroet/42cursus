/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:07:23 by seyun             #+#    #+#             */
/*   Updated: 2021/11/09 00:06:14 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		fd;
}	t_game;

void	init_game(t_game *game)
{
	ft_memset(game->tex.path, 0, 6);
	game->tex.floor = -1;
	game->tex.ceiling = -1;
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		ft_strexit("ERROR: Argument Error!");
	init_game(&game);
	open_cub(argv[1], &game);
	read_info(&game);
	return (0);
}

void	open_cub(char *file_name, t_game *game)
{
	if (!ft_isformat(file_name, ".cub");
		ft_strexit("ERROR: CUB File Needed!");
	game->fd = open(file_name, O_RDONLY);
	if (s->fd == -1)
		ft_strexit("ERROR: No Such CUB File Available!");
}
