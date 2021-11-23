/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:30:42 by seyun             #+#    #+#             */
/*   Updated: 2021/11/23 23:08:10 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_game *game, int x, int y, int color)
{
	int dx;
	int dy;

	dy = 0;
	while (dy < TILE)
	{
		dx = 0;
		while (dx < TILE)
		{
			game->img.date[game->width *

void	draw_squares(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[x][y] == 1)
				draw_square(game, TILE * x, TILE * y, 0x0000FF);
			else
				draw_square(game, TILE * x, TILE * y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}


void	draw_loop(t_game *gmae)
{
	draw_squares(game);
	draw_line(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	return (0);
}

void	cub2d(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, game->height, "2d");
	game->img->ptr = mlx_new_image(game->mlx, game->width, game->height);
	game->img->date = (int *)mlx_get_data_addr(game->img->img, &game->img->bpp,
			&game->img->size_l, &game->img->endian);
	//mlx_hook(game->win, KEY_EVENT_PRESS, 0, key_press, &game);
	//mlx_hook(game->i
	mlx_loop_hook(game->mlx, draw_loop, &game);
	mlx_loop(game->mlx);
	return (0);
}
