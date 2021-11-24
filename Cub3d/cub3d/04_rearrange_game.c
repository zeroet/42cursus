* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_rearrange_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:58:17 by seyun             #+#    #+#             */
/*   Updated: 2021/11/24 19:21:25 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rearrange_game(t_game *game)
{
	apply_player_orientation(game);
	game->mlx = mlx_init();
	allocate_buffer(s);
}

void	apply_player_orientation(t_game *game)
{
	int	degree;

	degree = 0;
	if (game->player.dir == 'N')
		degree = 90;
	else if (game->player.dir == 'S')
		degree = 270;
	else if (game->player.dir == 'E')
		degree = 0;
	else if (game->player.dir == 'W')
		degree = 180;
	rotate_player(&game->player, degree * (PI / 180));
}

void	allocate_buffer(t_game *game)
{
	int	i;

	game->buf = ft_calloc(game->height, sizeof(int **));
	if (!game->buf)
		ft_strexit("ERROR: Malloc Fail!");
	game->

