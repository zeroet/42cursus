/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:17:44 by seyun             #+#    #+#             */
/*   Updated: 2021/11/05 23:31:54 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <string.h>
#include <stdlib.h>

#define TIELS 60
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW

typedef struct s_img
{
	void *img_ptr;
	int *data;
	int bpp;
	int size_line;
	int endian;
} t_img;

typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
	int map[ROW][COL];
}	t_game;

void	mlx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WITDH, HEIGHT, "2d");
}

void	img_init(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game.img.size_line, &game.img->endian);
}

void	draw_piexles_of_tiles(t_game *game, int row, int col)
{
	int tile_row, tile_col;

	row *= TILES;



void	draw_tiles(t_game *game)
{
	int row, col;

	row = 0;
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 1)
				draw_pixels_of_tile(game, row, col);
			col++;
		}
		row++;
	}
}

void map_init(t_game *game)
{
	int src[ROW][COL] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	memcpy(game->map, src, sizeof(int) * ROW * COL);
	draw_tiles(game);
}

int	main(void)
{
	t_game game;

	mlx_init(&game);
	img_init(&game);
	map_init(&game);
	
