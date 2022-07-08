/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:06:03 by seyun             #+#    #+#             */
/*   Updated: 2022/07/08 19:36:53 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->width, game->height, TITLE);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, detect_keypress, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, ft_exit_key, game);
	mlx_loop_hook(game->mlx, execute_ray, game);
	mlx_loop(game->mlx);
}

int	detect_keypress(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
		move_back_forward(game, &game->player, game->player.move_speed);
	if (key == KEY_S || key == KEY_DOWN)
		move_back_forward(game, &game->player, -game->player.move_speed);
	if (key == KEY_A)
		move_left_right(game, &game->player, game->player.move_speed);
	if (key == KEY_D)
		move_left_right(game, &game->player, -game->player.move_speed);
	if (key == KEY_LEFT)
		rotate_player(&game->player, -game->player.rot_speed);
	if (key == KEY_RIGHT)
		rotate_player(&game->player, game->player.rot_speed);
	if (key == KEY_ESC || key == X_EVENT_KEY_EXIT)
		ft_strexit("KEY_ESC_PRESSED: Exit Successfully!");
	return (0);
}

void	move_back_forward(t_game *game, t_player *player, double move_speed)
{
	char	x;
	char	y;
//	int		goback_x;
//	int		goback_y;

//	goback_x = player->x;
//	goback_y = player->y;
	x = game->map[(int)player->y][(int)(player->x \
			+ player->dir_x * move_speed)];
	y = game->map[(int)(player->y + player->dir_y \
			*move_speed)][(int)player->x];
	if (x != WALL)
		player->x += player->dir_x * move_speed;
	if (y != WALL)
		player->y += player->dir_y * move_speed;
/*	if ((int)player->y != (int)goback_y || (int)player->x != (int)goback_x)
	{
		game->map[(int)goback_y][(int)(goback_x)] = '0';
		game->map[(int)player->y][(int)(player->x)] = player->dir;
	}*/
}

void	move_left_right(t_game *game, t_player *player, double move_speed)
{
	char	x;
	char	y;
//	int		tmp_x;
//	int		tmp_y;

//	tmp_x = player->x;
//	tmp_y = player->y;
	x = game->map[(int)player->y][(int)(player->x + \
			player->dir_y * move_speed)];
	y = game->map[(int)(player->y + player->dir_x * \
			move_speed)][(int)player->x];
	if (x != WALL)
		player->x += player->dir_y * move_speed;
	if (y != WALL)
		player->y += -player->dir_x * move_speed;
/*	if ((int)player->y != (int)tmp_y || (int)player->x != (int)tmp_x)
	{
		game->map[(int)tmp_y][(int)(tmp_x)] = '0';
		game->map[(int)player->y][(int)(player->x)] = player->dir;
	}*/
}

void	rotate_player(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) - \
					player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + \
					player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - \
					player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed) + \
					player->plane_y * cos(rot_speed);
}
